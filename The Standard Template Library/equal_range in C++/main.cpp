#include <iostream>
#include <map>

using namespace std;

int main() 
{
    multimap<int, string> team;

    // Insert key-value pairs into the multimap 
    team.insert(make_pair(1, "Mike"));
    team.insert(make_pair(3, "Siem"));
    team.insert(make_pair(2, "Ray"));
    team.insert(make_pair(1, "Joe"));

    // Output all elements of the multimap
    for (multimap<int, string>::iterator it = team.begin(); it != team.end(); it++) 
        cout << it->first << " : " << it->second << endl;
    
    cout << endl;

    /**
     * Next, we try to iterate through all elements with key 2.
     */

    for(multimap<int, string>::iterator it = team.find(2); it != team.end(); it++)
        cout << it->first << " : " << it->second << endl;

     /** 
     * Expected output:
     * 2 : Ray
     *
     * But instead, we get:
     * 2 : Ray
     * 3 : Siem
     *
     * The "find" function is really not useful when we are working with a collection where there is no unique key.
     * Because when we find the key, we will go to the end of the collection.
     */


    /**
     * So the question is how to get the range of elements in a map ?
     * The solution is to use the "equal_range" function, which returns a pair
     * of iterators defining the range of elements with the specified key.
    */
    pair<multimap<int, string>::iterator, multimap<int, string>::iterator> its = team.equal_range(1);

    /**
     *  Now we can iterate from one iterator to the other.
     * It is necessary to operate on the "first" and "second" values ​​of the iterator its
    */

    cout << endl;

    for(multimap<int, string>::iterator it = its.first; it != its.second; it++)
        cout << it->first << " : " << it->second << endl;

    // here we get the expected result

    /**
     * Explanation:
     * - "its.first" points to the first element of the specified key.
     * - "its.second" points to the position immediately after the last element of the key.
     * - Iterating from "its.first" to "its.second" garanty that we only process elements with the keys range .
    */

    return 0;
}
