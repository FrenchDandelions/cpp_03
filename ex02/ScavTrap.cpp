#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(), _guard_state(0)
{
    std::cout << "Default ScavTrap constructor called" << std::endl;
    this->_name = "ScavTrap";
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
        this->_name = copy._name;
        this->_hit_points = copy._hit_points;
        this->_energy_points = copy._energy_points;
        this->_max_energy = copy._max_energy;
        this->_attack_damage = copy._attack_damage;
        this->_max_hp = copy._max_hp;
        this->_guard_state = copy._guard_state;
    }
    return(*this);
}


void ScavTrap::attack(const std::string &target)
{
    if(this->_energy_points && this->_hit_points)
    {
        std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
        this->_energy_points--;
    }
    else if(!this->_energy_points && this->_hit_points)
    {
        std::cout << "ScavTrap " << this->_name << " can't attack because it has no energy left!" << std::endl;
    }
    else if(!this->_hit_points)
    {
        std::cout << "ScavTrap " << this->_name << " can't attack because it's dead!" << std::endl;
    }
}

void ScavTrap::takeDamage(unsigned int amount)
{
    if(this->_hit_points)
    {
        if(this->_hit_points <= amount)
        {
            std::cout << "ScavTrap " << this->_name << " took " << amount << " points of damage and is now dead!" << std::endl;
            this->_hit_points = 0;
        }
        else
        {
            std::cout << "ScavTrap " << this->_name << " took " << amount << " points of damage!" << std::endl;
            this->_hit_points -= amount;
        }
    }
    else if(!this->_hit_points)
    {
        std::cout << "ScavTrap " << this->_name << " is already dead!" << std::endl;
    }
}

void ScavTrap::beRepaired(unsigned int amount)
{
    if(this->_energy_points && this->_hit_points)
    {
        if((this->_hit_points + amount) >= this->_max_hp && this->_hit_points < this->_max_hp)
        {
            std::cout << "ScavTrap " << this->_name << " repaired itself and is now at full health!" << std::endl;
            this->_hit_points = this->_max_hp;
        }
        else if(this->_hit_points == this->_max_hp)
        {
            std::cout << "ScavTrap " << this->_name << " tried repairing itself, but it was already full health and lost energy for nothing! :(" << std::endl;
        }
        else
        {
            std::cout << "ScavTrap " << this->_name << " repaired itself!" << std::endl;
            this->_hit_points += amount;
        }
        this->_energy_points--;
    }
    else if(!this->_energy_points && this->_hit_points)
    {
        std::cout << "ScavTrap " << this->_name << " can't repair itself because it has no energy left!" << std::endl;
    }
    else if(!this->_hit_points)
    {
        std::cout << "ScavTrap " << this->_name << " can't repair itself because it's dead!" << std::endl;
    }
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
