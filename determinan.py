import numpy as np

n = int(input().strip())
matrix = []

for _ in range(n):
    row = list(map(float, input().strip().split()))
    matrix.append(row)

matrix = np.array(matrix)

det = np.linalg.det(matrix)

print(f"{det:.2f}")
