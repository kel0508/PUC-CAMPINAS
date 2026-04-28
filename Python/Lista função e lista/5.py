'''escreva um programa em python que exibe na tela quantos elementos
de uma lista de numeros dada estão abaixo da média dos elementos da mesma lista'''

lista = [2, 4, 6, 8, 10]

def abaixo_media (lista):
    posicao = 0 
    soma = 0
    while posicao < len(lista):
        soma += lista[posicao]
        media = soma / len(lista)

        menor_media = []
        if lista[posicao] < media:
            menor_media.append(lista[posicao])

    return menor_media

print(abaixo_media(lista))