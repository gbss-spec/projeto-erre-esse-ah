#include <stdio.h>

/*

A tarefa de Uzur é usar a chave fornecida por Nicholas para criptografar a mensagem do usuário. 

*/


int main(){
    char message[200];

    //Ler mensagem
    scanf("%[^\n]", message);
    printf("%s", message);
    return 0;

}