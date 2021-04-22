#include "Date.h"

int main()
{

	//create two dates and print them
	Date date1(10, 22, 2019);
	Date date2(10, 14, 1944);
	cout << "date1: " << date1 << endl;
	cout << "date2: " << date2 << endl;
	//create two more dates, increment them and print them
	Date date3 = date1;
	Date date4 = date2;
	date3++;
	date4++;
	cout << "date3: " << date3 << endl;
	cout << "date4: " << date4 << endl;
	//Add and subtract days to and from previous dates
	date3 += 20;
	date4 -= 130;
	date3.plusReset(date3);
	date4.minusReset(date4);
	cout << "date3 after change: " << date3 << endl;
	cout << "date4 after change: " << date4 << endl;
	//find the difference and print the number of days
	cout << "Difference between date3 and date4: " << date3 - date4 << " days" <<
		endl;

}

