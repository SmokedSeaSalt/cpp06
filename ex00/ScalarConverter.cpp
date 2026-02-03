#include "ScalarConverter.hpp"
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <regex>

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    (void)other;
    return (*this);
}

int isChar(std::string value)
{
    if (value.length() == 1)
    {
        if (std::isprint(value.front()) && !std::isdigit(value.front()))
        {
            return (1);
        }
    }
    return (0);
}

void ScalarConverter::convertChar(char value)
{
    if (std::isprint(value))
        std::cout << "char: '" << value << "'\n";
    else
        std::cout << "char: Non dispayable\n";
    std::cout << "int: " << static_cast<int>(value) << "\n";
    std::cout << "float: " << static_cast<float>(value) << "f\n";
    std::cout << "double: " << static_cast<double>(value) << "\n";
}

void ScalarConverter::convertInt(int value)
{
    if (value > 0 && value < 127 && std::isprint(static_cast<char>(value)))
        std::cout << "char: '" << static_cast<char>(value) << "'\n";
    else
        std::cout << "char: Non dispayable\n";
    std::cout << "int: " << value << "\n";
    std::cout << "float: " << static_cast<float>(value) << "f\n";
    std::cout << "double: " << static_cast<double>(value) << "\n";
}

void ScalarConverter::convertFloat(float value)
{
    if (!std::isfinite(value))
    {
        std::cout << "char: Impossible\n";
        std::cout << "int: Impossible\n";
    }
    else
    {
        if (value < 0.0 || value > 127.0)
            std::cout << "char: Out of range\n";
        else if (std::isprint(static_cast<char>(value)))
            std::cout << "char: '" << static_cast<char>(value) << "'\n";
        else
            std::cout << "char: Non dispayable\n";
        if (value > -2147483648.0 && value < 2147483647.0)
            std::cout << "int: " << static_cast<int>(value) << "\n";
        else
            std::cout << "int: Out of range\n";
    }
    std::cout << "float: " << (value) << "f\n";
    std::cout << "double: " << static_cast<double>(value) << "\n";
}

void ScalarConverter::convertDouble(double value)
{
    if (!std::isfinite(value))
    {
        std::cout << "char: Impossible\n";
        std::cout << "int: Impossible\n";
    }
    else
    {
        if (value < 0.0 || value > 127.0)
            std::cout << "char: Out of range\n";
        else if (std::isprint(static_cast<char>(value)))
            std::cout << "char: '" << static_cast<char>(value) << "'\n";
        else
            std::cout << "char: Non dispayable\n";
        if (value > -2147483648.0 && value < 2147483647.0)
            std::cout << "int: " << static_cast<int>(value) << "\n";
        else
            std::cout << "int: Out of range\n";
    }
    std::cout << "float: " << static_cast<float>(value) << "f\n";
    std::cout << "double: " << value << "\n";
}

e_type ScalarConverter::setType(std::string value)
{
    if (isChar(value))
        return (CHAR);
    std::regex intRegex("^[+|-]?[0-9]+$");
    if (std::regex_match(value, intRegex))
        return (INT);
    std::regex floatRegex("^[+|-]?[0-9]*+['.'][0-9]+[f]$");
    if (std::regex_match(value, floatRegex) || value == "nanf" || value == "+inff" ||
        value == "-inff")
        return (FLOAT);
    std::regex doubleRegex("^[+|-]?[0-9]*+['.'][0-9]+$");
    if (std::regex_match(value, doubleRegex) || value == "nan" || value == "+inf" ||
        value == "-inf")
        return (DOUBLE);
    return (UNKNOWN);
}

void ScalarConverter::convert(std::string value)
{
    e_type type = setType(value);
    std::cout << std::setprecision(1) << std::fixed;
    std::cout << "type: ";
    try
    {
        switch (type)
        {
        case CHAR:
            std::cout << "char\n";
            convertChar(*(value.begin()));
            break;
        case INT:
            std::cout << "int\n";
            convertInt(std::stoi(value));
            break;
        case FLOAT:
            std::cout << "float\n";
            convertFloat(std::stof(value));
            break;
        case DOUBLE:
            std::cout << "double\n";
            convertDouble(std::stod(value));
            break;
        default:
            std::cout << "Not a valid input" << "\n";
            break;
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "Cannot convert input because: " << e.what() << '\n';
    }
}