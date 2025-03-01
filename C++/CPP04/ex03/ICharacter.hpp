#pragma once

#include "AMateria.hpp"

class ICharacter
{
    public:
    virtual ~ICharacter() {}
    virtual std::string const& getName() const = 0;
    virtual void equip(AMateria* m) = 0;
    virtual void unequip(int idx) = 0;
    virtual void use(int idx, ICharacter& target) = 0;
    virtual AMateria* getMateria(int idx) const = 0;
    // ICharacter(const ICharacter&) = delete; // Запретить копирование
    // ICharacter& operator=(const ICharacter&) = delete; //delete-@ 11 standarta,kmaqres!
};