import matplotlib.pyplot as plt
import numpy as np

def filereader(filename):
    data = np.loadtxt(filename)
    return data

def plotter(x, u, n):
    plt.figure()
    plt.plot(x, u)
    plt.xlabel("x")
    plt.ylabel("u")
    plt.title("U(x, t) plotted versus x")
    plt.savefig("../../plots/bwd" + str(n) + ".pdf")


def main():
    n = 10
    path = "../../data/"
    bwd = path + "bwd" + str(n) + ".txt"
    data = filereader(bwd)
    x = np.linspace(0, 1, len(data)-2)
    plotter(x, data[1:-1], n)


if __name__ == '__main__':
    main()
