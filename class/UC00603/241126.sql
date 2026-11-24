create database cettetpsi0126_14_registo
default character set utf8mb3
default collate utf8_general_ci;
use cettetpsi0126_14_registo;

create table pessoas (
nome varchar(30) not null,
nascimento date,
sexo enum('M','F') not null,
peso decimal(5,2),
altura decimal(3,2),
nacionalidade varchar(20) default 'Portugal'
) DEFAULT CHARSET = utf8;