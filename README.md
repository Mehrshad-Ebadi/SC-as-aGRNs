# SC-as-aGRNs
This package generates modified scale free networks to serve as artificial gene regulatory networks and their duplicated versions simulating the result of whole genome duplication (WGD). It allows comparison of their performance and differences in various environments. Additional information can be found in [Ebadi et al. 2023](https://www.vandepeerlab.org/people/meeba). In the folder **network examples** you can find some graphical examples of the networks generated and their duplicates. 

# Requirements:
1. makefile
2. C/C++ compiler (version 11 or higher preferred)
3. 8 GB of RAM for a network of 100 nodes

** for the MPI version, openmpi is required. The MPI code is written for a cluster of 13 processes. If you want to run the code on a computer with a different number of nodes, please edit the code or consider running the code on a system with at least 13 processors.


# Running the code:
in linux: To run the code, please go the directory and type 'make'. After the make process finished, the excutable file will be saved in the directory of 
./..(all versions)/Exe/Final.out

# Workflow:
1. Go to the **Network-Generator** and run the code to generate the networks you require. By default the network generator generates 100k networks of  size 10 and their duplicated versions. Network size can be adjusted in /..(all versions)/Main/Main.cpp. The number of networks can be adjusted by changing the 'QWER' parameter on lin 9 of ./Network-Generator/Functions/start.cpp.

2. For each different scenario, copy-paste the generated networks to the directory of the corresponding scenario. For example if you want to run the **different input** scenario, you have to copy-paste the networks in ./Network-Generator/Results to ./Different-input, before running the code. Results will be saved in two folders: **output** and **angles**. The **outputs** give the mean value of the *output nodes* and the **angles** the exact value of both *output nodes* of the network per input value. 
 
important: To run the fitness scenario, you have to copy both Results and Results_du from network generator to the fitness folder.
