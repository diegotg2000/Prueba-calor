import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.cm as cm

vec=np.loadtxt('datos.txt',usecols=0)

Z=np.zeros(shape=(201,201))

    
for i in range(201):
    Z[i,:]=vec[i*201:(i+1)*201]

plt.figure(figsize=(14,5))
X=np.arange(201)
Y=X
X,Y=np.meshgrid(X,Y)
plt.subplot(1,2,1)
plt.pcolor(X, Y, Z, cmap=cm.viridis, vmin=abs(Z).min(), vmax=abs(Z).max())
plt.colorbar()
plt.ylabel('Índice T')
plt.xlabel('Índice X')
X=np.arange(201)
T0=Z[0,:]
Tf=Z[-1,:]
plt.subplot(1,2,2)
plt.plot(X,T0,label='Tiempo inicial')
plt.plot(X,Tf,label='Tiempo final')
plt.xlabel('Índice X')
plt.ylabel('Temperatura')
plt.legend()
plt.savefig('temp.png')