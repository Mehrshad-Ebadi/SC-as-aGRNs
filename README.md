# SC-as-aGRNs
This package will generate its own modified graph as an artificial gene regulatory network. Then it will make the whole genome duplicated version of the created networks (WGD) for comparing their performance and differences in various environments.

# requirments:
1- makefile
2- C/C++ compiler (version 11 or higher preferred)
3- for using a network of 10 nodes, 2G ram is required.
** for the MPI version, openmpi is required. Also, the MPI code is written for a cluster of 13 processes. Thus if you want to run the code on a computer with a different number of nodes, please edit the code or consider running the code on a system with min 13 processors.


Running the code:
in linux: To run the code, please go the directory and type 'make'. After the make process finished, the excutable file will be saved in the directory of 
./..(all versions)/Exe/Final.out

Order of the code:
1- first go to the 'Network-Generator' and run the code to generate networks that is needed. The default network size is 10, and the number of generated networks is 100k. You can change the network size in the /..(all versions)/Main/Main.cpp. If you want different number of networks, then you can change it 
./Network-Generator/Functions/start.cpp. After reaching there, in the line of 9, 'QWER' parameter is the number of generated networks and you can change it as you want.

2- for each different scenario, you have to copy the generated networks to the directory of that scenario. To do that, for example you want to run the code of 'different input' scenario. First you have to generate enough networks (we used 400 networks in the main script) from the network generator code, and then you have to copy the ./Network-Generator/Results to the ./Different-input. After that, the code is ready for run. Results will be saved in two folders: output and angles. Results of the outputs is the mean value of the 'output nodes' and the results in the angles is the exact value of both 'output nodes' of the network per input value. 
 
important: To run the fitness scenario, you have to copy both Results and Results_du from network generator to the fitness folder.
 
