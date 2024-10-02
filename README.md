# Overview
Minitalk is a Unix-based communication system between processes, implemented in C.  
It consists of a server and a client that communicate via Unix signals (SIGUSR1 and SIGUSR2). The client sends a message bit by bit to the server, which interprets and displays the message in real-time.

This project demonstrates signal handling, inter-process communication, and bitwise operations, providing a solid understanding of low-level system programming concepts in Unix environments.

## How It Works
- Server: The server listens for signals from the client, reconstructs each character from the received bits, and prints the message.

- Client: The client converts each character of the message into bits and sends them to the server using Unix signals. After transmitting each bit, the client waits for a confirmation signal from the server.
## Usage

	server: ./server

	Client: ./client [server_pid] [message]

 > Upon executing the command ./server, the server will display its process ID (PID) on the screen.
## Key Features
- Full-duplex communication using signals.  
- Robust signal handling with confirmation for every bit transmitted.  
- Bit-level data transfer simulation.

### Difficulty Rating:
⭐⭐☆☆☆
