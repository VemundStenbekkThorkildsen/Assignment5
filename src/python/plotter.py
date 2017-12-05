import matplotlib.pyplot as plt
import numpy as np

def filereader(filename):
    data = np.loadtxt(filename)
    return data

def plotter(x, fwd, bwd, crank, n):
    plt.figure()
    plt.plot(x, fwd, label="Forward Euler")
    plt.plot(x, bwd, '-o', label="Backward Euler")
    plt.plot(x, crank, label="Crank-Nicholson")
    plt.xlabel("x")
    plt.ylabel(r'$u(x, t)$')
    plt.title('$u(x, t)$ with $t_{max} = 1$, $\Delta x = 0.1$ and $\Delta t = 0.02$')
    plt.legend()
    plt.savefig("../../plots/bfwd" + str(n) + ".pdf")


def main():
    n = 10
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
