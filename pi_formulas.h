//============================================================================
// Name        : first_project.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
using namespace std;

int main()
{

	const double PI = 4*atan(1);
	const double SQRT2 = sqrt(2);
	const double SQRT130 = sqrt(130);
	const double SQRT5 = sqrt(5);
	const double SQRT13 = sqrt(13);
	const double SQRT142 = sqrt(142);
	const double SQRT190 = sqrt(190);
	const double SQRT10 = sqrt(10);
	const double SQRT310 = sqrt(310);
	const double SQRT522 = sqrt(522);
	const double SQRT29 = sqrt(29);
	const double SQRT6 = sqrt(6);



	cout.precision(16);

	cout << "pi = " << PI << " = 4*arctan(1)" << endl << endl;

	cout << "Ramanujan's pi formulas:" << endl;

	double pi15 = (12/SQRT130)*log((2+SQRT5)*(3+SQRT13)/SQRT2);
	cout << "pi15= " << pi15 << endl;

	double pi16 = (24/SQRT142)*log(sqrt((10 + 11*SQRT2)/4) + sqrt((10 + 7*SQRT2)/4));
	cout << "pi16= " << pi16 << endl;

	double pi18 = (12/SQRT190)*log((2*SQRT2+SQRT10)*(3+SQRT10));
	cout <<"pi18= " << pi18 << endl;

	double pi22 = (12/SQRT310)* log(((3+SQRT5)*(2+SQRT2) * ((5+2*SQRT10) + sqrt(61+20*SQRT10)))/4);
	cout << "pi22= " << pi22 << endl;

	//Finding 31 decimal places accuracy of ramanujan's formula
	double e1 = (5+SQRT29)/SQRT2;
	double exp1 = e1*e1*e1;

	double e2 = sqrt((9+3*SQRT6)/4) + sqrt((5+3*SQRT6)/4);
	double exp2 = e2*e2*e2*e2*e2*e2;

	double pi31 = (4/SQRT522) * log((exp1)* ((5*SQRT29)+(11*SQRT6)) * (exp2));
	cout << "pi31= " << pi31 << endl;

	cout.precision(8);
	float euler_pi = PI*PI/6;

	cout << endl;
	cout << "Euler's infinite sum for PI*PI/6 = " << euler_pi << endl;

	int iteration = 1;
	int odd = 1;
	float sum = 0;
	float divisor = 0;
	float term;

	do{
		divisor = divisor+odd;
		term = 1.0/divisor;
		sum+=term;
		iteration++;
		odd+=2;

	} while(term > 1.0e-8);

	cout << "              converged to " << sum << " after " << iteration << " iterations" << endl;

	float estimate = sqrt(sum*6);
	float error = abs(estimate - PI);

	cout << "Euler's estimate for PI is " << estimate << endl;
	cout << "             error = " << error << endl;

	return 0;
}
