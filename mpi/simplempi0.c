/*--------------------------------------
Melnyk O. V.
DA-82
lab 1
Program: GRID MPI
--------------------------------------*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <mpi.h>

#define timeC 1.0e9
#define CLOCK_REALTIME 0

double func(double x);

/*---------------------MAIN----------------------------------------------*/
int main(int argc, char* argv[])
{

	printf("\n\nStart program.");

/*-------------------------------------------------------*/

	const int clkID = CLOCK_REALTIME;
	struct timespec st, et;
	double   iv;

	clock_gettime(clkID, &st);
	printf("\nStart LINEAR midpoint rectangle method...\n");

	int n = 33;
	double h = 0.03;

	int numprocs, my_rank, i;
	double local_sum, rectangle_sum, x;
	double a = 1.0;

	local_sum = 0.0;
	for(i = 1; i <= n; ++i)
	{
		x = ((double)i - 0.5) * h ;
		local_sum += func(a + x);
	}
	local_sum *= h;

	printf("Result =  %lf\n", local_sum);

	clock_gettime(clkID, &et);
	iv = (et.tv_sec * timeC + et.tv_nsec) - (st.tv_sec * timeC + st.tv_nsec);
	printf("\n%.8lf seconds for LINEAR midpoint rectangle method.\n", iv / timeC);

/*-------------------------------------------------------*/

	printf("\n\n");

	return 0;

}

/*----------------------------END MAIN-------------------------------*/

double func(double x)
{
	/*----------------------*/
	int i = 0;
	int j = 0;
	double g = 0.0;
	for(i = 0; i < 65000; ++i)
	{
	    for(j = 0; j < 50; ++j)
	    {
			g = cos(cos(cos(x) * sin(x) * 100));
	    }
	}
	/*--------------------*/

	return cos(x * M_PI / 180) / x;
}
