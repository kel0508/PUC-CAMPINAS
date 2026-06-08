# =========================================================
# EXEMPLO DE ESTRUTURAS (para entender os exercícios)
# =========================================================

# lista de disciplinas (lista de dicionários)
# cada dicionário representa uma disciplina
# com nome, nota e frequência

# lista = [
#     {"disciplina": "Matemática", "nota": 8.5, "frequencia": 90}
# ]


# =========================================================
'''1 - Dada uma lista de registros (listona de dicionarinhos), escreva uma função em Python que 
resulta o nome da matéria com maior nota. No caso da lista vir vazia, retorne None.  
Assuma que não há mais de uma matéria com a mesma nota, sendo esta a maior de todas. '''
# =========================================================
def ex1_maior_nota(lista):
    if len(lista) == 0:  # verifica se lista está vazia
        return None

    maior = lista[0]  # assume o primeiro como maior

    for reg in lista:  # percorre todos os registros
        if reg["nota"] > maior["nota"]:  # compara notas
            maior = reg  # atualiza o maior

    return maior["disciplina"]  # retorna o nome


# =========================================================
'''2 - Dada uma lista de registros (listona de dicionarinhos), escreva uma função em Python que 
resulta o nome da matéria com menor frequência. No caso da lista vir vazia, retorne None.  
Assuma que não há mais de uma matéria com a mesma frequência, sendo esta a menor de 
todas.'''
# =========================================================
def ex2_menor_freq(lista):
    if len(lista) == 0:
        return None

    menor = lista[0]

    for reg in lista:
        if reg["frequencia"] < menor["frequencia"]:
            menor = reg

    return menor["disciplina"]


# =========================================================
'''3 - Dada uma lista de registros (listona de dicionarinhos), escreva uma função em Python que 
resulta a soma das notas de todas as disciplinas da lista. Retorne zero caso a lista venha 
vazia. '''
# =========================================================
def ex3_soma_notas(lista):
    soma = 0

    for reg in lista:
        soma += reg["nota"]  # acumula as notas

    return soma


# =========================================================
'''4 - Dada uma lista de registros (listona de dicionarinhos), escreva uma função em Python que 
resulta a média aritmética das notas de todas as disciplinas da lista. Retorne None caso a 
lista venha vazia. '''
# =========================================================
def ex4_media(lista):
    if len(lista) == 0:
        return None

    soma = 0

    for reg in lista:
        soma += reg["nota"]

    return soma / len(lista)


# =========================================================
'''5 - Dada uma lista de registros (listona de dicionarinhos), escreva uma função em Python que 
resulta a média geométrica das notas de todas as disciplinas da lista. Retorne None caso a 
lista venha vazia. '''
# =========================================================
def ex5_media_geom(lista):
    if len(lista) == 0:
        return None

    produto = 1

    for reg in lista:
        produto *= reg["nota"]  # multiplica todas as notas

    return produto ** (1 / len(lista))


# =========================================================
''' 6 - Dada uma lista de registros (listona de dicionarinhos), bem como uma lista de números 
reais positivos, escreva uma função em Python que resulta a média aritmética ponderada 
das notas de todas as disciplinas da primeira lista, ponderadas com os pesos da segunda 
lista. Retorne None caso alguma das listas vier vazia. Retorne None também quando as 
listas tiverem tamanhos diferentes. '''
# =========================================================
def ex6_media_pond(lista, pesos):
    if len(lista) == 0 or len(pesos) == 0:
        return None

    if len(lista) != len(pesos):
        return None

    soma = 0
    soma_pesos = 0

    for i in range(len(lista)):
        soma += lista[i]["nota"] * pesos[i]
        soma_pesos += pesos[i]

    return soma / soma_pesos


# =========================================================
'''7 - Dada uma lista de registros (listona de dicionarinhos), bem como uma lista de números 
reais positivos, escreva uma função em Python que resulta a média geométrica ponderada 
das notas de todas as disciplinas da primeira lista, ponderadas com os pesos da segunda 
lista. Retorne None caso alguma das listas vier vazia. Retorne None também quando as 
listas tiverem tamanhos diferentes. '''
# =========================================================
def ex7_media_geom_pond(lista, pesos):
    if len(lista) == 0 or len(pesos) == 0:
        return None

    if len(lista) != len(pesos):
        return None

    produto = 1
    soma_pesos = 0

    for i in range(len(lista)):
        produto *= lista[i]["nota"] ** pesos[i]
        soma_pesos += pesos[i]

    return produto ** (1 / soma_pesos)


# =========================================================
'''8 - Dada uma lista de registros (listona de dicionarinhos), escreva uma função em Python que 
resulta a True, caso os registros da lista estejam ordenados em ordem crescente de nota, ou 
então que resulta False, caso contrário. '''
# =========================================================
def ex8_ordem_crescente(lista):
    for i in range(len(lista) - 1):
        if lista[i]["nota"] > lista[i+1]["nota"]:
            return False

    return True


# =========================================================
'''9 - Dada uma lista de registros (listona de dicionarinhos), escreva uma função em Python que 
resulta a True, caso os registros da lista estejam ordenados em ordem decrescente de 
frequência, ou então que resulta False, caso contrário. '''
# =========================================================
def ex9_ordem_decrescente(lista):
    for i in range(len(lista) - 1):
        if lista[i]["frequencia"] < lista[i+1]["frequencia"]:
            return False

    return True


# =========================================================
'''10 -  Dados um registro (uma dicionarinho) e uma lista de registros (listona de dicionarinhos) 
com os registros ordenados em ordem crescente de nota, escreva um procedimento que 
inclui o registro fornecido no local apropriado da lista fornecida para que ela continue 
ordenada em ordem crescente de nota após a insersão. '''
# =========================================================
def ex10_inserir(lista, novo):
    i = 0

    while i < len(lista) and lista[i]["nota"] < novo["nota"]:
        i += 1

    lista.append(novo)

    j = len(lista) - 1

    while j > i:
        lista[j] = lista[j-1]
        j -= 1

    lista[i] = novo


# =========================================================
'''11 -  Dados um registro (uma dicionarinho) e uma lista de registros (listona de dicionarinhos) 
com os registros ordenados em ordem decrescente de frequência, escreva um 
procedimento que inclui o registro fornecido no local apropriado da lista fornecida para 
que ela continue ordenada em ordem decrescente de frequência após a insersão. '''
# =========================================================
def ex11_inserir(lista, novo):
    i = 0

    while i < len(lista) and lista[i]["frequencia"] > novo["frequencia"]:
        i += 1

    lista.append(novo)

    j = len(lista) - 1

    while j > i:
        lista[j] = lista[j-1]
        j -= 1

    lista[i] = novo


# =========================================================
'''12 -  Dada uma lista de registros (listona de dicionarinhos), escreva um procedimento em 
Python que ordena os registros em ordem crescente de nota. Para tanto, use o método da 
Bolha (Bubble Sort). '''
# =========================================================
def ex12_bubble(lista):
    for i in range(len(lista)):
        for j in range(len(lista)-1-i):
            if lista[j]["nota"] > lista[j+1]["nota"]:
                temp = lista[j]
                lista[j] = lista[j+1]
                lista[j+1] = temp


# =========================================================
'''13 -  Dada uma lista de registros (listona de dicionarinhos), escreva um procedimento em 
Python que ordena os registros em ordem decrescente de frequência. Para tanto, use o 
método da Bolha (Bubble Sort). '''
# =========================================================
def ex13_bubble(lista):
    for i in range(len(lista)):
        for j in range(len(lista)-1-i):
            if lista[j]["frequencia"] < lista[j+1]["frequencia"]:
                temp = lista[j]
                lista[j] = lista[j+1]
                lista[j+1] = temp


# =========================================================
'''14 -  Dada uma lista de registros (listona de dicionarinhos), escreva um procedimento em 
Python que ordena os registros em ordem crescente de nota. Para tanto, use o método da 
Inserção Direta (Insertion Sort). '''
# =========================================================
def ex14_insertion(lista):
    for i in range(1, len(lista)):
        atual = lista[i]
        j = i - 1

        while j >= 0 and lista[j]["nota"] > atual["nota"]:
            lista[j+1] = lista[j]
            j -= 1

        lista[j+1] = atual


# =========================================================
'''15 - Dada uma lista de registros (listona de dicionarinhos), escreva um procedimento em 
Python que ordena os registros em ordem decrescente de frequência. Para tanto, use o 
método da Inserção Direta (Insertion Sort). '''
# =========================================================
def ex15_insertion(lista):
    for i in range(1, len(lista)):
        atual = lista[i]
        j = i - 1

        while j >= 0 and lista[j]["frequencia"] < atual["frequencia"]:
            lista[j+1] = lista[j]
            j -= 1

        lista[j+1] = atual


# =========================================================
'''16 -  Dada uma lista de registros (listona de dicionarinhos), escreva um procedimento em 
Python que ordena os registros em ordem crescente de nota. Para tanto, use o método da 
Seleção Direta (Selection Sort). '''
# =========================================================
def ex16_selection(lista):
    for i in range(len(lista)):
        menor = i

        for j in range(i+1, len(lista)):
            if lista[j]["nota"] < lista[menor]["nota"]:
                menor = j

        temp = lista[i]
        lista[i] = lista[menor]
        lista[menor] = temp


# =========================================================
'''17 -  Dada uma lista de registros (listona de dicionarinhos), escreva um procedimento em 
Python que ordena os registros em ordem decrescente de frequência. Para tanto, use o 
método da Seleção Direta (Selection Sort). '''
# =========================================================
def ex17_selection(lista):
    for i in range(len(lista)):
        maior = i

        for j in range(i+1, len(lista)):
            if lista[j]["frequencia"] > lista[maior]["frequencia"]:
                maior = j

        temp = lista[i]
        lista[i] = lista[maior]
        lista[maior] = temp


# =========================================================
''' 18 -Dada uma lista de registros (listona de dicionarinhos), escreva um procedimento em 
Python que retira da lista fornecida o registro que contiver o nome da disciplina igual a um 
nome dado. Não faça nada, caso não exista um registro com o nome dado. '''
# =========================================================
def ex18_remover(lista, nome):
    i = 0

    while i < len(lista):
        if lista[i]["disciplina"] == nome:
            for j in range(i, len(lista)-1):
                lista[j] = lista[j+1]

            lista.pop()
            return

        i += 1


# =========================================================
''' 19 - Dada uma lista de registros (listona de dicionarinhos) escreva um procedimento em 
Python que remove da lista fornecida o registro que contiver a menor nota de todas. Não 
faça nada, caso a lista venha vazia.  Assuma que não há mais de uma matéria com a 
mesma nota, sendo esta a menor de todas. '''
# =========================================================
def ex19_remover(lista):
    if len(lista) == 0:
        return

    menor = 0

    for i in range(1, len(lista)):
        if lista[i]["nota"] < lista[menor]["nota"]:
            menor = i

    for j in range(menor, len(lista)-1):
        lista[j] = lista[j+1]

    lista.pop()


# =========================================================
'''20 -  Dada uma lista de registros (listona de dicionarinhos) escreva um procedimento em 
Python que remove da lista fornecida o registro que contiver a maior frequência de todas. 
Não faça nada, caso a lista venha vazia.  Assuma que não há mais de uma matéria com a 
mesma frequência, sendo esta a maior de todas.'''
# =========================================================
def ex20_remover(lista):
    if len(lista) == 0:
        return

    maior = 0

    for i in range(1, len(lista)):
        if lista[i]["frequencia"] > lista[maior]["frequencia"]:
            maior = i

    for j in range(maior, len(lista)-1):
        lista[j] = lista[j+1]

    lista.pop()


# =========================================================
# PARTE FINAL - LISTAS RELACIONADAS (21 ao 27)
# =========================================================


''' 21 - Dadas 3 listas de registros (listonas de dicionarinhos), uma de cada tipo, escreva uma 
função em Python que resulta o nome do aluno que teve a maior nota. Retorne None em 
caso de impossibilidade de produzir o resultado.  Assuma que não há mais de uma matéria 
com a mesma nota, sendo esta a maior de todas. Pode-se deixar de colocar como 
parâmetro a(s) lista(s) que lhe parecer(em) sem utilidade no exercício. '''

def ex21(alunos, resultados):
    maior = resultados[0]

    for r in resultados:
        if r[4] > maior[4]:
            maior = r

    for a in alunos:
        if a[0] == maior[0]:
            return a[1]


''' 22 -  Dadas 3 listas de registros (listonas de dicionarinhos), uma de cada tipo, escreva uma 
função em Python que resulta o nome da disciplina que teve a menor frequência. Retorne 
None em caso de impossibilidade de produzir o resultado.  Assuma que não há mais de 
uma matéria com a mesma frequência, sendo esta a menor de todas. Pode-se deixar de 
colocar como parâmetro a(s) lista(s) que lhe parecer(em) sem utilidade no exercício. '''

def ex22(disciplinas, resultados):
    menor = resultados[0]

    for r in resultados:
        if r[5] < menor[5]:
            menor = r

    for d in disciplinas:
        if d[0] == menor[1]:
            return d[1]


'''23 - Dadas 3 listas de registros (listonas de dicionarinhos), uma de cada tipo, escreva uma 
função em Python que resulta uma lista com o nome de todos os alunos, cuja média 
aritmética das notas seja igual a um valor também dado. Retorne [ ] em caso de 
impossibilidade de produzir o resultado. Pode-se deixar de colocar como parâmetro a(s) 
lista(s) que lhe parecer(em) sem utilidade no exercício. '''
def ex23(alunos, resultados, valor):
    resposta = []

    for a in alunos:
        soma = 0
        cont = 0

        for r in resultados:
            if r[0] == a[0]:
                soma += r[4]
                cont += 1

        if cont > 0 and soma / cont == valor:
            resposta.append(a[1])

    return resposta


''' 24 -  Dadas 3 listas de regi'stros (listonas de dicionarinhos), uma de cada tipo, escreva uma 
função em Python que resulta quantos dígitos pares tem nos RAs dos alunos cuja média 
geométrica das notas seja igual a um valor também dado. Retorne None em caso de 
impossibilidade de produzir o resultado. Pode-se deixar de colocar como parâmetro a(s) 
lista(s) que lhe parecer(em) sem utilidade no exercício.'''
def ex24(alunos, resultados, valor):
    total = 0

    for a in alunos:
        produto = 1
        cont = 0

        for r in resultados:
            if r[0] == a[0]:
                produto *= r[4]
                cont += 1

        if cont > 0:
            media = produto ** (1/cont)

            if media == valor:
                ra = a[0]

                while ra > 0:
                    if (ra % 10) % 2 == 0:
                        total += 1
                    ra //= 10

    return total


''' 25 -  Dadas 3 listas de registros (listonas de dicionarinhos), uma de cada tipo, escreva uma 
função em Python que resulta uma lista com o nome dos alunos que reprovaram em 
alguma disciplina. Retorne [ ] em caso de impossibilidade de produzir o resultado. Pode
se deixar de colocar como parâmetro a(s) lista(s) que lhe parecer(em) sem utilidade no 
exercício.'''
def ex25(alunos, resultados):
    resp = []

    for a in alunos:
        reprovou = False

        for r in resultados:
            if r[0] == a[0]:
                if r[4] < 5 or r[5] < 75:
                    reprovou = True

        if reprovou:
            resp.append(a[1])

    return resp


'''26 - Dadas 3 listas de registros (listonas de dicionarinhos), uma de cada tipo, escreva uma 
função em Python que resulta uma lista com o nome das disciplinas que nunca reprovaram 
um aluno. Retorne [ ] em caso de impossibilidade de produzir o resultado. Pode-se deixar 
de colocar como parâmetro a(s) lista(s) que lhe parecer(em) sem utilidade no exercício. '''
def ex26(disciplinas, resultados):
    resp = []

    for d in disciplinas:
        reprovou = False

        for r in resultados:
            if r[1] == d[0]:
                if r[4] < 5 or r[5] < 75:
                    reprovou = True

        if not reprovou:
            resp.append(d[1])

    return resp


'''27 - Dadas 3 listas de registros (listonas de dicionarinhos), uma de cada tipo, escreva uma 
função em Python que resulta uma lista com o e-mail dos alunos que reprovaram em todas 
as disciplinas que cursou. Retorne [ ] em caso de impossibilidade de produzir o resultado.'''
def ex27(alunos, resultados):
    resp = []

    for a in alunos:
        total = 0
        reprovadas = 0

        for r in resultados:
            if r[0] == a[0]:
                total += 1
                if r[4] < 5 or r[5] < 75:
                    reprovadas += 1

        if total > 0 and total == reprovadas:
            resp.append(a[3])

    return resp
