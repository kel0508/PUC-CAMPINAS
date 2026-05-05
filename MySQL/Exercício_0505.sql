#A.
create table clientes
(
id int auto_increment key,
nome varchar(100) not null,
email varchar(150) not null,
telefone varchar(15) not null
);

#B
create table pedidos
(
id int auto_increment primary key,
cliente_id int not null,
foreign key (cliente_id) references clientes(id),
data_pedido date not null,
total decimal(6,1) not null
);

#C
insert into clientes (nome, email, telefone) 
values ("ana", "ana@gmail.com", "(19)987654321");

#D
insert into pedidos (cliente_id, data_pedido, total)
values (1, '2026-04-20', 7500.9),
(1, '2026-05-02', 12500.9);

#E
create table produtos
(
id int auto_increment primary key,
nome varchar(100) not null, 
preco decimal(5,1) not null
);

#F
create table intens_pedido
(
id int auto_increment primary key,
pedido_id int not null,
foreign key (pedido_id) references pedidos(id),
produto_id int not null,
foreign key (produto_id) references produtos(id)
);

#G
insert into produtos (nome, preco)
values ("caneta", 3.5),
("caderno", 45.9);

#H
insert into itens_pedido (pedido_id, produto_id)
values (1, 1),
(1, 2);
