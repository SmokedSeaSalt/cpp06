#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
    public:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        virtual ~ScalarConverter() = 0;

        static void convert(std::string value);

    private:
};

#endif // SCALARCONVERTER_HPP