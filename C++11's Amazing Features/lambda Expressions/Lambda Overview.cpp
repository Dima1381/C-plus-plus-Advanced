#include <iostream>

    /** 
     * Lambda expressions allow built-in functions that can be used for short pieces of code 
     * that will not be reused and therefore do not need a name.
     * 
     * I will show some examples with a different situation 
     * to show how and where a lambda expression can be useful.
     * 
     * In their simplest form a lambda expression can be defined as follows: 
     * 
     *  [ capture clause ] (parameters) -> return-type  
     *  {   
     *      definition of method   
     *  } 
    */

void Example_one(void (*pFunc1)())
{
    pFunc1();
}

void Example_two(void (*pFunc2)(std::string, int)) {
    pFunc2("Mike", 43);
}

void Example_tree(double (*pFunc3)(double, double)) {
    std::cout <<  pFunc3(10.0, 5.0) << std::endl;
}



int main() 
{   
    //------------------------------    Example 1    -------------------
    std::cout << "============== Example 1 ==============" << std::endl;
    
    [](){}; // Emtpy lambda expression, this defines like an annonymous function 

    // here some annonymous function that just print message, 
    // and we stored a reference to that function in "Func_one" valieble 
    auto Func_one = [](){   std::cout << "This is simple lambda" << std::endl;   };
    
    Func_one(); // here we call the Lambda

    // Lambda expression compatible with function pointers.
    // Here we pass the expression in function 'Example_one' and call it from there
    Example_one(Func_one);

    //------------------------------    Example 2    -------------------
    std::cout << "============== Example 2 ==============" << std::endl;
    // Lambda Expressions with parametrs
    // As you know, we can put paramets in round brackets
    
    auto Func_two = [](std::string Name, int age) {
        std::cout << Name << " : " << age << std::endl;
    };

    Example_two(Func_two);

    //------------------------------    Example 3    -------------------
    std::cout << "============== Example 3 ==============" << std::endl;
    // Lambda Expressions with return
    // When we have multiply returns in lambda.
    // c++ can't infer the type. So we should explicitly specify the return type. 
    // And we can do that with the 'trailing return type syntax' - after round brackets - we put return type. 

    auto Divided = [](double a, double b) -> double { // []()- return type {}
        
        if(b == 0.0)
            return 0; // here returns 'int'
        
        return a/b; // here returns 'double'
    };

    Example_tree(Divided);

    //------------------------------    Example 4    -------------------
    std::cout << "============== Example 4 ==============" << std::endl;
    /**
     * Important things, it's that lambda expressions has its own scope.
     * For example:
     * 
     * int value = 5;
     * [](){    std::cout << value << std::endl;    }(); // here is error !!! 
     * 
     * In the situation we actually can use square brackets.
     * The square brackets will littrely CAPTURE variables.
    */
    
    int one = 1, two = 2, tree = 3;
    // Capture one and two by value:
    [one, two](){   std::cout << one << " : " << two << std::endl;    }();
    
    // Capture all local valiables by value:
    [=](){   std::cout << one << " : " << two << " : " << tree << std::endl;    }();

    // Capture all local valiables by value, and valiable 'tree' by reference:
    [=, &tree](){   std::cout << one << " : " << two << " : " << (tree + 1) << std::endl;    }();

    // Capture all local valiables by reference:
    [&](){   std::cout << one + 1 << " : " << two + 2<< " : " << tree + 3 << std::endl;    }();


    //------------------------------    Example 5    -------------------
    std::cout << "============== Example 5 ==============" << std::endl;

    /** Capture variables in our own type 
     *  We can't capture instance variable, in the same way. Need use 'this' pointer.
     *  If we use 'this' it's actuly capture all instance variables by REFERENCE.
    */

    class Example5
    {
    private:
        int one{1}, two{2};
    public:
        void Work() {

            [this](){  
                std::cout << one << " : "<< two << std::endl;
            }();

            // [=, this](){}; // it's make error 
    }
    };

    Example5 obj;
    obj.Work();
    

    
    return 0;
}