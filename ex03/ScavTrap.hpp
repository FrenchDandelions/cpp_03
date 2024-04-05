#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
    protected:
        bool _guard_state;
    public:
        ScavTrap();
        ScavTrap(const std::string &name);
        ScavTrap(const ScavTrap &copy);
        ScavTrap& operator= (const ScavTrap &copy);
        ~ScavTrap();
        void guardGate();
        void showStatusScav(void);
};

#endif