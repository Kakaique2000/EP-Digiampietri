#include "listadeprodutos.h"

PLISTA criarLista(){
  PLISTA res = (PLISTA) malloc(sizeof(LISTADEPRODUTOS));
  res->cabeca = (PONT) malloc(sizeof(REGISTRO));
  res->cabeca->id=-1;
  res->cabeca->tipo=-1;
  res->cabeca->quantidade=0;
  res->cabeca->valorUnitario=0;
  res->cabeca->proxProd=NULL;
  return res;
}


int tamanho(PLISTA l){
  PONT atual = l->cabeca->proxProd;
  int tam = 0;
  while (atual) {
    atual = atual->proxProd;
    tam++;
  }
  return tam;
}

PONT buscarID(PLISTA l, int id){
  PONT atual = l->cabeca->proxProd;
   while (atual) {
    if (atual->id == id) return atual;
    atual = atual->proxProd;
  }
  return NULL;
}

void exibirLog(PLISTA f){
  int numElementos = tamanho(f);
  printf("Log lista [elementos: %i]\n    ", numElementos);
  PONT atual = f->cabeca->proxProd;
  while (atual){
    printf(" [%i;%i;%i;%i;$%i]", atual->id, atual->tipo, atual->quantidade, atual->valorUnitario, atual->quantidade*atual->valorUnitario);
    atual = atual->proxProd;
  }
  printf("\n\n");
}

int consultarValorUnitario(PLISTA l, int id){
  PONT atual = l->cabeca->proxProd;
   while (atual) {
    if (atual->id == id) return atual->valorUnitario;
    atual = atual->proxProd;
  }
  return 0;
}





bool inserirNovoProduto(PLISTA l, int id, int tipo, int quantidade, int valor){
if(id<0 || tipo<0 || quantidade<0 || valor<0) return false; // Retorna falso caso um dos parametros seja falso
int idAux = buscarID(l,id);
if(id==idAux) return false;

PONT atual = l->cabeca;

   while(atual->proxProd != NULL){

    if((atual->proxProd->valorUnitario * atual->proxProd->quantidade) >= (quantidade*valor)){
        PONT registroNovo = (PONT) malloc(sizeof(REGISTRO));
        criarRegistro(registroNovo, id, tipo, quantidade, valor);
        registroNovo->proxProd = atual->proxProd;
        atual->proxProd = registroNovo;
        return true;
    }

     atual = atual->proxProd;
   }
    if(atual->proxProd == NULL){
        PONT registroNovo = (PONT) malloc(sizeof(REGISTRO));
        criarRegistro(registroNovo, id, tipo, quantidade, valor);
        atual->proxProd = registroNovo;
    }
  return true;
}

void criarRegistro(PONT registro, int id, int tipo, int quantidade, int valor ){

registro->id=id;
registro->proxProd=NULL;
registro->quantidade=quantidade;
registro->tipo=tipo;
registro->valorUnitario=valor;

}


bool removerItensDeUmProduto(PLISTA l, int id, int quantidade){

if(id<0 || quantidade<0) return false;


    PONT atual = l->cabeca;

   while(atual->proxProd != NULL){

    if(atual->proxProd->id == id){

        int valorUnitarioAux = atual->proxProd->valorUnitario;
        int quantidadeAux = atual->proxProd->quantidade - quantidade;
        int tipoAux = atual->proxProd->tipo;
        int idAux = atual->proxProd->id;
        PONT apagar = atual->proxProd;
        atual->proxProd = atual->proxProd->proxProd;
        free(apagar);

        inserirNovoProduto(l,idAux,tipoAux,quantidadeAux,valorUnitarioAux);



        return true;
    }

    atual = atual->proxProd;
   }

  return false;
}


bool atualizarValorDoProduto(PLISTA l, int id, int valor){

  /* COMPLETAR */

  return false;
}
