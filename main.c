#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHOMEMORIA 2

int quantidade_excucoes = 0;// utilizado para cotrolar as execucoes, caso seja a segunda execucao entao o metodo de verificacao é outro
int memoria_chaves [TAMANHOMEMORIA] = {0,0,0}; /* vetor para armazenar chaves */

#include "chave_primo_crypto.c"
#include "usuario_cryptografia.c"
#include "armazena_chave.c"


void digitar();

int main(){
    srand(time(NULL)); // faz com que seja sorteado sempre um numero diferente
    while(1){ // loop infinito
       digitar();
       quantidade_excucoes++;
       }

    return 0;
}

void digitar(){
    int pos= 0; /*varre o vetor para incrementar*/
    char caractere; /* recebe o caracter digitado*/
    long long int quant_digitos; /*tamanho do vetor*/
    long long int *ponteiro; /*ponteiro para alterar o tamanho do vetor*/
    ponteiro = &quant_digitos; /*ponteiro apontando para o endereço do tamanho do vetor*/
    *ponteiro = 2; /*tamanho do vetor inicia com 2*/
    long long int digitacao[quant_digitos]; /*vetor = 2*/

    printf( "\n Password: " );

    while ( 1 )
    {
        caractere = getch(); /*pega o caracter digitado e adiciona na variavel*/
        *ponteiro+=1; /*aumenta o tamanho do vetor*/
        if ( pos < quant_digitos)
        {
            putchar( caractere ); /*mostra digitação na tela*/
            digitacao[ pos++ ]= caractere; /*incrementa os caracteres ao vetor*/

        }
        if ( caractere == '\r'/*carrige return*/ ) /*enter*/
        {
            *ponteiro -= 2; /*decrementa para ficar no tamanho da digitacao*/
            break;

        }
        if ( pos > 0 && caractere == '\b' /*backspace*/) /*deletar caracter*/
        {
             pos-= 2; /*decrementa para apagar a digitação*/
             putchar( '\b' ); /*apaga caracter*/
             putchar( ' ' ); /*reescreve o espaço com vazio*/
             putchar( '\b' ); /*apaga novamente*/

        }

    }
    printf("\n");
    printf( "\n Password: " );
    for ( int i = 0; i < quant_digitos; i++)
    {
        putchar( digitacao[ i ] ); // mostra senha digitada
    }

    printf("\n \n Quantos digitos = %lld \n \n", quant_digitos); // mostra quantos digitos

    int resultado = encryptar(quant_digitos, digitacao); // resultado == 1, encryptar está correto

    int teste = verificar_Para_Enviar(resultado); // verificar == 1, verificacao está correta.
    printf("\n verificacao chave privada usuario =  %d \n ", teste);

    printf("\n verificacao se foi cryptografado = %d \n ", resultado); //retorna chave de envio
    for( int i = 0; i <= TAMANHOMEMORIA; i++){
        printf("\n chave: %d indice: %d \n", memoria_chaves[i], i); /*mostra as chaves (numeros primos gerado) na tela*/
    }
}

