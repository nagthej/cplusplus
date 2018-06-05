#include <iostream>
using namespace std;

//Class definition
class Birthday
{
public:
	void set_year(int y);
	void set_month(int m);
	void set_day(int d);

	const int get_year();
	const int get_month();
	const int get_day();
	const void print();

private:
	int year,month,day;

};

//Class member function definitions - getters or accessors
const int Birthday::get_year()
{
	return year;
}

const int Birthday::get_month()
{
	return month;
}

const int Birthday::get_day()
{
	return day;
}

//Class member function definitions - setters or mutators
void Birthday::set_year(int y)
{
	year = y;
}

void Birthday::set_month(int m)
{
	month = m;
}

void Birthday::set_day(int d)
{
	day = d;
}

const void Birthday::print()
{
	cout << month << "/" << day << "/" << year << endl;
}


int main()
{
	Birthday bd;
	bd.set_year(1990);
	bd.set_month(9);
	bd.set_day(2);
	bd.print();

	return 0;
}













