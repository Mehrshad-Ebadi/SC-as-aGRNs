import pandas as pd
import os
import shutil as sh
import matplotlib.pyplot as plt
import csv as CC
#import numpy as np
sh.rmtree('du_bar')
os.mkdir ('du_bar')
sh.rmtree('Bar_normal')
os.mkdir ('Bar_normal')

direction = './du_results/bar_'
extns = '.csv'
save_dir = './du_bar/'
direction2 = './Results/bar_'
#save_dir2 = './Bar_normal/'
w = 0.5

# The process of determing the size
Dir99 = direction + str(1) + extns
file = open(Dir99)
reader = CC.reader(file)
lines= len(list(reader))
Tricks = list()

for i in range (0, lines):
    j = 'G ' + str(i+1)
    Tricks.append(j)
#print (lines)


for i in range (1,10000):
    Dir = direction + str(i) + extns
    x1 = pd.read_csv(Dir,header=None)
    df1 = pd.DataFrame (x1)
    X1 = list(df1.iloc[:,0])
    Y1 = list(df1.iloc[:,1])
    print (len(X1))
    #ticks.append('gene' + str())
    
    Dir2 = direction2 + str(i) + extns
    x2 = pd.read_csv(Dir2,header=None)
    df2 = pd.DataFrame (x2)
    X2 = list(df2.iloc[:,0] + w)
    Y2 = list(df2.iloc[:,1])

    plt.bar(X1, Y1, w, label='duplicated')
    plt.bar(X2, Y2, w, label='non duplicated')
    plt.xlabel("Number of the Duplicated Output Gene")
    plt.ylabel("Output Weight")
    #plt.title('The output weight of duplicated Vs. Non-duplicated network',loc=10)
    plt.xticks(X1,Tricks, rotation=90, size= 5)
    plt.yticks(size=5)
    plt.legend()
    #plt.show()
    Save_Dir = save_dir + str(i)
    plt.savefig(Save_Dir, format='png', dpi=400)
    plt.close('all')
