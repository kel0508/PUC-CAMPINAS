create table FUNCIONARIO 
(
COD int(3) not null primary key,
NOME varchar(40) not null,
SALARIO decimal(9,2) not null,
CARGO varchar(30) not null,
CODDEPTO int(3) not null,
COMISSAO decimal(9,2)
);

 create table REQUISICAO 
(
CODREQ int(3) not null primary key,
CODFUNC int(3) not null,
DATAREQ date not null
);

insert into FUNCIONARIO (COD, NOME, SALARIO, CARGO, CODDEPTO, COMISSAO)
values (111, "joao", 1000.00, "Analista de Sistemas", 111, 100.00),
(222, "ana", 2000.00, "Vendedora", 222, 200.00),
(333, "luis", 3000.00, "Analista de Sistemas", 111, 300.00),
(144, "maria", 1500.00, "Analista de Sistemas", 111, 100.00),
(515, "angela", 900.00, "Vendedora", 222, 200.00),
(166, "luis ricardo", 5000.00, "Analista de Sistemas", 111, 300.00);

insert into REQUISICAO (CODREQ, CODFUNC, DATAREQ)
values (1, 111, "2004-05-01"),
(2, 222, "2004-05-15"),
(3, 111, "2004-05-10");

SELECT * from FUNCIONARIO;

SELECT * from FUNCIONARIO where SALARIO > 1000 order by COD, NOME;

select * from FUNCIONARIO where SALARIO >= 1000 AND SALARIO <= 2000 order by COD, NOME, SALARIO;

select *  from FUNCIONARIO where NOME LIKE "*na" or "*na*" or "na*";

select * from FUNCIONARIO where COD LIKE "1*" order by COD, NOME;

select * from FUNCIONARIO where SALARIO > 1000 order by COD;

select * from FUNCIONARIO where SALARIO > 1000 order by COD desc;

select * from FUNCIONARIO order by CODDEPTO, SALARIO desc;

select count(*) from FUNCIONARIO;