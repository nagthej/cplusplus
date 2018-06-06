#ifndef ROMANNUMERAL_H_
#define ROMANNUMERAL_H_

#include <string>
using namespace std;

class RomanNumeral
{
public:
	//Default constructor
	RomanNumeral();

	//constructor to convert to int value. @param str the Roman numeral string
	RomanNumeral(string str);

	//constructor to convert to string. @param value the decimal value of roman numeral
	RomanNumeral(int value);

	//Destructor
	~RomanNumeral();

	//public getter OR Accessor @return the decimal value
	const int get_decimal();

	//public getter OR Accessor. @return the string/RomanNumeral value
	const string get_roman();

	/*
	 * Overload + operator to add two romannumerals
	 *@param other - the other numeral to add to this one
	 *@param return - the sum of two roman numeral
	 */
	RomanNumeral operator +(const RomanNumeral& other);

	/*
	 * Overload - operator to add two romannumerals
	 *@param other - the other numeral to subtract to this one
	 *@param return - the difference of two roman numeral
	 */
	RomanNumeral operator -(const RomanNumeral& other);

	/*
	 * Overload * operator to add two romannumerals
	 *@param other - the other numeral to multiply to this one
	 *@param return - the product of two roman numeral
	 */
	RomanNumeral operator *(const RomanNumeral& other);

	/*
	 * Overload / operator to add two romannumerals
	 *@param other - the other numeral to divide to this one
	 *@param return - the quotient of two roman numeral
	 */
	RomanNumeral operator /(const RomanNumeral& other);

	/*
	 * Overload == operator to check equality
	 *@param other - the other numeral to compare to this one
	 *@param return - false if they are unequal, otherwise true
	 */
	bool operator ==(const RomanNumeral& other);

	/*
	 * Overload != operator to check inequality
	 *@param other - the other numeral to compare to this one
	 *@param return - true if they are unequal, otherwise true
	 */
	bool operator !=(const RomanNumeral& other);

	/*
	 * Overloaded input stream operator >> to construct roman numeral
	 * by reading its string Eg: MMXVI
	 * @param in - the input stream
	 * @param numeral - the constructed roman numeral
	 * @return - the input stream
	 */
	friend istream& operator >>(istream& in, RomanNumeral& numeral);

	/*
	 * Overloaded output stream operator << to construct roman numeral
	 * by reading in form [int_value:string], like [2016:MMXVI]
	 * @param out - the output stream
	 * @param numeral - the constructed roman numeral
	 * @return - the output stream
	 */
	friend ostream& operator <<(ostream& out, const RomanNumeral& numeral);

private:
	string roman; //Store RomanNumeral as string
	int decimal; //Store RomanNumeral as its decimal value

	//Private member functions to compute RomanNumeral string from decimal value and viceversa
	void to_roman();
	void to_decimal();
};

#endif

