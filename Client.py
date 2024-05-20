import socket

ServerIP = "192.168.1.8"
ServerPort = 14552

client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)


def send_cmd:
    try:
        inp = input("> ")
        client_socket.connect((ServerIP, ServerPort))
        client_socket.sendall(inp.encode('utf-8'))

        data = client_socket.recv(1024)
        print(f" <- {data.decode('utc-8')}")

    except Exception as e:
        prin(f"!An error occurred: {e}")

    finally:
        client_socket.close()
