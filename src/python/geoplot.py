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
    cont.set_clim(8, 1300)
    plt.colorbar(ticks=[8, 200, 400, 600, 800, 1000, 1200], format='%0.2f', label='T')
    plt.gca().invert_yaxis()
    plt.xlabel("x")
    plt.ylabel('z')
    plt.title(r'$T$ with $t_{max} = 10$ Ma, ' r'$\Delta x = \frac{1}{120}$ and ' r'$\Delta t = \frac{1}{3e^4}$')
    plt.savefig("../../plots/14kcont10ma.pdf")

def lineplotter(y, x, n):
    one = np.ones(121)
    plt.figure()
    plt.plot(y, x)
    plt.plot(y, one*(20))
    plt.plot(y, one*(40))
    plt.gca().invert_yaxis()
    plt.xlabel("T")
    plt.ylabel('z')
    plt.title(r'$T$ with $t_{max} = 10$ Ma, ' r'$\Delta x = \frac{1}{120}$ and ' r'$\Delta t = \frac{1}{3e^4}$')
    plt.savefig("../../plots/14kline10ma.pdf")


def main():
    n = 120
    path = "../../data/"
    fwd = path + "14k10Ma.txt"
    data = filereader(fwd)
    vector = []
    for i in range(121):
        vector.append(data[i][i])
    #x = np.linspace(0, 1, len(df[0,:]))
    #levels = [0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0]
    x = np.linspace(0, 121, len(vector))
    levels = np.arange(0, 1300, 0.5)
    contourf_plotter(data, n, levels)
    lineplotter(vector, x, n)


if __name__=='__main__':
    main()
