#include <eosiolib/eosio.hpp>

using namespace std;
using namespace eosio;

namespace owdin {
    class message : public eosio::contract {
        public:
            using contract::contract;

            // @abi action
            void hi( account_name user );

            // @abi action
            void write( account_name user, string message );

            // @abi action
            void remove( account_name user );
        private:
            //@abi table post i64
            struct post {
                account_name account;
                string       message;
                time         created;

                uint64_t primary_key() const { return account; }

                EOSLIB_SERIALIZE( post, (account)(message)(created) )
            };

            typedef multi_index<N(posts), post> postIndex;
    };
}

