#include <stdio.h>
#include <string.h>

/*

A tarefa de Uzur é usar a chave fornecida por Nicholas para criptografar a mensagem do usuário. 

*/


int main(){
    
    char texto[1001];
    
    //printf("Olá, viajante! Imagino que tenhas para mim uma chave e um segredo, não?! Haha-");
    
    fgets(texto, sizeof(texto), stdin);
    
    int tamanho = strlen(texto);
    unsigned long long int equiv_num[tamanho]; //Equivalente numérico
    
    for (int i = 0; i < tamanho; i++) {
        equiv_num[i] = (unsigned long long int)texto[i]; 
    }
    
    // Exibindo o resultado
    printf("\nArray de inteiros gerado:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%llu", equiv_num[i]);
    }
    printf("\n");

    /*Caminho reverso (para teste)*/
     for (int i = 0; i < tamanho; i++) {
         texto[i] = (char)equiv_num[i]; 
    }
    printf("\nreverse:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%c", texto[i]);
    }
    



    
    return 0;

}