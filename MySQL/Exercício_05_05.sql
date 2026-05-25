-- =========================================
-- A) TABELA CLIENTES
-- =========================================
create table clientes (
    id int auto_increment primary key,
    nome varchar(100) not null,
    email varchar(150) not null,
    telefone varchar(15) not null
);

-- =========================================
-- B) TABELA PEDIDOS
-- =========================================
create table pedidos (
    id int auto_increment primary key,
    cliente_id int not null,
    data_pedido date not null,
    total decimal(8,2) not null,
    foreign key (cliente_id) references clientes(id)
);

-- =========================================
-- E) TABELA PRODUTOS
-- =========================================
create table produtos (
    id int auto_increment primary key,
    nome varchar(100) not null,
    preco decimal(8,2) not null
);

-- =========================================
-- F) TABELA ITENS_PEDIDO
-- =========================================
create table itens_pedido (
    id int auto_increment primary key,
    pedido_id int not null,
    produto_id int not null,
    foreign key (pedido_id) references pedidos(id),
    foreign key (produto_id) references produtos(id)
);

-- =========================================
-- C) INSERIR CLIENTE
-- =========================================
insert into clientes (nome, email, telefone)
values ("Ana", "ana@gmail.com", "(19)987654321");

-- =========================================
-- D) INSERIR PEDIDOS
-- =========================================
insert into pedidos (cliente_id, data_pedido, total)
values 
(1, '2026-04-20', 7500.90),
(1, '2026-05-02', 12500.90);

-- =========================================
-- G) INSERIR PRODUTOS
-- =========================================
insert into produtos (nome, preco)
values 
("Caneta", 3.50),
("Caderno", 45.90);

-- =========================================
-- H) INSERIR ITENS
-- =========================================
insert into itens_pedido (pedido_id, produto_id)
values 
(1, 1),
(1, 2);

-- =========================================
-- I) MAIS DADOS
-- =========================================

-- Novo cliente
insert into clientes (nome, email, telefone)
values ("Joao", "joao@gmail.com", "(19)999999999");

-- Pedidos do João
insert into pedidos (cliente_id, data_pedido, total)
values 
(2, '2026-05-05', 300.00),
(2, '2026-05-06', 450.00),
(2, '2026-05-07', 600.00);

-- Novos produtos
insert into produtos (nome, preco)
values 
("Lapis", 2.00),
("Borracha", 1.50),
("Mochila", 120.00);

-- Itens do pedido
insert into itens_pedido (pedido_id, produto_id)
values 
(3, 3),
(3, 4),
(3, 5);

-- =========================================
-- J) CLIENTES QUE POSSUEM PEDIDOS
-- =========================================
select distinct c.*
from clientes c
inner join pedidos p on c.id = p.cliente_id;

-- =========================================
-- K) TOTAL GASTO POR CLIENTE
-- =========================================
select c.nome, sum(p.total) as total_gasto
from clientes c
inner join pedidos p on c.id = p.cliente_id
group by c.nome;

-- =========================================
-- L) CLIENTE, DATA E TOTAL DO PEDIDO
-- =========================================
select c.nome, p.data_pedido, p.total
from clientes c
inner join pedidos p on c.id = p.cliente_id;

-- =========================================
-- M) PRODUTO MAIS VENDIDO
-- =========================================
select pr.nome, count(ip.produto_id) as total_vendas
from produtos pr
inner join itens_pedido ip on pr.id = ip.produto_id
group by pr.nome
order by total_vendas desc
limit 1;

-- =========================================
-- N) CLIENTE QUE MAIS GASTOU
-- =========================================
select c.nome, sum(p.total) as total_gasto
from clientes c
inner join pedidos p on c.id = p.cliente_id
group by c.nome
order by total_gasto desc
limit 1;

-- =========================================
-- O) QUANTIDADE DE PEDIDOS POR CLIENTE
-- =========================================
select c.nome, count(p.id) as quantidade_pedidos
from clientes c
left join pedidos p on c.id = p.cliente_id
group by c.nome;

-- =========================================
-- CLIENTE
-- =========================================
create table cliente (
    id_cliente int auto_increment primary key,
    nome varchar(100),
    cpf varchar(14),
    email varchar(150),
    telefone varchar(20),
    endereco varchar(200),
    data_nascimento date
);

-- =========================================
-- PEDIDO
-- =========================================
create table pedido (
    id_pedido int auto_increment primary key,
    data_entrega date,
    quantidade int
);

-- =========================================
-- PRODUTO
-- =========================================
create table produto (
    id_produto int auto_increment primary key,
    nome varchar(100),
    modelo varchar(100),
    preco decimal(10,2),
    marca varchar(100)
);

-- =========================================
-- ADMINISTRADOR
-- =========================================
create table administrador (
    id_administrador int auto_increment primary key,
    nome varchar(100)
);

-- =========================================
-- FUNCIONARIO
-- =========================================
create table funcionario (
    id_funcionario int auto_increment primary key,
    nome varchar(100)
);

-- =========================================
-- RELACIONAMENTO: REALIZA (Cliente - Pedido)
-- =========================================
create table realiza (
    id_cliente int,
    id_pedido int,
    primary key (id_cliente, id_pedido),
    foreign key (id_cliente) references cliente(id_cliente),
    foreign key (id_pedido) references pedido(id_pedido)
);

-- =========================================
-- RELACIONAMENTO: CONTEM (Pedido - Produto)
-- =========================================
create table contem (
    id_pedido int,
    id_produto int,
    primary key (id_pedido, id_produto),
    foreign key (id_pedido) references pedido(id_pedido),
    foreign key (id_produto) references produto(id_produto)
);

-- =========================================
-- RELACIONAMENTO: COMPRA (Cliente - Produto)
-- =========================================
create table compra (
    id_cliente int,
    id_produto int,
    primary key (id_cliente, id_produto),
    foreign key (id_cliente) references cliente(id_cliente),
    foreign key (id_produto) references produto(id_produto)
);

-- =========================================
-- RELACIONAMENTO: GERENCIA_C (Cliente - Administrador)
-- =========================================
create table gerencia_c (
    id_cliente int,
    id_administrador int,
    primary key (id_cliente, id_administrador),
    foreign key (id_cliente) references cliente(id_cliente),
    foreign key (id_administrador) references administrador(id_administrador)
);

-- =========================================
-- RELACIONAMENTO: GERENCIA_F (Administrador - Funcionario)
-- =========================================
create table gerencia_f (
    id_administrador int,
    id_funcionario int,
    primary key (id_administrador, id_funcionario),
    foreign key (id_administrador) references administrador(id_administrador),
    foreign key (id_funcionario) references funcionario(id_funcionario)
);

-- =========================================
-- RELACIONAMENTO: ATUALIZA (Funcionario - Produto)
-- =========================================
create table atualiza (
    id_funcionario int,
    id_produto int,
    primary key (id_funcionario, id_produto),
    foreign key (id_funcionario) references funcionario(id_funcionario),
    foreign key (id_produto) references produto(id_produto)
);
