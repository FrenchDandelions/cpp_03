#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name")
{
    (const_cast<std::string&>(this->_diamond_name) = name);
    this->_attack_damage = 30;
}

DiamondTrap::~DiamondTrap()
{
}