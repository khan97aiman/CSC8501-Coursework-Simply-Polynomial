#include "TestLoader.h"

#ifdef RUN_TESTS

#include "doctest.h"
#include "PolynomialFitter.h"

TEST_CASE("PolynomialFitter: determineDegree()") {
    PolynomialFitter pFitter1(std::vector<int>{1, 8, 27, 64, 125}, 1, 5);
    CHECK(pFitter1.determineDegree() == 3);

    PolynomialFitter pFitter2(std::vector<int>{1, 4, 9, 16, 25}, 1, 5);
    CHECK(pFitter2.determineDegree() == 2);

    PolynomialFitter pFitter3(std::vector<int>{2, 5, 10, 17, 26}, 1, 5);
    CHECK(pFitter3.determineDegree() == 2);
}

TEST_CASE("PolynomialFitter: fit() with InputSet") {
    Polynomial p1(std::vector<int>{1, 0, 0});
    PolynomialFitter pFitter1(std::vector<int>{1, 4, 9, 16, 25}, 1, 5); 
    pFitter1.fit();
    CHECK(*pFitter1.getPolynomial() == p1);

    Polynomial p2(std::vector<int>{1, 0, 0, 0});
    PolynomialFitter pFitter2(std::vector<int>{1, 8, 27, 64, 125}, 1, 5); 
    pFitter2.fit();
    CHECK(*pFitter2.getPolynomial() == p2);
}
#endif