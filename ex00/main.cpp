#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap trap1;
    ClapTrap trap2("Diamond");
    ClapTrap trap3("Ruby");
    ClapTrap trap4;
    trap4 = trap3;

    {
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
        for(int i = 0; i < 12; i++)
            trap3.attack(trap2.getName());
        trap3.showStatus();
        trap2.showStatus();
        trap4.showStatus();
        trap4.takeDamage(-10);
        trap3.showStatus();
        trap2.showStatus();
        trap4.showStatus();
    }
    {

    }
}