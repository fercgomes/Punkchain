#include <string>
#include <vector>

class Chain
{
private:
    std::vector<std::string> transactions;

public:
    std::vector<std::string> GetTransactions();
};
