#include <iostream>
#include <cstdlib>
#include "Birthday3.h"

using namespace std;

Birthday::Birthday(): year(0), month(0), day(0)
{
	//Empty body - This is default constructor does nothing
}

Birthday::Birthday(int y, int m, int d): year(y), month(m), day(d)
{
	//Empty body - This constructor initialized private member variables
}

//Default destructor definition
Birthday::~Birthday()
{
	//Empty body
}

//Getters OR Accessors definition
const int Birthday::get_year() { return year; }
const int Birthday::get_month() { return month; }
const int Birthday::get_day() { return day; }

//Setters or Mutators definition
void Birthday::set_year(int y) { year = y; }
void Birthday::set_month(int m) { month = m; }
void Birthday::set_day(int d) { day = d; }

const void Birthday::print()
{
	cout << month << "/" << day << "/" << year << endl;
}

//Friend functions definitions - IMPORTANT
int Birthday::years_apart(const Birthday& bd1, const Birthday& bd2)
{
	return abs(bd1.year - bd2.year);
}

//Operator overloading function definition
int operator -(const Birthday& bd1, const Birthday& bd2)
{
	return abs(bd1.year - bd2.year);
}

//Output stream (monitor output) overloading
ostream& operator <<(ostream& outs, const Birthday& bd)
{
	outs << bd.month << "/" << bd.day << "/" << bd.year;
	return outs;
}

//input stream - syntax only
/*
 * istream& operator >>(istream& ins, const Birthday& bd)
 * {
 * 		...
 * }
 */











