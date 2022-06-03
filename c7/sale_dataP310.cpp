#include <iostream>
#include <string>
#include "Sales_data.h"
#include <fstream>

using std::endl;
using std::cerr;
using std::ifstream;
using std::ofstream;
using std::ios;
using std::istream;
using std::ostream;

Sales_data::Sales_data(std::istream &is) 
{
	// read will read a transaction from is into this object
	read(is, *this);
}

double 
Sales_data::avg_price() const {
	if (units_sold)
		return revenue/units_sold;
	else
		return 0;
}

// add the value of the given Sales_data into this object
Sales_data& 
Sales_data::combine(const Sales_data &rhs)
{
	units_sold += rhs.units_sold; // add the members of rhs into 
	revenue += rhs.revenue;       // the members of ``this'' object
	return *this; // return the object on which the function was called
}

Sales_data 
add(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;  // copy data members from lhs into sum
	sum.combine(rhs);      // add data members from rhs into sum
	return sum;
}

// transactions contain ISBN, number of copies sold, and sales price
istream&
read(istream &is, Sales_data &item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

ostream&
print(ostream &os, const Sales_data &item)
{
	os << item.isbn() << " " << item.units_sold << " " 
	   << item.revenue << " " << item.avg_price();
	return os;
}




int main()
{
    
    ifstream input(".\\7\\data\\book_sales", ios::in);
    //input.open(".\\7\\data\\book_sales", ios::in);
    ofstream output(".\\7\\data\\testout.txt", ios::out);
    //output.open(".\\7\\data\\testout.txt", ios::out);
    Sales_data total; 

    if(read(input, total)){
        Sales_data trans;
        while(read(input, trans) ){ //尽管read和下面的print指定的形参是istream&和ostream&，但是也可以接受fstream对象。
            if(total.isbn() == trans.isbn())
                total.combine(trans);
            else{
                print(output, total) << endl;
                total = trans;
            }
        }
        print(output, total) << endl;
    }else{
        cerr << "No data?!" << endl;
        return -1;
    }
    return 0;
}