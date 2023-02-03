import pandas as pd
import os
import shutil as sh
import matplotlib.pyplot as plt
sh.rmtree('Bar_normal')
os.mkdir ('Bar_normal')

direction2 = './Results/bar_'
extns2 = '.csv'
save_dir2 = './Bar_normal/'

for i in range (0,10000):
    Dir2 = direction2 + str(i) + extns
    x2 = pd.read_csv(Dir2)
    df2 = pd.DataFrame (x2)
    X2 = list(df2.iloc[:,0])
    Y2 = list(df2.iloc[:,1])
    plt.bar(X2, Y2, width=0.05)
    plt.xlabel("Number of the Gene")
    plt.ylabel("The Expression Level")
    Save_Dir = save_dir2 + str(i)
    plt.savefig(Save_Dir, format='png', dpi=400)
    plt.close('all')

