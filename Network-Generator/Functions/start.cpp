#include "../Headers/Genome.hpp"

void genome::Start(int N)  //Starting process ...
{
    n = N;
    nn = 2 * n;
    UU = 0;

    int QWER = 100000;   //Number of generated networks ...
    gn = new gene [n];
    adjac = new double* [n];
    iseed = 20L * time(0);

    du_adjac = new double* [nn];
    UU = n - 3;

    for (int i=0 ; i<n ; i++)   //Creating the adjacency matrix of single networks
    {        
        adjac[i] = new double [n];
    }

    for (int i=0 ; i<nn ; i++)  //Creating the adjacency matrix of duplicate networks
    {
        du_adjac [i] = new double [nn];
    }
    

    int jj = 0;
    for (int QW=0 ; QW < QWER ; QW++)
    {
        base();          //setting all initial values to zero, and create the initial network 
        Prf_attch();     //preferential attachment algorithm
        duplication();   //duplicating the generated networks

        Save(QW);       //saving generated network in the ./Result folder (for single networks)
        du_save(QW);    //saving generated network in the ./Result_du folder (for duplicated networks)
    }
}
