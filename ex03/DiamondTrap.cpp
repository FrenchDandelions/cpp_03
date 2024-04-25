#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap()
{
    std::cout << "Default DiamondTrap constructor called" << std::endl;
    this->DiamondTrap::_name = "DiamondTrap";
    this->ClapTrap::_name = DiamondTrap::_name + "_clap_name";
    this->_hit_points = FragTrap::_true_hp;
    this->_energy_points = ScavTrap::_energy_points;
    this->_attack_damage = FragTrap::_true_damage;
    this->_max_energy = ScavTrap::_max_energy;
    this->_max_hp = FragTrap::_true_hp;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"), FragTrap(name + "_clap_name"),ScavTrap(name + "_clap_name")
{
    std::cout << "DiamondTrap constructor called" << std::endl;
    DiamondTrap::_name = name;
    this->_hit_points = FragTrap::_true_hp;
    this->_energy_points = ScavTrap::_energy_points;
    this->_attack_damage = FragTrap::_true_damage;
    this->_max_energy = ScavTrap::_max_energy;
    this->_max_hp = FragTrap::_true_hp;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    this->operator=(copy);
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &copy)
{
    std::cout << "DiamondTrap copy assignement operator called" << std::endl;
    if(this != &copy){
        this->ClapTrap::_name = copy.ClapTrap::_name;
        this->DiamondTrap::_name = copy.DiamondTrap::_name;
        this->_hit_points = copy._hit_points;
        this->_energy_points = copy._energy_points;
        this->_max_energy = copy._max_energy;
        this->_attack_damage = copy._attack_damage;
        this->_max_hp = copy._max_hp;
    }
    return(*this);
}

const std::string DiamondTrap::getName(void){
    return(DiamondTrap::_name);
}

void DiamondTrap::whoAmI(void){
    std::cout << "I am both " << getName() << " and " << ClapTrap::getName() << std::endl;
}

void DiamondTrap::showCharacteristics(void){
        std::cout << "DiamondTrap " << getName() << " has " << this->_hit_points << " hp, " << this->_attack_damage << " dps and "<< this->_energy_points <<  " energy pts!" << std::endl;
}

void DiamondTrap::showStatus(void)
{
    if(this->_hit_points)
        std::cout << "DiamondTrap " << getName() << " has " << this->_hit_points << " hp and " << this->_attack_damage << " dps and "<< this->_energy_points <<  " energy left!" << std::endl;
    else
        std::cout << "DiamondTrap " << getName() << " is dead!" << std::endl;
}

void DiamondTrap::takeDamage(unsigned int amount)
{
    if(this->_hit_points)
    {
        if(this->_hit_points <= amount)
        {
            std::cout << "DiamondTrap " << this->_name << " took " << amount << " points of damage and is now dead!" << std::endl;
            this->_hit_points = 0;
        }
        else
        {
            std::cout << "DiamondTrap " << this->_name << " took " << amount << " points of damage!" << std::endl;
            this->_hit_points -= amount;
        }
    }
    else if(!this->_hit_points)
    {
        std::cout << "DiamondTrap " << this->_name << " is already dead!" << std::endl;
    }
}

void DiamondTrap::beRepaired(unsigned int amount)
{
    if(this->_energy_points && this->_hit_points)
    {
        if((this->_hit_points + amount) >= this->_max_hp && this->_hit_points < this->_max_hp)
        {
            std::cout << "DiamondTrap " << this->_name << " repaired itself and is now at full health!" << std::endl;
            this->_hit_points = this->_max_hp;
        }
        else if(this->_hit_points == this->_max_hp)
        {
            std::cout << "DiamondTrap " << this->_name << " tried repairing itself, but it was already full health and lost energy for nothing! :(" << std::endl;
        }
        else
        {
            std::cout << "DiamondTrap " << this->_name << " repaired itself!" << std::endl;
            this->_hit_points += amount;
        }
        this->_energy_points--;
    }
    else if(!this->_energy_points && this->_hit_points)
    {
        std::cout << "DiamondTrap " << this->_name << " can't repair itself because it has no energy left!" << std::endl;
    }
    else if(!this->_hit_points)
    {
        std::cout << "DiamondTrap " << this->_name << " can't repair itself because it's dead!" << std::endl;
    }
}

void DiamondTrap::attack(const std::string &name)
{
    ScavTrap::attack(name);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called" << std::endl;
}