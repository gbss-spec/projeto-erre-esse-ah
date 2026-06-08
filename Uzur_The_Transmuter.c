#include <stdio.h>
#include <string.h>

/*

A tarefa de Uzur é usar a chave fornecida por Nicholas para criptografar a mensagem do usuário. 

*/

//__________________Exponenciação Modular Rápida (Usada para cifrar os caracteres)
unsigned long long int ExMoRap(int modulo, int expoente, int equiv_num_car) {
    int result = 1; //Caso base

    // Loop until exponent becomes 0
    while(expoente >= 1) {
        
        // if odd, multiply result by current x and take modulo
        if(expoente % 2) {
            result = (result * modulo) % equiv_num_car;
            
            // Reduce exponent by 1 to make it even
            expoente--;  
        }
        
        // if even, square the base and halve the exponent
        else {
            modulo = (modulo * modulo) % equiv_num_car;
            expoente /= 2;
        }
    }
    return result;
}

int main(){
    
    unsigned long long int modulo, expoente;
    char texto[1001];
    
    printf("Olá, viajante! Diga-me o par de números que compõem sua chave, separando-os com um espaço.");
    scanf("%llu %llu", &modulo, &expoente);


    fgets(texto, sizeof(texto), stdin);
    
    int tamanho = strlen(texto);
    unsigned long long int equiv_num[tamanho]; //Equivalente numérico
    
    for (int i = 0; i < tamanho; i++) {
        equiv_num[i] = (unsigned long long int)texto[i]; 
    }


    //Escrever mensagem criptografada em txt usando exponenciação modular rápida
    char* filename = "Criptografado.txt";

        FILE* fptr = fopen(filename, "w");

    if(fptr == NULL)
    {
        printf("Error: could not open file '%s'.\n", filename);
        return 1;
    }

    /* Engrave the Elusive Message on the document */
    for (int i = 0; i < tamanho; i++) {
        fprintf("%d ", ExMoRap(modulo, expoente, equiv_num[i]));
    }

    /* Close the file */
    fclose(fptr);



    /*Exibindo o resultado
    printf("\nArray de inteiros gerado:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%llu", equiv_num[i]);
    }
    printf("\n");*/

    /*Caminho reverso (para teste)
     for (int i = 0; i < tamanho; i++) {
         texto[i] = (char)equiv_num[i]; 
    }
    printf("\nreverse:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%c", texto[i]);
    }
    */
    



    
    return 0;

}