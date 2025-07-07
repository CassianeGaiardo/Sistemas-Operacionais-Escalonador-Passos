# Trabalho de Sistemas Operacionais com objetivo de estudar o código de uma implementação do Unix versão 6 (xv6) para a plataforma Risc-v.

Descrição do Trabalho II: implementar o escalonador de processos stride scheduling (escalonamento em passos
largos). Semelhante ao escalonamento por loteria, cada processo recebe um número fixo de bilhetes (tickets). Ao
invés de utilizar um sorteio (abordagem probabilística), calcula-se o “passo” (stride) de cada processo como sendo
o resultado da divisão de um valor constante (e.g., 10.000) pelo número de bilhetes do processo. Cada processo
inicia com uma “passada inicial” igual a zero (0). O escalonador seleciona o processo com o menor valor de
passada atual; portanto, inicialmente qualquer um dos processos prontos pode ser selecionado. Nesse caso, utiliza-
se um critério qualquer para desempate (e.g., o processo com o maior PID é selecionado). Após selecionado, a
passada do processo é incrementada com o valor do “passo” do processo. Por exemplo, assuma que há 3 processos,
A, B e C, cada um com 100, 50 e 250 bilhetes, respectivamente; portanto, A tem passo 100, B tem passo 200 e C
tem passo 40. Caso o processo A seja selecionado inicialmente, a sua passada é atualizada para 100. Em seguida B
e C ainda tem passada zero. Vamos assumir que B seja escalonado, atualizando sua passada para 200. Em seguida,
o processo necessariamente selecionado é o C (passada ainda é zero), fazendo sua passada ser atualizada para 40.
Em sequência, o processo C é selecionado mais duas vezes seguidas até atingir uma passada maior que o processo
A (passada = 100). Essa abordagem torna o escalonamento determinístico, concedendo rapidamente uma fração da
CPU correspondente ao número de bilhetes de cada processo.

Lembretes: O readme explica como rodar o teste. escalonador em proc.c
