use BD24022618; 

#a)
create table Generos (
    genero_id int primary key,
    nome varchar(100)
);

#b)
create table Editoras (
    editora_id int primary key,
    nome varchar(100),
    pais varchar(100)
);

#c)
create table Livros (
livro_id int primary key,
titulo varchar(150),
preco decimal(10,2),
genero_id int,
editora_id int,

foreign key (genero_id) references Generos(genero_id),
foreign key (editora_id) references Editoras(editora_id)
);

#d)
insert into Generos (genero_id, nome) values
(1, 'Ficção Científica'),
(2, 'Romance');
insert into Editoras (editora_id, nome, pais) values
(1, 'Companhia das Letras', 'Brasil'),
(2, 'HarperCollins', 'Estados Unidos');

#e)
insert into Livros (livro_id, titulo, preco, genero_id, editora_id) values
(1, 'Duna', 89.90, 1, 2),
(2, 'Orgulho e Preconceito', 59.90, 2, 2),
(3, 'A Máquina do Tempo', 45.00, 1, 1);

#f)
select
    L.titulo as Livro,
    L.preco as Preco,
    G.nome as Genero,
    E.nome as Editora
	from Livros L
	inner join Generos G
    on L.genero_id = G.genero_id
	inner join Editoras E
    on L.editora_id = E.editora_id;

#g)
select
    L.titulo as Livro,
    E.nome as Editora,
    G.nome as Genero
	from Livros L
	inner join Generos G
    on L.genero_id = G.genero_id
	inner join Editoras E
    on L.editora_id = E.editora_id
	where G.nome = 'Ficção Científica';

#h)
select
    G.nome as Genero,
    avg(L.preco) as Preco_Medio
	from Livros L
	inner join Generos G
    on L.genero_id = G.genero_id
	group by G.nome;

#i)
select
    E.nome as Editora,
    L.titulo as Livro,
    L.preco as Preco
	from Livros L
	inner join Editoras E
    on L.editora_id = E.editora_id
	where L.preco = (
    select max(preco)
    from Livros
);