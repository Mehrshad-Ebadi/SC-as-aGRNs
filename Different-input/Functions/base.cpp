#include "../Headers/Genome.hpp"

void genome::base (int N)
{
    n = N;
    gn = new gene [n];
    adjac = new double* [n] ;
    II = 0;
    UU = 0;
    step = 100000;  //Number of times that the input value is changing ...
    int starting_number_net=0;
    int ending_number_net = 10000;
    crazyness_counter = 10000; //a limitation on network loops, to remove infinite loops from the networks, if there is any
    du_crazyness_counter = 2 * crazyness_counter; //same purpose but for dulicated one

    for (int i=0 ; i<n ; i++) //creating the adjacency matrix
    {
        adjac[i] = new double [n];
        gn[i].dg_in = 0;
        gn[i].dg_out = 0;
        gn[i].weights = 0;
    }
   
    iseed = 20L * time(0); //random generator's seed, changing with time ...

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
        gasdev(&iseed);
    }
    
    string data = "./Results/Net_";
    string extension = ".txt";
    int File_saver = 0;


//Different input-same weight: In this scenario, topology will be changed when all 'step=100,000' inputs have propogate through the network
    
for (int SH=starting_number_net ; SH<ending_number_net ; SH++)
    {  
        string boz = to_string(SH);
        
        string location = data + boz + extension; //location of the generated network
        
        if (checker(location) == true) //checking if the network is availble and is not removed!
        {   
            Reader(location); //reading the network
            Initializing();   //building the adjacency matrix
            duplication();    //Duplicating the read network
            specefication();  //specifying number of input, output, list of neighbors, and ...
            if (Evolution(1.0) && II !=0) //checking if there is any infinite loop in  the network or there is no input node.
            { 
                char data [40];
                char du_data[40];
                char PHASE_SPACE[500];
                char du_PHASE_SPACE[500];

                sprintf(data,"./Outputs/output_%d.txt", File_saver);
                sprintf(du_data,"./Outputs/du_Output_%d.txt", File_saver);
                sprintf(PHASE_SPACE, "./angles/phase_%d.txt", File_saver);
                sprintf(du_PHASE_SPACE, "./angles/du_phase_%d.txt", File_saver);

                ofstream Results (data);
                ofstream du_Results (du_data);
                ofstream phase_space (PHASE_SPACE);
                ofstream du_phase_space (du_PHASE_SPACE);
                
                File_saver ++;
                double evolve;
                phase_space<<"environment"<<'\t'<<"output1"<<'\t'<<"output2"<<'\n';
                du_phase_space<<"environment"<<'\t'<<"output1"<<'\t'<<"output2"<<'\n';
                for (int YY=0 ; YY<step ; YY++)  
                {
                    Remover(); //removing all weights and set them to zero, since in previous condition they may be assgined some values ...
                    evolve = gasdev(&iseed); //input value, (gasdev: Gaussian random generator).

                    Evolution(evolve); //propogating the input value through the network, for single
                    evo_dup(evolve);   //propogating the input value through the network, for duplicated

                    Results << parameters()<<endl;
                    du_Results << du_parameters()<<endl; 
                    
                    phase_space << evolve << '\t' << phase() << '\t' << phase2() <<endl;
                    du_phase_space << evolve << '\t'  << du_phase() << '\t' << du_phase2() <<endl;                
                }
            }
            
            Network_Deleter();
        }
    }

    cout<<"done!!"<<endl;
                    
}
