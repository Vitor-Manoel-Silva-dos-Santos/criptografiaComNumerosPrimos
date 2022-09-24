

#define TAMANHOMEMORIA 2
int memoria_chaves [TAMANHOMEMORIA] = {0,0,0}; /* vetor para armazenar chaves */
void armazenaChaves(){


    int teste = gerarChave(); /*gera primeira chave*/
    int teste2 = gerarChave(); /*gera segunda chave*/

    memoria_chaves[0] = teste; /*adiciona a chave ao vetor*/
    memoria_chaves[1] = teste2; /*adiciona a chave ao vetor*/

    for( int i = 0; i <= TAMANHOMEMORIA; i++){
        printf("chave: %d posicao: %d\n \n ", memoria_chaves[i], i); /*mostra as chaves na tela*/
    }
}

int chavePublica(){
    armazenaChaves();
    int chave_publica = memoria_chaves[0] * memoria_chaves[1]; /*chave para criptografar a mensagem*/

    return chave_publica;
}


int chavePrivadaEnvio (){
    int teste3 = gerarChave();
    memoria_chaves[2] = teste3; /*gera chave de envio da mensagem*/

    return teste3;
}

