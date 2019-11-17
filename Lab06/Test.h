#ifndef TEST_H
#define TEST_H

#include <string>
#include <iostream>
using namespace std;

class Test{
protected:
    const string pass = "SUCCESS\n"; /** Used to denote a success condition. */
    const string fail = "FAILURE\n"; /** Used to denote a failure condition. */
    /**
     * Used to denoted if a test gave a bad result indicating neither a success nor failure.
     */
    const string unkno = "UNKNOWN\n";
    string m_fileName; /** The name of the file being tested. */


    /**
    * func is a special type of bool that is defined as a function pointer for functions with no parameters.
    */
    typedef bool (*func)();

    /**
    * Runs a function and prints an output based on the how the function returns. testFunction is evaluated before
    * it is passed into the function so the content prints after the function runs. It automatically tabs the input,
    * any other prints completed should also be tabbed one more time for clarity.
    * @param write: A string to be written to the console.
    * @param testFunction: The function being evaluated.
    */
    void testFunc(string write, func testFunction, string denom);

    /**
    * Returns a pass, fail, unkno value based on string for the function
    * @param super: String for function that calls the subfunction.
    * @param write: A string to be written to the console.
    * @param testFunction: string value of the function that was just tested.
    * @param denom: Denominator for seperating the evaluation value.
    */
    void subTest(string super, string write, string testFunction, string denom);

    /**
    * Formats Error printing
    * @param e: Exception to format.
    */
    void failTry(exception e);

    Test();
};
#endif
