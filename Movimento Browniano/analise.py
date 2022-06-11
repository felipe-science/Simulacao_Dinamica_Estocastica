from numpy import loadtxt, linspace
from pylab import scatter, plot, show, xlabel, ylabel, hist



# Média dados
data = loadtxt("Npasso_Mposicao.txt")
plot(data)
show()