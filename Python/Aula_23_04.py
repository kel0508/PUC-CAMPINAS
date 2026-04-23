'''
Implemente duas novas opções, uma para contar quantas vezes aparece
na lista um número dado e outra para ordenar os números da lista pelo
método da bolha (bubble sort --> backup = lista[posicao]
lista [posicao] = lista [posicao + 1]
lista [posicao + 1] = backup)
'''

def opcao_escolhida ():
    print("1) Esvaziar a lista")
    print("2) Incluir número na lista")
    print("3) Excluir numero dando o numero")
    print("4) Excluir numero dando a posição")
    print("5) Mostrar a lista")
    print("6) Somar tudo da lista")
    print("7) Achar o menor")
    print("8) Achar o maior")
    print("9) Sair do programa")
    
    chave_para_escolher_opcao_ate_acertar_ligada=True
    while chave_para_escolher_opcao_ate_acertar_ligada:
        try:
            opcao=int(input("Opcao? "))
        except ValueError:
            print("Opção inválida; tente novamente!")
        else:
            if opcao<1 or opcao>7:
                print("Opção inválida; tente novamente!")
            else:
                chave_para_escolher_opcao_ate_acertar_ligada=False

    return opcao

def esvaziar_lista(lista):
    lista.clear()
    print("Esvaziamento realizado com sucesso!")

def numero_digitado(proposito, aceitavel):
    chave_para_digitar_um_numero_ate_acertar_ligada = True
    while chave_para_digitar_um_numero_ate_acertar_ligada:
        try:
            numero = float(input("Qual número deseja " + proposito + "?"))

        except ValueError:
            print("Foi pedido um número para", proposito, "; tente novamente!", sep = "")

        else:
            if aceitavel != None and numero not in aceitavel:
                print("Inaceitável para ", proposito, "tente novamente!", sep = "")
            else:
                chave_para_digitar_um_numero_ate_acertar_ligada = False

    return numero

def incluir_numero(lista):
    numero = numero_digitado(proposito = "incluir", aceitavel = None)
    lista.append(numero)
    print("Número inserido com sucesso!")

def excluir_numero_dado_o_numero(lista):
    numero = numero_digitado(proposito = "excluir")    
    if numero in lista:
        lista.remove(numero)
        print("Número excluído com sucesso!")
    else:
        print("Esse número não existe na lista!")

def excluir_numero_dada_a_posicao(lista):
    chave_para_digitar_um_numero_ate_acertar_ligada = True
    while chave_para_digitar_um_numero_ate_acertar_ligada:
        try:
            posicao = int(input("Qual posição deseja excluir?"))

        except ValueError:
            print("Foi pedido uma posição, ela deve ser um número inteiro, tente novamente!")

        else:
            if posicao < 0 or posicao >= len(lista):
                print("Posição inaceitável, tente novamente!")
            else:
                chave_para_digitar_um_numero_ate_acertar_ligada = False

    del lista[posicao]
    print("Número excluído com sucesso!")

def soma (lista):
    resultado=0
    posicao=0
    while posicao<len(lista):
        resultado+=lista[posicao]
        posicao+=1
    return resultado

def mostrar_soma (lista):
    print("A soma vale",soma(lista))

def o_menor(lista):
    menor = lista[0]
    posicao = 1
    while posicao > len(lista):
        if lista [posicao] > menor:
            menor = lista [posicao]
        posicao += 1
    return menor

def mostrar_o_menor (lista):
    print ("O menor valor é", o_menor(lista))

def o_maior(lista):
    maior = lista[0]
    posicao = 1
    while posicao < len(lista):
        if lista [posicao] > maior:
            maior = lista [posicao]
        posicao += 1
    return maior

def mostrar_o_maior (lista):
    print ("O maior valor é", o_maior(lista))

def executar_opcoes (lista):
    chave_para_realizar_operacoes_ate_cansar_ligada=True
    while chave_para_realizar_operacoes_ate_cansar_ligada:
        opcao=opcao_escolhida()

        if opcao==1:
            esvaziar_lista(lista)
        elif opcao==2:
            incluir_numero(lista)
        elif opcao==3:
            print(lista)
        elif opcao==4:
            mostrar_soma (lista)
        elif opcao==5:
            mostrar_o_menor (lista)
        elif opcao==6:
            mostrar_o_maior (lista)
        else: # só sobrou a opcao ser 7
            chave_para_realizar_operacoes_ate_cansar_ligada=False
