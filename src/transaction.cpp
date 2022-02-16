#include "transaction.hpp"
#include <iostream>
#include <sstream>
#include <time.h>
#include "utils.hpp"

std::ostream& operator<<(std::ostream& os, const TxOut& txOut)
{
    os << txOut.address << "-" << txOut.amount;
    return os;
}

std::string TxOut::ToString()
{
    std::stringstream ss;
    ss << this->address << "-" << this->amount;
    return ss.str();
}

Transaction::Transaction(Wallet& senderWallet, std::string recipientAddress, const double amount)
{
    id = 1;

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

        // This is a generated TxIn...
        // It must be an accepted tx from the blockchain
        // whose address pubkey matches this wallet.
        //
        // Validation means verifying the signature of
        // this Tx with the public key announced in the
        // UTXO being spent. Tx is valid iff public key
        // of UTXO's recipient verifies the Hash(UTXO + NewOwnerPubAddr)
        // See "2. Transactions" of Bitcoin's Whitepaper
        TxIn txIn{.timestamp = std::time(nullptr),
                  .amount    = senderWallet.GetBalance(),
                  .address   = senderWallet.GetPublicAddress()};

        // Hash(UTXO + NewOwnerPubKey)
        std::string       signature;
        std::stringstream ss;

        ss << txIn.timestamp << "-" << txIn.address << "-" << txIn.amount;

        std::string message   = ss.str();
        std::string hashedMsg = Utils::HashString(message);

        senderWallet.SignMessage(hashedMsg, signature);
        txIn.signature = signature; // TxIn is signed

        txInputs.push_back(txIn);
        txOutputs.push_back(txOut1);
        txOutputs.push_back(txOut2);
    }
}

std::ostream& operator<<(std::ostream& os, const Transaction& tx)
{
    os << "TxId: " << tx.id << std::endl;
    os << "TxInputs: " << std::endl;

    for (auto txIn : tx.txInputs)
    {
        os << "==== Address: " << txIn.address << std::endl;
        os << "==== Amount: " << txIn.amount << std::endl;
        os << "==== Timestamp: " << txIn.timestamp << std::endl;
        os << "==== Signature: " << txIn.signature << std::endl;
    }

    os << "TxOutputs: " << std::endl;

    for (auto txOut : tx.txOutputs)
    {
        os << "==== Address: " << txOut.address << std::endl;
        os << "==== Amount: " << txOut.amount << std::endl;
    }

    return os;
}