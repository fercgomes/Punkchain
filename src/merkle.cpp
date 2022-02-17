#include "merkle.hpp"
#include <memory>
#include "utils.hpp"

Merkle::Node::Node(std::unique_ptr<Merkle::Node> lhs, std::unique_ptr<Merkle::Node> rhs)
{
    // transfer ownership to this node
    // is this bad?
    this->lhs = std::move(lhs);
    this->lhs = std::move(rhs);

    // children have already been hashed
    // concat and hash
    std::string concat = lhs->hash + rhs->hash;
    std::string hashed = Utils::HashString(concat);
    hash               = hashed;
}

Merkle::Node::Node(std::string hash) : hash(hash) {}

Merkle::Node* Merkle::GenerateFromTransactions(std::vector<std::unique_ptr<Transaction>>& txs)
{
    int       txsLen = txs.size();
    int       idx    = 0;
    const int stride = 2;
    return nullptr;
}