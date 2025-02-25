#include <iostream>
#include <vector>
#include <initializer_list>

    /** 
    * In c++98 we can use braces "[]" and put a value in there, it's like involve an equal sing.
    * But in c++98 the use of curly brackets pretty limited.
    * In C++11 we can use basically use curly brackets "{}" everywhere in : STL, for our own custom type, etc.
    */


struct  test2
{
    void print(std::initializer_list<int> list) {
        for (auto value : list)
            std::cout << value << " ";
    }
} t2;

int main() 
{
    //------------------------------    Example 1    -------------------
    // Initializing variables, arrays
    int a{}; // empty brackets initialize to zero values, equivalent to int a = 0;
    int value1{10};
    std::string value2 {"hi"};
    std::string value3 []{"Hello", "World", "!!!"}; // initializing arrays of 3 variables


    //------------------------------    Example 2    -------------------

    std::vector<std::string> vec1{"Hello", "World", "!!!"}; // Initialization array

    std::vector<std::string> *v_prt1{&vec1};     // Initialization pointer

    std::cout << (*v_prt1)[0] << std::endl;

    //------------------------------    Example 3    -------------------
    
    struct test
    {
        int value1;
        std::string value2;
    } t1{5, "Test"};     // initialize t1 value
    
    std::cout << t1.value1 << ": " << t1.value2 << std::endl;

    //------------------------------    Example 4    -------------------
    // "List-initialization" Initializes an object from a brace-enclosed initializer list.

    
    t2.print({1,2,3,4,5});

    return 0;
}