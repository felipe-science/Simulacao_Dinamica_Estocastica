import random
from numpy import pi, zeros, sqrt
from pylab import plot, show, title, xlabel, ylabel, tick_params, legend

def caminhada_aleatoria(n_passos=1000):

    w = zeros(n_passos)
    for i in range(1,n_passos):
        yi = random.choice([1,-1])
        w[i] = w[i-1]+(yi/sqrt(n_passos))
    return w

processo1 = caminhada_aleatoria()
processo2 = caminhada_aleatoria()
processo3 = caminhada_aleatoria()
#plot(processo1, processo2)
plot(processo1, label='Partícula 1')
plot(processo2, label='Partícula 2')
plot(processo3, label='Partícula 3')

title("Caminhada aleatória unidimensional", fontsize='20')
xlabel("Número de passos", fontsize='15')
ylabel("Posição da partícula", fontsize = '15')
tick_params(labelsize=13)
legend()
show()     
    