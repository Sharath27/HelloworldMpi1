#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "mpi.h"


int main (int argc, char *argv[]) {
     int i, rank, size, namelen;
     char name[MPI_MAX_PROCESSOR_NAME];

        int n=sysconf(_SC_NPROCESSORS_ONLN);
    printf("Hello world! I have %ld logical cores.\n", sysconf(_SC_NPROCESSORS_ONLN ));

     MPI_Init (&argc, &argv);

     MPI_Comm_size (MPI_COMM_WORLD, &size);
     MPI_Comm_rank (MPI_COMM_WORLD, &rank);
     MPI_Get_processor_name (name, &namelen);

     printf ("Hello World from rank %d running on %s!\n", rank, name);
     if (rank == 0) printf("MPI World size = %d processes\n", size);

     MPI_Finalize ();
 }
