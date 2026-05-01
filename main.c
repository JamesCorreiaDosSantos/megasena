#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SORTEIOS 5000
#define NUM_NUMEROS 6
#define NUM_BOLAS 60

// Função para gerar números únicos aleatórios
void gerarSorteio(int sorteios[NUM_SORTEIOS][NUM_NUMEROS]) {
for (int i = 0; i < NUM_SORTEIOS; i++) {
int numerosSorteados[NUM_BOLAS];
for (int j = 0; j < NUM_BOLAS; j++) {
numerosSorteados[j] = j + 1;
}

for (int j = 0; j < NUM_NUMEROS; j++) {
int indice = rand() % (NUM_BOLAS - j);
sorteios[i][j] = numerosSorteados[indice];
numerosSorteados[indice] = numerosSorteados[NUM_BOLAS - j - 1];
}
}
}

int main() {
srand(time(NULL));
int sorteios[NUM_SORTEIOS][NUM_NUMEROS];
gerarSorteio(sorteios);

// Inicialize as estruturas de dados para a estatística aqui

// Realize os sorteios e preencha as estruturas de dados

// Simule jogadas para 3 usuários
for (int usuario = 0; usuario < 3; usuario++) {
char nome[100];
char cpf[12];
int numerosApostados[NUM_NUMEROS];

printf("Usuário %d, por favor, insira seu nome: ", usuario + 1);
scanf("%s", nome);
printf("Usuário %d, insira seu CPF: ", usuario + 1);
scanf("%s", cpf);

printf("Usuário %d, insira 6 números únicos (01 a 60): ", usuario + 1);
for (int i = 0; i < NUM_NUMEROS; i++) {
scanf("%d", &numerosApostados[i]);
}

// Verifique quantos números o usuário acertou em cada sorteio
int maxAcertos = 0;
int sorteioComMaisAcertos = 0;
for (int i = 0; i < NUM_SORTEIOS; i++) {
int acertos = 0;
for (int j = 0; j < NUM_NUMEROS; j++) {
for (int k = 0; k < NUM_NUMEROS; k++) {
if (numerosApostados[j] == sorteios[i][k]) {
acertos++;
break;
}
}
}
if (acertos > maxAcertos) {
maxAcertos = acertos;
sorteioComMaisAcertos = i + 1;
}
}

printf("Parabéns, %s! Você acertou %d números! No sorteio %d.\n", nome, maxAcertos, sorteioComMaisAcertos);
}

// Imprima as estatísticas aqui

return 0;
}