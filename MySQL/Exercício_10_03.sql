create database biblioteca;
use biblioteca;

create table AUTORES
(
id_autor integer not null primary key,
nome varchar(100) not null,
pais varchar(50) not null,
ano_nascimento integer not null
);

create table LIVROS
(
id_livro integer not null primary key,
titulo varchar(150) not null,
genero varchar(50) not null,
ano_publicacao integer not null,
id_autor integer not null
);

create table LEITORES
(
id_leitor integer not null primary key,
nome varchar(100) not null,
email varchar(100) not null,
telefone varchar(20) not null
);

create table EMPRESTIMOS
(
id_emprestimo integer not null primary key,
id_leitor integer not null,
id_livro integer not null,
data_emprestimo date not null,
data_devolucao date not null
);

alter table LIVROS 
add (quantidade_estoque integer not null);

alter table LEITORES 
add (data_cadastro date not null);

alter table LEITORES
modify telefone varchar(30);

alter table AUTORES
drop pais;

alter table LIVROS 
add (editora varchar(100) not null);

drop table EMPRESTIMOS;

drop table LIVROS;

drop table AUTORES;