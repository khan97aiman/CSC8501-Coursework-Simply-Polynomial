# CSC8501 Coursework - Polynomial
Simply Polynomial Simulator is a user interface designed to let you view output sets to your polynomials, or derive polynomials from your output sets.

You can either input through console or file. Entering invalid inputs ends the program by giving appropriate exception response. The filenames must be entered with the desired extension, otherwise it is considered as invalid input. Run the application again if it ends due to an invalid input.

# Features
This code base makes use of the following features:
1. Polymorphism
2. Header and Source Files
3. Auto
4. Ternary operator
5. Lambda Functions
6. Namespaces
7. Unit Tests using Doctest

# Test Cases
To run tests, uncomment `#define RUN_TESTS` in TestLoader.cpp.
To run the Simulator, comment out `#define RUN_TESTS` in TestLoader.cpp (this will disable all tests)

## Test Results:
```
[doctest] doctest version is "2.4.9"
[doctest] run with "--help" for options
===============================================================================
[doctest] test cases: 19 | 19 passed | 0 failed | 0 skipped
[doctest] assertions: 81 | 81 passed | 0 failed |
[doctest] Status: SUCCESS!
```

# File Format:
Following are the file formats used

## Reading an Expression File to View Output Sets
An expression file must be of .txt extension, and the format should be:
```
Polynomial Expression
startInputRange,endInputRange
Polynomial Expression
startInputRange,endInputRange
(and so on)
```
For example for 3 polynomial expressions, the file can be:
```
x^2+1
1,5
x^2+2x+4
1,20
3x^2+2x+4
1,21
```

## Reading an Output Set File to Derive Polynomials
An output set file must be of .csv extension, and the format should be:
```
Output Set
startInputRange,endInputRange
numberOfTerms
Output Set
startInputRange,endInputRange
numberOfTerms
(and so on)
```
For example for 3 output sets, the file can be:
```
7, 13, 17, 13, -5, -43, -107, -203, -337, -515, -743, -1027, -1373, -1787, -2275, -2843, -3497, -4243, -5087, -6035, -7093
0,20
4
114, 110, 100, 78, 38, -26, -120, -250, -422, -642, -916, -1250, -1650, -2122, -2672, -3306, -4030, -4850, -5772, -6802, -7946
0,20
UNKNOWN
715, 625, 523, 409, 283, 145, -5, -167, -341, -527, -725, -935, -1157
UNKNOWN,UNKNOWN
UNKNOWN
```
Note that `startInputRange`, `endInputRange` and `numberOfTerms` are optional, and hence can be replaced with `UNKNOWN `.

### IMPORTANT! 
1. `End of line should be on the last line of the file and not on a new empty line.`
2. `UNKNOWN should be all caps.`

## View Output Sets Of Polynomials
To view output sets of polynomial:
1. Run the .exe file Debug/Release Folder
2. Enter 1
3. Choose either console/file input method
4. Enter the desired inputs
5. Choose either console/file for displaying output

## Derive Polynomials from Output Sets
To derive polynomial from output sets:
1. Run the .exe file Debug/Release Folder
2. Enter 2
3. Choose either console/file input method
4. Enter the desired inputs
5. Choose either console/file for displaying output


how to check if code is working, last bit not correct
