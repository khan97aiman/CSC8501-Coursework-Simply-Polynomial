#include "TestLoader.h"

#ifndef RUN_TESTS

#include <iostream>
#include <vector>
#include "FileHandler.h"
#include "Parser.h"

int main()
{
    std::cout << "Hello World!\n";
    Parser::parseAlgExp("x^2+x-3x^-1");//("-2x^4 - 3x^2 - 6x + 87");
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


