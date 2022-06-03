#include<iostream>
#include"c2_Sales_data.h"

int main()
{
    Sales_data total; 
    if(std::cin >> total){
        Sales_data trans;
        while(std::cin >> trans){
            if(total.isbn() == trans.isbn())
                total += trans;
            else{
                std::cout << total << std::endl;
                total = trans;
            }
        }
        std::cout << total << std::endl;
    }else{
        std::cerr << "No data?!" << std::endl;
        return -1;
    }
    return 0;
}