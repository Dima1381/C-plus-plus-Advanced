#include <iostream>
#include <typeinfo> // to use typeid we need to include a header (by the way, iostream already has a typeid)


/**------------------         Typeid        ------------------------------------
  * 
  * The 'typeid' operator is used to retrieve type information of a variable or object at runtime.
  * Syntax:
  *       typeid(type)        // (1)  
  *       typeid(expression)  // (2)  
  * 
  * Returns:
  *       An object of class 'type_info' containing type information.
  * 
  * Important:
  *       Expressions passed to 'typeid' are NOT executed!
  * 
  * I'll demonstrate typeid usage with variables, expressions, and comparisons.
*/


template <typename T>
void printType(T value) 
{
    std::cout << "Value: " << value << ", Type [ " << typeid(value).name() << " ] "<< std::endl;
}

template<typename T1, typename T2>
void printType(T1 value1, T2 value2)
{
    std::cout << "Result type of (" << value1 << " + " << value2 << "): " 
              << typeid(value1 + value2).name() << std::endl;
}

class Parent
{
    public:
    virtual void Method(){}; // Create a virtual table (vtable)
};
class Child: public Parent
{
    void Method() override {}
};

int main() 
{
    //-----------  typeid with variable  -------------------------------------------

    printType(42);          // int
    printType(3.14);        // double
    printType("Hello!");    // const char[7]
    printType(std::string("Hello!")); // std::string

    std::cout << std::endl;

    //-----------  typeid with expression  -----------------------------------------
    printType(1, 5.5); // double 

    std::cout << std::endl;

    //-----------  typeid with comparison  -----------------------------------------
    /**
     * Idea: determine the type of an object created at runtime.
     * Create an object randomly and check its type.
     */
    srand(time(0));

    Parent *ptr = ((rand() % 2) == 0) ? new Parent(): new Child();

    if(typeid(*ptr) == typeid(Parent)) {
        std::cout << "Created Parent object" << std::endl;
    }
    else{
        std::cout << "Created Child object" << std::endl;
    }

    delete ptr;

    return 0;
}