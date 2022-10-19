#include "TestLoader.h"

#ifdef RUN_TESTS

#include "doctest.h"
#include "Parser.h"

TEST_CASE("Parser: parseCSV()") {
    std::vector<int> output{ 1, 2, 3, 4, 5 };
    CHECK(output == Parser::parseCSV("1,2,3,4,5,"));
    CHECK(output == Parser::parseCSV("1,2,3,4,5"));
    CHECK(output != Parser::parseCSV("1,2,3,4"));
}

TEST_CASE("Parser: parsePolynomial()") {
    std::string p0{ "x^2" };
    CHECK(std::vector<int>{0, 0, 1, 0, 0} == Parser::parsePolynomial(p0));

    std::string p1{ "x^2+1" };
    CHECK(std::vector<int>{0, 0, 1, 0, 1} == Parser::parsePolynomial(p1));

    std::string p2{ "x^2 + 0" };
    CHECK(std::vector<int>{0, 0, 1, 0, 0} == Parser::parsePolynomial(p2));

    std::string p3{ "-3x^4-9x^3+20+2x-x^2" };
    CHECK(std::vector<int>{-3, -9, -1, 2, 20} == Parser::parsePolynomial(p3));

    std::string p4{ "-3x^4-9x^3+10+10+x+x-x^2" };
    CHECK(std::vector<int>{-3, -9, -1, 2, 20} == Parser::parsePolynomial(p4));
}

TEST_CASE("Parser: Invalid Inputs - parsePolynomial()") {
    std::string p0{ "x^2 *" };
    CHECK_THROWS_AS(Parser::parsePolynomial(p0), const std::exception&);

    std::string p1{ "1.2x^2" };
    CHECK_THROWS_AS(Parser::parsePolynomial(p1), const std::exception&);

    std::string p2{ "x^-2" };
    CHECK_THROWS_AS(Parser::parsePolynomial(p2), const std::exception&);

    std::string p3{ "x^2 + A" };
    CHECK_THROWS_AS(Parser::parsePolynomial(p3), const std::exception&);

    std::string p4{ "y^2" };
    CHECK_THROWS_AS(Parser::parsePolynomial(p4), const std::exception&);
}

TEST_CASE("Parser: parseToCsvString()") {
    std::string output{ "1,2,3,4,5" };
    CHECK(output == Parser::parseToCsvString(std::vector<int>{ 1, 2, 3, 4, 5 }));
}

TEST_CASE("Parser: parseToPolynomialString()") {
    std::string p0{ "x^2+1" };
    CHECK(p0 == Parser::parseToPolynomialString(std::vector<int>{1, 0, 1}));

    std::string p1 {"x^2"};
    CHECK(p1 == Parser::parseToPolynomialString(std::vector<int>{1, 0, 0}));
    //(p1 == Parser::parseToPolynomialString(std::vector<int>{0, 0, 1, 0, 0}));

    std::string p2{ "-3x^4-9x^3-x^2+2x+20" };
    CHECK(p2 == Parser::parseToPolynomialString(std::vector<int>{-3, -9, -1, 2, 20}));
}


#endif