#include "../Headers/Genome.hpp"

void genome::initial_evaluation(string Mahal)
{
    Reader(Mahal);
    specefication();
    
    if (II != 0 && Evolution(ref_Envmnt))    
    {
        double KAPA = ref_Envmnt - parameters();
        KAPA = Ftnssfu(KAPA);
        
        if (KAPA > ran2(&iseed))
        {
            ref_alive +=1;
            ref_omega += KAPA;
        }
        else    // if the network could not reach the min fitness value/ performance, then it would be deleted by following code:
        {
            char arr[Mahal.length() + 1]; 
            strcpy(arr, Mahal.c_str()); 
            remove(arr);
        }
    }
    
    else // if there are some or one infinite loops, or if there is no input node, then network would be deleted as well, 
    {
        char arr[Mahal.length() + 1]; 
        strcpy(arr, Mahal.c_str()); 
        remove(arr);
    }
    
    memory_Deleter();  //deleting previous network properties, to make parameters ready for the next network!

}

void genome::du_initial_evaluation(string du_Mahal)
{
    du_Reader(du_Mahal);
    du_specefication();
    
    if (du_II !=0 && du_Evolution(ref_Envmnt))
    {
        double KAPA = ref_Envmnt - du_parameters();
        KAPA = Ftnssfu(KAPA);
        
        if (KAPA > ran2(&iseed))
        {
            du_ref_alive ++;
            du_ref_omega += KAPA;
        }
        else
        {
            char arr[du_Mahal.length() + 1]; 
            strcpy(arr, du_Mahal.c_str()); 
            remove(arr);
        }
    }
    else 
    {                   
        char arr[du_Mahal.length() + 1]; 
        strcpy(arr, du_Mahal.c_str()); 
        remove(arr);
    }                
    du_memory_Deleter();
}