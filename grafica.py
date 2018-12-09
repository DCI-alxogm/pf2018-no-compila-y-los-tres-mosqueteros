##PROGRAMA PARA GRAFICAR LOS PUNTOS CORRESPONDIENTES A CADA INTERACCIÓN Y GUARDARLO EN IMAGENES
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
import numpy as np
import sys

for i in range(1,len(sys.argv)):
    file=sys.argv[i]
    plt.clf()
    sp=np.loadtxt(file)
    fig = plt.figure()
    ax1 = fig.add_subplot(111, projection='3d')
    ax1.scatter3D(sp[:,0],sp[:,1],sp[:,2])
    plt.savefig(file+'.png')
