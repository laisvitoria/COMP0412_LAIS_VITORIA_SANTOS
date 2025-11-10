import pandas as pd
import matplotlib.pyplot as plt

# Lê o arquivo CSV
dados = pd.read_csv("resultados.csv")

# Identifica os tipos de vetor (Aleatorio, Crescente, Decrescente)
tipos = dados["Tipo"].unique()

# Cria um gráfico para cada tipo
for tipo in tipos:
    subset = dados[dados["Tipo"] == tipo]

    plt.figure(figsize=(10, 6))
    plt.plot(subset["Tamanho"], subset["QuickSort"], color="#1f77b4", linewidth=2.5, marker="o", label="QuickSort")
    plt.plot(subset["Tamanho"], subset["MergeSort"], color="#2ca02c", linewidth=2.5, marker="s", label="MergeSort")
    plt.plot(subset["Tamanho"], subset["InsertionSort"], color="#d62728", linewidth=2.5, marker="^", label="InsertionSort")

    plt.title(f"Desempenho - Vetor {tipo}", fontsize=14)
    plt.xlabel("Tamanho do Vetor", fontsize=12)
    plt.ylabel("Tempo de Execução (segundos)", fontsize=12)
    plt.grid(True, linestyle="--", alpha=0.6)
    plt.legend(fontsize=11)
    plt.tight_layout()

    # Salva o gráfico como imagem
    plt.savefig(f"grafico_{tipo.lower()}.png", dpi=150)
    plt.show()

print("✅ Gráficos gerados com sucesso: grafico_aleatorio.png, grafico_crescente.png e grafico_decrescente.png")
