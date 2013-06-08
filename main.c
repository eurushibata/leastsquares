#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    FILE *fp;
    int total, i;
    float mat[100][2], x=0, y=0, x2=0, lny=0, xlny=0, v1, v2, a=0, a1=0, b=0;
    
    // Abre o arquivo
    fp = fopen("dadoscap.txt", "r");
    
    // Verifica se o arquivo dadoscap.txt existe
    if (fp == NULL) {
        printf("Não foi possível encontrar o arquivo \'dadoscap.txt\'\n");
        exit(0);
    } else {
        // Leitura da primeira linha (total de pontos coletados)
        fscanf(fp, "%d", &total);
        i = 0;
        // Executar a iteração até que os termos acabem
        while (!feof(fp)) {
            // A última iteração não é executada, evitando que i seja maior que q quantidade
            // de valores coletados
            if (i==total) {
                break;
            }
            // Leitura das colunas do arquivo
            fscanf(fp, "%f %f", &v1, &v2);
            // A função é do tipo não linear, logo precisamos linearizá-la, aplicando log
            // Cálculo das somatórias para aplicação do sistema
            x = v1 + x;
            y = v2 + y;
            x2 = v1*v1 + x2;
            lny = log(v2) + lny;
            xlny = v1*log(v2) + xlny;
            i++;
        }
        // Cálculo do sistema
        a1 = (x2*lny-x*xlny)/(total*x2-pow(x,2));
        a = exp(a1);
        b = (total*xlny-x*lny)/(total*x2-pow(x,2));
        // Impressão dos valores de V0 e RC
        // Obs.: RC = -1/b como na fórmula apresentada na descrição do trabalho.
        printf("V0=%f  RC=%f \n", a, -1/b);
    }
    
    // Fecha o arquivo
    fclose(fp);
    return 0;
}