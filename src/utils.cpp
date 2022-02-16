#include <aes.h>
#include <assert.h>
#include <cryptlib.h>
#include <eccrypto.h>
#include <files.h>
#include <filters.h>
#include <fmt/format.h>
#include <hex.h>
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

std::string HashString(std::string msg)
{
    std::string          t;
    std::string          digest;
    CryptoPP::HexEncoder encoder(new CryptoPP::StringSink(t));
    CryptoPP::SHA256     hash;

    hash.Update((const CryptoPP::byte*)msg.data(), msg.size());
    digest.resize(hash.DigestSize());
    hash.Final((CryptoPP::byte*)&digest[0]);
    CryptoPP::StringSource(digest, true, new CryptoPP::Redirector(encoder));

    return t;
}

}; // namespace Utils