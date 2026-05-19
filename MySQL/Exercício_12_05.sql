-- =========================================
-- 1) CRIAÇÃO DAS TABELAS
-- =========================================

-- TABELA LIVROS
create table livros (
    id int auto_increment primary key,
    titulo varchar(150) not null,
    autor varchar(100) not null,
    genero varchar(50),
    editora varchar(100),
    ano_publicacao int
);

-- TABELA LEITORES
create table leitores (
    id int auto_increment primary key,
    nome varchar(100) not null,
    email varchar(150),
    telefone varchar(20)
);

-- TABELA EMPRESTIMOS
create table emprestimos (
    id int auto_increment primary key,
    leitor_id int,
    livro_id int,
    data_emprestimo date,
    data_devolucao date,
    
    foreign key (leitor_id) references leitores(id),
    foreign key (livro_id) references livros(id)
);

-- =========================================
-- 2) INSERÇÃO DE DADOS
-- =========================================

-- LIVROS
insert into livros (titulo, autor, genero, editora, ano_publicacao) values
("Dom Casmurro", "Machado de Assis", "romance", "Saraiva", 1899),
("O Alquimista", "Paulo Coelho", "romance", "Rocco", 1988),
("Harry Potter", "J.K. Rowling", "fantasia", "Bloomsbury", 1997),
("A Culpa é das Estrelas", "John Green", "romance", "Intrinseca", 2012),
("1984", "George Orwell", "ficcao", "Companhia das Letras", 1949),
("It", "Stephen King", "terror", "Suma", 2014);

-- LEITORES
insert into leitores (nome, email, telefone) values
("Ana", "ana@gmail.com", "1111-1111"),
("Joao", "joao@gmail.com", "2222-2222"),
("Maria", "maria@gmail.com", "3333-3333");

-- EMPRESTIMOS
insert into emprestimos (leitor_id, livro_id, data_emprestimo, data_devolucao) values
(1, 1, '2026-01-10', '2026-01-20'),
(1, 2, '2026-02-01', null),
(2, 3, '2025-12-01', '2025-12-15'),
(2, 4, '2026-03-01', null),
(3, 2, '2026-04-01', '2026-04-10'),
(3, 6, '2026-04-15', null);

-- =========================================
-- CONSULTAS
-- =========================================

-- a) Livros publicados antes de 2000
select * from livros
where ano_publicacao < 2000;

-- b) Livros do gênero romance após 2010
select * from livros
where genero = "romance" and ano_publicacao > 2010;

-- c) Livros que foram emprestados pelo menos uma vez
select distinct l.*
from livros l
inner join emprestimos e on l.id = e.livro_id;

-- d) Livros que nunca foram emprestados
select * from livros
where id not in (
    select livro_id from emprestimos
);

-- e) Empréstimos em atraso (não devolvidos e data já passou)
select *
from emprestimos
where data_devolucao is null
and data_emprestimo < curdate() - interval 7 day;

-- f) Leitor que mais emprestou livros
select le.nome, count(e.id) as total
from leitores le
join emprestimos e on le.id = e.leitor_id
group by le.nome
order by total desc
limit 1;

-- g) Livro mais emprestado
select l.titulo, count(e.id) as total
from livros l
join emprestimos e on l.id = e.livro_id
group by l.titulo
order by total desc
limit 1;

-- h) Leitor com mais livros emprestados atualmente
select le.nome, count(e.id) as total
from leitores le
join emprestimos e on le.id = e.leitor_id
where e.data_devolucao is null
group by le.nome
order by total desc
limit 1;

-- i) Leitor com mais empréstimos no último ano
select le.nome, count(e.id) as total
from leitores le
join emprestimos e on le.id = e.leitor_id
where e.data_emprestimo >= curdate() - interval 1 year
group by le.nome
order by total desc
limit 1;

-- j) Média de empréstimos por leitor
select avg(total_emprestimos) as media
from (
    select count(*) as total_emprestimos
    from emprestimos
    group by leitor_id
) as sub;
