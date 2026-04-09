#cadastro de alunos#
create table ALUNOS
(
id_aluno integer not null primary key,
nome varchar(100) not null,
idade integer not null,
cidade varchar(50)
);

insert into ALUNOS (id_aluno, nome, idade, cidade)
values (1, "Raquel", 18, "Paulínia");

insert into ALUNOS (id_aluno, nome, idade, cidade)
values (2, "Gustavo", 20, "Sumaré");

insert into ALUNOS (id_aluno, nome, idade, cidade)
values (3, "Bruna", 17, "Campinas");

update ALUNOS set cidade = "Valinhos" where id_aluno = 3;

delete from ALUNOS where idade < 18 and id_aluno = 3;

# cadastro de produtos #

create table PRODUTOS 
(
id_produto integer not null auto_increment primary key,
nome_produto varchar(100) not null,
preco decimal(3,1) not null,
estoque integer  
);

insert into PRODUTOS (id_produto, nome_produto, preco, estoque)
values (DEFAULT, "Livro", 50.9, 50);

insert into PRODUTOS (id_produto, nome_produto, preco, estoque)
values (DEFAULT, "Bolsa", 90.5, 10);

insert into PRODUTOS (id_produto, nome_produto, preco, estoque)
values (DEFAULT, "Colar", 85.9, 0);

insert into PRODUTOS (id_produto, nome_produto, preco, estoque)
values (DEFAULT, "Pasta de Dente", 09.9, 20);

update PRODUTOS set preco = preco + 1.1 where id_produto = 4;

delete from PRODUTOS where estoque = 0 and id_produto = 3;

#cadastro de funcionarios

create table FUNCIONARIOS
(
id_funcionario integer not null auto_increment primary key,
nome varchar(100) not null,
cargo varchar(50) not null,
salario decimal(5,1) not null
);

insert into FUNCIONARIOS (id_funcionario, nome, cargo, salario)
values (DEFAULT, "gu", "engenheiro", 9900.5),
(DEFAULT, "raquel", "analista", 7500.5),
(DEFAULT, "rafa", "ceo", 6200.0),
(DEFAULT, "bruna", "tecnica de manutenção", 6900.7),
(DEFAULT, "vini", "designer", 1900.5);

update FUNCIONARIOS set salario = salario + 500 where cargo = "analista" and id_funcionario = 2;

delete from FUNCIONARIOS where salario < 2000.0 and id_funcionario = 5;

#cadastro de livros

create table LIVROS
(
id_livro int not null auto_increment primary key,
titulo varchar(150) not null,
autor varchar(100) not null,
ano_publicacao int not null
);

insert into LIVROS (id_livro, titulo, autor, ano_publicacao)
values (DEFAULT, "quarta asa", "rebecca yarros", 2023),
(DEFAULT, "acotar", "sarah j maas", 2016),
(DEFAULT, "o conde de monte cristo", "alexandre dumas", 1844),
(DEFAULT, "binding 13", "chloe walsh", 2018);

update LIVROS set ano_publicacao = 1846 where id_livro = 3;

delete from LIVROS where ano_publicacao < 2000 and id_livro = 3;

#cadastro clientes 

create table CLIENTES
(
id_cliente int not null auto_increment primary key,
nome varchar(100) not null,
email varchar(100) not null,
telefone varchar(20) not null
);

insert into CLIENTES (id_cliente, nome, email, telefone)
values (DEFAULT, "ana", "ana@gmail.com", "(19)988334466"),
	   (DEFAULT, "maria", "maria@gmail.com", "(19)648528459"),
	   (DEFAULT, "julia", "julia@gmail.com", "(19)184469565"),
	   (DEFAULT, "bruna", "bruna@gmail.com", "(19)587453486"),
	   (DEFAULT, "rafa", "rafa@email.com", "(19)976483452");

update CLIENTES set telefone = "19648516264" where id_cliente = 3;

delete from CLIENTES where email like "@email.com" and id_cliente = 5;