import random
from numpy import pi, zeros, sqrt
from pylab import plot, show, title, xlabel, ylabel, tick_params

def caminhada_aleatoria(n_passos=1000):

    w = zeros(n_passos)
    for i in range(1,n_passos):
        yi = random.choice([1,-1])
        w[i] = w[i-1]+(yi/sqrt(n_passos))
    return w

processos = []
for k in range(3):
    processos.append(caminhada_aleatoria())
    plot(processos[k])

title("Caminhada aleatória unidimensional", fontsize='20')
xlabel("Número de passos", fontsize='15')
ylabel("Posição da partícula", fontsize = '15')
tick_params(labelsize=13)
show()     
    