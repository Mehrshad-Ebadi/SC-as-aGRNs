import numpy as np
import matplotlib.pyplot as plt
import os as os
import shutil as sh
import seaborn as sns

sh.rmtree('./cloud')
os.mkdir("./cloud")
sh.rmtree('./SNS')
os.mkdir("./SNS")


for p in range (0,500):
    savving_address = "./cloud/topology_"
    SEABORN = "./SNS/sns_"
    I = str(p)
    extension = ".txt"
    imgage_extension = ".png"
    address = "./Outputs/cloud_"
    address = address + I + extension
    File = np.loadtxt(address)
    X = list()
    Y = list()
    #u = input ("hello") 
    for i in range(0,len(File)):
        X.append(round(File [i][0], 3))
        Y.append(round(File [i][1], 3))
    #print (X)
    #print (Y)
    plt.scatter(X, Y, label='Duplicated output per single output', s=0.2)
    
    plt.legend() 
    plt.xlabel(" Mean Value of Single Output")
    plt.ylabel("Mean Value of Duplicated output")
    savving_address = savving_address + I + imgage_extension
    
    plt.savefig(savving_address,dpi=400)
    plt.close('all')
    sns.jointplot(x=X, y=Y)
    SEABORN = SEABORN + I + imgage_extension
    plt.savefig(SEABORN,dpi=400)
    plt.close('all')
    print(SEABORN)