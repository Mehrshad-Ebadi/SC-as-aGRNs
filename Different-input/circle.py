from itertools import count
import numpy as np
import matplotlib.pyplot as plt
import os as os
import shutil as sh

sh.rmtree('./diagrams')
os.mkdir("./diagrams")
for p in range (0,500):
    savving_address = "./diagrams/topology_"
    I = str(p)
    extension = ".txt"
    imgage_extension = ".png"
    address = "./Outputs/output_"
    du_address = "./Outputs/du_Output_"
    address = address + I + extension
    du_address = du_address + I + extension
    File = np.loadtxt(address)
    for i in range (0, File.size):
        File[i] = round(File[i],1) 
    
    du_File = np.loadtxt(du_address)
    for i in range (0, du_File.size):
        du_File[i] = round(du_File[i], 1)
    #print (File, du_File)
    original = np.unique(File)
    du_original = np.unique(du_File)
    Count = np.zeros(original.size)
    du_Count = np.zeros(du_original.size)
    #print ("done!")
    for i in range(0, original.size):
        Count[i] = (np.count_nonzero(File == original[i])) / 10000
        #print (Count[i], original[i])
    #print ("done!")    
    for j in range(0, du_original.size):
        du_Count[j] = (np.count_nonzero(du_File == du_original[j])) / 10000
        #print (du_Count[j], du_original[j])
        
        
       
    savving_address = savving_address + I + imgage_extension
    #print ("it is finished!!")
    #plt.legend("Non-Duplicated")
    ax = plt.gca()
    ax.set_xlim(0, 15)
    ax.set_ylim(-3,3)

    for i in range (0,original.size):
        no_dupi = plt.Circle((original[i], 0), Count[i],facecolor='blue', edgecolor='blue', fill=False, linewidth=0.5)
        ax.add_patch(no_dupi)
    
    for i in range (0,du_original.size):
        no_dupi = plt.Circle((du_original[i], 0), du_Count[i], facecolor='orange', edgecolor='orange', linewidth=0.5 ,fill=False, alpha=0.6)
        ax.add_patch(no_dupi)
    
    #plt.plot(original, Count, label='non-Duplicated')
    #plt.plot(du_original, du_Count,label='Duplicated',alpha=0.6)
    plt.legend() 
    #plt.text(1,1,'blue = not')
    plt.xlabel("The Output Weight")
    plt.ylabel("Radius of the circle is number of repeated")
    plt.savefig(savving_address,dpi=900)
    plt.close('all')
    print (savving_address)
    
        
        
    
        
