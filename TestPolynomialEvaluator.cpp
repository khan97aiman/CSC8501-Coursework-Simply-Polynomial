#include "TestLoader.h"

#ifdef RUN_TESTS

#include "doctest.h"
#include "PolynomialEvaluator.h"

TEST_CASE("PolynomialEvaluater: evaluate()") {
    PolynomialEvaluator e0(std::vector<int>{1, 0, 0}, 1, 5);
    e0.evaluate();
    CHECK(e0.getOutput() == std::vector<int>{1, 4, 9, 16, 25});

    PolynomialEvaluator e1(std::vector<int>{3, 0, 0, 0}, 0, 20);
    e1.evaluate();
    CHECK(e1.getOutput() == std::vector<int>{ 0, 3, 24, 81, 192, 375, 648, 1029, 1536, 2187, 3000, 3993, 5184, 6591, 8232, 10125, 12288, 14739, 17496, 20577, 24000 });

    PolynomialEvaluator e2(std::vector<int>{5, 0, 0, 0, -9}, 0, 20);
    e2.evaluate();
    CHECK(e2.getOutput() == std::vector<int>{ -9, -4, 71, 396, 1271, 3116, 6471, 11996, 20471, 32796, 49991, 73196, 103671, 142796, 192071, 253116, 327671, 417596, 524871, 651596, 799991 });

    PolynomialEvaluator e3(std::vector<int>{9, 7, -2, 0}, 0, 20);
    e3.evaluate();
    CHECK(e3.getOutput() == std::vector<int>{ 0, 14, 96, 300, 680, 1290, 2184, 3416, 5040, 7110, 9680, 12804, 16536, 20930, 26040, 31920, 38624, 46206, 54720, 64220, 74760 });

    PolynomialEvaluator e4(std::vector<int>{-1, 2, 5, 7}, 0, 20);
    e4.evaluate();
    CHECK(e4.getOutput() == std::vector<int>{ 7, 13, 17, 13, -5, -43, -107, -203, -337, -515, -743, -1027, -1373, -1787, -2275, -2843, -3497, -4243, -5087, -6035, -7093 });

    PolynomialEvaluator e5(std::vector<int>{-1, 0, -3, 114}, 0, 20);
    e5.evaluate();
    CHECK(e5.getOutput() == std::vector<int>{ 114, 110, 100, 78, 38, -26, -120, -250, -422, -642, -916, -1250, -1650, -2122, -2672, -3306, -4030, -4850, -5772, -6802, -7946 });
}

#endif