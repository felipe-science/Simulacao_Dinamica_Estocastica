from numpy import loadtxt, linspace
from pylab import scatter, plot, show, xlabel, ylabel

livre_caminho_medio = 1e-9
tempo_de_relaxacao = 1e-9


dados = loadtxt('media_posicao.txt',float)

posicaox1 = dados[:,0]
posicaox2 = dados[:,1]
posicaoy1 = dados[:,2]
posicaoy2 = dados[:,3]
tempo = linspace(0,len(posicaox1),len(posicaox1))




plot(posicaox1)
xlabel("Tempo [ns]")
ylabel("<x> [nm]")

show()

scatter(tempo,posicaox1)
show()
