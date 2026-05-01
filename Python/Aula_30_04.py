#disciplina = [["APPC", 8.5, 0.90], ["EPBD", 9.5, 0.95], ["TEO", 7.5, 0.77]]

aluno = [[26262626, "João", 1919191919, "joão@puccampinas.edu.br"], [25252525, "Ana", 1181818188, "ana@puccampinas.edu.br"]]

disciplina = [[123, "APPC", 4], [234, "EPBD", 2]]

resultado = [[26262626, 123, 1, 2026, 7.5, 0.85], [26262626, 234, 1, 2026, 6.5, 0.75],
             [25252525, 134, 1, 2025, 3.0, 0.80], [25252525, 123, 1, 2026, 7.0, 0.85]]

def nomeAunoMaiorNota (aluno, resultado):
    resMaiorNota = resultado[0]
    posicao = 1
    while posicao < len(aluno):
        if resultado[posicao][4] > resMaiorNota[4]:
            resMaiorNota = resultado[posicao]
        posicao += 1

    raAlunoMaiorNota = resMaiorNota[0]
    posicao = 0

    while posicao < len(aluno):
        if raAlunoMaiorNota == aluno[posicao][0]:
            return aluno[posicao][1]
        posicao += 1

print (nomeAunoMaiorNota(aluno, resultado))

def nomeMenorFrequencia (disciplina, resultado):
    resMenorFrequencia = resultado[0]
    posicao = 1
    while posicao < len(resultado):
        if resultado[posicao][5] < resMenorFrequencia[5]:
            resMenorFrequencia = resultado[posicao]
        posicao += 1

    codDisciplina = resMenorFrequencia[1]
    posicao = 0

    while posicao < len(disciplina):
        if codDisciplina == disciplina[posicao][0]:
            return disciplina[posicao][1]
        posicao += 1

print(nomeMenorFrequencia(disciplina, resultado))

def mediaIgual(aluno, resultado,nota):
    resMedia = resultado[0]
    posicao = 0
    listaMediaIgual = []
    valorDado = float(input("Digite uma um valor para uma média: "))
    while posicao < len(aluno):
        if resultado[posicao][4] == valorDado:
            listaMediaIgual.append(resultado[posicao][1])
        posicao += 1
