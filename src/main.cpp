#include <iostream>
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

    return 0;
}
