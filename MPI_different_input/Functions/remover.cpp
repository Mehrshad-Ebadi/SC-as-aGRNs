#include "../Headers/Genome.hpp"

void genome::Remover()
{
    for (int OO=0 ; OO<n ; OO++)
    {
        gn[OO].weights = 0;
    }

    for (int QQ=0 ; QQ<nn ; QQ++)
    {
        du[QQ].weights = 0;
    }

    for (int oo=0 ; oo<UU ; oo++)
        gn[output[oo]].weights = 0;

    for (int oo=0 ; oo<du_UU ; oo++)
        du[du_output[oo]].weights = 0;

}

void genome::Network_Deleter()
{
    delete [] output;
    delete [] input;
    delete [] du_input;
    delete [] du_output;
    
    for (int F=0 ; F<n ; F++)
    {
        gn[F].dg_in = 0;
        gn[F].dg_out = 0;
        gn[F].nghbrs.clear();
        gn[F].Connected.clear();
        gn[F].weights = 0;

        for (int j=0 ; j<n ; j++)
        { adjac[F][j] = 0; }
    }

    II = 0;
    UU = 0;
    du_II = 0;
    du_UU = 0;
    
    for (int F=0 ; F<nn ; F++)
    {
        du[F].dg_in = 0;
        du[F].dg_out = 0;     
        du[F].nghbrs.clear();
        du[F].Connected.clear();
        du[F].weights = 0;

        for (int j=0 ; j<nn ; j++)
        { du_adjac[F][j] = 0; }
    }
    
    
}