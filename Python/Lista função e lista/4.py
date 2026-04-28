'''escreva um programa em python que exibe na tela o menor
elemento de uma lista de numeros dada'''

lista = [2, 4, 6, 8]

def menor_elemento(lista):
    posicao = 0
    menor = 0
    while posicao < len(lista):
        if lista[posicao] < lista[menor]:
            lista[menor] = lista[posicao]

        posicao += 1

    return lista[menor]

print(menor_elemento(lista))