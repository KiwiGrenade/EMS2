//
// Created by Grim Reaper on 28.08.2022.
//
#include <iostream>
#include <vector>
#include <string>
#include "Rotor.h"

Rotor::Rotor(size_t number, size_t position) noexcept(true)
:   number(number)
{
    this->position[number] = position;
}

void Rotor::goThrough(std::vector <std::string> &text) noexcept(true)
{
    for(size_t k = 0; k < text.size(); k++)
    {
        for(size_t m = 0; m < text[k].size(); m++)
        {
            //SEE IF ALGORITHM WORKS
            //((int)'A') = 65
            size_t translation = (int)text[k][m];
            if((translation < 65) || (translation > 90))
            {
                size_t index = ((int)text[k][m]) - 65;
                index += position[number];
                index %= 26;
                if(position[number] == turnoverNotchPosition[number])
                {
                    position[number + 1] = (position[number + 1] + 1) % 26;
                }
                position[number] = (position[number] + 1) % 26;
                text[k][m] = rotorList[number - 1][index];
            }
        }
    }
}
