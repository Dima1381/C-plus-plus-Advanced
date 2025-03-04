#include <iostream>

using namespace std;

    /** ==========================    mutable    ==========================
     * 
     * Sometimes there is requirement to modify one or more data members of class / struct 
     * through const function even though you don’t want the function to update other members of class / struct. 
     * This task can be easily performed by using mutable keyword. 
     * 
     * Here I'll show some examples, also with lambda expression.
    */

int main() 
{   
    // =======================      Example 1       =======================
    // mutable in a class (member variables in const methods)

    class Data {
        private:
            mutable int cachedValue{-1}; // Cached value
            int value{0};
        public:
            void Set_value(int v) { this->value = v; this->cachedValue = -1;}
            
            int getCachedValue() const {
                if (cachedValue == -1) { // We calculate only once
                    cachedValue = value * value;
                }
                return cachedValue;
            }
    };
    
    Data d;
    d.Set_value(5);
    cout << "Cached Value: " << d.getCachedValue() << endl; // Output: 25
    d.Set_value(7);
    cout << "Cached Value: " << d.getCachedValue() << endl << endl; // Output: 49

    // =======================      Example 2       =======================
    // mutable with lambda expressions

    int counter{0};

    auto count_call = [counter]() mutable {
        return ++counter; 
    };
    // As we know, lambda has its own space, so outside the space "counter" will not be changed.

    cout << "Counter = " << counter << endl;

    cout << "Call 1: " << count_call() << endl;
    cout << "Call 2: " << count_call() << endl;
    cout << "Call 3: " << count_call() << endl;
    cout << "Call 4: " << count_call() << endl;


    return 0;
}