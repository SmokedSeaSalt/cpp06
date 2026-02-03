#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include "terminalOutput.hpp"
#include <cstdlib>
#include <iostream>

Base* generate(void)
{
    int classType = rand() % 3;
    switch (classType)
    {
    case 0:
        return (new A);
        break;
    case 1:
        return (new B);
        break;
    case 2:
        return (new C);
        break;
    default:
        std::cout << C_RED << "Something went wrong with RNG!\n" << C_END;
        break;
    }
    return (nullptr);
}

void identify(Base* p)
{
    A* aPtr = dynamic_cast<A*>(p);
    if (aPtr)
        std::cout << C_BLUE << "Class: A\n" << C_END;
    B* bPtr = dynamic_cast<B*>(p);
    if (bPtr)
        std::cout << C_BLUE << "Class: B\n" << C_END;
    C* cPtr = dynamic_cast<C*>(p);
    if (cPtr)
        std::cout << C_BLUE << "Class: C\n" << C_END;
}

void identify(Base& p)
{
    // clang-format off
    try
    {
        A& aRef = dynamic_cast<A&>(p);
        std::cout << C_BLUE << "Class: A\n" << C_END;
        (void)aRef;
    }
    catch (...) {}
    try
    {
        B& bRef = dynamic_cast<B&>(p);
        std::cout << C_BLUE << "Class: B\n" << C_END;
        (void)bRef;
    }
    catch (...) {}
    try
    {
        C& cRef = dynamic_cast<C&>(p);
        std::cout << C_BLUE << "Class: C\n" << C_END;
        (void)cRef;
    }
    catch (...) {}
    // clang-format on
}

int main()
{
    Base* test = generate();
    identify(test);
    identify(*test);
    test = generate();
    identify(test);
    identify(*test);
    test = generate();
    identify(test);
    identify(*test);
    test = generate();
    identify(test);
    identify(*test);
    test = generate();
    identify(test);
    identify(*test);
    test = generate();
    identify(test);
    identify(*test);
}