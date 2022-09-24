/*solicitar usuario e login <------------ */

/*gerar chave encrypt <---------------*/

/*encryptar usuario e login com a mesma chave se for a primeira vez de execução*/

/*salvar chave e encrypte em um vetor*/

/*encryptar novamente se o usuario entrar*/

/*se for feito login entao deve pegar a chave encryptar novamente*/

/*gerar matriz*/

/*verificar se os encrypts parecem corretos, porém deve verificar todos os encryptes do vetor, porem para verificar o
computador deve executar uma matriz*/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "chave_primo_crypto.c"
#include "usuario_cryptografia.c"
#include "armazena_chave.c"
void digitar();
int main(){
    srand(time(NULL));

    digitar();


    /*solicitarUsuario();*/
    /* digitar();*/
    /*int teste = gerarChave();

    printf("\n \n retorno = %d \n \n ", teste);*/
    //armazenaChaves();
    //int verchavepublica = chavePublica();

    /*printf("%d \n\n", verchavepublica);*/

    //int verchave;
    //verchave = encryptar(10);
    //printf("%d  %d\n\n", primeiro_parametro_envio, segundo_parametro_envio);

    //int chaveprivada = chavePrivadaEnvio();
    //printf("chave privada[2] %d \n\n", chaveprivada);



    return 0;
}

void digitar(){
    int pos= 0; /*varre o vetor para incrementar*/
    char caractere; /* recebe o caracter digitado*/
    long int quant_digitos; /*tamanho do vetor*/
    long int *ponteiro; /*ponteiro para alterar o tamanho do vetor*/
    ponteiro = &quant_digitos; /*ponteiro apontando para o endereço do tamanho do vetor*/
    *ponteiro = 2; /*tamanho do vetor inicia com 2*/
    long long digitacao[quant_digitos]; /*vetor = 2*/
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
    printf( "\n\n Password: " );
    for ( int i = 0; i < quant_digitos; i++)
    {
        putchar( digitacao[ i ] );
    }

    printf("\n \n \n \n%lld \n", quant_digitos);

    int resultado = encryptar(quant_digitos, digitacao);
    printf("\n \n Resultado = %d \n \n", resultado);
    for( int i = 0; i <= TAMANHOMEMORIA; i++){
        printf("chave: %d posicao: %d\n \n ", memoria_chaves[i], i); /*mostra as chaves na tela*/
    }
}

