import matplotlib.pyplot as plt
import numpy as np

def filereader(filename):
    data = np.loadtxt(filename)
    return data

def plotter(x, fwd, bwd, crank, n):
    plt.figure()
    plt.plot(x, fwd, '-o', label="Forward Euler", markersize=7, markevery=5)
    #plt.plot(x, fwd, '-o', label="Forward Euler")
    plt.plot(x, bwd, label="Backward Euler")
    plt.plot(x, crank, label="Crank-Nicholson")
    plt.xlabel("x")
    plt.ylabel(r'$u(x, t)$')
    plt.title('$u(x, t)$ with $t_{max} = 0.1$, $\Delta x = 0.00001$ and $\Delta t = 0.000005$')
    plt.legend()
    plt.savefig("../../plots/t1_" + str(n) + ".pdf")


def main():
    n = 100
    path = "../../data/"
    bwd = path + "bwd" + str(n) + ".txt"
    fwd = path + "fwd" + str(n) + ".txt"
    crank = path + "crank" + str(n) + ".txt"
    db = filereader(bwd)
    df = filereader(fwd)
    dc = filereader(crank)
    x = np.linspace(0, 1, len(df))
    plotter(x, df, db, dc, n)


if __name__ == '__main__':
    main()
