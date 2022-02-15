#include "transaction.hpp"
#include <iostream>
#include <time.h>

Transaction::Transaction(Wallet& senderWallet, std::string recipientAddress, float amount)
{
    if (amount > senderWallet.GetBalance())
    {
        std::cerr << "Sender has no balance" << std::endl;
        throw std::invalid_argument("no balance");
    }
    else
    {
        TxOut txOut1{.amount  = senderWallet.GetBalance() - amount,
                     .address = senderWallet.GetPublicAddress()};
        TxOut txOut2{.amount = amount, .address = recipientAddress};

        // Sign transaction ?
        std::string signature;
        std::string message = "test";
        senderWallet.SignMessage(message, signature);

        TxIn txIn
        {
            .timestamp = std::time(nullptr), .amount = senderWallet.GetBalance(),
            .address = senderWallet.GetPublicAddress(), .signature = signature
        };

        txInputs.push_back(txIn);
        txOutputs.push_back(txOut1);
        txOutputs.push_back(txOut2);
    }
}