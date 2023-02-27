#include <iostream> 
#include <stdlib.h> 
using namespace std;

struct nodo 
{ 
    int clave; 
    nodo *izq, *der; 
}; 


//Funcion para crear nuevo nodo BST 
nodo *nuevonodo(int objeto) 
{ 
  nodo *aux = new nodo; 
  aux->clave = objeto; 
  aux->izq = aux->der = NULL; 
  return aux; 
} 
   
// funcion par atravesar en order el BST 
void enorden(nodo *root) 
{ 
  if (root != NULL) 
    { 
      enorden(root->izq);
      cout<<root->clave<<endl; 
      enorden(root->der); 
    } 
} 
   
/* Funcion par insertar un nuevo nodo dado una clave al BST */
nodo* insertar(nodo* nodo, int clave) 
{ 
  /* si el arbol esta vacio, devuelve un nuevo nodo */
  if (nodo == NULL) return nuevonodo(clave); 
  
  /* sino recorre el arbol */
  if (clave < nodo->clave) 
    nodo->izq  = insertar(nodo->izq, clave); 
  else if (clave > nodo->clave) 
    nodo->der = insertar(nodo->der, clave);    
  
  /* el nodo puntero (sin cambios) */
  return nodo; 
}

nodo * minvalornodo(nodo* nodo) 
{ 
  struct nodo* act = nodo; 
  
  /* ciclo hasta encontrar la hoja que este mas a la izquierda */
  while (act && act->izq != NULL) 
    act = act->izq; 
  
  return act; 
} 
  
/*dado un BST y una clave, esta funcion borra la clave  
  y devuelve el nuevo root */
nodo* borrarnodo(nodo* root, int clave) 
{ 
  // caso base 
  if (root == NULL) return root; 
  
  // si la clave a ser borrada es mas pequenna que la clave del root, 
  // entonce se queda en el subarbol izquierdo 
  if (clave < root->clave) 
    root->izq = borrarnodo(root->izq, clave); 
  
  // si la clave a ser borrada es mas grande que la clave del root, 
  // entonce se queda en el subarbol derecho
  else if (clave > root->clave) 
    root->der = borrarnodo(root->der, clave); 
  
  // si la clave es la misma que la del root, entonces es el nodo a borrar
  else
    { 
      // nodo con solo un hijo o ninguno 
      if (root->izq == NULL) 
        { 
	  nodo *aux = root->der; 
	  free(root); 
	  return aux; 
        } 
      else if (root->der == NULL) 
        { 
	  nodo *aux = root->izq; 
	  free(root); 
	  return aux; 
        } 
      
      // nodo con 2 hijos, obtiene el enorden sucesor (el mas pequeno del sub arbol derecho)
      nodo* aux = minvalornodo(root->der); 
      
      // copia el contenido del sucesor de  enorden a este nodo 
      root->clave = aux->clave; 
      
      // borra el sucesor de enorden 
      root->der = borrarnodo(root->der, aux->clave); 
    } 
  return root; 
} 
 
int main() 
{
  /*  BST 
       50 
     /     \ 
    30      70 
   /  \    /  \ 
 20   40  60   80 */
  nodo *root = NULL; 
  root = insertar(root, 50); 
  root = insertar(root, 30); 
  root = insertar(root, 20); 
  root = insertar(root, 40); 
  root = insertar(root, 70); 
  root = insertar(root, 60); 
  root = insertar(root, 80); 

  cout<<"el arbol en orden\n";
  enorden(root); 

  cout<<"se borra 20\n"; 
  root = borrarnodo(root, 20); 
  cout<<"Arbol modificado en orden \n";
  enorden(root); 
  
  cout<<"se borra 30\n"; 
  root = borrarnodo(root, 30); 
  cout<<"Arbol modificado en orden \n"; 
  enorden(root); 
  
  cout<<"se borra 50\n"; 
  root = borrarnodo(root, 50); 
  cout<<"Arbol modificado en orden \n";
  enorden(root); 
  
  return 0; 
} 

