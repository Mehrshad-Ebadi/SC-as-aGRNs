#include "../Headers/Genome.hpp"


bool genome::du_Evolution(double evolve)
{    
    du[selected_node].weights = evolve;
    counter = 0;
    
    for (int i=0 ; i<du[selected_node].nghbrs.size() ; i++)
    { 
        int node2 = du[selected_node].nghbrs[i];
        double VV = 0;
        
        for (int GH=0 ; GH < du[node2].Connected.size(); GH++)
        {
            int gh = du[node2].Connected[GH];
            VV += double(du[gh].weights * du_adjac[gh][node2]);
        }        
        
        du[node2].weights = The_Function(VV);
        du_updater (node2);    
    }
    if (counter < du_craziness_counter)
    {
        return true;
    }
    
    if (counter >= du_craziness_counter)
    {
        return false;
    } 
}

void genome::du_updater (int nodex)
{  
    counter++;

    if (counter < du_craziness_counter)
    { 
        for (int i=0 ; i<du[nodex].nghbrs.size() ; i++)
        {   
            double values = 0;
            int node4 = du[nodex].nghbrs[i];  
            
            for (int GH=0 ; GH < du[node4].Connected.size(); GH++)
            {
                int gh = du[node4].Connected[GH];
                values += double(du[gh].weights * du_adjac[gh][node4]);
            }
            
            du[node4].weights = The_Function(values);
            du_updater (node4);
        }
    }
}