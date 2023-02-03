import numpy as np
import matplotlib.pyplot as plt
import os as os
import shutil as sh
import seaborn as sns

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
    du_File = np.loadtxt(du_address)
    
    #for i in range (0, File.size):
    #    File[i] = round(File[i], 0)
    
    #for i in range (0, du_File.size):
    #    du_File[i] = round(du_File[i], 0)
    print('for the single =',max(File),'and for duplicated =',max(du_File))
    print('MIN for the single =',min(File),'and for duplicated =',min(du_File))
    go = input ()
    #sns.histplot(File)   
    sns.histplot(du_File, alpha=0.6, color='orange')
    print (File)
    savving_address = savving_address + I + imgage_extension
    #print ("it is finished!!")
    #plt.legend("Non-Duplicated")
    #plt.scatter(original, Count, label='non-Duplicated',s=7)
    #plt.scatter(du_original, du_Count,label='Duplicated',alpha=0.6, s=7)
    #plt.plot(original, Count, label='non-Duplicated')
    #plt.plot(du_original, du_Count,label='Duplicated',alpha=0.6)
    #plt.scatter(original, Count, label='non-Duplicated', s=0.5)
    #plt.scatter(du_original, du_Count,label='Duplicated', s=1)
    plt.legend() 
    #plt.ylim(0, 200)
    plt.xlabel("The Phenotype")
    plt.ylabel("Number of Times the Phenotype is Repeated")
    plt.savefig(savving_address,dpi=400)
    plt.close('all')
    #plt.show()
    print (savving_address)
    
        
        
    
        
