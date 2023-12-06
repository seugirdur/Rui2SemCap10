#include <stdio.h>
#define Ex104


#ifdef Ex101


int main() {
    FILE *arquivo;
    char caractere;

    arquivo = fopen("arq.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao criar ou abrir o arquivo.\n");
        return 1;
    }

    printf("Digite caracteres (0 para finalizar):\n");
    do {
        scanf(" %c", &caractere);
        if (caractere != '0') {
            fputc(caractere, arquivo);
        }
    } while (caractere != '0');

    fclose(arquivo);

    arquivo = fopen("arq.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return 1;
    }
    printf("\nConteudo do arquivo:\n");
    while ((caractere = fgetc(arquivo)) != EOF) {
        printf("%c\n", caractere);
    }
    fclose(arquivo);

    return 0;
}

#endif

#ifdef Ex102
#include <stdlib.h>

struct Contato {
    char nome[50];
    char telefone[15];
    int dia_aniversario;
    int mes_aniversario;
};

void inserirContato(struct Contato *contatos);
void listarContatos(struct Contato *contatos);
void pesquisarContatoPorNome(struct Contato *contatos);
void listarContatosPorLetra(struct Contato *contatos);
void imprimirAniversariantesDoMes(struct Contato *contatos);
void alterarContato(struct Contato *contatos);
void excluirContato(struct Contato *contatos);
void salvarContatosNoArquivo(struct Contato *contatos);
void carregarContatosDoArquivo(struct Contato *contatos);

int main() {
    struct Contato contatos[4];
    carregarContatosDoArquivo(contatos);

    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Inserir contato\n");
        printf("2. Listar todos os contatos\n");
        printf("3. Pesquisar contato pelo nome\n");
        printf("4. Listar contatos por letra inicial\n");
        printf("5. Imprimir aniversariantes do mes\n");
        printf("6. Alterar contato\n");
        printf("7. Excluir contato\n");
        printf("8. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirContato(contatos);
                break;
            case 2:
                listarContatos(contatos);
                break;
            case 3:
                pesquisarContatoPorNome(contatos);
                break;
            case 4:
                listarContatosPorLetra(contatos);
                break;
            case 5:
                imprimirAniversariantesDoMes(contatos);
                break;
            case 6:
                alterarContato(contatos);
                break;
            case 7:
                excluirContato(contatos);
                break;
            case 8:
                salvarContatosNoArquivo(contatos);
                printf("Saindo do programa. Obrigado!\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 8);

    return 0;
}

void inserirContato(struct Contato *contatos) {
    for (int i = 0; i < 4; ++i) {
        if (contatos[i].nome[0] == '\0') {
            printf("\nInserindo novo contato:\n");
            printf("Nome: ");
            scanf("%s", contatos[i].nome);
            printf("Telefone: ");
            scanf("%s", contatos[i].telefone);
            printf("Dia do aniversario: ");
            scanf("%d", &contatos[i].dia_aniversario);
            printf("Mes do aniversario: ");
            scanf("%d", &contatos[i].mes_aniversario);
            printf("Contato inserido com sucesso.\n");
            return;
        }
    }

    printf("A agenda esta cheia. Nao e possivel inserir mais contatos.\n");
}

void listarContatos(struct Contato *contatos) {
    printf("\nLista de contatos:\n");
    for (int i = 0; i < 4; ++i) {
        if (contatos[i].nome[0] != '\0') {
            printf("\nContato %d:\n", i + 1);
            printf("Nome: %s\n", contatos[i].nome);
            printf("Telefone: %s\n", contatos[i].telefone);
            printf("Aniversario: %d/%d\n", contatos[i].dia_aniversario, contatos[i].mes_aniversario);
        }
    }
}

void pesquisarContatoPorNome(struct Contato *contatos) {
    char nome[50];
    printf("\nDigite o nome para pesquisar: ");
    scanf("%s", nome);

    for (int i = 0; i < 4; ++i) {
        int j;
        for (j = 0; contatos[i].nome[j] != '\0' && nome[j] != '\0'; ++j) {
            if (contatos[i].nome[j] != nome[j]) {
                break;
            }
        }

        if (contatos[i].nome[j] == '\0' && nome[j] == '\0') {
            printf("\nContato encontrado:\n");
            printf("Nome: %s\n", contatos[i].nome);
            printf("Telefone: %s\n", contatos[i].telefone);
            printf("Aniversario: %d/%d\n", contatos[i].dia_aniversario, contatos[i].mes_aniversario);
            return;
        }
    }

    printf("Contato nao encontrado.\n");
}

void listarContatosPorLetra(struct Contato *contatos) {
    char letra;
    printf("\nDigite a letra inicial para listar contatos: ");
    scanf(" %c", &letra);

    printf("\nContatos com nome iniciando com '%c':\n", letra);
    for (int i = 0; i < 4; ++i) {
        if (contatos[i].nome[0] != '\0' && contatos[i].nome[0] == letra) {
            printf("\nContato %d:\n", i + 1);
            printf("Nome: %s\n", contatos[i].nome);
            printf("Telefone: %s\n", contatos[i].telefone);
            printf("Aniversario: %d/%d\n", contatos[i].dia_aniversario, contatos[i].mes_aniversario);
        }
    }
}

void imprimirAniversariantesDoMes(struct Contato *contatos) {
    int mes;
    printf("\nDigite o mes para listar aniversariantes: ");
    scanf("%d", &mes);

    printf("\nAniversariantes do mes %d:\n", mes);
    for (int i = 0; i < 4; ++i) {
        if (contatos[i].nome[0] != '\0' && contatos[i].mes_aniversario == mes) {
            printf("\nContato %d:\n", i + 1);
            printf("Nome: %s\n", contatos[i].nome);
            printf("Telefone: %s\n", contatos[i].telefone);
            printf("Aniversario: %d/%d\n", contatos[i].dia_aniversario, contatos[i].mes_aniversario);
        }
    }
}

void alterarContato(struct Contato *contatos) {
    char nome[50];
    printf("\nDigite o nome do contato para alterar: ");
    scanf("%s", nome);

    for (int i = 0; i < 4; ++i) {
        int j;
        for (j = 0; contatos[i].nome[j] != '\0' && nome[j] != '\0'; ++j) {
            if (contatos[i].nome[j] != nome[j]) {
                break;
            }
        }

        if (contatos[i].nome[j] == '\0' && nome[j] == '\0') {
            printf("\nAlterando o contato:\n");
            printf("Novo Nome: ");
            scanf("%s", contatos[i].nome);
            printf("Novo Telefone: ");
            scanf("%s", contatos[i].telefone);
            printf("Novo Dia do Aniversario: ");
            scanf("%d", &contatos[i].dia_aniversario);
            printf("Novo Mes do Aniversario: ");
            scanf("%d", &contatos[i].mes_aniversario);
            printf("Contato alterado com sucesso.\n");
            return;
        }
    }

    printf("Contato nao encontrado.\n");
}

void excluirContato(struct Contato *contatos) {
    char nome[50];
    printf("\nDigite o nome do contato para excluir: ");
    scanf("%s", nome);

    for (int i = 0; i < 4; ++i) {
        int j;
        for (j = 0; contatos[i].nome[j] != '\0' && nome[j] != '\0'; ++j) {
            if (contatos[i].nome[j] != nome[j]) {
                break;
            }
        }

        if (contatos[i].nome[j] == '\0' && nome[j] == '\0') {
            printf("\nExcluindo o contato:\n");
            contatos[i].nome[0] = '\0';
            contatos[i].telefone[0] = '\0';
            contatos[i].dia_aniversario = 0;
            contatos[i].mes_aniversario = 0;
            printf("Contato excluido com sucesso.\n");
            return;
        }
    }

    printf("Contato nao encontrado.\n");
}
void salvarContatosNoArquivo(struct Contato *contatos) {
    FILE *arquivo;
    arquivo = fopen("contatos.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao criar ou abrir o arquivo de contatos.\n");
        exit(1);
    }

    for (int i = 0; i < 4; ++i) {
        if (contatos[i].nome[0] != '\0') {
            fprintf(arquivo, "%s %s %d %d\n", contatos[i].nome, contatos[i].telefone,
                    contatos[i].dia_aniversario, contatos[i].mes_aniversario);
        }
    }

    fclose(arquivo);
}

void carregarContatosDoArquivo(struct Contato *contatos) {
    FILE *arquivo;
    arquivo = fopen("contatos.txt", "r");

    if (arquivo == NULL) {
        for (int i = 0; i < 4; ++i) {
            contatos[i].nome[0] = '\0';
        }
        return;
    }

    for (int i = 0; i < 4; ++i) {
        if (fscanf(arquivo, "%s %s %d %d", contatos[i].nome, contatos[i].telefone,
                   &contatos[i].dia_aniversario, &contatos[i].mes_aniversario) != 4) {
            break;
        }
    }

    fclose(arquivo);
}


#endif


#ifdef Ex103

struct Produto {
    int codigo;
    char nome[50];
    int quantidade;
};

void incluirProdutos(FILE *arquivo);
void listarTodosProdutos(FILE *arquivo);
void pesquisarPorDescricao(FILE *arquivo);
void listarProdutosNaoDisponiveis(FILE *arquivo);
void alterarQuantidade(FILE *arquivo);
void alterarProduto(FILE *arquivo);
void excluirProduto(FILE *arquivo);

int main() {
    FILE *arquivo;
    arquivo = fopen("mercadorias.txt", "r+");

    if (arquivo == NULL) {
        arquivo = fopen("mercadorias.txt", "w+");
        if (arquivo == NULL) {
            printf("Erro ao criar ou abrir o arquivo de mercadorias.\n");
            return 1;
        }
    }

    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Incluir produtos\n");
        printf("2. Listar todos os produtos\n");
        printf("3. Pesquisar mercadoria pela descricao\n");
        printf("4. Listar produtos nao disponiveis\n");
        printf("5. Alterar quantidade atual\n");
        printf("6. Alterar produtos\n");
        printf("7. Excluir produtos\n");
        printf("8. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                incluirProdutos(arquivo);
                break;
            case 2:
                listarTodosProdutos(arquivo);
                break;
            case 3:
                pesquisarPorDescricao(arquivo);
                break;
            case 4:
                listarProdutosNaoDisponiveis(arquivo);
                break;
            case 5:
                alterarQuantidade(arquivo);
                break;
            case 6:
                alterarProduto(arquivo);
                break;
            case 7:
                excluirProduto(arquivo);
                break;
            case 8:
                printf("Saindo do programa. Obrigado!\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 8);

    fclose(arquivo);

    return 0;
}

void incluirProdutos(FILE *arquivo) {
    fseek(arquivo, 0, SEEK_END);

    struct Produto produto;
    printf("\nIncluindo novo produto:\n");
    printf("Codigo: ");
    scanf("%d", &produto.codigo);
    printf("Nome: ");
    scanf("%s", produto.nome);
    printf("Quantidade: ");
    scanf("%d", &produto.quantidade);

    fwrite(&produto, sizeof(struct Produto), 1, arquivo);

    printf("Produto incluido com sucesso.\n");
}

void listarTodosProdutos(FILE *arquivo) {
    fseek(arquivo, 0, SEEK_SET);

    struct Produto produto;

    printf("\nLista de todos os produtos:\n");

    while (fread(&produto, sizeof(struct Produto), 1, arquivo) == 1) {
        printf("\nCodigo: %d\n", produto.codigo);
        printf("Nome: %s\n", produto.nome);
        printf("Quantidade: %d\n", produto.quantidade);
    }
}

void pesquisarPorDescricao(FILE *arquivo) {
    fseek(arquivo, 0, SEEK_SET);

    struct Produto produto;
    char descricao[50];

    printf("\nDigite a descricao para pesquisar: ");
    scanf("%s", descricao);

    int encontrado = 0;

    while (fread(&produto, sizeof(struct Produto), 1, arquivo) == 1) {
        int i;
        for (i = 0; produto.nome[i] != '\0' && descricao[i] != '\0'; ++i) {
            if (produto.nome[i] != descricao[i]) {
                break;
            }
        }

        if (produto.nome[i] == '\0' && descricao[i] == '\0') {
            printf("\nProduto encontrado:\n");
            printf("Codigo: %d\n", produto.codigo);
            printf("Nome: %s\n", produto.nome);
            printf("Quantidade: %d\n", produto.quantidade);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Produto nao encontrado.\n");
    }
}

void listarProdutosNaoDisponiveis(FILE *arquivo) {
    fseek(arquivo, 0, SEEK_SET);

    struct Produto produto;

    printf("\nLista de produtos nao disponiveis:\n");

    while (fread(&produto, sizeof(struct Produto), 1, arquivo) == 1) {
        if (produto.quantidade == 0) {
            printf("\nCodigo: %d\n", produto.codigo);
            printf("Nome: %s\n", produto.nome);
            printf("Quantidade: %d\n", produto.quantidade);
        }
    }
}

void alterarQuantidade(FILE *arquivo) {
    fseek(arquivo, 0, SEEK_SET);

    struct Produto produto;
    int codigo, novaQuantidade;

    printf("\nDigite o codigo do produto para alterar a quantidade: ");
    scanf("%d", &codigo);

    int encontrado = 0;

    while (fread(&produto, sizeof(struct Produto), 1, arquivo) == 1) {
        if (produto.codigo == codigo) {
            encontrado = 1;
            printf("\nProduto encontrado:\n");
            printf("Codigo: %d\n", produto.codigo);
            printf("Nome: %s\n", produto.nome);
            printf("Quantidade atual: %d\n", produto.quantidade);

            printf("\nDigite a nova quantidade: ");
            scanf("%d", &novaQuantidade);

            produto.quantidade = novaQuantidade;

            fseek(arquivo, -sizeof(struct Produto), SEEK_CUR);
            fwrite(&produto, sizeof(struct Produto), 1, arquivo);
            printf("Quantidade alterada com sucesso.\n");

            break;
        }
    }

    if (!encontrado) {
        printf("Produto nao encontrado.\n");
    }
}

void alterarProduto(FILE *arquivo) {
    fseek(arquivo, 0, SEEK_SET);

    struct Produto produto;
    int codigo;

    printf("\nDigite o codigo do produto para alterar: ");
    scanf("%d", &codigo);

    int encontrado = 0;

    while (fread(&produto, sizeof(struct Produto), 1, arquivo) == 1) {
        if (produto.codigo == codigo) {
            encontrado = 1;
            printf("\nProduto encontrado:\n");
            printf("Codigo: %d\n", produto.codigo);
            printf("Nome atual: %s\n", produto.nome);
            printf("Quantidade atual: %d\n", produto.quantidade);

            printf("\nDigite o novo nome: ");
            scanf("%s", produto.nome);

            fseek(arquivo, -sizeof(struct Produto), SEEK_CUR);
            fwrite(&produto, sizeof(struct Produto), 1, arquivo);
            printf("Produto alterado com sucesso.\n");

            break;
        }
    }

    if (!encontrado) {
        printf("Produto nao encontrado.\n");
    }
}

void excluirProduto(FILE *arquivo) {
    fseek(arquivo, 0, SEEK_SET);

    struct Produto produto;
    int codigo;

    printf("\nDigite o codigo do produto para excluir: ");
    scanf("%d", &codigo);

    int encontrado = 0;

    while (fread(&produto, sizeof(struct Produto), 1, arquivo) == 1) {
        if (produto.codigo == codigo) {
            encontrado = 1;
            printf("\nProduto encontrado:\n");
            printf("Codigo: %d\n", produto.codigo);
            printf("Nome: %s\n", produto.nome);
            printf("Quantidade: %d\n", produto.quantidade);

            printf("\nExcluindo o produto...\n");
            produto.codigo = 0;

            fseek(arquivo, -sizeof(struct Produto), SEEK_CUR);
            fwrite(&produto, sizeof(struct Produto), 1, arquivo);
            printf("Produto excluido com sucesso.\n");

            break;
        }
    }

    if (!encontrado) {
        printf("Produto nao encontrado.\n");
    }
}

#endif

#ifdef Ex104


struct Cliente {
    char nome[50];
    char email[50];
    char celular[15];
};

void incluirRegistros(FILE *arquivo);
void listarTodosRegistros(FILE *arquivo);
void pesquisarPorNome(FILE *arquivo);
void alterarRegistro(FILE *arquivo);
void excluirRegistro(FILE *arquivo);

int main() {
    FILE *arquivo;
    arquivo = fopen("clientes.txt", "r+");

    if (arquivo == NULL) {
        arquivo = fopen("clientes.txt", "w+");
        if (arquivo == NULL) {
            printf("Erro ao criar ou abrir o arquivo de clientes.\n");
            return 1;
        }
    }

    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Incluir registros\n");
        printf("2. Listar todos os registros\n");
        printf("3. Pesquisar registro pelo nome\n");
        printf("4. Alterar registro\n");
        printf("5. Excluir registro\n");
        printf("6. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                incluirRegistros(arquivo);
                break;
            case 2:
                listarTodosRegistros(arquivo);
                break;
            case 3:
                pesquisarPorNome(arquivo);
                break;
            case 4:
                alterarRegistro(arquivo);
                break;
            case 5:
                excluirRegistro(arquivo);
                break;
            case 6:
                printf("Saindo do programa. Obrigado!\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 6);

    fclose(arquivo);

    return 0;
}

void incluirRegistros(FILE *arquivo) {
    fseek(arquivo, 0, SEEK_END);

    struct Cliente cliente;
    printf("\nIncluindo novo registro:\n");
    printf("Nome: ");
    scanf("%s", cliente.nome);
    printf("Email: ");
    scanf("%s", cliente.email);
    printf("Celular: ");
    scanf("%s", cliente.celular);

    fwrite(&cliente, sizeof(struct Cliente), 1, arquivo);

    printf("Registro incluido com sucesso.\n");
}

void listarTodosRegistros(FILE *arquivo) {
    fseek(arquivo, 0, SEEK_SET);

    struct Cliente cliente;

    printf("\nLista de todos os registros:\n");

    while (fread(&cliente, sizeof(struct Cliente), 1, arquivo) == 1) {
        printf("\nNome: %s\n", cliente.nome);
        printf("Email: %s\n", cliente.email);
        printf("Celular: %s\n", cliente.celular);
    }
}

void pesquisarPorNome(FILE *arquivo) {
    fseek(arquivo, 0, SEEK_SET);

    struct Cliente cliente;
    char nome[50];

    printf("\nDigite o nome para pesquisar: ");
    scanf("%s", nome);

    int encontrado = 0;

    while (fread(&cliente, sizeof(struct Cliente), 1, arquivo) == 1) {
        int i;
        for (i = 0; cliente.nome[i] != '\0' && nome[i] != '\0'; ++i) {
            if (cliente.nome[i] != nome[i]) {
                break;
            }
        }

        if (cliente.nome[i] == '\0' && nome[i] == '\0') {
            printf("\nRegistro encontrado:\n");
            printf("Nome: %s\n", cliente.nome);
            printf("Email: %s\n", cliente.email);
            printf("Celular: %s\n", cliente.celular);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Registro nao encontrado.\n");
    }
}

void alterarRegistro(FILE *arquivo) {
    fseek(arquivo, 0, SEEK_SET);

    struct Cliente cliente;
    char nome[50];

    printf("\nDigite o nome do registro para alterar: ");
    scanf("%s", nome);

    int encontrado = 0;

    while (fread(&cliente, sizeof(struct Cliente), 1, arquivo) == 1) {
        int i;
        for (i = 0; cliente.nome[i] != '\0' && nome[i] != '\0'; ++i) {
            if (cliente.nome[i] != nome[i]) {
                break;
            }
        }

        if (cliente.nome[i] == '\0' && nome[i] == '\0') {
            encontrado = 1;
            printf("\nAlterando o registro:\n");
            printf("Novo Nome: ");
            scanf("%s", cliente.nome);
            printf("Novo Email: ");
            scanf("%s", cliente.email);
            printf("Novo Celular: ");
            scanf("%s", cliente.celular);

            fseek(arquivo, -sizeof(struct Cliente), SEEK_CUR);
            fwrite(&cliente, sizeof(struct Cliente), 1, arquivo);
            printf("Registro alterado com sucesso.\n");

            break;
        }
    }

    if (!encontrado) {
        printf("Registro nao encontrado.\n");
    }
}

void excluirRegistro(FILE *arquivo) {
    fseek(arquivo, 0, SEEK_SET);

    struct Cliente cliente;
    char nome[50];

    printf("\nDigite o nome do registro para excluir: ");
    scanf("%s", nome);

    int encontrado = 0;

    while (fread(&cliente, sizeof(struct Cliente), 1, arquivo) == 1) {
        int i;
        for (i = 0; cliente.nome[i] != '\0' && nome[i] != '\0'; ++i) {
            if (cliente.nome[i] != nome[i]) {
                break;
            }
        }

        if (cliente.nome[i] == '\0' && nome[i] == '\0') {
            encontrado = 1;
            printf("\nExcluindo o registro:\n");

            cliente.nome[0] = '\0';
            cliente.email[0] = '\0';
            cliente.celular[0] = '\0';

            fseek(arquivo, -sizeof(struct Cliente), SEEK_CUR);
            fwrite(&cliente, sizeof(struct Cliente), 1, arquivo);
            printf("Registro excluido com sucesso.\n");

            break;
        }
    }

    if (!encontrado) {
        printf("Registro nao encontrado.\n");
    }
}

#endif