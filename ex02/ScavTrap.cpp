#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(), _guard_state(0)
{
    std::cout << "Default ScavTrap constructor called" << std::endl;
    (const_cast<std::string&>(this->_name)) = "ScavTrap";
    this->_hit_points = 100;
    this->_energy_points = 50;
    this->_max_energy = 50;
    this->_attack_damage = 20;
    this->_max_hp = 100;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name), _guard_state(0)
{
    std::cout << "ScavTrap constructor called" << std::endl;
    this->_hit_points = 100;
    this->_energy_points = 50;
    this->_max_energy = 50;
    this->_attack_damage = 20;
    this->_max_hp = 100;
}

ScavTrap::ScavTrap(const ScavTrap &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    this->operator=(copy);
}

ScavTrap& ScavTrap::operator= (const ScavTrap &copy)
{
    std::cout << "ScavTrap copy assignement operator called" << std::endl;
    if(this != &copy){
        (const_cast<std::string&>(this->_name)) = copy._name;
        this->_hit_points = copy._hit_points;
        this->_energy_points = copy._energy_points;
        this->_max_energy = copy._max_energy;
        this->_attack_damage = copy._attack_damage;
        this->_max_hp = copy._max_hp;
        this->_guard_state = copy._guard_state;
    }
    return(*this);
}

void ScavTrap::showStatusScav(void)
{
    if(this->_hit_points)
        std::cout << "ScavTrap " << getName() << " has " << this->_hit_points << " hp and " << this->_energy_points <<  " energy left and " << (this->_guard_state ? "is in Gate keeper mode!" : "isn't in Gate keeper mode!") << std::endl;
    else
        std::cout << "ScavTrap " << getName() << " is dead!" << std::endl;
}

void ScavTrap::guardGate()
{
    if(!this->_guard_state)
    {
        this->_guard_state = 1;
        std::cout << "Scavtrap " << getName() << " is now in Gate keeper mode!" << std::endl;
    }
    else
    {
        std::cout << "Scavtrap " << getName() << " is already in Gate keeper mode!" << std::endl;
    }
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called" << std::endl;
}
