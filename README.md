Minitalk - Explicação Resumida
Ideia Principal
Criar dois programas que se comunicam usando apenas sinais do sistema, como se fosse um "walkie-talkie" entre processos.

Os Dois Programas
Servidor (./server)
Inicia primeiro e mostra seu número PID

Fica esperando sinais como um "ouvinte"

Reconstrói a mensagem bit a bit

Imprime a mensagem quando recebe tudo

Cliente (./client)
Precisa do PID do servidor e da mensagem

Envia a mensagem convertendo cada caractere em bits

Usa sinais:

SIGUSR1 = bit 0

SIGUSR2 = bit 1

Como Funciona a Transmissão
Exemplo: Enviar a letra 'A'
'A' em ASCII = 65 = 01000001 em binário

text
Cliente envia: 0 1 0 0 0 0 0 1
               ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓
Sinais:       USR2 USR1 USR1 USR1 USR1 USR1 USR2 USR1
8 sinais = 1 caractere

Regras Importantes
Só pode usar SIGUSR1 e SIGUSR2
Sem vazamentos de memória
Rápido: 100 caracteres em < 1 segundo
Servidor atende múltiplos clientes
Não pode usar: sockets, pipes, arquivos, etc.

Como Usar
bash
# Terminal 1
./server
# Mostra: Server PID: 12345

# Terminal 2  
./client 12345 "Olá mundo!"
Resultado no servidor: Olá mundo!

