#pragma once

#include <iostream>
#include "Data.hpp"
#include <cstdint>
class Serializer
{
private:
    Serializer();
    Serializer(const Serializer& other);
    Serializer& operator=(const Serializer& other);
    ~Serializer();
public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};
