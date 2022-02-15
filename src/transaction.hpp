#include <cstdint>
#include <string>
#include <vector>
#include "wallet.hpp"

struct TxIn
{
    uint32_t    timestamp;
    float       amount;
    std::string address;
    std::string signature;
};

struct TxOut
{
    float       amount;
    std::string address;
};

class Transaction
{
private:
    uint64_t           id;
    std::vector<TxIn>  txInputs;
    std::vector<TxOut> txOutputs;

public:
    Transaction(Wallet& senderWallet, std::string recipientAddress, float amount);
};