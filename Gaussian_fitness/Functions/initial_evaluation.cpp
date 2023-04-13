#include "../Headers/Genome.hpp"

void genome::initial_evaluation(string Mahal, string du_Mahal)
{
    Reader(Mahal);
    specefication();    
    
    if (II == 0 || Evolution(ref_Envmnt) == false) // if there are some or one infinite loops, or if there is no input node, then network would be deleted as well, 
    {
        char arr[Mahal.length() + 1]; 
        strcpy(arr, Mahal.c_str()); 
        remove(arr);

        char du_arr [du_Mahal.length() + 1];
        strcpy(du_arr, du_Mahal.c_str()); 
        remove(du_arr);
    }
    
    memory_Deleter();  //deleting previous network properties, to make parameters ready for the next network!

}

void genome::du_initial_evaluation(string du_Mahal, string Mahal)
{
    du_Reader(du_Mahal);
    du_specefication();
    
     
    
    if(du_II == 0 || du_Evolution(ref_Envmnt) == false) 
    {                   
        char du_arr[du_Mahal.length() + 1]; 
        strcpy(du_arr, du_Mahal.c_str()); 
        remove(du_arr);

        char arr[Mahal.length() + 1]; 
        strcpy(arr, Mahal.c_str()); 
        remove(arr);
    }                
    du_memory_Deleter();
}