drop database cettetpsi0126_14_registo;

create database cettetpsi0126_14_registo;
use cettetpsi0126_14_registo;
create table pessoas (
id int not null auto_increment,
nome varchar(30) not null,
nascimento date,
sexo enum('M','F'),
peso decimal (5,2),
altura decimal (3,2),
nacionalidade varchar(20) default 'Portugal',
primary key (id)
) default charset = utf8mb4;