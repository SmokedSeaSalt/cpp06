#include "ScalarConverter.hpp"
#include "terminalOutput.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << C_YELLOW << "Usage: /convert <value>\n" << C_END;
        return (1);
    }
	if (argv[1] == "test")
	{

	}
	else
    	ScalarConverter::convert(argv[1]);
}