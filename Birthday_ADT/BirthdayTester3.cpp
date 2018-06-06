#include <iostream>
#include "Birthday3.h"

using namespace std;

int main()
{

	Birthday bd1;
	Birthday bd2(1990, 9, 2);
	Birthday bd3(2001, 5, 8);

	bd1.print();
	bd2.print();

	//int yrs = years_apart(bd2, bd3);
	//cout << yrs << endl;
	cout << bd2 - bd3 << endl;
	cout << bd1 << ", " << bd2 << ", " << bd3 << endl;

	return 0;
}
