#include "TestLoader.h"

#ifdef RUN_TESTS

#include "doctest.h"
#include "PolynomialFitter.h"

TEST_CASE("PolynomialFitter: determineDegree()") {
    PolynomialFitter pFitter1(std::vector<int>{1, 8, 27, 64, 125}, 1, 5, 0);
    CHECK(pFitter1.determineDegree() == 3);

    PolynomialFitter pFitter2(std::vector<int>{1, 4, 9, 16, 25}, 1, 5, 0);
    CHECK(pFitter2.determineDegree() == 2);

    PolynomialFitter pFitter3(std::vector<int>{2, 5, 10, 17, 26}, 1, 5, 0);
    CHECK(pFitter3.determineDegree() == 2);
}

TEST_CASE("PolynomialFitter: fit() with InputSet") {
    Polynomial p1(std::vector<int>{1, 0, 0});
    PolynomialFitter pFitter1(std::vector<int>{1, 4, 9, 16, 25}, 1, 5, 0); 
    pFitter1.fit();
    CHECK(*pFitter1.getPolynomial() == p1);

    Polynomial p2(std::vector<int>{1, 0, 0, 0});
    PolynomialFitter pFitter2(std::vector<int>{1, 8, 27, 64, 125}, 1, 5, 0); 
    pFitter2.fit();
    CHECK(*pFitter2.getPolynomial() == p2);

    Polynomial p3(std::vector<int>{3, 0, 0, 0});
    std::vector<int> outputSet3{ 0, 3, 24, 81, 192, 375, 648, 1029, 1536, 2187, 3000, 3993, 5184, 6591, 8232, 10125, 12288, 14739, 17496, 20577, 24000 };
    PolynomialFitter pFitter3(outputSet3, 0, 20, 1);
    pFitter3.fit();
    CHECK(*pFitter3.getPolynomial() == p3);

    Polynomial p4(std::vector<int>{5, 0, 0, 0, -9});
    std::vector<int> outputSet4{ -9, -4, 71, 396, 1271, 3116, 6471, 11996, 20471, 32796, 49991, 73196, 103671, 142796, 192071, 253116, 327671, 417596, 524871, 651596, 799991 };
    PolynomialFitter pFitter4(outputSet4, 0, 20, 2);
    pFitter4.fit();
    CHECK(*pFitter4.getPolynomial() == p4);

    Polynomial p5(std::vector<int>{9, 7, -2, 0});
    std::vector<int> outputSet5{ 0, 14, 96, 300, 680, 1290, 2184, 3416, 5040, 7110, 9680, 12804, 16536, 20930, 26040, 31920, 38624, 46206, 54720, 64220, 74760 };
    PolynomialFitter pFitter5(outputSet5, 0, 20, 3);
    pFitter5.fit();
    CHECK(*pFitter5.getPolynomial() == p5);

    Polynomial p6(std::vector<int>{-1, 2, 5, 7});
    std::vector<int> outputSet6{ 7, 13, 17, 13, -5, -43, -107, -203, -337, -515, -743, -1027, -1373, -1787, -2275, -2843, -3497, -4243, -5087, -6035, -7093 };
    PolynomialFitter pFitter6(outputSet6, 0, 20, 4);
    pFitter6.fit();
    CHECK(*pFitter6.getPolynomial() == p6);

    Polynomial p7(std::vector<int>{-1, 0, -3, 114});
    std::vector<int> outputSet7{ 114, 110, 100, 78, 38, -26, -120, -250, -422, -642, -916, -1250, -1650, -2122, -2672, -3306, -4030, -4850, -5772, -6802, -7946 };
    PolynomialFitter pFitter7(outputSet7, 0, 20, 5);
    pFitter7.fit();
    CHECK(*pFitter7.getPolynomial() == p7);
}
#endif