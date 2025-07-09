#include <fstream>
#include <string>
#include <iostream>

static std::string replaceLine(std::string line, const std::string s1, const std::string s2)
{
	std::string result;
	size_t start = 0;
	size_t pos;

	while((pos = line.find(s1, start)) != std::string::npos)
	{
		result += line.substr(start, pos - start);
		result += s2;
		start = pos + s1.length();
	}
	result += line.substr(start);
	return result;
}

int replaceInFile(const std::string filename, const std::string s1, const std::string s2)
{
	if (s1.empty())
	{
		std::cerr << "Error: s1 cannot be empty." << std::endl;
        return 1;
	}
	std::ifstream infile(filename.c_str());
	if(!infile)
	{
		std::cerr << "Error: could not open input file." << std::endl;
        return 1;
	}
	std::ofstream outfile((filename + ".replace").c_str());
	if(!outfile)
	{
		std::cerr << "Error: could not open output file." << std::endl;
        return 1;
	}
	std::string line;
	while(getline(infile, line))
	{
		outfile << replaceLine(line, s1, s2) << std::endl;
	}
	infile.close();
	outfile.close();
	return 0;
}

int main(int ac, char **av)
{
	if (ac != 4) {
        std::cerr << "Usage: ./new_sed <filename> <s1> <s2>" << std::endl;
        return 1;
    }
	std::string filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];

	return replaceInFile(filename, s1, s2);
}
