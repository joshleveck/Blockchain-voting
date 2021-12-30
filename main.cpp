#include <iostream>
#include <vector>
#include <atomic>
#include <thread>
#include "./Blockchain/Blockchain.h"
#include "./SHA256/sha256.h"

//Constant definitions
const char *NAMES[3] = {"Joe Biden",
                        "Donald Trump",
                        "Kanye West"};

//Function declerations
Blockchain election(const char *names[], int cap);
int get_vote(const char *names[], int cap);
int main();

//Function definitions
int get_vote(const char *names[], int cap)
{
    char a;
    std::cout << "Do you want to submit another vote (y/n): ";
    std::cin >> a;
    if (a == 'y' || a == 'y')
    {
        while (true)
        {
            int n{0};
            std::cout << "Enter the number corresponding to the candidate you would like to vote for." << std::endl;
            for (int i = 0; i < cap; ++i)
            {
                std::cout << (i + 1) << ". " << names[i] << std::endl;
            }
            std::cin >> n;

            if (n > 0 && n < cap + 1)
            {
                return n - 1;
            }
        }
    }
    else
    {
        return -1;
    }
}

Blockchain election(const char *names[], int cap)
{
    Blockchain chain = Blockchain();
    int counter{1};

    std::vector<int> tmp_votes;
    bool voting{true};

    for (int i = 0; i < 1; ++i)
    {
        int vote = get_vote(names, cap);
        tmp_votes.push_back(vote);
    }

    while (voting)
    {

        std::vector<int> votes = tmp_votes;
        std::atomic<bool> done(false);

        tmp_votes = {};
        //Thread the mining
        std::thread t([&done, &chain, &votes, &counter]
                      {
                          chain.add_block(Block(counter, votes));
                          ++counter;
                          done = true;
                      });
        // Capture the votes while mining is going on
        while (!done)
        {
            int vote = get_vote(names, cap);
            if (vote == -1)
            {
                voting = false;
                break;
            }
            else
            {
                tmp_votes.push_back(vote);
            }
        }
        t.join();
    }
    if (tmp_votes.size() != 0)
    {
        std::vector<int> votes = tmp_votes;
        chain.add_block(Block(counter, votes));
    }
    return chain;
}

int main()
{
    Blockchain chain = election(NAMES, 3);
    chain.print_blockchain();
}
