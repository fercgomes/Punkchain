#pragma once
#include <cstdint>
#include <string>
#include <vector>
#include "wallet.hpp"

struct TxIn
{
    uint32_t    timestamp;
    double      amount;
    std::string address;
    std::string signature;
};

struct TxOut
{
    double      amount;
    std::string address;

    std::string ToString();

    friend std::ostream& operator<<(std::ostream& os, const TxIn& txIn);
};

std::ostream& operator<<(std::ostream& os, const TxOut& txOut);

class Transaction
{
private:
    uint64_t           id;
    std::vector<TxIn>  txInputs;
    std::vector<TxOut> txOutputs;

public:
    Transaction(Wallet& senderWallet, std::string recipientAddress, const double amount);

    friend std::ostream& operator<<(std::ostream& os, const Transaction& tx);
};

std::ostream& operator<<(std::ostream& os, const Transaction& tx);