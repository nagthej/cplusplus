#ifndef BIRTHDAY3_H_
#define BIRTHDAY3_H_

using namespace std;

class Birthday
{
public:
	//constructors
	Birthday(); //This is default constructor which does nothing
	Birthday(int y, int m, int d);

	//Destructor
	~Birthday();

	//Public getters OR accessors
	const int get_year();
	const int get_month();
	const int get_day();

	//Public setters or mutators
	void set_year(int y);
	void set_month(int m);
	void set_day(int d);

	const void print();

	//Friend function declarations - To help access private member variables directly without using getters and setters
	friend bool equal(const Birthday& bd1, const Birthday& bd2);
	int years_apart(const Birthday& bd1, const Birthday& bd2);
	friend int operator -(const Birthday& bd1, const Birthday& bd2);
	friend ostream& operator <<(ostream& outs, const Birthday& bd);
	friend istream& operator >>(istream& ins, const Birthday& bd);


private:
	//Private Member variables
	int year, month, day;

};

#endif
