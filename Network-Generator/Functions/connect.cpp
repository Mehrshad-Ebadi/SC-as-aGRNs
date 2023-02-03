#include "../Headers/Genome.hpp"

void genome::connect (int i, int j, double Wgh)
{

    adjac[i][j] = Wgh;
    gn[i].dg_out++;
    gn[j].dg_in++;
    k_in++;
    k_out++;
    gn[i].nghbrs.push_back(j);
    gn[j].connect.push_back(i);
}


int genome::police1 (int i, int j)
{
    {
        vector<int>::iterator it;
        
        it = find (gn[i].nghbrs.begin(), gn[i].nghbrs.end(), j); 
        if (it != gn[i].nghbrs.end())
        {
            int xx = it - gn[i].nghbrs.begin();
            return xx;
            
        }
        else
        {
            return -1;
        }
    }
}
    int genome::police2 (int i, int j)
    {
        
        vector<int>::iterator it;
        
        it = find (du[i].nghbrs.begin(), du[i].nghbrs.end(), j); 
        if (it != du[i].nghbrs.end())
        {
            int xx = it - du[i].nghbrs.begin();
            return xx;
            
        }
        else
        {
            return -1;
        }       
    } 
