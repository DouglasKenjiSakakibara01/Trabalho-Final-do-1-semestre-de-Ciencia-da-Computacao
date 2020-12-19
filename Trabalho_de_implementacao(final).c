#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<locale.h>
#include<stddef.h>

int escolha,cont,cont2=0,pos,atualizacao,registroacad;
char cid[25],novocurso[25];
FILE *file;

struct registro{
        char nome[25],curso[25],cidade[25];
        int ano,ra;
};
void arquivo(struct registro *n){
    struct registro aluno[20];
    file=fopen("arquivotrabalho.txt","rb+");
    if(file==NULL){
        file=fopen("arquivotrabalho.txt","wb+");
    }
    fclose(file);
    file=fopen("arquivotrabalho.txt","rb+");
    while(!feof(file)){
        fread(&n[cont],sizeof(struct registro),1,file);
        cont2++;
    }
    cont2--;
    printf("%d",cont2);
    fclose(file);
}
void inserir(struct registro *a){
        printf("Digite seu nome:");
        fgets(a[cont2].nome,25,stdin);
        printf("Digite seu curso:");
        fgets(a[cont2].curso,25,stdin);
        a[cont2].curso[strlen(a[cont2].curso)-1]='\0';
        printf("Digite qual cidade voce reside no momento(sem acentuacao):");
        fgets(a[cont2].cidade,25,stdin);
        a[cont2].cidade[strlen(a[cont2].cidade)-1]='\0';
        strlwr(a[cont2].cidade);
        printf("Digite o ano de entrada na universidade:");
        scanf("%d",&a[cont2].ano);
        fflush(stdin);
        printf("Digite seu RA(registro academico):");
        scanf("%d",&a[cont2].ra);
        fflush(stdin);
        cont2++;
        printf("\nAluno registrado com sucesso");

}
void remover(struct registro *b){
        printf("\nEm qual posicao esta o registro que voce deseja excluir:");
        scanf("%d",&pos);
        int contador=pos;
        pos--;
        int i;
        if((pos>=0)&&(pos<cont2)){
            cont2--;
            printf("\nO registro da posicao %d foi removido",contador);
            for(i=pos;i<cont2;i++){
            b[i]=b[i+1];
        }
        }
        else{
            printf("\nO registro nao foi encontrado na posicao digitada");
            }
    }
void listar(struct registro *c){
        for(cont=0;cont<cont2;cont++){
            printf("\nNome:%s",c[cont].nome);
            printf("\nCurso:%s",c[cont].curso);
            printf("\nAno de entrada %d",c[cont].ano);
            printf("\nRA:%d",c[cont].ra);
            printf("\nCidade:%s",c[cont].cidade);
            printf("\n");
            printf("\n");
          }

    }
void consultachave(struct registro *d,int reg){
        int cont3=0;
        for(cont=0;cont<cont2;cont++){
            if(reg==d[cont].ra){
                printf("\nNome:%s",d[cont].nome);
                printf("\nCurso:%s",d[cont].curso);
                printf("\nAno de entrada na universidade:%d",d[cont].ano);
                printf("\nRA:%d",d[cont].ra);
                cont3++;
                }
        }
        if(cont3==0){
            printf("\n");
            printf("Registro nao encontrado");
        }

    }
void atualizar(struct registro *e,int numero){
        int cont4=0,cont5;
        printf("\nDigite o nome do curso que  esta cursando nesse momento:",numero);
        fgets(novocurso,25,stdin);
        novocurso[strlen(novocurso) - 1]='\0';
        for(cont=0;cont<cont2;cont++){
            if(numero==e[cont].ra){
                cont5=cont;
                for(cont=0;cont<strlen(novocurso);cont++){
                  e[cont5].curso[cont]=novocurso[cont];
                  cont4++;

            }

            }

        }
        if(cont4>0){
            printf("\nO curso %s foi inserido com sucesso no registro do ra %d",novocurso,numero);
        }

        else if(cont4==0){
            printf("\nERRO");
            printf("\nNao foi possivel realizar a atualizacao no cadastro");
            printf("\nO ra %d nao foi encontrado no registro de aluno ",numero);

        }
    }
void cidade_registro(struct registro *f){
        int cont5=0;
        int valor;
        char c[25];
        printf("Digite a cidade:");
        fgets(c,25,stdin);
        c[strlen(c)-1]='\0';
        strlwr(c);
        printf("\nAlunos encontrados no registro que residem em %s:",c);
        for(cont=0;cont<cont2;cont++){
            valor=strcmp(f[cont].cidade,c);
            if(valor==0){
               printf("\n%s",f[cont].nome);
               cont5++;

            }
        }
        if(cont5==0){
            printf("\nERRO");
            printf("\nNenhum aluno que reside em %s foi encontrado no registro",c);
        }

    }
int main(){
    struct registro aluno[20],aluno2[20];
    arquivo(&aluno);
    /*for(cont=0;cont<3;cont++){
        printf("Digite seu nome:");
        fgets(aluno[cont].nome,25,stdin);
        printf("Digite seu curso:");
        fgets(aluno[cont].curso,25,stdin);
        aluno[cont].curso[strlen(aluno[cont].curso)-1]='\0';
        printf("Digite qual cidade voce reside no momento(sem acentuacao):");
        fgets(aluno[cont].cidade,25,stdin);
        aluno[cont].cidade[strlen(aluno[cont].cidade)-1]='\0';
        strlwr(aluno[cont].cidade);
        printf("Digite o ano de entrada na universidade:");
        scanf("%d",&aluno[cont].ano);
        fflush(stdin);
        printf("Digite seu RA(registro academico):");
        scanf("%d",&aluno[cont].ra);
        fflush(stdin);
        printf("\n");
    }*/
    while(escolha!=7){
    printf("\n");
    printf("*******Cadastro*******");
    printf("\nDigite:");
    printf("\n1-Caso queira inserir um registro");
    printf("\n2-Caso queira remover  um registro");
    printf("\n3-Caso queira a listagem  de todos  registros ");
    printf("\n4-Caso queira fazer uma consulta no registro usando o RA ");
    printf("\n5-Caso queira atualizar o curso no registro ");
    printf("\n6-Caso queira saber os nomes dos alunos no registro que residem em uma determinada cidade" );
    printf("\n7-Caso queira sair do menu");
    printf("\nEscolha:");
    scanf("%d",&escolha);
    fflush(stdin);

    switch(escolha){
     case 1:
        inserir(&aluno);
        break;


     case 2:
        remover(&aluno);
        break;


     case 3:
        listar(&aluno);
        break;


     case 4:
        printf("\nDigite seu RA:");
        scanf("%d",&registroacad);
        consultachave(&aluno,registroacad);
        break;


     case 5:
        printf("\nDigite seu RA:");
        scanf("%d",&atualizacao);
        fflush(stdin);
        atualizar(&aluno,atualizacao);
        break;


     case 6:
        cidade_registro(&aluno);
        break;


     case 7:
        file=fopen("arquivotrabalho.txt","wb+");
        for(cont=0;cont<cont2;cont++){
         fwrite(&aluno[cont],sizeof(struct registro),1,file);
       }
        fclose(file);
        file=fopen("arquivotrabalho.txt","rb+");
        rewind(file);
        for(cont=0;cont<cont2;cont++){
            fread(&aluno2[cont],sizeof(struct registro),1,file);

        }
        for(cont=0;cont<cont2;cont++){
            printf("\n");
            printf("%s",aluno2[cont].nome);
            printf("%d",aluno2[cont].ra);
            printf("\n%d",aluno2[cont].ano);
            printf("\n%s",aluno2[cont].curso);
            printf("\n%s",aluno2[cont].cidade);
        }
        fclose(file);
    }
    }
    return 0;
}





