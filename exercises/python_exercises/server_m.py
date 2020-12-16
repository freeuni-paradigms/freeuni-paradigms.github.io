import socket
import threading

HOST = '127.0.0.1' 
PORT = 7777     

def handle(conn, addr):
    with conn:
        print('Connected by', addr)
        while True:
            data = conn.recv(1024)
            if not data:
                break
            conn.sendall(data)       

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind((HOST, PORT))
    s.listen()
    print(f"Server started listening on port {PORT}")
    while True:
        try:
            conn, addr = s.accept()
            client_thread = threading.Thread(target=handle, args=(conn, addr))
            client_thread.start()
        except KeyboardInterrupt:
            break