#include "../Headers/Genome.hpp"

void genome::base (int N)
{
    int number_networks = 10000;
    n = N;
    gn = new gene [n];
    adjac = new double* [n] ;
    II = 0;
    UU = 0;

    alive = 0;
    du_alive = 0;
    ref_Envmnt = 0.01;  //starting input value, or reference environment value ..
    craziness_counter = 30000; //counting number of cicle in a loop, to check if there is any infinite loops or not.
    du_craziness_counter = 2 * craziness_counter;
    
    for (int i=0 ; i<n ; i++)
    {
        adjac[i] = new double [n];
        gn[i].dg_in = 0;
        gn[i].dg_out = 0;
        gn[i].weights = 0;
    }
   
    iseed = 20L * time(0);

    for (int i=0 ; i<n ; i++)
    {
        for (int j=0 ; j<n ; j++)
            adjac[i][j] = 0;
    }

    //+++++++++++++++++++++++++++++++++ the process of duplications++++++++++++++++++++++++++++++++++++++++++
    
    nn = 2*n;
    du_adjac = new double* [nn];
    du = new dupli [nn];
    du_II = 0;
    du_UU = 0;
    
    for (int i=0 ; i<nn ; i++)
    {
        du_adjac [i] = new double [nn];
        du[i].dg_in = 0;
        du[i].dg_out = 0;    
        du[i].weights = 0;    
    }

    for (int i=0 ; i<nn ; i++)
    {    for (int j=0 ; j<nn ; j++)
            du_adjac[i][j] = 0;
    }

    for (int i=0 ; i<100 ; i++)
    {
        ran2(&iseed);
    }

    ofstream Alive ("./Outputs/Alive.txt");
    ofstream du_Alive ("./Outputs/du_Alive.txt");
    
    /* Reference conditions :
    **************************************
    **************************************
    **************************************
    */

    for (int SH=0 ; SH<number_networks ; SH++)
    { 
        string data = "./Results/Net_";
        string du_data = "./Results_du/Net_du_";
        string Extension = ".txt";
        string HH = to_string(SH);
        string location = data + HH + Extension;
        string du_location = du_data + HH + Extension; 
        if (checker(location) == true)
        { 
            initial_evaluation(location,du_location);
        }
        if (du_checker(du_location) == true)
        {
            du_initial_evaluation(du_location, location);
        }
    }
 
    for (int ini=0 ; ini < 200 ; ini++) // the simulation continues running until population of single, duplicates or both reach a small amount (less than 10 networks)
    {
        double evolve = (ini / 100.0) + ref_Envmnt; // input (or environment) value

        cout<<"step = " << evolve <<endl;
        alive = 0;
        du_alive = 0;
        
        for (int SH=0 ; SH<number_networks ; SH++)
        {
            string data = "./Results/Net_";
            string du_data = "./Results_du/Net_du_";
            string Extension = ".txt";
            string HH = to_string(SH);
            string location = data + HH + Extension;
            string du_location = du_data + HH + Extension;       

            if (checker(location) == true) //reading all survived networks from reference environment ...
            {   
                Reader(location);
                specefication();
                Evolution(evolve);
                double KAPA = evolve - parameters();
                KAPA = Ftnssfu(KAPA);
                
                if (KAPA > ran2(&iseed))
                {
                    alive ++;
                }
                
                
                memory_Deleter();
            }
           
            /****************************************************
             * the Duplications now .....
             * *////////////////////////////////////////////

            if (du_checker(du_location) == true)
            {   
                du_Reader(du_location);
                du_specefication();
                du_Evolution(evolve);
                double KAPA = evolve - du_parameters();
                KAPA = Ftnssfu(KAPA);

                if (KAPA > ran2(&iseed))
                {
                    du_alive ++;
                }

                du_memory_Deleter();
            }
                     
        }



        Alive << evolve <<'\t'<< alive <<endl;
        du_Alive << evolve <<'\t'<< du_alive <<endl;
    }

    cout<<"done!!"<<endl;                 
}
