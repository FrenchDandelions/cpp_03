#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
    protected:
        unsigned int _hit_points;
        unsigned int _energy_points;
        unsigned int _attack_damage;
        const std::string _name;
        unsigned int _max_hp;
        unsigned int _max_energy;

    public:
        ClapTrap();
        ClapTrap(const std::string &name);
        ClapTrap(const ClapTrap &copy);
        ClapTrap& operator=(const ClapTrap &copy);
        ~ClapTrap();

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        void showStatus(void);
        void showCharacteristics(void);
        const std::string getName(void);

};

#endif