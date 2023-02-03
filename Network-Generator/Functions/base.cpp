#include "../Headers/Genome.hpp"

void genome::base ()
{
    k_in = 0; 
	k_out = 0; 
    k_in_du = 0;
    k_out_du = 0; 
    double node_weight = 1;

    for (int i=0 ; i<n ; i++)
    {
        gn[i].dg_in = 0;
        gn[i].dg_out = 0;
        gn[i].weights = node_weight;

        for (int j=0 ; j<n ; j++)
            adjac[i][j] = 0;
    }

    for (int i=0 ; i<nn ; i++)
    {
        for (int j=0 ; j<nn ; j++)
        {
            du_adjac[i][j] = 0;
        }
    }

    anses_network(); //creating the initial networks
}



void genome::anses_network ()
{
    connect(0, 1, 1.0);
    connect(0, 2, 1.0);
    connect(1, 2, 1.0);	
}

