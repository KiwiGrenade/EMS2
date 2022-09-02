//
// Created by Grim Reaper on 28.08.2022.
//
#include <iostream>
#include <vector>
#include <string>
#include "Rotor.h"

Rotor::Rotor(size_t number, size_t pos) noexcept(true)
:   number(number)
{
    position[number] = pos;
}

void Rotor::step() noexcept(true)
{
    if(position[number] == notchPosition[number])
    {
        position[number + 1] = (position[number + 1] + 1) % 26;
    }
    position[number] = (position[number] + 1) % 26;
}

void Rotor::goThrough(std::vector <std::string> &text) noexcept(true)
{
    for(size_t k = 0; k < text.size(); k++)
    {
        for(size_t m = 0; m < text[k].size(); m++)
        {
            //convert char to int
            size_t translation = (int)text[k][m];
            //is char CAP?
            if((translation >= ((int)'A')) && (translation <= ((int)'Z')))
            {
                if((position[number] + notchPosition[number]) % 26 == 0)
                {
                    position[number + 1] = (position[number + 1] + 1) % 26;
                }
                position[number] = (position[number] + 1) % 26;
                size_t index = (translation - 65 + position[number]) % 26;
                text[k][m] = rotorList[number][index];
            }
        }
    }
}
