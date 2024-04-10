#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "FragTrap.hpp"

class DiamondTrap : virtual public FragTrap, virtual public ScavTrap
{
    private:
        const std::string _name;
    public:
        DiamondTrap();
        DiamondTrap(const std::string &name);
        DiamondTrap(const DiamondTrap &copy);
        DiamondTrap& operator=(const DiamondTrap &copy);
        ~DiamondTrap();

        void attack(const std::string &name);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        void showStatus(void);
        void showCharacteristics(void);
        const std::string getName(void);
        void whoAmI(void);
};

#endif