import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D


def grafica(datafile1, datafile2,datafile3,plotfile, plotlabel):
    data = np.loadtxt(datafile1)
    data1 = np.loadtxt(datafile2)
    data2 = np.loadtxt(datafile3)
    
    plt.figure(figsize=(14,4))
    plt.subplot(1,3,1)
    plt.plot(data[:,0],data[:,1])
    plt.scatter(data[:,0],data[:,1])
    plt.xlabel('$N_x$')
    plt.ylabel('N iteraciones')
    
    plt.subplot(1,3,2)
    plt.plot(data1[:,0],data1[:,1])
    plt.scatter(data1[:,0],data1[:,1])
    plt.xlabel('$N_x$')
    plt.ylabel('Error Centro x $10^2$')
    
    plt.subplot(1,3,3)
    plt.plot(data2[:,0],data2[:,1])
    plt.scatter(data2[:,0],data2[:,1])
    plt.xlabel('$N_x$')
    plt.ylabel('Error Convergencia x $10^6$')
    
    plt.savefig(plotfile, bbox_inches='tight')

grafica("evolve_10.dat","errorcor10.dat" ,"errorcero10.dat","evolve.png", "$N_x=10$ ")