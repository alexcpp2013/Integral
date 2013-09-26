/*--------------------------------------
Melnyk O. V.
DA-82
lab 1
Program: GRID
--------------------------------------*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*#define timeC 1.0e9
#define CLOCK_REALTIME 0*/

int manageMidlRect();
double midlRect(const double a, const double h, const int n);
double func(double x);

/*---------------------MAIN----------------------------------------------*/
int main(int argc, char* argv[])
{

	printf("\n\nStart program.");

/*-------------------------------------------------------*/

	/*if(argc == 2)
	{
	    printf("\nInsert: %s\n", argv[1]);
  	}
  	if(argc == 1)
	{
	    FILE *file;
	    char *fname = "simple.txt";
    	    const int N = 20;
    	    char str[N];
    	    int y;
    	    memset (str, '\n', N);
    	    file = fopen(fname, "r");
	    if(file != NULL)
	    {
		fgets(str, (N - 1), file);
		printf("\nInsert: %s\n", str);
		fclose(file);
    	    }
  	}*/

	manageMidlRect();

/*-------------------------------------------------------*/

	printf("\n\n");

	return 0;

}

/*----------------------------END MAIN-------------------------------*/

int manageMidlRect()
{
	const int clkID = CLOCK_REALTIME;
	struct timespec st, et;
	double   iv;

	/*clock_gettime(clkID, &st);
	printf("\nStart LINEAR midpoint rectangle method...\n");*/

	const double a = 1.0;
	const double b = 2.0;
	const double h = 0.03;
	const int n = 33;

	double res = midlRect(a, h, n);
	printf("\n\nIntegral ~= %.4lf\n", res);

	/*double res1 = midlRect(a, h / 2, 2 * n);
	printf("\n\nIntegralRunge ~= %.4lf", res);
	double runge = (double)abs(res1 - res) / 3;
	printf("\n\nRunge = %.4lf", runge);*/

	/*clock_gettime(clkID, &et);
	iv = (et.tv_sec * timeC + et.tv_nsec) - (st.tv_sec * timeC + st.tv_nsec);
	printf("\n%.8lf seconds for LINEAR midpoint rectangle method.\n", iv / timeC);*/

	return 0;
}

double func(double x)
{
	/*----------------------*/
	/*int i = 0;
	int j = 0;
	double g = 0.0;
	for(i = 0; i < 65000; ++i)
	{
	    for(j = 0; j < 50; ++j)
	    {
		g = cos(cos(cos(x) * sin(x) * 100));
	    }
	}*/
	/*--------------------*/

	return cos(x * M_PI/ 180) / x;
}

double midlRect(const double a, const double h, const int n)
{
	double result;
	int i;

	result = 0.0;

	for(i = 1; i <= n; ++i)
	{
		result += func(a + h * ((double)i - 0.5));
	}
	result *= h;

    return result;
}

