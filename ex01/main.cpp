#include "Serializer.hpp"
#include "terminalOutput.hpp"
#include <iostream>
#include <string>

int main()
{
    Data a;
    std::cout << C_BLUE << "Data location: " << &a << ". Data value: " << a.meme << ".\n" << C_END;
    uintptr_t b = Serializer::serialize(&a);
    std::cout << C_PURPLE << "Serialized to: " << b << ".\n" << C_END;
    Data* c = Serializer::deserialize(b);
    std::cout << C_BLUE << "Data location: " << c << ". Data value: " << c->meme << ".\n" << C_END;
}