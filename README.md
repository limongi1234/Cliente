# Cliente (Sockets TCP em C) 🖧

Lado **cliente** de uma aplicação **cliente-servidor** de **locadora de filmes**, baseada em **sockets TCP/IP** e escrita em **C**. Conecta ao servidor, envia a operação, o código do cliente e o nome do filme, e exibe a resposta.

## ✨ Características

- Comunicação via **socket TCP**, conectando na **porta 2000**
- Pede o **IP do servidor** ao iniciar
- Envia ao servidor a **operação**, o **código do cliente** e o **nome do filme**
- Usa `winsock` no Windows e sockets POSIX no Linux/Unix

## 🛠️ Tecnologias

![C](https://img.shields.io/badge/C-00599C?style=flat&logo=c&logoColor=white)

- **C** + API de **sockets** (Winsock / Berkeley sockets)

## 🚀 Como executar

Abra o projeto `cliente.dev` no **Dev-C++** e compile, ou pelo terminal:

```bash
# Windows (MinGW)
gcc cliente.c -o cliente -lwsock32

# Linux
gcc cliente.c -o cliente
./cliente
```

## 🔗 Servidor

Use junto com o repositório [`Servidor`](https://github.com/limongi1234/Servidor). Inicie o servidor primeiro; os dois usam a porta **2000**.
