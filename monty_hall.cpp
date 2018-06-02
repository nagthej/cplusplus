#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef int Door;
const int SIMULATION_COUNT = 1000;

//All function declarations here before the main(), also shows program structure
void simulate(int, int&, int&);
Door hidecar();
Door randomdoor();
Door makefirstchoice();
Door opendoor(Door firstchoicedoor, Door cardoor);
Door randomdoornot(Door firstchoicedoor, Door cardoor);
Door chooseremainingdoor(Door firstchoicedoor, Door cardoor);
Door makesecondchoice(Door firstchoicedoor, Door openeddoor);

int main()
{
	int win1=0,win2=0;
	int won1=0,won2=0;

	//Seed the random number generator
	srand(time(NULL));

	//for the heading
	cout <<"#" << "\t" << "Car_here | " << "First_choice | " << "Opened_door | " << "Second_choice | "
				<< "win_first | " << "win_second" << endl;



	//Run the simulation by adjusting SIMULATION_COUNT
	for(int i=1;i<=SIMULATION_COUNT;i++)
	{
		simulate(i,win1,win2);
		//count the number of wins if stayed with first door choice
		if(win1==1)
		{
			won1=won1+1;
		}
		//count the number of wins if switched door to second door choice
		else if(win2==1)
		{
			won2=won2+1;
		}

	}

	cout << endl << endl;
	cout << "The number of wins by staying in first choice are " << won1 << endl;
	cout << "The number of wins by switching to other door is " << won2 << endl;


	double windiff = (won2-won1);
	//cout << windiff << endl;
	double winpercentage = (windiff/SIMULATION_COUNT)*100;
	//cout << winpercentage;
	cout << endl;
	cout << "The probability of winning by switching to other door is " << 100-winpercentage << "%";

return 0;

}



//All function definitions here
void simulate(int sequence, int& win1, int& win2)
{
	Door cardoor = hidecar();
	Door firstchoicedoor = makefirstchoice();
	Door openeddoor = opendoor(firstchoicedoor, cardoor);
	Door seconddoorchoice = makesecondchoice(firstchoicedoor, openeddoor);

	string yeswin1;
	string yeswin2;

	if(firstchoicedoor == cardoor)
	{
			win1 = 1;
			win2 = 0;
			yeswin1 = "Yes";
			yeswin2 = "";
	}
	else if (seconddoorchoice == cardoor)
	{
		win2 = 1;
		win1 = 0;
		yeswin2 = "Yes";
		yeswin1 = "";
	}

	cout << sequence << "\t" << cardoor << "\t\t" << firstchoicedoor << "\t\t" << openeddoor << "\t\t"
			<< seconddoorchoice << "\t" << yeswin1 << "\t\t" << yeswin2 << endl;

}

Door hidecar()
{
	return randomdoor();
}

Door randomdoor()
{
	return rand()%3+1;
}

Door makefirstchoice()
{
	return randomdoor();
}

Door opendoor(Door firstchoicedoor, Door cardoor)
{
	if(firstchoicedoor == cardoor)
	{
		return randomdoornot(firstchoicedoor, cardoor);
	}
	else
	{
		return chooseremainingdoor(firstchoicedoor, cardoor);
	}

}

Door randomdoornot(Door firstchoicedoor, Door cardoor)
{
	y: Door r = randomdoor();
		if(r!=firstchoicedoor)
		{
			return r;
		}
		else
			goto y;
}

Door chooseremainingdoor(Door firstchoicedoor, Door cardoor)
{
 p:	Door z = randomdoor();
	if(z!=firstchoicedoor && z!=cardoor)
	{
		return z;
	}
	else
		goto p;
}

Door makesecondchoice(Door firstchoicedoor, Door openeddoor)
{
	m: Door n = randomdoor();
	if(n!=firstchoicedoor && n!=openeddoor)
	{
		return n;
	}
	else
		goto m;
}




