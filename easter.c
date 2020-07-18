#include <stdio.h>
int calculate_easter_date (int year); //new function to calculate easter date
int main(void)// main function start from here
{
	
    int year, a;
    printf("enter the year:"); // to show the user what he has to give in input
    scanf("%d", &year); // to get input from user
    while (year != EOF) // condition to read all the elements of file untill EOF end of file occures
	{
		
      	a = calculate_easter_date(year); //function call, to calculte easter date given by user
        if (a == 0)
        {
        	fprintf( stderr, "invalid entry %d \n", a); // this will print a error message for out of range enteries
        }
		else if (a > 0)
	    {
	        printf ("%d April-%d",year, a); //prints when easter come in APRIL
		}
		else
		{
		    printf ("%d March-%d",year, a * (-1)); // prints when easter come in MARCH
		}
        scanf("%d",&year); //to get input from user multiple times or read all values of file
    }
	return 0;
	
}
int calculate_easter_date(int year)
{
    int goldenyear, century, skippedleapyear, correctionfactor, d, epact, fullmoonday;
    if (year < 1582 || year > 39999) // condtion to check the year is  in range of years given
	{
	    return 0;
    }
	goldenyear = (year % 19) + 1; //number of year in metonic cycle in which we are
	century = (year / 100) + 1; // the century of the required easter year
	skippedleapyear = ((3 * century) / 4) - 12; //these are the leap years skipped in this century
	correctionfactor = ( ( (8 * century) + 5) / 25) - 5; //they introduced this correction factor to get rid of the fractional part of the date
	d = ((5 * year) / 4) - skippedleapyear - 10;  // it is helpful to calculate the first date appear on sunday
	epact = ((11 * goldenyear) + 20 + correctionfactor - skippedleapyear) % 30; //age of the moon,from the new moon ,it specifies when the full moon will occure
	if (epact == 25 && goldenyear > 11 || epact == 24)
	{
	    epact = epact + 1; 
	}
	fullmoonday = 44 - epact;
	if ( fullmoonday < 21)
	{
	    fullmoonday = fullmoonday + 30; //it is sunday after full moon day which will be calculated after the below calculation
	}
	fullmoonday = fullmoonday + 7 -((d + fullmoonday) % 7);
	if (fullmoonday > 31) // * this condition decide the month and date of easter *
	{
	    return  (fullmoonday - 31);
	}
	else
	{
	    return (-1) * fullmoonday;
	}
	
}
