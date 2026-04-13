print("PROGRAMA DE PIRÂMIDE DE BOLINHA")
programa = True
while programa:
    try:
        numero = int(input("Digite um número maior ou igual a 2: "))
    except ValueError:
        print("você deve digitar um número inteiro")
    else:
        if numero < 2:
            print("O número deve ser maior ou igual a 2!")

        else:
            i = 1
            while i <= numero:
                espaco = " " * (numero - i)

                if i == 1:
                    #topo da piramide
                    print(espaco + "O")
                elif i == numero:
                    #base toda preenchida
                    print(espaco + "O" * (2 * i - 1))
                else:
                    #meio(contorno)
                    meio= " " * (2 * i - 3)
                    print(espaco + "O" + meio + "O")

                i += 1
                
                if i > numero:
                    programa = False
