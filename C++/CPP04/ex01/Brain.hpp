#pragma once

#include "Animal.hpp"
#include <iostream>
#include <string>

class Brain
{
    private:
        std::string ideas[100];
    public:
        Brain();
        Brain(const Brain& other);
        Brain& operator=(const Brain& other);
        ~Brain();
};

