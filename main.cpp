#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include "Rotor.h"
#include "TrainOfGears.h"

void getInput(size_t* ptr, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        std::cin >> *(ptr + i);
    }
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
            std::cout << "See ya!";
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


    std::cout << "Enter numbers of rotors (1 - 8)." << std::endl;
    size_t numbers[nRotors];
    getInput(numbers, nRotors);


    std::cout << "Enter positions of rotors (0-26):" << std::endl;
    size_t positions[nRotors];
    getInput(positions, nRotors);

    std::vector<Rotor*> rotors;
    rotors.reserve(nRotors);
    for(size_t i = 0; i < nRotors; i++)
    {
        rotors.push_back(new Rotor(numbers[i], positions[i]));
    }

    std::cout << "Enter text you want to encrypt: " << std::endl;
    std::cin.clear();
    std::cin.ignore(256, '\n');
    std::vector <std::string> text;
    std::string line;
    do
    {
        std::getline(std::cin, line);
        text.push_back(line);
    }
    while (line.length() != 0);

    TrainOfGears* train = new TrainOfGears();
    train->runPlugboard(text, plugboard);
    train->runRotors(text, rotors);

    for (size_t i = 0; i < text.size(); i++)
    {
        std::cout << text[i] << std::endl;
    }

    delete train;
    for (Rotor* elem: rotors)
    {
        delete elem;
    }
    return 0;
}
