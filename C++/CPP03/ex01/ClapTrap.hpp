#pragma once

#include <iostream>
#include <string>

class ClapTrap
{
    protected:
        std::string _name;
        int _hit_points;
        int _energy_points;
        int _attack_damage;
    public:
        ClapTrap();
        ClapTrap(const ClapTrap& other);
        ClapTrap& operator=(const ClapTrap& other);
        ClapTrap(std::string name);
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        //getter
        // std::string get_name(){ return _name;}
        // int get_int_member(){return _hit_points;}

        virtual ~ClapTrap();
};

 