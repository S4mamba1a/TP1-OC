CC = gcc
CFLAGS = -Wall -I headers
TARGET = montador
SRCS = arquivo_principal/main.c sources/instrucoes.c sources/dicionario.c

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET) saida.txt