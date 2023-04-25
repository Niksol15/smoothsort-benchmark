import matplotlib.pyplot as plt
import numpy as np

n = [100, 1000, 10000, 100000, 1000000, 10000000]
random_ns = [570, 5732, 57876, 581986, 7226540, 1694037269]

plt.plot(n, random_ns, 'r')
nlogn = [6 * i * np.log2(i) for i in n]
plt.plot(n, nlogn, 'b')
plt.show()
