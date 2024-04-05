#include "FragTrap.hpp"

class DiamondTrap : virtual public ClapTrap, virtual public FragTrap, virtual public ScavTrap
{
private:
    const std::string _diamond_name;
public:
    DiamondTrap(const std::string &name);
    ~DiamondTrap();
};

