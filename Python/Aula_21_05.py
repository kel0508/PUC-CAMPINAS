#lista6 ex23 versao 1
def nomesAluMediaIgualValor (alu, res, valor):
    nomes = []

    for a in alu:
        soma = 0
        qtd = 0
        for r in res:
            if r[0]== a[0]:
                soma += r[4]
                qtd += 1
        
        media = soma/qtd
        if media == valor: 
            nomes.append(a[1])

    return nomes 

#lista6 ex23 versao 2
def nomesAluMediaIgualValor (alu, res, valor):
    nomes = []

    for pisicaoAlu in range(len(res)):
        soma = 0
        qtd = 0
        for posicaoRes in range(len(res)):
            if res[posicaoRes][0]== alu[pisicaoAlu][0]:
                soma += res[posicaoRes][4]
                qtd += 1
        media = soma/qtd
        if media == valor: nomes.append(alu[pisicaoAlu][1])

    return nomes

print(nomesAluMediaIgualValor(alu, res, 5.5))            
print(nomesAluMediaIgualValor(alu, res, 7.0))

#versao 1 soma
def soma(lista):
    resultado = 0
    posicao = 0
    for posicao in range (len(lista)):
        resultado += lista[posicao]
        posicao += 1
    
    return resultado

#versao 2 soma
def soma(lista):
    resultado = 0
    
    for numero in lista:
        resultado += numero
    
    return resultado