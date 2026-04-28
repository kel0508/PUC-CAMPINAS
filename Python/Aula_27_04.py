''' escreva uma função em python que recebe uma lista e a retorna invertida
sub inversao(L) 
print(inversao[2,4,6])
[6,4,2]'''

def inversao(L):
    posInicio = 0 #Aqui criamos dois marcadores de posição (índices). O posInicio aponta para o primeiro item da lista (índice 0),
    posFinal = len(L)-1 #e o posFinal aponta para o último item (tamanho da lista menos 1).
    while posInicio < posFinal:
        backup = L[posInicio]
        L [posInicio] = L [posFinal]
        posInicio += 1
        posFinal -= 1
    return L

print(inversao[2, 4, 6])

''' escreva um programa em python com uma função que receba uma lista
e quando executdo os comando abaixo ele exiba o que se pede (disciplina com a maior nota
menor frequencia e a media das notas)
lista = [["APPC", 7.5, 0.75]; ["EPBD", 8.0, 0.85]; ["TEO", 5.0, 0.95]]
print (discMaiorNota (lista))
é para printar EPBD
print (discMenorFrequencia (lista))
é para printar APPC
print(mediaNotas (lista))
é para printar 6.83333...3'''

L = [["APPC", 7.5, 0.75], ["EPBD", 8.0, 0.85], ["TEO", 5.0, 0.95]]

def discMaiorNota(L):
    posMaiorNota = 0
    posicaoAtual = 1
    while posicaoAtual < len(L):
        if L[posicaoAtual][1] > L[posMaiorNota][1]:
            posMaiorNota = posicaoAtual 

        posicaoAtual += 1
    return L[posMaiorNota][0]

def discMenorFrequencia(L):
    posMenorFrequencia = 0
    posicaoAtual = 1
    while posicaoAtual < len(L):
        if L[posicaoAtual][2] < L[posMenorFrequencia][2]:
            posMenorFrequencia = posicaoAtual 

        posicaoAtual += 1
    return L[posMenorFrequencia][0]
    
def mediaNotas(L):
    soma = 0
    posicaoAtual = 0
    while posicaoAtual < len(L):
        soma += L[posicaoAtual][1]
    
        posicaoAtual += 1
    return soma / len(L)

print(discMaiorNota(L))      
print(discMenorFrequencia(L))
print(mediaNotas(L))
