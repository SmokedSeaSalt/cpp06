#include "ScalarConverter.hpp"
#include "terminalOutput.hpp"
#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << C_YELLOW << "Usage: /convert <value>\n" << C_END;
        return (1);
    }
    if (static_cast<std::string>(argv[1]) == "test")
    {
        ScalarConverter::convert("123");
        ScalarConverter::convert("e");
        ScalarConverter::convert("42.0");
        ScalarConverter::convert("42.0f");
        ScalarConverter::convert("0");
        ScalarConverter::convert("0.0");
        ScalarConverter::convert("0.0f");
        ScalarConverter::convert("abc");
    }
    else
        ScalarConverter::convert(argv[1]);
}