#include <iostream>
#include <sstream>
#include <vector>
#include <thread>
#include "./Blockchain/Blockchain.h"
#include "./SHA256/sha256.h"

//Constant definitions
const std::vector<std::string> NAMES{"Joe Biden",
                                     "Donald Trump",
                                     "Kanye West"};

//Function declerations
void election(std::vector<std::string> names);
int main();

//Functio definitions
void election(std::vector<std::string> names)
{
    return;
}

int main()
{
    election(NAMES);
}
