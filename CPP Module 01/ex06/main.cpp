#include "Harl.hpp"

int getLevelIdx(std::string level)
{
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++)
	{
		if(level == levels[i])
			return i;
	}
	return -1;
}

int main(int ac, char **av)
{
	if (ac != 2) {
        std::cerr << "Usage: ./harlFilter <level>" << std::endl;
        return 1;
    }

	Harl harl;
	int levelIdx = getLevelIdx(av[1]);

	switch (levelIdx) {
        case 0:
            harl.complain("DEBUG");
        case 1:
            harl.complain("INFO");
        case 2:
            harl.complain("WARNING");
        case 3:
            harl.complain("ERROR");
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
	return 0;
}
