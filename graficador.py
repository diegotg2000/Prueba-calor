import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.cm as cm

vec=np.loadtxt('datos.txt',usecols=0)

Z=np.zeros(shape=(201,201))

    
for i in range(201):
    Z[i,:]=vec[i*201:(i+1)*201]
    
X=np.arange(201)
Y=X
X,Y=np.meshgrid(X,Y)
fig, ax = plt.subplots()
p = ax.pcolor(X, Y, Z, cmap=cm.viridis, vmin=abs(Z).min(), vmax=abs(Z).max())
cb = fig.colorbar(p)
plt.savefig('temp.png')