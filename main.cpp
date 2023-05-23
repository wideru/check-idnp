#include <iostream>
#include <regex>
#include <string>

bool CheckIDNP(const std::string& idnp)
{
    if (idnp.empty())
        return false;

    std::regex r("\\d{13}");
    std::smatch match;
    std::regex_match(idnp, match, r);

    if (!match.size())
        return false;

    std::vector<char> charIdnp(idnp.begin(), idnp.end());

    int intSum1 = 0, intSum2 = 0, intSum3 = 0;
    for (int i = 0; i < idnp.length() - 1; i += 3)
    {
        intSum1 += static_cast<int>(charIdnp[i]) - '0';
        intSum2 += static_cast<int>(charIdnp[i + 1]) - '0';
        intSum3 += static_cast<int>(charIdnp[i + 2]) - '0';
    }

    return idnp[idnp.length() - 1] == '0' + ((intSum1 * 7 + intSum2 * 3 + intSum3) % 10);
}

int main()
{
    std::string idnp = "1234567891234";

    bool idnpValid = CheckIDNP(idnp);

    if (idnpValid)
        std::cout << "Valid IDNP" << std::endl;
    else
        std::cout << "Not a valid IDNP" << std::endl;

    return 0;
}