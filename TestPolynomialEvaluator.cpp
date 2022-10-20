#include "TestLoader.h"

#ifdef RUN_TESTS

#include "doctest.h"
#include "PolynomialEvaluator.h"

TEST_CASE("PolynomialEvaluater: evaluate()") {
    std::vector<int> coefficients{ 1,0,0 };
    PolynomialEvaluator evaluator(coefficients, 1, 5);
    evaluator.evaluate();
    CHECK(evaluator.getOutput() == std::vector<int>{1, 4, 9, 16, 25});
}

#endif