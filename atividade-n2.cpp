#include <stdio.h>

struct Funcionario {
    char nome[100];
    char cargo[100];
    double salarioBase, beneficios, descontos;

    void imprimir() {
        printf("\n - Nome: %s\n - Cargo: %s\n - Salario Base: %.2lf\n - Beneficio: %.2lf\n - Descontos: %.2lf\n - Salario Liquido: %.2lf\n\n\n"
        , nome, cargo, salarioBase, beneficios, descontos, calcularSalarioLiquido());
    }

    void ler() {
        printf("Nome:");
        scanf("%[^\n]%*c", nome);
         printf("Cargo:");
        scanf("%[^\n]%*c", cargo);
         printf("Salario base:");
        scanf("%lf%*c", &salarioBase);
         printf("Beneficios:");
        scanf("%lf%*c", &beneficios);
         printf("Descontos:");
        scanf("%lf%*c", &descontos);
    }

    double calcularSalarioLiquido() {
        return salarioBase + beneficios - descontos;
    }
};

struct Loja {
    Funcionario funcionarios[10];
    int qtdFuncionarios;

    Loja() {
        qtdFuncionarios = 0;
    }

    void cadastrarFuncionario() {

        if (qtdFuncionarios >= 10) {
            //printf("NOME:.\n - CARGO:");
            printf("Limite tingido.\n");
            return;
        }
        funcionarios[qtdFuncionarios].ler();
        qtdFuncionarios++;
    }

    void imprimirTodos() {
        if (qtdFuncionarios == 0) {
            printf(" ");
            printf("Loja vazia.\n");
            return;
        }
        for (int i = 0; i < qtdFuncionarios; i++) {
            funcionarios[i].imprimir();
        }
    }

    void imprimirMaiorSalario() {
        if (qtdFuncionarios == 0) {
            printf("Loja vazia.\n");
            return;
        }
        double maiorSalario = funcionarios[0].calcularSalarioLiquido();
        int indice = 0;
        for (int i = 1; i < qtdFuncionarios; i++) {
            double salarioLiquido = funcionarios[i].calcularSalarioLiquido();
            if (salarioLiquido > maiorSalario) {
                maiorSalario = salarioLiquido;
                indice = i;
            }
        }
        funcionarios[indice].imprimir();
    }

    void calcularMediaSalario() {
        if (qtdFuncionarios == 0) {
            printf("Loja vazia.\n");
            return;
        }
        double somaSalarios = 0;
        for (int i = 0; i < qtdFuncionarios; i++) {
            somaSalarios += funcionarios[i].calcularSalarioLiquido();
        }
        double mediaSalario = somaSalarios / qtdFuncionarios;
        printf("Media Salarial: %.2lf\n", mediaSalario);
    }
};

int main() {
    Loja l;

    int opcao;

    do {
        printf("1. Cadastrar Funcionario\n");
        printf("2. Imprimir todos\n");
        printf("3. Imprimir Maior Salario\n");
        printf("4. Calcular Media Salarial\n");
        printf("0. Sair\n");
        scanf("%d%*c", &opcao);
        switch (opcao) {
        case 1:
            l.cadastrarFuncionario();
            break;
        case 2:
            l.imprimirTodos();
            break;
        case 3:
            l.imprimirMaiorSalario();
            break;
        case 4:
            l.calcularMediaSalario();
            break;
        }
    } while (opcao != 0);

    return 0;
}
