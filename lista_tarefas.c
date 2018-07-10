// compilar: gcc lista_tarefas.c -o tarefas
// executar: ./tarefas

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LISTA{
  int id;
  char tarefa[50];
  struct LISTA *prox;  
}lista;

lista *agendar(lista *l, int id){
  lista *novo = (lista*)malloc(sizeof(lista));
  printf("Nome da tarefa: ");
  scanf("%s",novo->tarefa);
  novo->id = id;
  novo->prox = l;

  return novo;
}

void ver_lista(lista *l){
  lista *aux = l;

  if(l==NULL){
    printf("Lista vazia\n");
    return;
  }

  if(aux->prox==NULL){
    printf("Tarefa %d - %s\n", aux->id,aux->tarefa);
  }
  else{
    ver_lista(aux->prox);
    printf("Tarefa %d - %s\n", aux->id,aux->tarefa);
  }

  return;
}

lista *remover(lista *l){
  lista *aux,*ant;
  int id;

  printf("Id da tarefa: \n");
  scanf("%d",&id);

  if(l->id == id){
    aux = l->prox;
    free(l);
    return aux;
  }

  ant = l;
  for(aux=l->prox;aux!=NULL;aux=aux->prox){
    if(aux->id == id){
      ant->prox = aux->prox;
      free(aux);
      return l;
    }
    ant = aux;
  }
  return l;
}

void remover_lista(lista *l){
  if(l->prox==NULL){
    free(l);
  }
  else{
    remover_lista(l->prox);
    free(l);
  }
  return;
}


int main(){
  int id=0, op=1;
  lista *lista_tarefas = NULL;

  while(op){
    printf("Lista de tarefas\n");
    printf("1 <- Agendar tarefa\n");
    printf("2 <- Ver tarefas\n");
    printf("3 <- Remover tarefa\n");
    printf("0 <- Sair\n");
    scanf("%d",&op);

    switch(op){
      case 1:
        lista_tarefas = agendar(lista_tarefas,id);
        id++;
        break;
      case 2:
        ver_lista(lista_tarefas);
        break;
      case 3:
        lista_tarefas = remover(lista_tarefas);
        break;
    }
    printf("\n");
  }
  remover_lista(lista_tarefas);

  return 0;
}