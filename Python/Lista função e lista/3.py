'''escreva um programa em python que exibe na tela o maior 
elemento de uma lista dada'''

lista = [2, 4, 6, 8]

def maior_elemento(lista):
    posicao = 0
    maior = 0
    while posicao < len(lista):
        if lista[posicao] > maior:
            maior = lista[posicao]

        posicao += 1

    return maior

print(maior_elemento(lista))