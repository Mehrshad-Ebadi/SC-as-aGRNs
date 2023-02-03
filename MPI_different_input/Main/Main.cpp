#include "../Headers/Genome.hpp"
#include <mpi.h>

// This code is the #MPI version of previous code. It is runned based on a 13 nodes computer and can be modified base on your processor.
//requirement : #OPENMPI, 13 nodes (can be modified ...)
//How to run? first type 'make' in your computer, wait for responce, then type mpiexec -n 6 ./Exe/Final.out
// Have fun!
int main (int argc, char **argv)
{
    
    int N = 100;
    int world_size, my_rank;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    
    if (my_rank == 0)
    {
        genome GM;
        GM.base(N,0,33);
    }

    if (my_rank == 1)
    {
        genome QM;
        QM.base(N,33,66);
    }
    
    
    if (my_rank == 2)
    {
        genome WM;
        WM.base(N,66,99);
    }

    
    if (my_rank == 3)
    {
        genome EM;
        EM.base(N,99,123);
    }
    
    
    if (my_rank == 4)
    {
        genome RM;
        RM.base(N,123,156);
    }
    if (my_rank == 5)
    {
        genome TM;
        TM.base(N,156,189);
    }

    if (my_rank == 6)
    {
	    genome YM;
	    YM.base (N, 189, 222);
    }

    if (my_rank == 7)
    {
	    genome UM;
	    UM.base(N, 222, 255);
    }

    if (my_rank == 8)
    {
        genome IM;
        IM.base(N,255,287);
    }

    if (my_rank == 9)
    {
	    genome OM;
	    OM.base (N, 287, 320);
    }

    if (my_rank == 10)
    {
	    genome PM;
	    PM.base(N, 320, 353);
    }

    if (my_rank == 11)
    {
	    genome AM;
	    AM.base (N, 353, 386);
    }

    if (my_rank == 12)
    {
	    genome SM;
	    SM.base(N, 386, 400);
    }
    
    MPI_Finalize();
}
