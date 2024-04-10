#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ScavTrap.hpp"

class FragTrap : public virtual ClapTrap
{
    protected:
        static const int _true_hp = 100;
        static const int _true_damage = 30;
    public:
        FragTrap();
        FragTrap(const std::string &name);
        FragTrap(const FragTrap &copy);
        FragTrap& operator= (const FragTrap &copy);
        ~FragTrap();
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        void showStatus(void);
        void highFivesGuys(void);
};

#endif