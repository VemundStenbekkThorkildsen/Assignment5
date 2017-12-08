import matplotlib.pyplot as plt
import numpy as np

x=np.linspace(0,1,100)
y=x.copy()
T=np.zeros((100,100))

T[0,:] = 0
T[99,:] = 0
T[:,99] = 1
T[:,0] = 0


for n in range(1,101):
    if((n % 2)==0):
        A=0;
    else:
        A=(2/np.sinh(n*np.pi))*(2/(n*np.pi))

    for i in range(1, 99):
        for j in range(1, 99):
            T[i,j]+=(A*np.sinh(n*np.pi*x[j])*np.sin(n*np.pi*y[i]))

plt.figure()
levels = [0, 0.2, 0.4, 0.6, 0.8, 1.0]
cont = plt.contourf(T, levels=x, cmap='gnuplot2')
cont.set_clim(0, 1)
plt.xlabel('x')
plt.ylabel('y')
plt.colorbar(ticks=[0, 0.2, 0.4, 0.6, 0.8, 1.0], label="T")
plt.title("Analytical solution for 2 dimensions")
#plt.colorbar()
plt.savefig("../../plots/2Danal.pdf")
