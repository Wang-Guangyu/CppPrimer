#include<iostream>
int main()
{
    std::cout << "Enter two numbers:" << std::endl; //向流写入数据
    int v1 = 0, v2 = 0;
    std::cin>> v1 >> v2;
    std::cout <<"The sum of " << v1 << " and " << v2 << " is " << v1+v2 << std::endl;

    return 0;
}