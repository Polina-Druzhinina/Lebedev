import matplotlib.pyplot as plt
import pandas as pd
import numpy as np


data = pd.read_excel("otchet.xlsx")

N = data["N"].values.astype(float)
f = data["Time"].values.astype(float)
print(N, f)
g = N

k = np.sum(f*g) / np.sum(g**2)
print(k)
theory = k*g

plt.figure()
plt.plot(N, f, marker='o')
plt.plot(N, theory)
plt.xlabel("Количество")
plt.ylabel("Время (сек)")
plt.legend()
plt.grid(True)
plt.show()