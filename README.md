# Escalonador de Tarefas

Esse projeto implementa algoritmos de escalonamento de tarefas: Round-Robin com Prioridade (RR_p) e o Earliest Deadline First (EDF).

## Alunos

- Henrique Valiati Schroeder
- Arthur Felipe Carminati

## Requisitos

- Sobre o RR_p, a prioridade só será levada em conta na escolha de qual task deve ser executada caso haja duas (ou mais) tasks para serem executadas no momento. Em caso de prioridades iguais, pode implementar o seu critério, como quem é a primeira da lista (por exemplo). Nesse trabalho, considere a maior prioridade como sendo 1. Além disso, é obrigatório o uso de múltiplas filas para a gerência de prioridade.

- Você deve considerar mais filas de aptos para diferentes prioridades. Acrescente duas taks para cada prioridade criada.

- A contagem de tempo (slice) pode ser implementada como desejar, como com bibliotecas ou por uma variável global compartilhada.

- Lembre-se que a lista de task (fila de aptos) deve ser mantida “viva” durante toda a execução. Sendo assim, é recomendado implementar ela em uma biblioteca (podendo ser dentro da próprio schedulers.h) e compartilhar como uma variável global.

- Novamente, você pode modificar os arquivos, principalmente o “list”, mas sem deixar a essência original deles comprometida. Porém, esse arquivo auxilia na criação de prioridade, já que funciona no modelo pilha.

- Para usar o Makefile, gere um arquivo schedule_rr.c, schedule_rrp.c e schedule_fcfs.c que incluem a biblioteca schedulers.h (pode modificar o nome da biblioteca também). Caso não queira usar o Makefile, pode trabalhar com a IDE de preferência ou compilar via terminal.

- Utilize um slice de no máximo 10 unidades de tempo.

- Para os algoritmos, você deverá, via uma primeira thread extra, a simulação da ocorrência do timer em hardware. Essa thread irá fazer a simulação do tempo e gerará a flag de estouro do tempo (para o slice). Além disso, para o algoritmo EDF será necessário avaliar o deadline das tasks e verificar qual das tasks está com o menor deadline.