#include "ClapTrap.hpp"

int main(void)
{
    {
        std::cout << std::endl << "****************Test1****************" << std::endl << std::endl;
        ClapTrap trap1;
        ClapTrap trap2("Diamond");
        trap1.attack(trap2.getName());
        trap2.takeDamage(3);
        trap1.showStatus();
        trap2.showStatus();
        trap2.attack(trap1.getName());
        trap1.takeDamage(11);
        trap1.showStatus();
        trap2.showStatus();

    }
    {
        std::cout << std::endl << "****************Test2****************" << std::endl << std::endl;
        ClapTrap trap1;
        ClapTrap trap2("Diamond");
        ClapTrap trap3("Ruby");
        ClapTrap trap4;
        trap4 = trap3;
        ClapTrap trap5("Emerald");
        for(int i = 0; i < 12; i++)
            trap3.attack(trap2.getName());
        trap3.showStatus();
        trap2.showStatus();
        trap4.showStatus();
        trap4.takeDamage(-10);
        trap3.showStatus();
        trap2.showStatus();
        trap4.showStatus();
        trap4.beRepaired(10);
        trap2.beRepaired(12);
        trap3.beRepaired(1);
        trap3.showStatus();
        trap2.showStatus();
        trap4.showStatus();
        trap1.showStatus();
        trap5.beRepaired(1);
        trap5.showStatus();
    }
    {
        std::cout << std::endl << "****************Test3****************" << std::endl << std::endl;
        ClapTrap trap1("Sapphire");
        ClapTrap trap2("Diamond");
        ClapTrap trap3("Ruby");
        ClapTrap trap4("Amethyst");
        ClapTrap trap5("Emerald");
        ClapTrap trap6(trap5);
        trap1.showStatus();
        trap2.showStatus();
        trap3.showStatus();
        trap4.showStatus();
        trap5.showStatus();
        trap1.attack(trap2.getName());
        trap2.takeDamage(2);
        trap2.attack(trap1.getName());
        trap1.takeDamage(6);
        trap1.showStatus();
        trap2.showStatus();
        trap2.beRepaired(1);
        trap1.beRepaired(5);
        trap1.showStatus();
        trap2.showStatus();
        trap3.showStatus();
        for(int i  = 0; i <= 5; i++)
        {
            i % 2 == 0 ? trap3.attack(trap4.getName()) : trap3.attack(trap5.getName());
            i % 2 == 0 ? trap4.takeDamage(2) : trap5.takeDamage(3);
            (i % 5 == 0 && i != 0) ? (trap4.attack(trap3.getName()), trap5.attack(trap3.getName()), trap3.takeDamage(7)) : (void)i;
        }
        trap3.showStatus();
        trap4.showStatus();
        trap5.showStatus();
        for(int i = 0; i < 6; i++)
            trap3.beRepaired(2);
        trap3.showStatus();
        for(int i = 0; i < 6; i++)
            trap4.beRepaired(1);
        trap4.showStatus();
        for(int i = 0; i < 6; i++)
            trap5.beRepaired(2);
        trap5.showStatus();
        trap5.attack(trap3.getName());
        trap5.attack(trap4.getName());
        trap3.takeDamage(10);
        trap4.takeDamage(10);
        trap5.showStatus();
        trap4.showStatus();
        trap3.showStatus();
    }
}