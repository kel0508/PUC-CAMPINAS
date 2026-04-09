import mysql.connector

def obtemConexao (servidor, usuario, senha, bd):
    if obtemConexao.conexao==None:
        obtemConexao.conexao = mysql.connector.connect(host=f"{servidor}",\
        user=f"{usuario}",\
        password=f"{senha}",\
        database=f"bd")

    return obtemConexao.conexao
obtemConexao.conexao=None

def insercao_de_aluno(ra, nome):
    comando=f"insert into Alunos (RA, Nome) values ({ra}, '{nome}')"
    conexao=obtemConexao("172.16.12.14", "XXXXX", "YYYYY", "XXXXX")
    cursor=conexao.cursor()
    cursor.execute(comando)
    conexao.commit()

def selecao_aluno (ra):
    comando=f"select * from Alunos where RA = {ra}"
    conexao=obtemConexao("172.16.12.14", "XXXXX", "YYYYY", "XXXXX")
    cursor=conexao.cursor()
    cursor.execute(comando)
    linhas=cursor.fatchall()
    if linhas ==[] : return None
    return linhas [0]