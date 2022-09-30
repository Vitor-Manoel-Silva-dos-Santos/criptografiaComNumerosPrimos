#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define TAMANHOMEMORIA 3
long long int quant_digitos = 2;
int quantidade_excucoes = 0;// utilizado para cotrolar as execucoes, caso seja a segunda execucao entao o metodo de verificacao é outro
int memoria_chaves [TAMANHOMEMORIA]; /* vetor para armazenar chaves */
long long int *v;
long long int i = 0;
char caractere;

#include "chave_primo_crypto.c"
#include "usuario_cryptografia.c"
#include "armazena_chave.c"

int chavePublica();
int chavePrivadaEnvio();
int chavePrimo();

void digitar();

int main(){
    system("color 2F");
    srand(time(NULL)); // faz com que seja sorteado sempre um numero diferente
    int continuar = 1;
    while(continuar == 1){
        digitar();
        printf("\nDeseja continuar: \t (1 para sim e 0 para nao)");
        scanf("%d", &continuar);
        if (continuar == 0){
            break;
        }
    }


    return 0;
}

void digitar(){
    if (quantidade_excucoes == 1){
        free(v);
        quant_digitos = 2;
        i = 0;
    }
    v = malloc (quant_digitos * sizeof (long long int));

    printf("digite uma cadeia de caracteres: ");
    while(1){
        caractere = getch();

        if (caractere == '\r'){
            quant_digitos-=2;
            v = realloc (v, quant_digitos * sizeof(long long int));
            break;
        }

        if (caractere != '\b'){
            v[i++] = caractere;
        }
        if (caractere != '\b' && caractere != '\r'){
            putchar(caractere);
        }

        if (i == quant_digitos-1){
            quant_digitos += 1;
            v = realloc (v, quant_digitos * sizeof (long long int));
        }

        if ( i > 0 && caractere == '\b' /*backspace*/) /*deletar caracter*/
        {
             i--; /*decrementa para apagar a digitação*/
             quant_digitos--;
             v = realloc (v, quant_digitos * sizeof(long long int));
             putchar( '\b' ); /*apaga caracter*/
             putchar( ' ' ); /*reescreve o espaço com vazio*/
             putchar( '\b' ); /*apaga novamente*/
        }

    }
/*
    for (int o = 0; o < quant_digitos; o++){
        printf("\n O valor inteiro digitado = [%d]  ", o);
        putchar(v[o]);
        printf("\n");
    }
*/
/*
    printf("\n");
    printf( "\n Password: " );
    for ( long long int a = 0; a < quant_digitos; a++)
    {
        putchar( v[ a ] ); // mostra senha digitada
    }
*/
    /*for (long long int c = 0; c < quant_digitos; c++){
        printf("\nquero ver : %d", v[c]);
    }*/

    /*printf("\n \n Quantos digitos = %lld \n \n", quant_digitos);
    */

    int resultado = encryptar(quant_digitos, v);

    int teste = verificar_Para_Enviar(resultado);

    /*printf("\n verificacao chave privada usuario =  %d \n ", teste);
    printf("\n verificacao se foi cryptografado = %d \n ", resultado);*/ //retorna chave de envio

   /*for( int u = 0; u < TAMANHOMEMORIA; u++){
        printf("\n chave: %d indice: %d \n", memoria_chaves[u], u); //mostra as chaves (numeros primos gerado) na tela
    }*/
}


