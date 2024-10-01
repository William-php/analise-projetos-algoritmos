#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

void analyze_algorithm(const char *code);

int main() {
    FILE *file;
    char filename[100];
    char line[MAX_LINE_LENGTH];
    
    printf("Digite o nome do arquivo com o código do algoritmo: ");
    scanf("%99s", filename);
    
    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }
    
    // Lê e armazena o código do algoritmo
    char *code = NULL;
    size_t code_size = 0;
    while (fgets(line, sizeof(line), file)) {
        size_t line_length = strlen(line);
        code = realloc(code, code_size + line_length + 1);
        if (code == NULL) {
            perror("Erro de alocação de memória");
            fclose(file);
            return 1;
        }
        strcpy(code + code_size, line);
        code_size += line_length;
    }
    
    fclose(file);
    
    if (code != NULL) {
        // Análise básica de complexidade
        analyze_algorithm(code);
        free(code);
    }
    
    return 0;
}

// Função conceitual para análise de complexidade
void analyze_algorithm(const char *code) {
    // Análise simples de complexidade baseada em padrões do código
    // Aqui você deve implementar uma análise real, o que é muito complexo
    // Então este é apenas um exemplo simples
    if (strstr(code, "for") != NULL) {
        printf("O código contém loops, a complexidade pode ser O(n) ou O(n^2).\n");
    } else {
        printf("Não foram encontrados loops no código. A análise mais detalhada é necessária.\n");
    }
}
