#include "TestLoader.h"

#ifdef RUN_TESTS

#include "doctest.h"
#include <vector>
#include "FileHandler.h"

TEST_CASE("FileHandler: readBulk/writeBulk") {
    std::vector< std::vector<int>> wData = {
        {1, 2, 3, 5, 6},
        {4, 5, 6},
        {7, 8, 9, 2}
    };
    FileHandler::writeBulk("test.csv", wData);
    std::vector< std::vector<int>> rData = FileHandler::readBulk("test.csv");
    CHECK(wData == rData);
}

TEST_CASE("FileHandler: read/write") {
    std::vector<int> wData = { 1, 2, 3, 5, 6 };
    FileHandler::write("test.csv", wData);
    std::vector<int> rData = FileHandler::read("test.csv");
    CHECK(wData == rData);
}

TEST_CASE("FileHandler: reading invalid file with read()") {
    CHECK_THROWS_AS(FileHandler::read("invalidFile.csv"), const std::exception&);
}

TEST_CASE("FileHandler: reading invalid file with readBulk()") {
    CHECK_THROWS_AS(FileHandler::readBulk("invalidFile.csv"), const std::exception&);
}

TEST_CASE("FileHandler: filenames with invalid extensions") {
    CHECK_THROWS_AS(FileHandler::checkFileExtension("invalidFile"), const std::exception&);
    CHECK_THROWS_AS(FileHandler::checkFileExtension("invalidFile.txt"), const std::exception&);
    CHECK_THROWS_AS(FileHandler::checkFileExtension("invalidFile.exe"), const std::exception&);
    CHECK_THROWS_AS(FileHandler::checkFileExtension("invalidFile.csvv"), const std::exception&);
    CHECK_THROWS_AS(FileHandler::checkFileExtension("invalidFile.csv.ccsv"), const std::exception&);
}
#endif