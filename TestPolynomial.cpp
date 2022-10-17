#include "TestLoader.h"

#ifdef RUN_TESTS

#include "doctest.h"
#include "Polynomial.h"

TEST_CASE("Polynomial: Assignment(Copy) and Equality") {
    Polynomial p1(std::vector<int>({ 2,4,9 }));
    Polynomial p2 = p1;
    CHECK(p1 == p2);
}

TEST_CASE("Polynomial: evaluate()") {
    Polynomial p1(std::vector<int>({ 2,4,9 }));
    CHECK(p1.evaluate(2) == 25);

    Polynomial p2(std::vector<int>({ 2,0,9 }));
    CHECK(p2.evaluate(2) == 17);

    Polynomial p3(std::vector<int>({ 2,0,0 }));
    CHECK(p3.evaluate(2) == 8);
}

TEST_CASE("Polynomial: degree()") {
    Polynomial p1(std::vector<int>({ 2,4,9 }));
    CHECK(p1.degree() == 2);

    Polynomial p2(std::vector<int>({ 9,0,0,0 }));
    CHECK(p2.degree() == 3);

    Polynomial p3(std::vector<int>({ 2,0,0 }));
    CHECK(p3.degree() == 2);

    Polynomial p4(std::vector<int>({ 9 }));
    CHECK(p4.degree() == 0);
}

#endif