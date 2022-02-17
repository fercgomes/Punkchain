#include <iostream>
#include "block.hpp"
#include "transaction.hpp"
#include "wallet.hpp"

int main(int argc, char* argv[])
{
    std::cout << "== PUNKCHAIN == " << std::endl;
    Wallet wallet;
    Wallet wallet2;

    std::cout << "Public Address" << std::endl;
    std::cout << wallet.GetPublicAddress() << std::endl;

    Transaction t1(wallet, wallet2.GetPublicAddress(), 10.0);

    std::cout << t1 << std::endl;

    const int target = 2;
    for (;;)
    {
        Block b(std::string("dsfjsdklhfjksdahfjkadshfkladjshfkdjshfhasdf"));
        b.Hash();

        std::string hash = b.GetHash();
        std::string targetString(target, '0');
        std::string sliced = hash.substr(0, target);

        std::cout << "Hash: " << hash << std::endl;

        if (sliced.compare(targetString) == 0)
        {
            std::cout << "mined" << std::endl;
            break;
        }
    }

    return 0;
}
