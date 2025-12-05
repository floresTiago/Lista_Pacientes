#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <conio.h>

struct elemento{
	int dado, senha;
	struct elemento *prox;
};

typedef struct elemento Elem;

typedef struct elemento* Lista;

Lista* li;

Lista* criarLista(){
	Lista* li = (Lista*) malloc(sizeof(Lista));
	
	if(li != NULL){
	    *li = NULL; 
	}
	return li;
}

void liberaLista(Lista *li){
	if(li != NULL){
		Elem* no;
		while ((*li) != NULL){
			no = *li;
			*li = (*li)->prox;
			free(no);
		}
		free(li);
	}
}

int insereOrdenado(Lista* li, int gravidade, int senha){
	if(li == NULL){
	    return 0;
	} 
	Elem* no = (Elem*) malloc(sizeof(Elem));
	if(no == NULL){
	    return 0;
	}
	if(gravidade<1||gravidade>5){
	    printf("\nGrau de risco não existente\n");
	    return 0;
	}
	
	no->dado = gravidade;
	no->senha = senha;
	no->prox = NULL;
    if(*li == NULL || (*li)->dado < gravidade){
        no->prox = *li;
        *li = no;
        return 1;
    }

    Elem *aux = *li;
    while(aux->prox != NULL && aux->prox->dado >= gravidade){
        aux = aux->prox;
    }

    no->prox = aux->prox;
    aux->prox = no;

    return 1;
}

int removeInicio(Lista *li){
	if(li == NULL){
	    return 0;
	} 
	if((*li) == NULL){
	    return 0;
	} 
	
	Elem *no = *li;
	printf("\nProximo paciente:\nSenha: %d\n", no->senha);
	*li = no->prox;
	free(no);
	return 1;
}

void mostraLista(Lista *li){
	Elem *no = *li;
	if(no==NULL){
	    printf("\nSem pacientes na espera\n");
	}else{
    	printf("\nLista de pacientes em espera:\nGrau de risco:      Senha:\n");
    	while(no != NULL){	
            printf("%d                   %d\n", no->dado, no->senha);
            no = no->prox;
        }	    
	}

}

void limpaTela(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int  main(){
  	int opcao, gravidade, senha=0;
	Lista* myList;
	myList = criarLista();
    do{
        printf("\nSelecione uma opção:\n\n1. Adicionar paciente\n2. Chamar proximo paciente\n3. Mostrar lista de pacientes\n0. Sair\n\n");
        scanf("%d",&opcao);
        switch(opcao){
            case 0:
                limpaTela();
                printf("\nSistema finalizado\n");
            break;
            case 1:
	            limpaTela();
	            printf("Protocolo Manchester:\n 5 - Emergente (VERMELHO)\n 4 - Muito Urgente (LARANJA)\n 3 - Urgente (AMARELO)\n 2 - Pouco Urgente (VERDE)\n 1 - Sem Urgencia (AZUL)\n");
	            printf("\nGrau de urgência (numero): ");
	            scanf("%d", &gravidade);
	            senha++;
	            limpaTela();
	            insereOrdenado(myList, gravidade, senha);
	        break;
	        case 2:
	            limpaTela();
	            removeInicio(myList);
	        break;
	        case 3:
	            limpaTela();
	            mostraLista(myList);
	        break;
	        default:
	            limpaTela();
	            printf("\nOpção Inválida\n");
	        break;
	    }
	}while(opcao!=0);
	liberaLista(myList);
	getch();
	return 0;    
}