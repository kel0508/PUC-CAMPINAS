#QUESTÃO 1
create table CLIENTES 
(
Cod_Cli varchar(4), 
Nome_Cli varchar(20), 
Cidade varchar(15),
Limite_Credito decimal(10,2)
);

alter table CLIENTES add constraint pk_clientes primary key (Cod_Cli);

insert into CLIENTES values ('0101', 'José C. Santos', 'Campinas', 10500.00);
insert into CLIENTES values ('0102', 'Maria Oliver', 'Campinas', 7500.00);
insert into CLIENTES values ('0103', 'Ana Gimenes', 'Valinhos', 12500.00);
insert into CLIENTES values ('0104', 'José Porto', 'Campinas', 14500.00);
insert into CLIENTES values ('0105', 'Ana Erickson', 'Valinhos', 8500.00);
insert into CLIENTES values ('0106', 'Paulo Amaro', 'Itatiba', 16500.00);
insert into CLIENTES values ('0107', 'Ruth Almeida', 'Itatiba', 12500.00);
insert into CLIENTES values ('0108', 'João Dickson', 'Itatiba', 0.00);
insert into CLIENTES values ('0109', 'Carla Alves', 'Valinhos', 20500.00);
insert into CLIENTES values ('0110', 'Caê Cerri', 'Campinas', 22000.00);
insert into CLIENTES values ('0120', 'João Alves', 'Itatiba', 0.00);
insert into CLIENTES values ('0121', 'Cátia Abreu', 'Valinhos', 20500.00);
insert into CLIENTES values ('0122', 'Ana Morris', 'Campinas', 22000.00);
insert into CLIENTES values ('2121', 'Paula Morgado', 'Campinas', 2000.00);

# A)
select Cod_Cli, Nome_Cli from CLIENTES where Limite_Credito between 12000 and 20000;

# B)
select Cod_Cli, Nome_Cli from CLIENTES where Cidade = "Itatiba" and Limite_Credito < 12000;

# C)
select Cod_Cli, Nome_Cli from CLIENTES where Limite_Credito = (select min(Limite_Credito) from CLIENTES);

# D)
select distinct Cidade from CLIENTES;

# E)
select min(Limite_Credito) from CLIENTES;

# F)
select avg(Limite_Credito) from CLIENTES where Cidade = "Valinhos";

# G)
update CLIENTES set Limite_Credito = Limite_Credito * 1.15 where Cidade = "Itatiba";

# H)
delete from CLIENTES where Limite_Credito between 0 and 8000;

create table VENDAS 
(
Cod_Cli varchar(4), 
Data_Venda date, 
Valor decimal(10,2)
);

insert into VENDAS values ('0101', str_to_date('22/02/2023', '%d/%m/%Y'), 1500.00);
insert into VENDAS values ('0101', str_to_date('25/02/2023', '%d/%m/%Y'), 2000.00);
insert into VENDAS values ('0101', str_to_date('27/02/2023', '%d/%m/%Y'), 3500.00);
insert into VENDAS values ('0101', str_to_date('22/03/2023', '%d/%m/%Y'), 3500.00);
insert into VENDAS values ('0102', str_to_date('22/03/2023', '%d/%m/%Y'), 1500.00);
insert into VENDAS values ('0102', str_to_date('12/02/2023', '%d/%m/%Y'), 500.00);
insert into VENDAS values ('0103', str_to_date('22/02/2023', '%d/%m/%Y'), 1500.00);
insert into VENDAS values ('0104', str_to_date('25/02/2023', '%d/%m/%Y'), 2000.00);
insert into VENDAS values ('0105', str_to_date('27/02/2023', '%d/%m/%Y'), 5500.00);
insert into VENDAS values ('0105', str_to_date('22/03/2023', '%d/%m/%Y'), 2000.00);
insert into VENDAS values ('0105', str_to_date('22/03/2023', '%d/%m/%Y'), 3500.00);
insert into VENDAS values ('0106', str_to_date('12/02/2023', '%d/%m/%Y'),2500.00);
insert into VENDAS values ('0107', str_to_date('02/02/2023', '%d/%m/%Y'), 1500.00);
insert into VENDAS values ('0107', str_to_date('05/03/2023', '%d/%m/%Y'), 2000.00);
insert into VENDAS values ('0108', str_to_date('27/08/2023', '%d/%m/%Y'), 5500.00);
insert into VENDAS values ('0108', str_to_date('23/02/2023', '%d/%m/%Y'), 2000.00);
insert into VENDAS values ('0109', str_to_date('22/02/2023', '%d/%m/%Y'), 1500.00);
insert into VENDAS values ('0110', str_to_date('12/03/2023', '%d/%m/%Y'),2500.00);
insert into VENDAS values ('0120', str_to_date('20/02/2023', '%d/%m/%Y'), 1500.00);
insert into VENDAS values ('0121', str_to_date('26/02/2023', '%d/%m/%Y'), 2000.00);
insert into VENDAS values ('0122', str_to_date('14/02/2023', '%d/%m/%Y'), 2500.00);
insert into VENDAS values ('2121', str_to_date('04/03/2023', '%d/%m/%Y'), 2500.00);
insert into VENDAS values ('2121', str_to_date('22/02/2023', '%d/%m/%Y'), 500.00);

# I)
select sum(Valor) from VENDAS where Cod_Cli = '0101';

# J)
select sum(Valor) from VENDAS where Cod_Cli = '0101' and Data_Venda > '2023-03-22' and Data_Venda < '2023-03-25';

# K)
select Cod_Cli, Data_Venda, Valor from VENDAS where Valor < 3000;

# L)
select Valor, Data_Venda from VENDAS where Cod_Cli = (select Cod_Cli from CLIENTES where Nome_Cli = "Paulo Amaro");

# M)
select sum(Valor) from VENDAS where Cod_Cli = (select Cod_Cli from CLIENTES where Nome_Cli = "João Dickson");

# N)
select Cod_Cli, Data_Venda, Valor from VENDAS where Valor > 2000 and Valor < 5000;

#QUESTÃO 2

create table ATIVOS
(
CodAtivo int not null primary key,
DescAtivo varchar(100) not null,
CodTipo varchar(20) not null,
ValorUnit decimal(5,2) not null,
QtdMeses int not null
);

insert into ATIVOS values (1, 'Mesa cinza', 'móvel', 100.50, 12);
insert into ATIVOS values (2, 'Cadeira de rodinha', 'móvel', 50.50, 6);
insert into ATIVOS values (3, 'Mouse', 'eletrônico', 200.75, 10);
insert into ATIVOS values (4, 'Lousa', 'móvel', 80.99, 15);
insert into ATIVOS values (5, 'Projetor', 'eletrônico', 600.50, 24);
