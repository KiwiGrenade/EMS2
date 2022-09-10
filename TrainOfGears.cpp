//
// Created by mango on 05.09.22.
//

#include "TrainOfGears.h"
//RESOLVE NOTCH ISSUE AND CHANGE ACCORDINGLY TO THE OUTCOME
void TrainOfGears::step(std::vector<Rotor*> rotors) noexcept(false)
{
    for(size_t i = 0; i + 1 < rotors.size(); i++)
    {
        if(rotors[i]->getPosition() == rotors[i + 1]->getNotchPosition())
        {
            rotors[i]->step();
            rotors[i + 1]->step();
        }
    }
    rotors[0]->step();
}

void TrainOfGears::runPlugboard(std::vector<std::string> &text, const std::string &plugboard) noexcept(false)
{
    for (size_t i = 0; i < plugboard.size(); i += 2)
    {
        for (size_t j = 0; j < text.size(); j++)
        {
            while (text[j].find(plugboard[i]) != -1)
            {
                text[j][text[j].find(plugboard[i])] = plugboard[i + 1];
            }
        }
    }
}

void TrainOfGears::runRotors(std::vector<std::string> &text, std::vector<Rotor *> &rotors) noexcept(false)
{
    for (size_t i = 0; i < text.size(); i++)
    {
        for (int j = 0; j < text[i].size(); j++)
        {
            size_t translation = (int) text[i][j];
            if((translation >= ((int)'A')) && (translation <= ((int)'Z')))
            {
                step(rotors);
                for (size_t k = 0; k < rotors.size(); k++)
                {
                    translation = (int) text[i][j];
                    translation = translation - 65 + rotors[k]->getPosition();
                    translation %= 26;
                    text[i][j] = rotorList[rotors[k]->getNumber()][translation];
                }
            }
        }
    }
}