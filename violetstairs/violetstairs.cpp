#include "violetstairs.hpp"

namespace owdin {
    void message::hi( account_name user ) {
        print( "Hello, ", name{user} );
    }

    void message::write( account_name user, string message ) {
        require_auth( user );
        time current_time = now();

        postIndex post( _self, user );
        post.emplace( _self, [&]( auto& s ) {
            s.account = user;
            s.message = message;
            s.created = current_time;
        });
    }

    void message::remove( account_name user ) {
        postIndex post( _self, user );
        auto itr = post.find( user );
        eosio_assert( itr != post.end(), "can not found account" );
        post.erase( itr );
    }
}

EOSIO_ABI( owdin::message, (hi)(write)(remove) )
