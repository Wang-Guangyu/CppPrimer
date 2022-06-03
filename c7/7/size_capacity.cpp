#include<iostream>
#include<vector>
#include<string>

using std::vector;
using std::cout;
using std::endl;

int main()
{
    vector<int> ivec;

    cout << " ivec: size " <<ivec.size() << " capacity: " << ivec.capacity() << endl;
    // add 24 elements
    for (vector<int>::size_type ix=0; ix != 24; ++ix)
        ivec.push_back(ix);
    //size=24,capacity should larger than 24, depending on the implementation of standard libaray.
    cout << " ivec: size " <<ivec.size() << " capacity: " << ivec.capacity() << endl;

    //only increase the capacity
    ivec.reserve(50);
    cout << " ivec: size " <<ivec.size() << " capacity: " << ivec.capacity() << endl;

    //add elements to fill the capacity;
    while (ivec.size() != ivec.capacity() )
        ivec.push_back(0);
    cout << " ivec: size " <<ivec.size() << " capacity: " << ivec.capacity() << endl;

    //add one more element, let size>capacity!
    ivec.push_back(42);
    cout << " ivec: size " <<ivec.size() << " capacity: " << ivec.capacity() << endl;

    //using shrink_to_fit function, command vector return the surplus memory space
    ivec.shrink_to_fit();
    cout << " ivec: size " <<ivec.size() << " capacity: " << ivec.capacity() << endl;

    const char *cp = "Stately, plump Buck";
    using std::string;
    string s;
//    cout << s << endl;
    s.assign(cp, 7);
    cout << s << endl;
    cout << s.size() << endl;
    s.insert(s.size(), cp+11);
    cout << s << endl;
    cout << s.size() << endl;

    return 0;
}