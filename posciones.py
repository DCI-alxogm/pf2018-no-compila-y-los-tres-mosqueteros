import matplotlib.pyplot as plt
import numpy as np
from scipy.special import gammainc

def sample(center,radius,n_per_sphere):
    r = radius
    ndim = center.size
    x = np.random.normal(size=(n_per_sphere, ndim))
    ssq = np.sum(x**2,axis=1)
    fr = r*gammainc(ndim/2,ssq/2)**(1/ndim)/np.sqrt(ssq)
    frtiled = np.tile(fr.reshape(n_per_sphere,1),(1,ndim))
    p = center + np.multiply(x,frtiled)
    return p

center = np.array([0,0,0])
radius = 6.1879e+5
sp1 = sample(center,radius,204)
center = np.array([1.6501e+6,0,0])
sp2 = sample(center,radius,204)
sp=np.array([(np.append(sp1[:,0],sp2[:,0])),(np.append(sp1[:,1],sp2[:,1])),(np.append(sp1[:,1],sp2[:,1]))])
sp=sp.T
print(sp)
np.savetxt('posiciones.txt',sp)

vx1=np.linspace(0,0,204)
vy1=np.linspace(0,0,204)
vz1=np.linspace(0,0,204)
vx2=np.linspace(-84,-84,204)
vy2=np.linspace(84,84,204)
vz2=np.linspace(0,0,204)
vx=np.append(vx1,vx2)
vy=np.append(vy1,vy2)
vz=np.append(vz1,vz2)
v=np.append(vx,vy)
v=np.append(v,vz)
v=np.array(v).reshape(3,408)
v=v.T
np.savetxt('velocidades.txt',v)


