

int armazenaChaves(int teste, int teste2){

    memoria_chaves[0] = teste; /*adiciona a chave ao vetor*/
    memoria_chaves[1] = teste2; /*adiciona a chave ao vetor*/

    for( int i = 0; i <= TAMANHOMEMORIA; i++){
        printf("chave: %d indice: %d\n \n ", memoria_chaves[i], i); /*mostra as chaves na tela*/
    }

    return memoria_chaves;
}

int chavePrivadaEnvio (){

    int teste3 = gerarChave(); //gera chave de envio da mensagem
    memoria_chaves[2] = teste3; //armazena chave de envio da mensagem (chave privada do usuario)

    return teste3;
}

int chavePublica(){

    int chave_publica;

    if (quantidade_excucoes == 0){ //primeira execucao

        int primeira_chave_excucao = gerarChave(); /*gera primeira chave*/
        int segunda_chave_excucao = gerarChave(); /*gera segunda chave*/

        armazenaChaves(primeira_chave_excucao, segunda_chave_excucao); // armazena chaves no vetor pertencente ao app

        return chave_publica = memoria_chaves[0] * memoria_chaves[1]; /*chave para criptografar a mensagem*/
    }

    if (quantidade_excucoes > 0){// caso seja a segunda execucao em diante, executa novo metodo.

        memoria_chaves[0] = memoria_chaves[1]; // as chaves se movem um indice a frente no vetor
        memoria_chaves[1] = memoria_chaves[2] - 1; // as chaves se movem um indice a frente no vetor

        printf("\n verifica se moveu [0] = %d \n", memoria_chaves[0]);
        printf("\n verifica se moveu [1] = %d \n", memoria_chaves[1]);

        return chave_publica = memoria_chaves[0] * memoria_chaves[1]; /*chave para criptografar a mensagem (chave publica usuario)*/
    }
}




