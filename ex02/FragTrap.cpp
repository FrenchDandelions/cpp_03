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

void FragTrap::showStatus(void)
{
    if(this->_hit_points)
        std::cout << "FragTrap " << getName() << " has " << this->_hit_points << " hp and " << this->_energy_points <<  " energy left!" << std::endl;
    else
        std::cout << "FragTrap " << getName() << " is dead!" << std::endl;
}

void FragTrap::attack(const std::string &target)
{
    if(this->_energy_points && this->_hit_points)
    {
        std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
        this->_energy_points--;
    }
    else if(!this->_energy_points && this->_hit_points)
    {
        std::cout << "FragTrap " << this->_name << " can't attack because it has no energy left!" << std::endl;
    }
    else if(!this->_hit_points)
    {
        std::cout << "FragTrap " << this->_name << " can't attack because it's dead!" << std::endl;
    }
}

void FragTrap::takeDamage(unsigned int amount)
{
    if(this->_hit_points)
    {
        if(this->_hit_points <= amount)
        {
            std::cout << "FragTrap " << this->_name << " took " << amount << " points of damage and is now dead!" << std::endl;
            this->_hit_points = 0;
        }
        else
        {
            std::cout << "FragTrap " << this->_name << " took " << amount << " points of damage!" << std::endl;
            this->_hit_points -= amount;
        }
    }
    else if(!this->_hit_points)
    {
        std::cout << "FragTrap " << this->_name << " is already dead!" << std::endl;
    }
}

void FragTrap::beRepaired(unsigned int amount)
{
    if(this->_energy_points && this->_hit_points)
    {
        if((this->_hit_points + amount) >= this->_max_hp && this->_hit_points < this->_max_hp)
        {
            std::cout << "FragTrap " << this->_name << " repaired itself and is now at full health!" << std::endl;
            this->_hit_points = this->_max_hp;
        }
        else if(this->_hit_points == this->_max_hp)
        {
            std::cout << "FragTrap " << this->_name << " tried repairing itself, but it was already full health and lost energy for nothing! :(" << std::endl;
        }
        else
        {
            std::cout << "FragTrap " << this->_name << " repaired itself!" << std::endl;
            this->_hit_points += amount;
        }
        this->_energy_points--;
    }
    else if(!this->_energy_points && this->_hit_points)
    {
        std::cout << "FragTrap " << this->_name << " can't repair itself because it has no energy left!" << std::endl;
    }
    else if(!this->_hit_points)
    {
        std::cout << "FragTrap " << this->_name << " can't repair itself because it's dead!" << std::endl;
    }
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "It's cute ! FragTrap " << getName() << " is asking for a high five! 🥹" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called" << std::endl;
}