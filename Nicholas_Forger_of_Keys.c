#include <stdio.h>
#include <stdbool.h>
#include <math.h>

/*Nicholas tem como objetivo:
- Ler um par de números primos a1 e a2;
- Ler um expoente e que seja relativamente primo a (p-1)(q-1);
- Produzir um arquivo txt com os dois números que formam a chave pública;
*/


//Função para checar se um número n é primo
bool primo_check(unsigned long long int n){
    
    if (n<2)return 0; //Caso base: Se n é menor que 2, ele não é primo. Responder "falso".
    if (n%2==0)return 0; //Caso n seja par, ele não é primo. Responder "falso".
    for (int i=3;i<=sqrt(n);i+=2){//O loop checa a divisão de n por todos os números ímpares até sqrt(n)
        if (n%i==0)return 0;//Se alguma divisão retornar resto 0, n não é primo. 
    }

    return 1;//Se nenhum dos anteriores aconteceu, retornar 1 (Verdadeiro, n é primo).

}





int main(){

    unsigned long long int entrada1, entrada2; //Ao usar unsigned, esta variável expande sua capacidade de representar grandes números positivos, em detrimento de sua capacidade de representar números negativos. 

    //Diálogo de Nicholas.
    printf("Bem vindo, filho... Há algo que queiras proteger? Conta-me sobre números interessantes e dar-te-ei trancas em que podes confiar...\n");
    printf("Conta-me de dois números primos... Que sejam grandes... Com, pelo menos, 6 dígitos...\n");
    

    for (int i=0;i<=1;i++){//Loop para ler entradas
    
        //Primeira leitura (entrada1)
        if (i==0){

            scanf("%llu", &entrada1);
            
            //Caso entrada1 tenha menos que 6 dígitos...
            if(entrada1<100000){
                //Nicholas nega a entrada e pede que o usuário tente novamente. 
                printf("hmmphmm... Este número é muito pequeno... Não daria uma chave boa... Tentas um número maior...\n");
                i--;
                }

            //Invoca função primo_check para dizer se o número é primo ou não
            else if (primo_check(entrada1)==0){
                //Subtrai 1 de i para que a leitura de entrada1 seja feita novamente. 
                printf("Hmmphm.. Este número não é primo... Tentas mais uma vez...\n");
                i--;
                }
            
            
            

        //Segunda leitura (Completamente análoga à primeira).
        else if (i==1){
            scanf("%llu", &entrada2);
            
            if(entrada1<100000){
                printf("hmmphmm... Este número é muito pequeno... Não daria uma chave boa... Tentas um número maior...\n");
                i--;
                }

            else if (primo_check(entrada2)==0){
                printf("Hmmphm.. Este número não é primo... Tentas mais uma vez...\n");
                i--;
                }
            
            
            }
        }
    }

    printf("%llu %llu", entrada1, entrada2);


}