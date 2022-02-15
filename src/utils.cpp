#include <aes.h>
#include <assert.h>
#include <eccrypto.h>
#include <files.h>
#include <filters.h>
#include <fmt/format.h>
#include <integer.h>
#include <iostream>
#include <oids.h>
#include <osrng.h>
#include <sha.h>

using CryptoPP::DL_GroupParameters_EC;
using CryptoPP::ECDSA;
using CryptoPP::ECP;
using CryptoPP::SHA1;
using std::cout;
using std::endl;

namespace Utils
{
void PrintDomainParameters(const DL_GroupParameters_EC<ECP>& params)
{
    cout << endl;

    cout << "Modulus:" << endl;
    cout << " " << params.GetCurve().GetField().GetModulus() << endl;

    cout << "Coefficient A:" << endl;
    cout << " " << params.GetCurve().GetA() << endl;

    cout << "Coefficient B:" << endl;
    cout << " " << params.GetCurve().GetB() << endl;

    cout << "Base Point:" << endl;
    cout << " X: " << params.GetSubgroupGenerator().x << endl;
    cout << " Y: " << params.GetSubgroupGenerator().y << endl;

    cout << "Subgroup Order:" << endl;
    cout << " " << params.GetSubgroupOrder() << endl;

    cout << "Cofactor:" << endl;
    cout << " " << params.GetCofactor() << endl;
}

void PrintPrivateKey(const ECDSA<ECP, SHA1>::PrivateKey& key)
{
    cout << endl;
    cout << "Private Exponent:" << endl;
    cout << " " << key.GetPrivateExponent() << endl;
}

void PrintPublicKey(const ECDSA<ECP, SHA1>::PublicKey& key)
{
    cout << endl;
    cout << "Public Element:" << endl;
    cout << " X: " << key.GetPublicElement().x << endl;
    cout << " Y: " << key.GetPublicElement().y << endl;
}
}; // namespace Utils