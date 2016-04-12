import numpy as np

b0 = np.random.randn()
b1 = np.concatenate((np.repeat(20,10), np.random.randn(10)))

"""
b2 <- rbind(cbind(matrix(-15, 6, 6),
                  matrix(rnorm(6 * 14), 6, 14)),
            matrix(rnorm(14 * 20), 14, 20))
"""
b3 = np.ndarray((20,)*3)
b3[0 : 5, 0 : 5, 0 : 5] = - 10
b4 = np.ndarray((20,)*4)
b4[0 : 4, 0 : 4, 0 : 4, 0 : 4] = 5

def morris.function(x, b0, b1, b2):
  # X is a list, transform it into array
  X = np.array(x)
  w = 2.0 * (X - 0.5)
  w[:, [2, 4, 6] <- 2 * (1.1 * X[:, [2, 4, 6]] / (X[:, [2, 4, 6]] + .1) - 0.5)
  y = b0
  for i in range(20):
      y += b1[i] * w[:, i]

  for i in range(19):
      for j in range(i + 1, 20):
          y +=  b2[i, j] * w[:, i] * w[:, j]

  for i in range(18):
      for j in range(i + 1, 19):
          for k in range(j + 1, 20):
              y += y + b3[i, j, k] * w[:, i] * w[:, j] * w[:, k]

  for i in range(17):
      for j in range(i + 1, 18):
          for k in range(j + 1, 20):
              for l in range(k + 1, 20):
                  y += b4[i, j, k, l] * w[:, i] * w[:, j] * w[:, k] * w[:, l]

  return [y]
