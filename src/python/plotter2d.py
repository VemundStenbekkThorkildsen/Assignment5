import matplotlib.pyplot as plt
import numpy as np

def filereader(filename):
    data = np.loadtxt(filename)
    return data

def contourf_plotter(data, n, levels):
    '''Function that returns in-data as a countourf plot with boundary and the possibility
     of rectangles.'''
    fig = plt.figure()
    cont = plt.contourf(data, levels=levels, cmap='gnuplot2')
    cont.set_clim(0, 1)
    plt.colorbar(ticks=[0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0], format='%0.2f', label='t')
    plt.xlabel("x")
    plt.ylabel('y')
    plt.title('$u(x, y, t)$ with $t_{max} = 1$, $\Delta x = 0.1$ and $\Delta t = 0.02$')
    plt.savefig("../../plots/fwd2" + str(n) + ".pdf")


def main():
    n = 100
    path = "../../data/"
    fwd = path + "2fwd" + str(n) + ".txt"
    data = filereader(fwd)
    #x = np.linspace(0, 1, len(df[0,:]))
    #levels = [0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0]
    levels = np.arange(0, 1.0005, 0.0005)
    print(levels)
    contourf_plotter(data, n, levels)


if __name__=='__main__':
    main()
