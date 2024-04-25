#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _hit_points(10), _energy_points(10), _attack_damage(0), _name("ClapTrap"), _max_hp(10), _max_energy(10)
{
    std::cout << "Default ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) :_hit_points(10), _energy_points(10), _attack_damage(0),_name(name), _max_hp(10), _max_energy(10)
{
    std::cout << "ClapTrap constructor called" << std::endl;
    // std::cout << "ClapTrap " << getName() << " is created!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    this->operator=(copy);
}

ClapTrap& ClapTrap::operator=(const ClapTrap &copy)
{
    std::cout << "ClapTrap copy assignement operator called" << std::endl;
    if(this != &copy){
        this->_name = copy._name;
        this->_attack_damage = copy._attack_damage;
        this->_energy_points = copy._energy_points;
        this->_hit_points = copy._hit_points;
        this->_max_energy = copy._max_energy;
        this->_max_hp = copy._max_hp;
    }
    return(*this);
}

void ClapTrap::showStatus(void)
{
    if(this->_hit_points)
        std::cout << "ClapTrap " << getName() << " has " << this->_hit_points << " hp and " << this->_energy_points <<  " energy left!" << std::endl;
    else
        std::cout << "ClapTrap " << getName() << " is dead!" << std::endl;
}

void ClapTrap::showCharacteristics(void){
    std::cout << "Class has " << this->_name << " for name and " << this->_attack_damage << " attack damage and " << this->_max_energy << " energy points and " << this->_max_hp << " hp" << std::endl;
}

const std::string ClapTrap::getName(void)
{
    return(this->_name);
}

void ClapTrap::attack(const std::string &target)
{
    if(this->_energy_points && this->_hit_points)
    {
        std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
        this->_energy_points--;
    }
    else if(!this->_energy_points && this->_hit_points)
    {
        std::cout << "ClapTrap " << this->_name << " can't attack because it has no energy left!" << std::endl;
    }
    else if(!this->_hit_points)
    {
        std::cout << "ClapTrap " << this->_name << " can't attack because it's dead!" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if(this->_hit_points)
    {
        if(this->_hit_points <= amount)
        {
            std::cout << "ClapTrap " << this->_name << " took " << amount << " points of damage and is now dead!" << std::endl;
            this->_hit_points = 0;
        }
        else
        {
            std::cout << "ClapTrap " << this->_name << " took " << amount << " points of damage!" << std::endl;
            this->_hit_points -= amount;
        }
    }
    else if(!this->_hit_points)
    {
        std::cout << "ClapTrap " << this->_name << " is already dead!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if(this->_energy_points && this->_hit_points)
    {
        if((this->_hit_points + amount) >= this->_max_hp && this->_hit_points < this->_max_hp)
        {
            std::cout << "ClapTrap " << this->_name << " repaired itself and is now at full health!" << std::endl;
            this->_hit_points = this->_max_hp;
        }
        else if(this->_hit_points == this->_max_hp)
        {
            std::cout << "ClapTrap " << this->_name << " tried repairing itself, but it was already full health and lost energy for nothing! :(" << std::endl;
        }
        else
        {
            std::cout << "ClapTrap " << this->_name << " repaired itself!" << std::endl;
            this->_hit_points += amount;
        }
        this->_energy_points--;
    }
    else if(!this->_energy_points && this->_hit_points)
    {
        std::cout << "ClapTrap " << this->_name << " can't repair itself because it has no energy left!" << std::endl;
    }
    else if(!this->_hit_points)
    {
        std::cout << "ClapTrap " << this->_name << " can't repair itself because it's dead!" << std::endl;
    }
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called" << std::endl;
}
