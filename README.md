# **Minitalk**

**Minitalk** is a simple communication program that includes a client and a server. The server prints messages received from the client. The communication is done using UNIX signals, specifically `SIGUSR1` and `SIGUSR2`.

## **Features**

- The server prints its PID when launched.
- The client sends a string to the server using the server's PID.
- The server displays the received string quickly.
- The server can handle multiple clients in succession without restarting.
- Communication between client and server is achieved using only `SIGUSR1` and `SIGUSR2` signals.

## **Getting Started**

### **Installation**

1. Clone the repository:
    ```sh
    git clone https://github.com/yourusername/minitalk.git
    ```
2. Navigate to the project directory:
    ```sh
    cd minitalk
    ```
3. Compile the server and client programs:
    ```sh
    make
    ```

### **Usage**

1. Start the server:
    ```sh
    ./server
    ```
   - The server will print its PID, which will be used by the client.

2. Start the client with the server's PID and the string to send:
    ```sh
    ./client <server_pid> "<message>"
    ```

Example:
   ```sh
   ./client 12345 "Hello, World!"
   ```

### **Signals Used**

- `SIGUSR1`: Represents a binary 0.
- `SIGUSR2`: Represents a binary 1.

---
