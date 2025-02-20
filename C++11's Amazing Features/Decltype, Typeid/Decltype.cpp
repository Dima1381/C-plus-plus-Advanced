#include <iostream>

    /** =====================    Decltype     =====================
    * Keyword (operator) 'decltype' allows us to declare variables of an existing type.
    * Decltype lets you extract the type from the variable or expression.
    * 
    * Syntax
    *    decltype ( entity )	  (1)	
    *    decltype ( expression ) (2)
    *
    * Return value
    *    The type of the expression parameter.
    * 
    * In Example 1 you can see the basic explanation
    * and in example 2 and 3 you can see a real case there decltype solve some problem.
    */


template <class T1, class T2>
auto Add(T1 value1, T2 value2) -> decltype(value1 + value2)
{
    return value1 + value2;
}


std::string Name(){
    return "Bella";
}

auto GetName() -> decltype(Name())
{
    return Name();
}

int main() 
{
    //------------------------------    Example 1    -------------------
    std::string value;

    decltype(value) name = "Jon"; // 'name' has data type string

    std::cout << "\n------------------------------    Example 1    -------------------" << std::endl;
    std::cout << "Type of valiable = " << typeid(name).name() << std::endl;
    std::cout << "Value = " << name << std::endl << std::endl;

    /** Here decltype is extracted the type from 'value' variable  
      * So this 'decltype(value)' - means string, 
      * and after we use that to declare variable 'name' of that type. 
      *
    */
    


    //------------------------------    Example 2    -------------------
    
    /**
      *  Here we specify the final return type of the function "'GetName' 
      *  by decltype where we specify an expression in the parameters.
    */

    std::cout << "------------------------------    Example 2    -------------------" << std::endl;
    std::string Name = GetName();
    std::cout << "Name = " << Name << std::endl << std::endl; 



    //------------------------------    Example 3    -------------------

    /**
     *  Let cteate a template funcrion of adding two numbers.
     *  Also, this function will return the same type of value 
     *  as the type of the parameter (value type) that was passed to the function.
     *  For this we declera return type as 'auto'.
     *  And here we get some problem, becouse 'auto' need some information to figure out the return type.
     *  So here we can use 'decltype' to enquire the type of (T1 nad T2)
     * 
    */
    std::cout << "------------------------------    Example 3    -------------------" << std::endl;
    
    int ivalue1 = 10, ivalue2 = 20;
    std::string svalue1 = "Hello ", svalue2 = "world !";


    std::cout << "Int [ " << ivalue1 << " ] + [ " << ivalue2 << " ] = " << Add(ivalue1, ivalue2) << std::endl; 
    std::cout << "String [ " << svalue1 << " ] + [ " << svalue2 << " ] = " << Add(svalue1, svalue2) << std::endl << std::endl; 


    return 0;
}