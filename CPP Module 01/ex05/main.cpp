#include "Harl.hpp"

int main()
{
	Harl harl;

	harl.complain("WARNING");
	harl.complain("INFO");
	harl.complain("DEBUG");
	harl.complain("ERROR");
	harl.complain("UNKNOWN");
	return 0;
}