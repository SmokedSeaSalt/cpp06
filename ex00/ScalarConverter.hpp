#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

enum e_type
{
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    UNKNOWN,
};

class ScalarConverter
{
    public:
        static void convert(std::string value);

    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        virtual ~ScalarConverter() = 0;

        static e_type setType(std::string value);
        static void   convertChar(char value);
        static void   convertInt(int value);
        static void   convertFloat(float value);
        static void   convertDouble(double value);
};

#endif // SCALARCONVERTER_HPP