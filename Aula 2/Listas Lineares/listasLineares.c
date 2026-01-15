// O jogador podera
// 1 - Inserir novos itens
// 2 - Remover itens existentes
// 3 - Listas todos os itens
// 4 - Buscar um iten pelo nome
// O objetivo é implementar um minissistema de gerenciamento de itens que quetiliza:
// - Vetor (Lista Estática)
// - Lista encadeada
// - Inserção
// - Remoção
// - Listagem de itens
// - Busca Linear
// - Comparação entre Busca manual (Humana) e autoraizada

// Tarefa 1
// Lista Estática
// Sistema de lista de compras
// Ferramentas do Sistema
// Adicionar itens
// Mas tem um limitador de quantiade de itens, se ultrapasar o valor acaba
// Pode remover intens
// Sitema de busca de itens
// E listagem dos itens

// Tarefa 2
// Em lista modular 
// Sistema de lista de compras
// Ferramentas do Sistema
// Pode adicionar intes
// Pode removelos
// Sistema de busca de itens
// e listalos

// biblioteca padrão
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função Gerais
// Limpa o buffer do scanf e do fgets
void limparBuffer(void){ // Função utilitária para limpar caracteres residuais no buffer do teclado
    int c; // Variável para armazenar temporariamente cada caractere lido
    while ((c = getchar()) != '\n' && c != EOF); // Consome caracteres até encontrar uma nova linha ou fim de arquivo
}

// Tarefa 1
// Define o tamanho maximo de itens
#define max_itens 10    // Define o tamanho maximo de uma array
#define max_string 100  // Define o tamanho maximo de uma variavel char

// Estrutura que representa a Lista Estática
typedef struct { 
    char dados[max_itens][max_string]; // Matriz: max_itens linhas, max_string colunas (Caracter por intem)
    
    int quantidade; // Contador de controle. Ele informa qunatos itens estão realmente armazenados na lista
} listaEstatica;

typedef struct No {
    char dados[max_string];   // UM item: "banana"
    struct No *proximo;       // aponta para o próximo item
} No;

typedef struct{
    No *inicio;
    int quantidade;
} listaDinamica;

// Objeto da lista dinâmica
listaDinamica *dinamicaLista;

// Objeto da lista estatica
listaEstatica estaticaLista;

// Declarando funções referentes a lista Estáticas
void inicialiarListaEstatica(listaEstatica *lista);

void inserirListaEstatica(listaEstatica *lista, const char * texto);
void removerListaEstatica(listaEstatica *lista, const char * texto);
void listarListaEstatica(const listaEstatica *lista);


// Declarando funções referentes a listas Dinâmicas
void inicializarListaDinamica(listaDinamica *lista);

void inserirListaDinamica(listaDinamica *lista, const char * texto);
void removerListaDinamica(listaDinamica *lista, const char * texto);
void listarListaDinamica(listaDinamica *lista);


// Criando funções de lista Estáticas
void inicialiarListaEstatica(listaEstatica *lista){
    lista->quantidade = 0;
}

void inserirListaEstatica(listaEstatica *lista, const char * texto){

    if (lista->quantidade >= max_itens){
        printf("Máximo de itens na lista!");
        return;
    }

    strcpy(lista->dados[lista->quantidade], texto);
    lista->quantidade ++;
    printf("Texto \"%s\" inserido com sucesso!\n", texto);

}

void removerListaEstatica(listaEstatica *lista, const char * texto){
    // O sitema de remoção funciona pegando o dado desejado
    // Pegando o seu dado anterior se ele existir e fazer com que ele sejá direcionado para o dado da frente
    // Para que fique interligados
    // dado1, dado2, dado3
    // Excluindo o dado 2
    // dado1, dado 3

    int i, pos = -1;

    for (i = 0; i < lista->quantidade; i++){
        if (strcmp(lista->dados[i], texto) == 0){
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        printf("Item não encontrado! \n");
        return;
    }

    for (i = pos; i < lista->quantidade; i++){
        strcpy(lista->dados[i], lista->dados[i + 1]);
    }

    lista->quantidade--;
    printf("Texto \"%s\" removido com sucesso! \n", texto);

}

void listarListaEstatica(const listaEstatica *lista){

    if (lista->quantidade <= 0){
        printf("Nenhum item cadastrado! \n");
        return;
    }

    printf("Itens da lista: [");


    for (int i = 0; i < lista->quantidade; i++){
        if (i == lista->quantidade - 1){
            printf("%s", lista->dados[i]);
        }else{
            printf("%s, ", lista->dados[i]);
        }
    }

    printf("] \n");
}

// Criando cunções de lista Dinâmicas
void inicializarListaDinamica(listaDinamica *lista){ // Iniciando a quantidade de intens na lista dinâmica
    lista->quantidade = 0;
}

void inserirListaDinamica(listaDinamica *lista, const char * texto){
    
    // Cria um novo nó na memória dinâmica
    // "malloc" reserva espaço suficiente para armazenar um nó completo (dados + ponteiro para próximo)
    No *novo = malloc(sizeof(No));

    // Copia o texto fornecido pelo usuário para o campo 'dados' do novo nó
    // Cada nó armazena sua própria string
    strcpy(novo->dados, texto);

    // Faz o novo nó apontar para o antigo início da lista
    // Isso garante que os nós existentes não sejam perdidos
    // Visualmente:
    // Antes: inicio -> banana -> maça -> NULL
    // Novo nó: novo -> ?
    // Após esta linha: novo -> banana -> maça -> NULL
    novo->proximo = lista->inicio;

    // Atualiza o início da lista para o novo nó
    // Agora o novo nó é o primeiro da lista
    // Exemplo final:
    // inicio -> pera -> banana -> maça -> NULL
    lista->inicio = novo;

    // Atualiza a quantidade de nós na lista (opcional, mas útil para menus e validações)
    lista->quantidade++;
}

// Funções de Menu
void menuEstatico(){

    int opcao;

    do{
        printf("\n------------------------------- \n");
        printf("--Sistema de Lista Estática--\n");
        printf("1 - Para adicionar itens na lisata\n");
        printf("2 - Para remover itens da lista\n");
        printf("3 - Para listar os itens da lista\n");
        printf("0 - Para sair do sistema de LIsta Estáticas\n");
        scanf("%d", &opcao);
        printf("------------------------------- \n");

        limparBuffer();

        switch (opcao)
        {
            case (0):{
                printf("\n------------------------------- \n");
                printf("Saindo do sistema de lista estáticas!\n");
                printf("------------------------------- \n");
                break;
            }
            break;
        
            case(1):{

                if (estaticaLista.quantidade >= max_itens){
                    printf("Itens máximo cadastrados\n");
                    printf("------------------------------- \n");
                    break;
                }
                
                char texto[max_string];

                printf("\n------------------------------- \n");
                printf("--Sistema de Adicionar Itens\n");
                printf("Adicione um item: ");
                fgets(texto, max_string, stdin);
                texto[strcspn(texto, "\n")] = '\0';
                

                inserirListaEstatica(&estaticaLista, texto);
                printf("------------------------------- \n");
            }break;

            case(2):{
                char texto[max_string];

                printf("\n------------------------------- \n");
                
                if (estaticaLista.quantidade <= 0){
                    printf("Não à itens cadastrados! \n");
                    printf("------------------------------- \n");
                    break;
                }
                
                printf("Qual item pretende excluir?");
                fgets(texto, max_string, stdin);
                texto[strcspn(texto, "\n")] = '\0';

                removerListaEstatica(&estaticaLista, texto);
                printf("------------------------------- \n");
            }break;

            case(3):{
                printf("\n------------------------------- \n");
                listarListaEstatica(&estaticaLista);
                printf("------------------------------- \n");
            }break;

            default:
                printf("\n------------------------------- \n");
                printf("Erro, opção invalidade!\n");
                printf("Rente novamente \n");
                printf("------------------------------- \n");
            break;
        }
    } while(opcao != 0);
}

int main(){

    int opcao;
    inicialiarListaEstatica(&estaticaLista);

    do {
        printf("\n---------------------\n");
        printf("--Sistema de Listas--\n");
        printf("1 - Lista Estática\n");
        printf("2 - Lista Dinâmica\n");
        printf("0 - Para sair do sistema\n");
        scanf("%d", &opcao);
        printf("---------------------\n");

        limparBuffer();

        switch (opcao)
        {
            case(0):{
                printf("Nunca é um adeus\n");
                break;
            }
            break;
            
            case(1):{
                menuEstatico();
            }break;

            default:
            printf("\n---------------------\n");
            printf("Opção indisponivel ou inesistente!\n");
            printf("Tente novamente\n");
            printf("---------------------\n");

            break;
        }
    } while(opcao != 0);
}