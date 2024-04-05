#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "Default FragTrap constructor called" << std::endl;
    (const_cast<std::string&>(this->_name)) = "FragTrap";
    this->_hit_points = 100;
    this->_energy_points = 100;
    this->_max_energy = 100;
    this->_attack_damage = 30;
    this->_max_hp = 100;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
    std::cout << "FragTrap constructor called" << std::endl;
    this->_hit_points = 100;
    this->_energy_points = 100;
    this->_max_energy = 100;
    this->_attack_damage = 30;
    this->_max_hp = 100;
}

FragTrap::FragTrap(const FragTrap &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    this->operator=(copy);
}


FragTrap& FragTrap::operator=(const FragTrap &copy)
{
    std::cout << "FragTrap copy assignement operator called" << std::endl;
    if(this != &copy){
        (const_cast<std::string&>(this->_name)) = copy._name;
        this->_hit_points = copy._hit_points;
        this->_energy_points = copy._energy_points;
        this->_max_energy = copy._max_energy;
        this->_attack_damage = copy._attack_damage;
        this->_max_hp = copy._max_hp;
    }
    return(*this);
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "It's cute ! FragTrap " << getName() << " is asking for a high five! 🥹" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called" << std::endl;
}