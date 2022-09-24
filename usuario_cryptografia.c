
int primeiro_parametro_envio, segundo_parametro_envio;

/*int verificar_Para_Encryptar(int chave_publica_verificar, int chave_privada_verificar){
    return (memoria_chaves[0] * memoria_chaves[1] == chave_publica_verificar && memoria_chaves[2] == chave_privada_verificar) ? 1 : 0;
}*/

int encryptar (long int quanti_caracteres, long long *percorrer_vetor){
    long long criptografado[quanti_caracteres];

    primeiro_parametro_envio = chavePublica();
    segundo_parametro_envio = chavePrivadaEnvio();


    int para_usuario [2] = {primeiro_parametro_envio,segundo_parametro_envio};
    /*int verificacao = verificar_Para_Encryptar(primeiro_parametro_envio, segundo_parametro_envio);*/
    /*printf("\n verificacao = %d \n", verificacao);*/
    printf(" criptografado: \n\n");

    for (long int i = 0; i < quanti_caracteres; i++){
        /*percorrer_vetor[i] += '0';*/
        criptografado[i] = percorrer_vetor[i] * primeiro_parametro_envio;
        //criptografado[i] = percorrer_vetor[i];

        //printf("\n chave publica para criptografar %d \n\n",primeiro_parametro_envio);

        printf("%ld", criptografado[i]);

        //putchar( criptografado[i] ); // caso queira visualizar em teclas do teclado
    }

    //mostrando em binario:
    /*for (long int i = 0; i < quanti_caracteres; i++){
        int binario = criptografado[i] % 2;
        printf(" %d ", binario);
        if ( i % 10 == 0){
            printf("\n");
        }
    }*/

    //desEncryptar(quanti_caracteres,criptografado);
    return segundo_parametro_envio;
}

int desEncryptar(long int quanti_caracter, long long *criptografado){

    printf("\n Des_criptografado: \n\n");
    for (int i = 0; i < quanti_caracter; i++){
        /*percorrer_vetor[i] += '0';*/

        //printf("%d", criptografado[i] / segundo_parametro_envio);

        putchar( criptografado[i] / primeiro_parametro_envio ); // caso queira visualizar em teclas do teclado
    }
    return 1;
}
