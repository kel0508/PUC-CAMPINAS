# =========================================
''' 1 - Escreva uma função em Python que resulta uma cadeia de caracteres com a conversão de
eventuais caracteres invisíveis que compõem uma cadeia de caracteres dada em seqüências
de \, e.g., <TAB> pelo caractere \ seguindo pelo caractere t. As sequências de \ que existem
são: \’, \”, \a, \b, \f, \n, \r, \t, \v. Faça um programa em Python para testar sua função'''
# =========================================
def ex1_converter_invisiveis(texto):
    resultado = ""  # string que vai guardar o resultado final

    for c in texto:  # percorre cada caractere do texto
        if c == "\n":  # se for quebra de linha
            resultado += "\\n"  # adiciona o texto \n
        elif c == "\t":  # se for TAB
            resultado += "\\t"
        else:
            resultado += c  # mantém o caractere normal

    return resultado


# =========================================
''' 2 - Escreva uma função em Python que resulta uma cadeia de caracteres com a a cadeia de
caracteres fornecida, eliminados os espaços em branco supérfluos, i.e., que retire deela os
espaços em branco iniciais e finais, e que substitua nela seqüências de dois ou mais
espaços em branco por apenas um espaço em branco. Faça um programa em Python para
testar sua função.'''
# =========================================
def ex2_limpar_espacos(texto):
    resultado = ""
    i = 0

    # remove espaços do início
    while i < len(texto) and texto[i] == " ":
        i += 1

    espaco = False  # controla se já adicionou espaço

    while i < len(texto):
        if texto[i] == " ":
            if not espaco:  # só adiciona 1 espaço
                resultado += " "
                espaco = True
        else:
            resultado += texto[i]
            espaco = False
        i += 1

    return resultado


# =========================================
'''3 - Escreva uma função em Python que resulta uma cadeia de caracteres com a manipulação
de uma cadeia de caractere dada e expanda subcadeias da forma "<Char0>-<Charn>" em
subcadeias da forma "<Char0><Char1> ... <Charn>". Assim, a cadeia de caracteres "qweAEpio0-4mbn" seria expandida na cadeia "qweABCDEpio01234mbn". Faça um programa em
Python para testar sua função.'''
# =========================================
def ex3_expandir(texto):
    resultado = ""
    i = 0

    while i < len(texto):
        # verifica padrão tipo A-D
        if i + 2 < len(texto) and texto[i+1] == "-":
            inicio = texto[i]
            fim = texto[i+2]

            # percorre intervalo usando ASCII
            for c in range(ord(inicio), ord(fim) + 1):
                resultado += chr(c)

            i += 3  # pula o intervalo
        else:
            resultado += texto[i]
            i += 1

    return resultado


# =========================================
'''4 - Escreva uma função em Python que resulta uma cadeia de caracteres com a conversão de
letras minúsculas, que eventualmente componham uma cadeia de caracteres fornecida, em
letras maiúsculas. Faça um programa em Python para testar sua função.'''
# =========================================
def ex4_maiusculas(texto):
    resultado = ""

    for c in texto:
        if 'a' <= c <= 'z':  # verifica se é minúscula
            resultado += chr(ord(c) - 32)  # converte para maiúscula
        else:
            resultado += c

    return resultado


# =========================================
'''5 - Escreva em Python uma função que resulta o inverso de uma cadeia de caracteres dada.
Faça um programa em Python para testar sua função.'''
# =========================================
def ex5_inverter(texto):
    resultado = ""

    for i in range(len(texto)-1, -1, -1):  # percorre de trás pra frente
        resultado += texto[i]

    return resultado


# =========================================
# 6 - Inverter recursivo
# =========================================
def ex6_inverter_rec(texto):
    if texto == "":  # caso base
        return ""
    return texto[-1] + ex6_inverter_rec(texto[:-1])  # chama recursão


# =========================================
# 7 - Verificar palíndromo
# =========================================
def ex7_palindromo(texto):
    i = 0
    j = len(texto) - 1

    while i < j:
        if texto[i] != texto[j]:
            return 0
        i += 1
        j -= 1

    return 1


# =========================================
# 8 - TAB → 8 espaços
# =========================================
def ex8_tab_para_espaco(texto):
    resultado = ""

    for c in texto:
        if c == "\t":
            resultado += "        "  # 8 espaços
        else:
            resultado += c

    return resultado


# =========================================
# 9 - 8 espaços → TAB
# =========================================
def ex9_espaco_para_tab(texto):
    resultado = ""
    i = 0

    while i < len(texto):
        if texto[i:i+8] == "        ":
            resultado += "\t"
            i += 8
        else:
            resultado += texto[i]
            i += 1

    return resultado


# =========================================
# 10 - Posição esquerda de um caractere
# =========================================
def ex10_pos_esq(texto, alvo):
    for i in range(len(texto)):
        if texto[i] == alvo:
            return i
    return -1


# =========================================
# 11 - Posição direita de um caractere
# =========================================
def ex11_pos_dir(texto, alvo):
    pos = -1

    for i in range(len(texto)):
        if texto[i] == alvo:
            pos = i

    return pos


# =========================================
# 12 - Contar caractere
# =========================================
def ex12_contar(texto, alvo):
    contador = 0

    for c in texto:
        if c == alvo:
            contador += 1

    return contador


# =========================================
# 13 - Primeira posição de um conjunto
# =========================================
def ex13_pos_conjunto(texto, conjunto):
    for i in range(len(texto)):
        for c in conjunto:
            if texto[i] == c:
                return i
    return -1


# =========================================
# 14 - Última posição de um conjunto
# =========================================
def ex14_pos_dir_conjunto(texto, conjunto):
    pos = -1

    for i in range(len(texto)):
        for c in conjunto:
            if texto[i] == c:
                pos = i

    return pos


# =========================================
# 15 - Contar caracteres do conjunto
# =========================================
def ex15_contar_conjunto(texto, conjunto):
    contador = 0

    for t in texto:
        for c in conjunto:
            if t == c:
                contador += 1
                break

    return contador


# =========================================
# 16 - Primeira substring
# =========================================
def ex16_sub_esq(texto, sub):
    for i in range(len(texto) - len(sub) + 1):
        achou = True

        for j in range(len(sub)):
            if texto[i+j] != sub[j]:
                achou = False
                break

        if achou:
            return i

    return -1


# =========================================
# 17 - Última substring
# =========================================
def ex17_sub_dir(texto, sub):
    pos = -1

    for i in range(len(texto) - len(sub) + 1):
        achou = True

        for j in range(len(sub)):
            if texto[i+j] != sub[j]:
                achou = False
                break

        if achou:
            pos = i

    return pos


# =========================================
# 18 - Contar substring
# =========================================
def ex18_contar_sub(texto, sub):
    contador = 0

    for i in range(len(texto) - len(sub) + 1):
        achou = True

        for j in range(len(sub)):
            if texto[i+j] != sub[j]:
                achou = False
                break

        if achou:
            contador += 1

    return contador


# =========================================
# 19 - Remover caractere
# =========================================
def ex19_remover(texto, alvo):
    resultado = ""

    for c in texto:
        if c != alvo:
            resultado += c

    return resultado


# =========================================
# 20 - Remover conjunto
# =========================================
def ex20_remover_conjunto(texto, conjunto):
    resultado = ""

    for t in texto:
        remover = False

        for c in conjunto:
            if t == c:
                remover = True
                break

        if not remover:
            resultado += t

    return resultado


# =========================================
# 21 - Remover substring
# =========================================
def ex21_remover_sub(texto, sub):
    resultado = ""
    i = 0

    while i < len(texto):
        achou = True

        if i + len(sub) <= len(texto):
            for j in range(len(sub)):
                if texto[i+j] != sub[j]:
                    achou = False
                    break
        else:
            achou = False

        if achou:
            i += len(sub)
        else:
            resultado += texto[i]
            i += 1

    return resultado


# =========================================
# 22 - Binário → decimal
# =========================================
def ex22_bin_para_dec(binario):
    resultado = 0
    potencia = 1

    for i in range(len(binario)-1, -1, -1):
        if binario[i] == '1':
            resultado += potencia
        potencia *= 2

    return resultado


# =========================================
# 23 - Decimal → binário
# =========================================
def ex23_dec_para_bin(numero):
    if numero == 0:
        return "0"

    resultado = ""

    while numero > 0:
        resultado = str(numero % 2) + resultado
        numero //= 2

    return resultado


# =========================================
# 24 - Octal → decimal
# =========================================
def ex24_oct_para_dec(octal):
    resultado = 0
    potencia = 1

    for i in range(len(octal)-1, -1, -1):
        resultado += (ord(octal[i]) - 48) * potencia
        potencia *= 8

    return resultado


# =========================================
# 25 - Decimal → octal
# =========================================
def ex25_dec_para_oct(numero):
    if numero == 0:
        return "0"

    resultado = ""

    while numero > 0:
        resultado = str(numero % 8) + resultado
        numero //= 8

    return resultado


# =========================================
# 26 - String → decimal
# =========================================
def ex26_string_para_dec(texto):
    resultado = 0

    for c in texto:
        resultado = resultado * 10 + (ord(c) - 48)

    return resultado


# =========================================
# 27 - Decimal → string
# =========================================
def ex27_dec_para_string(numero):
    if numero == 0:
        return "0"

    resultado = ""

    while numero > 0:
        resultado = chr((numero % 10) + 48) + resultado
        numero //= 10

    return resultado


# =========================================
# 28 - Hex → decimal
# =========================================
def ex28_hex_para_dec(hexadecimal):
    resultado = 0
    potencia = 1

    for i in range(len(hexadecimal)-1, -1, -1):
        c = hexadecimal[i]

        if '0' <= c <= '9':
            valor = ord(c) - 48
        else:
            valor = ord(c) - 55

        resultado += valor * potencia
        potencia *= 16

    return resultado


# =========================================
# 29 - Decimal → hex
# =========================================
def ex29_dec_para_hex(numero):
    if numero == 0:
        return "0"

    resultado = ""

    while numero > 0:
        resto = numero % 16

        if resto < 10:
            resultado = chr(resto + 48) + resultado
        else:
            resultado = chr(resto + 55) + resultado

        numero //= 16

    return resultado


# =========================================
# 30 - Base qualquer → decimal
# =========================================
def ex30_base_para_dec(texto, base):
    resultado = 0
    potencia = 1

    for i in range(len(texto)-1, -1, -1):
        c = texto[i]

        if '0' <= c <= '9':
            valor = ord(c) - 48
        else:
            valor = ord(c) - 55

        resultado += valor * potencia
        potencia *= base

    return resultado


# =========================================
# 31 - Decimal → base qualquer
# =========================================
def ex31_dec_para_base(numero, base):
    if numero == 0:
        return "0"

    resultado = ""

    while numero > 0:
        resto = numero % base

        if resto < 10:
            resultado = chr(resto + 48) + resultado
        else:
            resultado = chr(resto + 55) + resultado

        numero //= base

    return resultado


# =========================================
# 32 - String → inteiro (com sinal)
# =========================================
def ex32_string_para_int(texto):
    sinal = 1
    i = 0

    if texto[0] == '-':
        sinal = -1
        i = 1

    resultado = 0

    while i < len(texto):
        resultado = resultado * 10 + (ord(texto[i]) - 48)
        i += 1

    return resultado * sinal


# =========================================
# 33 - Inteiro → string
# =========================================
def ex33_int_para_string(numero):
    if numero == 0:
        return "0"

    sinal = ""
    if numero < 0:
        sinal = "-"
        numero = -numero

    resultado = ""

    while numero > 0:
        resultado = chr((numero % 10) + 48) + resultado
        numero //= 10

    return sinal + resultado


# =========================================
# 34 - String → real (com notação científica)
# =========================================
def ex34_string_para_real(texto):
    i = 0
    sinal = 1

    if texto[i] == '-':
        sinal = -1
        i += 1

    inteiro = 0
    while i < len(texto) and texto[i] not in ".e":
        inteiro = inteiro * 10 + (ord(texto[i]) - 48)
        i += 1

    decimal = 0
    divisor = 1

    if i < len(texto) and texto[i] == '.':
        i += 1
        while i < len(texto) and texto[i] != 'e':
            decimal = decimal * 10 + (ord(texto[i]) - 48)
            divisor *= 10
            i += 1

    numero = inteiro + decimal / divisor

    if i < len(texto) and texto[i] == 'e':
        i += 1

        sinal_exp = 1
        if texto[i] == '-':
            sinal_exp = -1
            i += 1

        expoente = 0
        while i < len(texto):
            expoente = expoente * 10 + (ord(texto[i]) - 48)
            i += 1

        expoente *= sinal_exp

        if expoente > 0:
            for _ in range(expoente):
                numero *= 10
        else:
            for _ in range(-expoente):
                numero /= 10

    return numero * sinal


# =========================================
# 35 - Real → string (notação científica simples)
# =========================================
def ex35_real_para_string(numero):
    if numero == 0:
        return "0"

    sinal = ""
    if numero < 0:
        sinal = "-"
        numero = -numero

    expoente = 0

    while numero >= 10:
        numero /= 10
        expoente += 1

    while numero < 1:
        numero *= 10
        expoente -= 1

    inteiro = int(numero)
    resto = numero - inteiro

    resultado = chr(inteiro + 48) + "."

    for _ in range(6):
        resto *= 10
        digito = int(resto)
        resultado += chr(digito + 48)
        resto -= digito

    if expoente != 0:
        resultado += "e"
        if expoente > 0:
            resultado += "+"
        resultado += ex33_int_para_string(expoente)

    return sinal + resultado