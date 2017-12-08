import matplotlib.pyplot as plt
import numpy as np



a=[-0.28, -0.07, -0.11]
b=[-29, -20.6, -23.8]
c=[8, 92, 28]

z=np.linspace(0,-120,121)

T = np.zeros(121)

for i in range(121):
    if(i<19):
        T[i]=a[0]*z[i]**2+b[0]*z[i]+c[0]
    elif(i>=19 and i<39):
        T[i]=a[1]*z[i]**2+b[1]*z[i]+c[1]
    elif(i>=39 and i<=120):
        T[i]=a[2]*z[i]**2+b[2]*z[i]+c[2]

M = np.zeros((121, 121))
for i in range(121):
    M[i, :] = T[i]


one = np.ones(121)

plt.figure()
plt.plot(T, z)
plt.plot(T, one*(-20))
plt.plot(T, one*(-40))
plt.savefig("../../plots/lineanal.pdf")



fig = plt.figure()
levels = np.arange(0, 1300, 0.5)
cont = plt.contourf(M, levels = levels, cmap='gnuplot2')
#plt.plot(T, one*(20))
#plt.plot(T, one*(40))
cont.set_clim(8, 1300)
plt.colorbar(ticks=[8, 200, 400, 600, 800, 1000, 1200], format='%0.2f', label='T')
plt.gca().invert_yaxis()
plt.xlabel("x")
plt.ylabel('z')
#plt.title(r'$T$ with $t_{max} = 1$ Ma, ' r'$\Delta x = \frac{1}{120}$ and ' r'$\Delta t = \frac{1}{3e^4}$')
#plt.savefig("../../plots/geoplot" + str(n) + ".pdf")
plt.savefig("../../plots/contanal.pdf")
