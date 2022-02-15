#include <iostream>
#include "wallet.hpp"

int main(int argc, char* argv[])
{
    std::cout << "== PUNKCHAIN == " << std::endl;
    Wallet wallet;

    std::string testStr = "ednaldo pereira";
    std::string signature;

    bool signResult = wallet.SignMessage(testStr, signature);
    auto publicKey  = wallet.GetPublicKey();

    // std::cout << signature << std::endl;

    bool verifyResult = wallet.VerifyMessage(publicKey, testStr, signature);
    std::cout << verifyResult << std::endl;

    return 0;
}
