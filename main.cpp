#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

size_t* getRotors(size_t nRotors)
{
    size_t wantedRotors[nRotors];
    for (size_t i = 0; i < nRotors; i++)
    {
        std::cin >> wantedRotors[i];
        if (std::cin.fail())
        {
            std::cout << "ERROR 505";
            break;
        }
    }
    return wantedRotors;
}

std::string getPlugboard()
{
    std::string plugboard;
    std::getline(std::cin, plugboard);
    while (plugboard.find(' ') != -1)
    {
        plugboard.erase(plugboard.find(' '), 1);
    }
    return plugboard;
}

bool isPlugboardValid(const std::string &plugboard)
{
    std::unordered_set<char> set(begin(plugboard), end(plugboard));
    return  ((set.size() == plugboard.length()) || ((set.size() % 2) == 0) || (set.size() < 26));
}

void runPlugboard(const std::string &plugboard, std::vector<std::string> &text)
{
    for(size_t i = 0; i < plugboard.size(); i += 2)
    {
        for(size_t j = 0; j < text.size(); j++)
        {
            int indexInLine = text[j].find(plugboard[i]);
            if(indexInLine != -1)
            {
                text[j][indexInLine] = plugboard[i + 1];
            }
        }
    }
}

int main()
{
    char choice;
    do
    {
        std::cout << "Hello, welcome to EMS2, short for Enigma Simulator V2." << std::endl
                  << "Please proceed according to instructions." << std::endl
                  << "Thank you and have a great time!" << std::endl
                  << "Do you want to continue? (Y/n)" << std::endl;
        std::cin.clear();
        std::cin >> choice;
        std::cin.ignore(256, '\n');
        if ((choice == 'N') || (choice == 'n'))
        {
            return 0;
        }
    }
    while ((choice != 'Y') && (choice != 'y'));


    std::cout << "Setting up the plug board." << std::endl
              << "Enter up to 13 pairs of characters in CAPITAL LETTERS." << std::endl
              << "EX.: AI PO SJ HG" << std::endl;
    std::string plugboard;
    do
    {
        plugboard = getPlugboard();
        if(isPlugboardValid(plugboard) == false)
        {
            std::cout << "ERROR: Inserted pairs are not valid!" << std::endl;
        }
    }
    while(isPlugboardValid(plugboard) == false);


    size_t nRotors;
    do
    {
        std::cout << "Enter number of rotors you want to use: " << std::endl;
        std::cin >> nRotors;
    }
    while (nRotors > 8);


    std::cout << "Enter numbers of rotors that you would like to use (from 1 to 8)." << std::endl
              << "Ex.: 1 2 8 3 4 (press ENTER to save)" << std::endl;
    size_t* wantedRotors = getRotors(nRotors);

    std::cout << "Enter text you want to encrypt: " << std::endl;
    std::cin.clear();
    std::cin.ignore(256, '\n');
    std::vector <std::string> textToEncrypt;
    std::string line;
    do
    {
        std::getline(std::cin, line);
        textToEncrypt.push_back(line);
    }
    while (line.length() != 0);

    runPlugboard(plugboard, textToEncrypt);
    for (size_t row = 0; row < textToEncrypt.size(); row++)
    {
        for(size_t col = 0; col < textToEncrypt[row].size(); col++)
        {
            encrypt(&textToEncrypt[row][col], nRotors, wantedRotors);
        }
    }
    for (size_t i = 0; i < textToEncrypt.size(); i++)
    {
        std::cout << textToEncrypt[i] << std::endl;
    }
    return 0;
}
