
int primeiro_parametro_envio, segundo_parametro_envio;

int verificar_Para_Encryptar(int chave_publica_verificar){ // funcao que verifica se a chave publica do usuario esta correta

    //memoria_chaves[0] = 20; // caso queiram falsificar a chave de encryp. (TESTE DE VERIFICACAO)

    return (memoria_chaves[0] * memoria_chaves[1] == chave_publica_verificar) ? 1 : 0; // operador ternario retorna 1 para verdadeiro e 0 para falso
}

int encryptar (long long int quanti_caracteres, long long int *percorrer_vetor){ // cryptografa a mensagem, recebe um vetor como parametro e a quantidade de caracteres

    long long int criptografado[quanti_caracteres]; // vetor que armazena a mensagem encryptada

    primeiro_parametro_envio = chavePublica(); // recebe a chave publica
    segundo_parametro_envio = chavePrivadaEnvio(); // recebe a chave privada


    int para_usuario [2];
    para_usuario[0]= primeiro_parametro_envio;
    para_usuario[1] = segundo_parametro_envio; // adiciona as chaves do usuario em um vetor

    int verificacao = verificar_Para_Encryptar(primeiro_parametro_envio); // chama a funcao que verifica se pode cryptografar

    //printf("\n verificacao para cryptografar dentro da funcao cryptografar = %d \n", verificacao);

    if (verificacao == 1){
        printf("\n criptografado: ");

        for (long long int i = 0; i < quanti_caracteres; i++){

            criptografado[i] = percorrer_vetor[i] * primeiro_parametro_envio;

            printf("%lld", criptografado[i]);

            //putchar( criptografado[i] ); // caso queira visualizar em teclas do teclado
        }
        printf("\n");
        //desEncryptar(quanti_caracteres,criptografado);
    }
    else{
        printf("\n --> CHAVE INCORRETA, IMPOSSIVEL CRIPTOGRAFAR. <---\n");
    }
    return segundo_parametro_envio;
}
int verificar_Para_Enviar(int chave_privada_verificar){
    //return (memoria_chaves[2] == encryptar()) ? 1 : 0;
    return (memoria_chaves[2] == chave_privada_verificar) ? 1 : 0; //verifica se a chave privada do usuario esta correta, para que seja enviado
}

int desEncryptar(long long int quanti_caracter, long long int *criptografado){ //metodo para desEncryptar

    printf("\n Des_criptografado: ");
    for (int i = 0; i < quanti_caracter; i++){
        /*percorrer_vetor[i] += '0';*/

        //printf("%d", criptografado[i] / segundo_parametro_envio);

        putchar( criptografado[i] / primeiro_parametro_envio ); // caso queira visualizar em teclas do teclado
    }
    printf("\n");
    return 1;
}
