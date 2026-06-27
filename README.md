# Servidor (Sockets TCP em C) 🖧

Lado **servidor** de uma aplicação **cliente-servidor** baseada em **sockets TCP/IP**, escrita em **C**. O servidor mantém um catálogo de filmes e responde às requisições do cliente.

## ✨ Características

- Comunicação via **sockets TCP** (porta 2000)
- Código **multiplataforma**: usa `winsock` no Windows e sockets POSIX no Linux/Unix
- Gerencia um catálogo (`struct Filmes`) com status de cada item
- Atende conexões de clientes e troca dados pela rede

## 🛠️ Tecnologias

![C](https://img.shields.io/badge/C-00599C?style=flat&logo=c&logoColor=white)

- **C** + API de **sockets** (Berkeley sockets / Winsock)

## 🚀 Como executar

```bash
# Linux
gcc servidor.c -o servidor
./servidor

# Windows (MinGW): linkar com a winsock
gcc servidor.c -o servidor -lwsock32
```

## 🔗 Cliente

Use junto com o repositório [`Cliente`](https://github.com/limongi1234/Cliente), que faz as requisições a este servidor.
