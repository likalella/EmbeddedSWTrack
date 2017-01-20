import socket
import sys
import s_matrix
import gpioInit
import construct

HOST = '203.253.23.53'
PORT = 9000
row = [0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01]
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

try:
    server_socket.bind((HOST, PORT))
except:
    print("Fail to bind")
    sys.exit()

print("Start Server")
server_socket.listen(5)
conn, addr = server_socket.accept()
print("Connect to client")

# init matrix
matrix = s_matrix.StringMatrix()
g = gpioInit.GpioSetting()

while True:
    buf = conn.recv(1024)
    c = construct.Struct(
        "col" / construct.Array(8, construct.Int8ub)
    )
    con = c.parse(buf)
    print con.col
    for i in range(250):
        for i in range(8):
            tmp = (row[i] << 8) | con.col[i]
            g.set16(tmp)
conn.close()
server_socket.close()
