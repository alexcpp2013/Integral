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
	
	/* MPI i n i t i a l i z a t i o n s */
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

	/* B r o a d c a s t n and h t o a l l p r o c e s s e s */
	MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);
	MPI_Bcast(&h, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);
	/* E v e r y p r o c e s s s e t s up i t s c o n t r i b u t i o n t o t h e i n t e g r a l */
	local_sum = 0.0;
	for(i = my_rank; i < n; i += numprocs)
	{
		x = ((double)i - 0.5) * h ;
		local_sum += func(a + x);
	}
	local_sum *= h;
	if(my_rank == 0)
	{
		MPI_Status status;
		rectangle_sum = local_sum;
		for(i = 1; i < numprocs; ++i)
		{
			MPI_Recv (&local_sum, 1, MPI_DOUBLE, MPI_ANY_SOURCE, 500, MPI_COMM_WORLD, &status);
			rectangle_sum += local_sum;
		}
		printf("Result =  %lf\n", rectangle_sum);
	}
	else
		MPI_Send(&local_sum, 1, MPI_DOUBLE, 0, 500, MPI_COMM_WORLD);

	/* End MPI */
	MPI_Finalize();

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
