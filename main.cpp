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

bool isPlugboardValid(std::string plugboard)
{
    std::unordered_set<char> set(begin(plugboard), end(plugboard));
    return  ((set.size() != plugboard.length()) || ((set.size() % 2) != 0) || (set.size() > 26));
}
//get this done
void runPlugboard(const std::string &plugboard, std::vector<std::string> &text)
{

    for(size_t i = 0; i < plugboard.size()/2, i++)
    {
        for(size_t j = 0; j < text.size(); j++)
        {
            while(text[]plugboard[i*2])
        }
    }
}

void encrypt (char* letter, const size_t numRotors, const size_t* rotors) noexcept(true)
{
    char rotorList[6][26] =
    {
        // normal alphabet
        {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'},
        // rotor I
        {'E','K','M','F','L','G','D','Q','V','Z','N','T','O','W','Y','H','X','U','S','P','A','I','B','R','C','J'},
        // rotor II
        {'A','J','D','K','S','I','R','U','X','B','L','H','W','T','M','C','Q','G','Z','N','P','Y','F','V','O','E'},
        // rotor III
        {'B','D','F','H','J','L','C','P','R','T','X','V','Z','N','Y','E','I','W','G','A','K','M','U','S','Q','O'},
        // rotor IV
        {'E','S','O','V','P','Z','J','A','Y','Q','U','I','R','H','X','L','N','F','T','G','K','D','C','M','W','B'},
        // rotor V
        {'V','Z','B','R','G','I','T','Y','U','P','S','D','N','H','L','X','A','W','M','J','Q','O','F','E','C','K'},
    };
    size_t indexInRotorList;
    for( size_t i = 0; i < numRotors; i++)
    {
        indexInRotorList = *(rotors + i);
        for (size_t m = 0; m < 26; m++)
        {
            if (*letter == rotorList[0][m])
            {
                *letter = rotorList[indexInRotorList][m];
                break;
            }
        }
    }
}

int main() {
    char choice;
    while ((choice != 'Y') && (choice != 'y'))
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
    std::cout << "Setting up the plug board." << std::endl
              << "Enter up to 13 pairs of characters in CAPITAL LETTERS." << std::endl
              << "EX.: AI PO SJ HG" << std::endl;

    if(isPlugboardValid(getPlugboard()) == false)
    {
        std::cout << "ERROR: Inserted pairs are not valid!" << std::endl;
    }



    std::cout << "Enter number of rotors you want to use: " << std::endl;
    size_t nRotors;
    std::cin >> nRotors;

    std::cout << "Enter numbers of rotors that you would like to use (from 1 to 8)." << std::endl
              << "Ex.: 1 2 8 3 4 (press ENTER to save)" << std::endl;
    size_t* wantedRotors = getRotors(nRotors);

    std::cout << "Enter text you want to encrypt: " << std::endl;
    std::vector <std::string> textToEncrypt;
    std::cin.clear();
    std::cin.ignore(256, '\n');
    std::string line;
    do
    {
        std::getline(std::cin, line);
        textToEncrypt.push_back(line);
    }
    while (line.length() != 0);
    for (size_t row = 0; row < textToEncrypt.size(); row++)
    {
        for(size_t col = 0; col < textToEncrypt[row].size(); col++)
        {
            //go through plugboard
            encrypt(&textToEncrypt[row][col], nRotors, wantedRotors);
        }
    }
    for (size_t i = 0; i < textToEncrypt.size(); i++)
    {
        std::cout << textToEncrypt[i] << std::endl;
    }
    return 0;
}
