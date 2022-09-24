
#define INICIOLIMITE 10
#define FINALLIMITE 100

int chavePrimo(int numero){
    int memoria2 = numero; /*variavel para armazenar decremento de numero*/
    int sinal; /*sinal para sinaliza��o caso primo == 1*/
    while (memoria2 >= 3){
        memoria2--; /*decremento de numero*/
        if (numero % memoria2 == 0){ /*operacao matematica para verificar se nao � primo*/
            sinal = 0;
            break;
        }
        else{
            sinal = 1;
        }
    }

    return sinal;
}

int gerarChave(){
    int verificar; /*variavel para armazenar numero gerado*/
    verificar = INICIOLIMITE + (rand() % FINALLIMITE); /*randomizar um numero*/
    return (chavePrimo(verificar) == 0) ? gerarChave(): verificar; /*chamada recursiva para verificar se � um numero primo*/
}





