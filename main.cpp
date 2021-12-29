#include <iostream>
#include <sstream>
#include <vector>
#include "./Blockchain/Blockchain.h"
#include "./SHA256/sha256.h"

void election(std::vector<std::string> names);

int main()
{
    char a;
    std::cout << "Do you want to run an election? (y/n)";
    std::cin >> a;

    if (a == 'y' || a == 'Y')
    {
        int candidates;
        while (true)
        {
            std::cout << "Enter the amount of candidates you want (must be greater than 1): ";
            std::cin >> candidates;
            if (candidates > 1)
            {
                break;
            }
        }

        std::vector<std::string> names;
        for (int i = 0; i < candidates; ++i)
        {
            std::string name;
            while (true)
            {
                std::cout << "Enter a candidate name: ";
                std::getline(std::cin, name);
                if (!std::empty(name))
                {
                    break;
                }
            }
            names[i] = name;
        }
        election(names);
    }
}