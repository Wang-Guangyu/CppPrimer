#include<iostream>
#include<string>

using std::cout;
using std::string;
using std::endl;

int main()
{
    string s("Hello World!!!");
    for (auto &c : s)  //c是引用
        c = toupper(c); //改变c将会改变s中字符的值
    cout << s << endl;

    return 0;
}