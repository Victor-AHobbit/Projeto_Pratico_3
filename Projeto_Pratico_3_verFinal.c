//Nome completo: Victor Araújo da Silva Brito
//Matricula: UC21105910
//Curso: Ciências da Computação

//Nome completo: Maiky Silverio Freires
//Matricula: UC20104316
//Curso: Ciências da Computação

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <locale.h>

//STRUCT
typedef struct cadastro user;
struct cadastro
{
    int id;
    char nome[100], email[100], sexo[100], endereco[100];
    double altura;
    bool vacina;
    user *proximo;

} * info, *backup = NULL;

//FUNCAO
user *inicializar();
void fazerCadastro();
void excluirUsuario();
void fazerBackup();
void cadastroId(user *novo_cad);
void cadastroNome(user *novo_cad);
void cadastroEmail(user *novo_cad);
void cadastroSexo(user *novo_cad);
void cadastroEndereco(user *novo_cad);
void cadastroAltura(user *novo_cad);
void cadastroVacina(user *novo_cad);
void editar();
void listar(user *info);
void buscarId(user *info);
void buscarEmail(user *info);
void limpezaBackup();
void limpezaInfo();
void menu();

//=====
int main()
{
    
    setlocale(LC_ALL, "Portuguese");
    int opcao = 0, escolha = 0;

    info = inicializar();
    backup = inicializar();
    do
    {
        menu();
        fflush(stdin);
        scanf("%d", &opcao);
        while (opcao < 1 || opcao > 8)
        {
            printf("\n\t\t\t\t  Menu invalido, digite apenas os disponiveis: ");
            fflush(stdin);
            scanf("%d", &opcao);
        }
        switch (opcao)
        {
        case 1:
            fazerCadastro();
            break;
        case 2:
            editar();
            break;
        case 3:
            excluirUsuario();
            break;
        case 4:
            system("cls");
            printf("_-_-_-_-_-_-_-_-_-_-_BUSCAR USUARIO-_-_-_-_-_-_-_-_-_\n");
            printf("\n1 - Procurar por Id");
            printf("\n2 - Procurar por Email");
            printf("\n3 - Voltar ao Menu");
            printf("\n\n_-_-_-_-DIGITE O NUMERO DA OPCAO PARA PROSSEGUIR-_-_-_-_\n");
            fflush(stdin);
            scanf("%d", &escolha);
            if (escolha == 1)
            {
                buscarId(info);
            }
            else if (escolha == 2)
            {
                buscarEmail(info);
            }
            else
            {
                printf("\nVoltando ao menu. . .");
                getch();
            }
            break;
        case 5:
            listar(info);
            break;
        case 6:
            fazerBackup();
            break;
        case 7:
            system("cls");
            printf("Nome completo: Victor Araujo da Silva Brito\n");
            printf("Matricula: UC21105910\n");
            printf("Curso: Ciencias da Computacao\n\n");
            printf("Nome completo: Maiky Silverio Freires\n");
            printf("Matricula: UC20104316\n");
            printf("Curso: Ciencias da Computacao\n");
            getch();
        default:
            break;
        }
    } while (opcao != 8);
limpezaInfo ();
limpezaBackup ();
}
void limpezaInfo()
{
     user *p = info, *q;
    while (p != NULL) {
        q = p;
        p = p->proximo;
        free(q);
    }
    info = inicializar(); 
      
}
void limpezaBackup()
{
     user *p = backup, *q;
    while (p != NULL) {
        q = p;
        p = p->proximo;
        free(q);
    }
    backup = inicializar(); 
}
void menu()
{
    system("cls");
    printf("\t\t\t     _-_-_-_-_-_-[BEM VINDO AO PROGRAMA USUARIO]-_-_-_-_-_-_\n");
    printf("\n\n\t\t\t\t|| [1]Adicionar Usuario || [2]Editar Usuario   ||");
    printf("\n\n\t\t\t\t|| [3]Excluir Usuario   || [4]Buscar Usuario   ||");
    printf("\n\n\t\t\t\t|| [5]Listar Usuarios   || [6]Realizar Backup  ||");
    printf("\n\n\t\t\t\t|| [7]Creditos          || [8]Fechar Programa  ||");
    printf("\n\n\t\t\t  SELECIONE UMA DAS OPCOES A CIMA PARA CONTINUAR O PROGRAMA: ");
}

user *inicializar()
{
    return NULL;
}

void fazerCadastro()
{
    user *novo_cad = (user *)malloc(sizeof(info));
    system("cls");
    printf("_-_-_-_-_-_-_-_ ADICIONAR USUARIO _-_-_-_-_-_-_-_\n");

    cadastroId(novo_cad);

    cadastroNome(novo_cad);

    cadastroEmail(novo_cad);

    cadastroSexo(novo_cad);

    cadastroEndereco(novo_cad);

    cadastroAltura(novo_cad);

    cadastroVacina(novo_cad);

    getch();

    system("cls");
    printf("Id: %d\n", novo_cad->id);
    printf("Nome: %s\n", novo_cad->nome);
    printf("Email: %s\n", novo_cad->email);
    printf("Sexo: %s\n", novo_cad->sexo);
    printf("Endereco: %s\n", novo_cad->endereco);
    printf("Altura: %0.2lf\n", novo_cad->altura);
    novo_cad->vacina ? printf("Vacina: Dose aplicada!\n") : printf("Vacina: Dose nao aplicada!\n");
    getch();
    novo_cad->proximo = info;
    info = novo_cad;
}

void cadastroId(user *novo_cad)
{
    srand(time(NULL));
    novo_cad->id = (rand() % (1000 - 1 + 1)) + 1;
    printf("Id: %d\n", novo_cad->id);
    fflush(stdin);
}

void cadastroNome(user *novo_cad)
{
    printf("\nDigite o nome a ser cadastrado: ");
    scanf("%s", novo_cad->nome);
    fflush(stdin);
}

void cadastroEmail(user *novo_cad)
{
    printf("\nDigite o email a ser cadastrado(Necessario um @): ");
    scanf("%s", novo_cad->email);
    fflush(stdin);
}

void cadastroSexo(user *novo_cad)
{
    printf("\nDigite o sexo a ser registrado(Masculino, Feminino ou Nao declarar): ");
    scanf("%s", novo_cad->sexo);
    fflush(stdin);
}

void cadastroEndereco(user *novo_cad)
{
    printf("\nDigite o endereco do usuario: ");
    scanf("%s", novo_cad->endereco);
    fflush(stdin);
}

void cadastroAltura(user *novo_cad)
{
    do
    {
        printf("\nDigite a altura a ser cadastrada: ");

        scanf("%lf", &novo_cad->altura);
        if (novo_cad->altura < 1 || novo_cad->altura > 2)
        {
            printf("\nAltura invalida! Digite novamente");
        }
    } while (novo_cad->altura < 1 || novo_cad->altura > 2);

    fflush(stdin);
}

void cadastroVacina(user *novo_cad)
{
    char vacinado[10];
    int confirmador = 1;

    do
    {
        printf("\nDigite se ja tomou a vacina(Responder com sim ou nao): ");

        scanf("%s", vacinado);
        if (stricmp(vacinado, "Sim") == 0)
        {
            novo_cad->vacina = true;
            confirmador = 0;
        }
        else if ((stricmp(vacinado, "Nao") == 0))
        {
            novo_cad->vacina = false;
            confirmador = 0;
        }
        else
        {
            printf("\nInvalido, digite apenas sim ou nao");
        }
    } while (confirmador == 1);

    fflush(stdin);
}

void listar(user *info)
{
    user *auxiliar;

    for (auxiliar = info; auxiliar != NULL; auxiliar = auxiliar->proximo)
    {
        fflush(stdin);
        system("cls");
        printf("_-_-_-_-_-_-_-_-_-_-_INFORMACAO-_-_-_-_-_-_-_-_-_\n");
        printf("Id: %d\n", auxiliar->id);
        printf("Nome: %s\n", auxiliar->nome);
        printf("Email: %s\n", auxiliar->email);
        printf("Sexo: %s\n", auxiliar->sexo);
        printf("Endereco: %s\n", auxiliar->endereco);
        printf("Altura: %0.2lf\n", auxiliar->altura);
        auxiliar->vacina ? printf("Vacina: Dose aplicada!\n") : printf("Vacina: Dose nao aplicada!\n");
        getch();
    }
}

void buscarId(user *info)
{
    user *auxiliar;
    int buscaId = 0, contagem = 0, tamanhoLista = 0;

    system("cls");
    printf("Digite o ID que deseja procurar: ");
    fflush(stdin);
    scanf("%d", &buscaId);

    for (auxiliar = info; auxiliar != NULL; auxiliar = auxiliar->proximo)
    {
        tamanhoLista++;
        if (auxiliar->id == buscaId)
        {
            system("cls");
            printf("_-_-_-_-_-_-_-_-_-_-_INFORMACAO-_-_-_-_-_-_-_-_-_\n");
            printf("Id: %d\n", auxiliar->id);
            printf("Nome: %s\n", auxiliar->nome);
            printf("Email: %s\n", auxiliar->email);
            printf("Sexo: %s\n", auxiliar->sexo);
            printf("Endereco: %s\n", auxiliar->endereco);
            printf("Altura: %0.2lf\n", auxiliar->altura);
            auxiliar->vacina ? printf("Vacina: Dose aplicada!\n") : printf("Vacina: Dose nao aplicada!\n");
            getch();
            break;
        }
        else
            contagem++;
    }
    if (tamanhoLista == contagem)
    {
        printf("\nNao cadastrado.");
        getch();
    }
}

void buscarEmail(user *info)
{
    user *auxiliar;
    int contagem = 0, tamanhoLista = 0;
    char buscaEmail[50];

    system("cls");
    printf("Digite o email que deseja procurar: ");
    fflush(stdin);
    gets(buscaEmail);

    for (auxiliar = info; auxiliar != NULL; auxiliar = auxiliar->proximo)
    {
        tamanhoLista++;
        if (stricmp(buscaEmail, auxiliar->email) == 0)
        {
            system("cls");
            printf("_-_-_-_-_-_-_-_-_-_-_INFORMACAO-_-_-_-_-_-_-_-_-_\n");
            printf("Id: %d\n", auxiliar->id);
            printf("Nome: %s\n", auxiliar->nome);
            printf("Email: %s\n", auxiliar->email);
            printf("Sexo: %s\n", auxiliar->sexo);
            printf("Endereco: %s\n", auxiliar->endereco);
            printf("Altura: %0.2lf\n", auxiliar->altura);
            auxiliar->vacina ? printf("Vacina: Dose aplicada!\n") : printf("Vacina: Dose nao aplicada!\n");
            getch();
            break;
        }
        else
            contagem++;
    }
    if (tamanhoLista == contagem)
    {
        printf("\nNao cadastrado.");
        getch();
    }
}

void excluirUsuario()
{
    user *anterior;
    user *auxiliar;
    int opcao = 0;
    int idProcurar = 0;
    char buscaEmail[50];

    do
    {
        system("cls");
        printf("_-_-_-_-_-_-_-_EXCLUIR USUARIO_-_-_-_-_-_-_-_\n");
        printf("\n1 - Procurar o Id");
        printf("\n2 - Voltar ao Menu");
        printf("\n_-_-_-_-_-_-_-_DIGITE O NUMERO DA OPCAO PARA PROSSEGUIR_-_-_-_-_-_-_-_ \n");
        scanf("%d", &opcao);
    } while (opcao < 1 || opcao > 2);

    switch (opcao)
    {
    case 1:
        system("cls");
        printf("Digite o ID que deseja procurar:\n");
        fflush(stdin);
        scanf("%d", &idProcurar);

        for (anterior = NULL, auxiliar = info; auxiliar != NULL && auxiliar->id != idProcurar; anterior = auxiliar, auxiliar = auxiliar->proximo)
        {
        }

        if (auxiliar == NULL)
        {
            printf("\nID nao encontrado!");
            getch();
            return info;
        }

        if (anterior == NULL)
        {
            info = auxiliar->proximo;
            free(auxiliar);
        }
        else
        {
            anterior->proximo = auxiliar->proximo;
            free(auxiliar);
        }

        printf("\nUsuario apagado com sucesso!");
        getch();
        return info;
        break;

    default:
        return info;
        break;
    }
}

void editar()
{
    int idBuscado, opcao = 1;
    user *editor = info;
    system("cls");
    printf("Digite o ID que deseja procurar: ");
    scanf("%d", &idBuscado);
    //rastrear o id do usuario
    while (editor != NULL && editor->id != idBuscado)
    {
        editor = editor->proximo;
    }
    while (opcao >= 0 && opcao <= 6)
    {
        if (editor != NULL)
        {
            system("cls");
            printf("_-_-_-_-_-_-_-_ SELECIONE A OPCAO QUE DESEJA _-_-_-_-_-_-_-_\n\n");
            printf("1 - Editar nome\n");
            printf("2 - Editar email\n");
            printf("3 - Editar sexo\n");
            printf("4 - Editar endereco\n");
            printf("5 - Editar altura\n");
            printf("6 - Editar vacina\n");
            printf("7 - Voltar ao menu\n");
            scanf("%d", &opcao);
            switch (opcao)
            {
            case 1:
                cadastroNome(editor);
                printf("dado alterado com sucesso!!\n");
                getch();
                system("cls");
                break;
            case 2:
                cadastroEmail(editor);
                printf("dado alterado com sucesso!!\n");
                getch();
                system("cls");
                break;
            case 3:
                cadastroSexo(editor);
                printf("dado alterado com sucesso!!\n");
                getch();
                system("cls");
                break;
            case 4:
                cadastroEndereco(editor);
                printf("dado alterado com sucesso!!\n");
                getch();
                system("cls");
                break;
            case 5:
                cadastroAltura(editor);
                printf("dado alterado com sucesso!!\n");
                getch();
                system("cls");
                break;
            case 6:
                cadastroVacina(editor);
                printf("dado alterado com sucesso!!\n");
                getch();
                system("cls");
                break;
            default:
                break;
            }
        }
        else
        {
            printf("id nao encontrado!");
            printf("caso deseje voltar ao menu aperte qualquer tecla\n");
            getch();
            break;
        }
    }
}

void fazerBackup()
{
    user *auxiliar;
    int opcao = 0;

    do
    {
        system("cls");
        printf("\t\t\t     _-_-_-_-_-_-[BACKUP USUARIO]-_-_-_-_-_-_\n");
        printf("\n\n\t\t\t\t|| [1]Realizar Backup || [2]Restaurar Backup  ||");
        printf("\n\n\t\t\t\t|| [3]lista backup    || [4]Voltar ao menu    ||");
        fflush(stdin);
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            limpezaBackup();
            //backup=NULL;
            for (auxiliar = info; auxiliar != NULL; auxiliar = auxiliar->proximo)
            {
                user *novo_backup = (user *)malloc(sizeof(backup));
                novo_backup->id = auxiliar->id;
                strcpy(novo_backup->nome, auxiliar->nome);  
                strcpy(novo_backup->email, auxiliar->email);
                strcpy(novo_backup->sexo, auxiliar->sexo);
                strcpy(novo_backup->endereco, auxiliar->endereco);
                novo_backup->altura = auxiliar->altura;
                novo_backup->vacina = auxiliar->vacina;
                novo_backup->proximo = backup;
                backup = novo_backup;
            }
            for (auxiliar = backup; auxiliar != NULL; auxiliar = auxiliar->proximo)
            {
            printf ("id: %d\n", auxiliar->id);
            }
            system ("pause");

            //qntBackup = qntBackup + 1;
            break;

        case 2:
            //fazer if de confirmacao de restauracao
            limpezaInfo();
            //info= NULL;
            for (auxiliar = backup; auxiliar != NULL; auxiliar = auxiliar->proximo)
            {
                user *novo_backup = (user *)malloc(sizeof(backup));
                novo_backup->id=auxiliar->id;
                strcpy(novo_backup->nome, auxiliar->nome);
                strcpy(novo_backup->email, auxiliar->email);
                strcpy(novo_backup->sexo, auxiliar->sexo);
                strcpy(novo_backup->endereco, auxiliar->endereco);
                novo_backup->altura = auxiliar->altura;
                novo_backup->vacina = auxiliar->vacina;
                novo_backup->proximo = info;
                info = novo_backup;
            }
            break;
        case 3:

        for (auxiliar = backup; auxiliar != NULL; auxiliar = auxiliar->proximo)
        {
        printf ("id: %d\n", auxiliar->id);
        }
        system ("pause");
        break;
        default:
            break;
        }
    } while (opcao < 1 || opcao > 4);
}