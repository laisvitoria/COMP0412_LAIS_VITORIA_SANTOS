import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

# Lê o arquivo CSV
dados = pd.read_csv("resultados.csv")

# Define a largura de cada grupo de barras
largura = 0.25

# Posições no eixo X para cada grupo de tamanhos
x = np.arange(len(dados["Tamanho"]))

# Criação do gráfico de barras
plt.figure(figsize=(9,6))
plt.bar(x - largura, dados["QuickSort"], width=largura, label="QuickSort")
plt.bar(x, dados["MergeSort"], width=largura, label="MergeSort")
plt.bar(x + largura, dados["InsertionSort"], width=largura, label="InsertionSort")

# Rótulos e título
plt.title("Comparativo de Desempenho dos Algoritmos de Ordenação", fontsize=13)
plt.xlabel("Tamanho do Vetor", fontsize=11)
plt.ylabel("Tempo de Execução (segundos)", fontsize=11)
plt.xticks(x, dados["Tamanho"])  # Exibe os tamanhos nos rótulos do eixo X
plt.legend()
plt.grid(axis="y", linestyle="--", alpha=0.6)

# Ajusta margens e exibe
plt.tight_layout()
plt.show()
