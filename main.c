#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <conio.h>

/****************************************************************************/
/*       ESTRUTURA ELEMENTO					                                */ 
/*       Esta estrutura armazar� as informa��es da Lista					*/
/****************************************************************************/
struct elemento{
	int dado, senha;
	struct elemento *prox;
};
typedef struct elemento Elem;

/****************************************************************************/
/*       Defini��o de um ponteiro *Lista do tipo elemento                   */ 
/*       Mas quem � o Elemento?            				                    */ 
/*       - � a estrutura da Lista 						                    */ 
/*       que contem o Dado e ponteiro para o pr�ximo elemento da lista      */ 
/****************************************************************************/
typedef struct elemento* Lista;

/*       Programa Principal 							    				*/ 
/*       criando um ponteiro para a Lista (aponta para o in�cio da Lista);  */ 
/*       Lembre-se: Lista � um ponteiro para a estrutura elemento;			*/
/*       ----																*/
/*		 Nesse caso, *li � um "ponteiro para ponteiro" [**] onde cada		*/ 
/*       elemento (ou n�) da lista [dado, *prox] � um ponteiro, o *li � um  */
/*       "ponteiro para ponteiro" [**] que aponta para Lista [dado, *prox]	*/
/*       ----																*/
/*       Um "ponteiro para ponteiro" consegue armazenar o endere�o de um	*/
/*       ponteiro															*/
Lista* li; // li � um ponteiro para ponteiro para a struct Elemento

/*      CRIAR LISTA						                        	        */
/* 		A fun��o criarLista retorna uma lista* (lista asterisco)			*/
Lista* criarLista(){
	Lista* li = (Lista*) malloc(sizeof(Lista));/* malloc para reservar mem�ria para o primeiro n� da Lista */
	
	if(li != NULL)  // se der certo a aloca��o o meu primeiro n� vai apontar para NULL
		*li = NULL; // ao pontar para NULL representa uma lista vazia
			  		// ver a 1� linha do main
	return li;
 	
 	//      CHAMADA NO MAIN
 	//      li = criarLista();   

}

/****************************************************************************/
/*      LIBERAR LISTA						                        	    */
/* 		A fun��o libera a lista quando eu n�o for mais usar ela				*/
/*		Ela recebe como par�metro a lista que pretende liberar, nesse caso  */
/*      queremos liberar a Lista *li										*/
/****************************************************************************/
void liberaLista(Lista *li){  // passa a Lista* li
	if(li != NULL){ // se tivermos uma lista v�lida, come�amos a esvazi�-la.
		Elem* no;   // defino um ponteiro Elem (AUXILIAR)
		while ((*li) != NULL){ // pego o 1� elemento da lista (o in�cio da Lista). Enquanto ela for diferente de NULL, ou seja, enquanto eu n�o tiver uma lista vazia...
			no = *li;           // o meu NO recebe *li, ou seja, o meu NO recebe o in�cio da Lista (*li)...
			*li = (*li)->prox; // o in�cio da lista (*li) vai apontar par ao pr�ximo elemento da lista (prox) e...
			free(no);			// vamos liberar o NO, que era o antigo in�cio. Assim, nunca percemos a refer�ncia do in�cio da Lista
		}						// repete todo o processo at� eliminar todos os elementos lista.
		free(li);  				// quanto chegar em NULL, a Lista* li � liberada.
	}
	
	//      CHAMADA NO MAIN
 	//      liberaLista(li); 
}

/****************************************************************************/
/*      VERIFICAR O TAMANHO DA LISTA			                       	    */
/* 		A fun��o verifica o tamonho da lista, contando quantos elementos h�	*/
/****************************************************************************/
int tamanhoDaLista(Lista* li){
	if(li == NULL) return 0; // se o in�cio for NULL, retorna O, i.e. lista vazia
    int cont = 0; 			 // uma vari�vel contatora
    Elem* no = *li;			// 'no' auxiliar aponta para o in�cio da lista (*li)
    while(no != NULL){		// Enquanto o 'no' for diferente de NULL, ou seja, enquanto n�o chegar ao final da Lista, percorre...
    	cont++; 			// incrementa a vari�vel contadora
    	no = no->prox;  	// 'no' aponta para o pr�ximo, percorrendo toda a Lista
	}
	return cont;			// ap�s percorrer a lista, retorna o valor de cont
	
	//      CHAMADA NO MAIN
 	//      int x = tamanhoDaLista(li); 
}

/****************************************************************************/
/*      VERIFICAR SE LISTA CHEIA			                       		    */
/* 		A fun��o verifica se a lista esta cheia								*/
/*		Embora saibamos que a lista ser� cheia se acabar a m�m�ria do PC	*/
/****************************************************************************/
int listaCheia(Lista* li){
	return 0;			// retorna falso
			
	//      CHAMADA NO MAIN
 	//      int x = listaCheia(li); 
 	// 		if(listaCheia(li))
}

/****************************************************************************/
/*      VERIFICAR SE LISTA VAZIA			                       		    */
/* 		A fun��o verifica se a lista esta vazia								*/
/*		*/
/****************************************************************************/
int listaVazia(Lista* li){
	if(li == NULL)	// se lista for nula li== NULL, retorna verdadeiro 
		  return 1;
	if(*li == NULL)	// se o conte�do da lista for nula *li== NULL, retorna verdadeiro 
		  return 1;
	return 0;			// retorna falso, ou seja, a Lista n�o esta vazia
			
	//      CHAMADA NO MAIN
 	//      int x = listaVazia(li); 
 	// 		if(listaVazia(li))
}

/****************************************************************************/
/*      INSERIR ELEMENTO NA LISTA				                       		*/
/*		Mas sempre temos que verificar a condi��o da nossa lista ao inserir */
/*      elementos em uma lista vazio.										*/
/* -------------------------------------------------------------------------*/
/*      O que acontece?														*/
/*		Quando criamos uma lista, ela � vazia, onde � reservado espa�o para */
/*		o conte�do e um ponteiro apontado para o prox.						*/
/*		Nesse caso, o INICIO para apontar para o NO, e o PROX para NULL, ou */
/* 		para o pr�prio INICIO												*/
/****************************************************************************/

int insereOrdenado(Lista* li, int x, int senha){ // posso inserir nos 3 casos, no inicio, no meio, ouno fim
	if(li == NULL) return 0; //falso, lista n�o existe
	Elem* no = (Elem*) malloc(sizeof(Elem)); // aloco em mem�ria o novo Elem NO
	if(no == NULL) return 0; //falso, n�o conseguiu alocar NO
	
	if(x<1||x>5){
	    printf("\nGrau de risco não exisente\n");
	    return 0;
	}
	
	/***** implementar **********/ 	
	no->dado = x; 	// NO recebe dados
	no->senha = senha;
	no->prox = NULL;	// NO->PROX aponta para NULL
	if(*li == NULL || (*li)->dado < x){
        no->prox = *li;
        *li = no;
        
        return 1;
    }else{				//Sen�o
        Elem *ant = *li;        // anterior
        Elem *atual = (*li)->prox; // atual
    
        while(atual != NULL && atual->dado >= x){
            ant = atual;
            atual = atual->prox;
        }
    
        // Inserindo no meio ou fim
        ant->prox = no;
        no->prox = atual;
        
        return 1;
    }
	return 1;
}

/****************************************************************************/
/*      REMOVER ELEMENTO NA LISTA				                       		*/
/*		Mas sempre temos que verificar a consi��o da nossa lista 			*/
/*		CUIDADOS!!!															*/
/*		- N�o posso remover algo de uma lista vazia							*/
/*		- removendo o �ltimo n�, a lista fica vazia							*/
/****************************************************************************/

int removeInicio(Lista *li){
	if(li == NULL) return 0; //falso, lista n�o existe
	if((*li) == NULL) return 0; //falso, lista vazia
	
	Elem *no = *li; // NO aponta para INICIO
	printf("\nProximo paciente:\nSenha: %d\n", no->senha);
	*li = no->prox; //  INICIO aponta para o NO->PROX
	free(no);	    // Libera o NO 
	return 1;
 	//      CHAMADA NO MAIN
 	//      int x = removeInicio(li); 	
}

void mostraLista(Lista *li){
	Elem *no = *li;
	printf("\nLista de pacientes em espera:\nGrau de risco:      Senha:\n");
	while(no != NULL){	
        printf("%d                   %d\n", no->dado, no->senha);
        no = no->prox;
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
	            printf("Grau de urgência: ");
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