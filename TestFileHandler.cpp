#include "TestLoader.h"

#ifdef RUN_TESTS

#include "doctest.h"
#include <vector>
#include "FileHandler.h"
#include <fstream>
#include <algorithm>

//taken from https://stackoverflow.com/questions/15118661/in-c-whats-the-fastest-way-to-tell-whether-two-string-or-binary-files-are-di
bool compare_files(const std::string& filename1, const std::string& filename2)
{
    std::ifstream file1(filename1, std::ifstream::ate | std::ifstream::binary); //open file at the end
    std::ifstream file2(filename2, std::ifstream::ate | std::ifstream::binary); //open file at the end
    const std::ifstream::pos_type fileSize = file1.tellg();

    if (fileSize != file2.tellg()) {
        return false; //different file size
    }

    file1.seekg(0); //rewind
    file2.seekg(0); //rewind

    std::istreambuf_iterator<char> begin1(file1);
    std::istreambuf_iterator<char> begin2(file2);

    return std::equal(begin1, std::istreambuf_iterator<char>(), begin2); //Second argument is end-of-range iterator
}

TEST_CASE("FileHandler::CSV write()") {
    std::vector< std::vector<int>> wData = {
        {1, 2, 3, 5, 6},
        {4, 5, 6},
        {7, 8, 9, 2}
    };
    FileHandler::CSV::write("test_writeBulk.csv", wData);
    CHECK(compare_files("writeBulk.csv", "test_writeBulk.csv"));
}

TEST_CASE("FileHandler::CSV read()") {

    std::vector<FileHandler::FileFormatCSV> obj{
        FileHandler::FileFormatCSV(std::vector<int> { 1, 4, 9, 16, 25 }, std::vector<int> { 1, 5}, 1),
        FileHandler::FileFormatCSV(std::vector<int> { 2, 5, 10, 17, 26 }, std::vector<int> { 1, 5}, 2),
    };

    std::vector<FileHandler::FileFormatCSV> test = FileHandler::CSV::read("readBulk.csv");

    for (size_t i = 0; i < test.size(); i++) {
        CHECK(test[i].outputSet == obj[i].outputSet);
        CHECK(test[i].inputRange == obj[i].inputRange);
        CHECK(test[i].numTerms == obj[i].numTerms);
    }

}

TEST_CASE("FileHandler::CSV reading invalid file with read()") {
    CHECK_THROWS_AS(FileHandler::CSV::read("invalidFile.csv"), const std::exception&);
}

TEST_CASE("FileHandler::TXT reading invalid file with read()") {
    CHECK_THROWS_AS(FileHandler::TXT::read("invalidFile.csv"), const std::exception&);
}

TEST_CASE("FileHandler: filenames with invalid extensions") {
    CHECK_THROWS_AS(FileHandler::checkFileExtension("invalidFile",".csv"), const std::exception&);
    CHECK_THROWS_AS(FileHandler::checkFileExtension("invalidFile.txt",".csv"), const std::exception&);
    CHECK_THROWS_AS(FileHandler::checkFileExtension("invalidFile.exe",".csv"), const std::exception&);
    CHECK_THROWS_AS(FileHandler::checkFileExtension("invalidFile.csvv",".csv"), const std::exception&);
    CHECK_THROWS_AS(FileHandler::checkFileExtension("invalidFile.csv.ccsv",".csv"), const std::exception&);

    CHECK_THROWS_AS(FileHandler::checkFileExtension("invalidFile", ".txt"), const std::exception&);
    CHECK_THROWS_AS(FileHandler::checkFileExtension("invalidFile.csv", ".txt"), const std::exception&);
    CHECK_THROWS_AS(FileHandler::checkFileExtension("invalidFile.exe", ".txt"), const std::exception&);
    CHECK_THROWS_AS(FileHandler::checkFileExtension("invalidFile.txtt", ".txt"), const std::exception&);
    CHECK_THROWS_AS(FileHandler::checkFileExtension("invalidFile.txt.ttxt", ".txt"), const std::exception&);
}

TEST_CASE("FileHandler::TXT write()/read()") {

    std::vector<FileHandler::FileFormatEXP> obj{
        FileHandler::FileFormatEXP(std::vector<int> { 0, 0, 1, 0, 0 }, std::vector<int> { 1, 5}),
        FileHandler::FileFormatEXP(std::vector<int> { 0, 0, 1, 0, 1 }, std::vector<int> { 1, 5}),
    };

    FileHandler::TXT::write("test_writeBulk.txt", obj);
    CHECK(compare_files("writeBulk.txt", "test_writeBulk.txt"));

    std::vector<FileHandler::FileFormatEXP> test = FileHandler::TXT::read("test_writeBulk.txt");
    for (size_t i = 0; i < test.size(); i++) {
        CHECK(test[i].pCoefficients == obj[i].pCoefficients);
        CHECK(test[i].inputRange == obj[i].inputRange);
    }
}

#endif