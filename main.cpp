#include "TestLoader.h"

#ifndef RUN_TESTS

#include <iostream>
#include "SimplyPolynomialSimulator.h"


int main() {
    SimplyPolynomialSimulator pSimulator;
    pSimulator.startUp();
    pSimulator.mainMenu();
    pSimulator.run();

    std::cout << "Destructing all objects" << '\n';
    std::cout << "-----------------------------------------" << '\n';
}
#endif


#ifdef RUN_TESTS
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
int main()
{
    doctest::Context context;
    context.setOption("order-by", "name");            // sort the test cases by their name
    context.setOption("no-breaks", true);             // don't break in the debugger when assertions fail

    int res = context.run(); 

    return res;
}
#endif


