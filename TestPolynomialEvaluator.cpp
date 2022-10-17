#include "TestLoader.h"

#ifdef RUN_TESTS

#include "doctest.h"
#include "PolynomialEvaluator.h"

TEST_CASE("PolynomialEvaluate: evaluate()") {
    Polynomial p1(std::vector<int>({ 1,0,0 }));
    PolynomialEvaluator evaluator(&p1, 1, 5);
    CHECK(evaluator.evaluate() == std::vector<int>{1, 4, 9, 16, 25});
}

#endif