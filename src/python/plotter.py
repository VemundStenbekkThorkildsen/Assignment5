import matplotlib.pyplot as plt
import numpy as np

def filereader(filename):
    data = np.loadtxt(filename)
    return data

def plotter(x, fwd, bwd, n):
    plt.figure()
    plt.plot(x[1:-1], fwd[1:-1], label="Forward Euler")
    plt.plot(x[1:-1], bwd[1:-1], label="Backward Euler")
    plt.xlabel("x")
    plt.ylabel("u")
    plt.title("U(x, t) plotted versus x")
    plt.legend()
    plt.savefig("../../plots/bfwd" + str(n) + ".pdf")


def main():
    n = 100
    path = "../../data/"
    bwd = path + "bwd" + str(n) + ".txt"
    fwd = path + "fwd" + str(n) + ".txt"
    db = filereader(bwd)
    df = filereader(fwd)
    x = np.linspace(0, 1, len(df))
    plotter(x, df, db, n)


if __name__ == '__main__':
    main()
