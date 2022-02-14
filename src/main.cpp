#include <fmt/format.h>
#include "./chain.hpp"

int main(int argc, char* argv[])
{
    if (argc) { fmt::print("hello world from {}!", argv[0]); }
    return 0;
}
