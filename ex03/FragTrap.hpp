#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ScavTrap.hpp"

class FragTrap : public virtual ClapTrap
{
    public:
        FragTrap();
        FragTrap(const std::string &name);
        FragTrap(const FragTrap &copy);
        FragTrap& operator= (const FragTrap &copy);
        ~FragTrap();
        void highFivesGuys(void);
};

#endif