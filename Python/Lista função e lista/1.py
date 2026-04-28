''' escreva um programa em python que exibe na tela a soma dos elementos de 
uma lista de numeros dada'''

lista = [2, 4, 6, 8]

def soma_elementos(lista):
    posicao = 0 
    soma = 0
    while posicao < len(lista):
        soma += lista[posicao]
        posicao += 1
       
    return soma

print(soma_elementos(lista))