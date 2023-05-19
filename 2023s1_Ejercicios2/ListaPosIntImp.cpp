#include "ListaPosInt.h"

#ifdef LISTA_POS_INT_IMP

struct _cabezalListaPosInt {
	NodoListaInt* ppio;
	unsigned int largo;
};


/* FUNCIONES AUXILIARES */


void crearListaPosInt(NodoListaInt*& l, int dato, unsigned int pos) {
	if (l == NULL) {
		NodoListaInt* nodoNuevo = new NodoListaInt(dato);
		l = nodoNuevo;
	}
	else if (l->sig == NULL) {
		NodoListaInt* nodoNuevo = new NodoListaInt(dato);
		l->sig = nodoNuevo;
	}
	else {
		//crearListaPosInt(l, dato, pos - 1);
	}
}


/* FIN FUNCIONES AUXILIARES */


ListaPosInt crearListaPosInt() {
	ListaPosInt cabezal = new _cabezalListaPosInt;
	cabezal->ppio = NULL;
	cabezal->largo = 0;
	return cabezal;
}

void agregar(ListaPosInt& l, int e, unsigned int pos) {
	//crearListaPosInt(l->ppio, e, pos);
}

void borrar(ListaPosInt& l, unsigned int pos)
{
	//IMPLEMENTAR SOLUCION
}

int elemento(ListaPosInt l, unsigned int pos)
{
	//IMPLEMENTAR SOLUCION
	return 0;
}

bool esVacia(ListaPosInt l)
{
	//IMPLEMENTAR SOLUCION
	return true;
}

unsigned int cantidadElementos(ListaPosInt l)
{
	//IMPLEMENTAR SOLUCION
	return 0;
}

ListaPosInt clon(ListaPosInt l)
{
	//IMPLEMENTAR SOLUCION
	return NULL;
}

void destruir(ListaPosInt& l)
{
	//IMPLEMENTAR SOLUCION
}


#endif