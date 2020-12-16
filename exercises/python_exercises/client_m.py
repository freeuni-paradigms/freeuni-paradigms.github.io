import socket

HOST = '127.0.0.1'
PORT = 7777

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST, PORT))
    while True:
        try:   
            input_data = input()
            s.sendall(input_data.encode())
            data = s.recv(1024)
            print('Received', data)
        except KeyboardInterrupt:
            break
