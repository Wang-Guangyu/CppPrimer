#include<iostream>
#include"Sales_data_me.h"

using std::istream;
using std::ostream;

//以istream为参数的构造函数。
Sales_data::Sales_data(std::istream &is) 
{
	// read will read a transaction from is into this object
	read(is, *this);
}

//两个成员函数avg_price和combine
double Sales_data::avg_price() const{
    if(units_sold)
        return revenue/units_sold;
    else
        return 0;
    }

Sales_data& Sales_data::combine(const Sales_data &rhs){ //函数的返回类型是一个Sales_data的引用。
    units_sold += rhs.units_sold;
    revenue += rhs.revenue
    return *this; //返回调用该函数的对象
}

//三个非成员函数
istream& //return type
read(istream &is, Sales_data &item) //输入信息：包括ISBN、数量、单价
{
    double price=0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price*item.units_sold;
    return is;
}

ostream&
print(ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
    return os;
}

Sales_data
add(const Sales_data &lhs, const Sales_data &rhs) //lhs是一个对Sales_data对象的引用，同时又是一个常量，即不能改变Sales_data的值？
{
    Sales_data sum = lhs; //新建Sales_data对象，命名为sum；先用lhs初始化sum
    sum.combine(rhs); //再让sum+=rhs，统计真实的和
    return sum;
}



//主函数
int main()
{
    Sales_data total;
    if(read(cin, total)){
        Sales_data trans;
        while(read(cin, trans)){
            if(total.isbn() == trans.isbn())
                total.combine(trans);
            else{
                print(cout, total) << endl;
                total = trans;
            }
        }
        print(cout, total) << endl;
    }else{
        cerr << "No data?!" << endl;
    }
}