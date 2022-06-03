#include<iostream>
#include<vector>

using std::vector;
using std::cout;
using std::endl;

int main()
{
    vector<int> v2;
    for(int i=0; i!=100; ++i)
        v2.push_back(i);
    cout << v2[1] <<endl;
    return 0;
}