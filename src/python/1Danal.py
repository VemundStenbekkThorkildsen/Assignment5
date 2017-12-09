import matplotlib.pyplot as plt
import numpy as np

def main():
    n = 100
    x = np.linspace(0, 1, n)
    y = np.linspace(0, 1, n)
    plt.plot(x, y)
    plt.xlabel('x')
    plt.ylabel('u(x,t)')
    plt.title("Analytical solution for 1 dimension")
    plt.savefig("../../plots/1Danal.pdf")



if __name__ == '__main__':
    main()


