#include <memory>
#include <vector>
#include "transaction.hpp"

// Merkle Tree
// n data nodes (hashable)
// generates a binary tree

namespace Merkle
{
class Node
{
private:
    std::unique_ptr<Node> lhs = nullptr;
    std::unique_ptr<Node> rhs = nullptr;
    std::string           hash;

public:
    // Inner node/root constructor
    Node(std::unique_ptr<Node> lhs, std::unique_ptr<Node> rhs);

    // Leaf constructor
    Node(std::string hash);

    // Leaf constructor with data
    // ??
};

Node* GenerateFromTransactions(std::vector<std::unique_ptr<Transaction>>& txs);
} // namespace Merkle