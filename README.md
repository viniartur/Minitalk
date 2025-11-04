# Minitalk
O Minitalk é um projeto que visa a codificação de um pequeno programa de troca de dados utilizando exclusivamente sinais UNIX. Ele é estruturado na forma de um cliente e um servidor.



Objetivos e Componentes Principais

Comunicação Exclusiva por Sinais UNIX: O cerne do projeto é a comunicação entre o cliente e o servidor, que deve usar apenas os sinais SIGUSR1 e SIGUSR2.

Servidor:

Deve ser iniciado primeiro.

Ao iniciar, deve imprimir seu PID (Process ID).

Deve ser capaz de receber strings de vários clientes em sequência sem precisar ser reiniciado.

Após o recebimento, deve imprimir a string sem demora.

Cliente:

Recebe dois parâmetros: o PID do servidor e a string a ser enviada.

Deve enviar a string especificada para o servidor.


Requisitos de Implementação: O projeto deve ser escrito em C , e os executáveis devem ser nomeados client e server.


Restrições Técnicas

Funções Permitidas: A parte obrigatória restringe o uso de funções a uma lista específica, incluindo signal, sigaction, kill, getpid, write, malloc, free, entre outras (e sua própria ft_printf ou equivalente que você tenha codificado).



Variáveis Globais: É permitido usar uma variável global por programa (client e server), mas seu uso deve ser justificado.


Erros e Vazamentos: Os programas devem lidar com erros completamente e não devem sair inesperadamente (como segmentation fault ou double free). Devem estar livres de vazamentos de memória.
