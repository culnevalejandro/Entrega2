#include "ListaPosInt.h"

#ifdef LISTA_POS_INT_IMP

struct _cabezalListaPosInt {
<<<<<<< Updated upstream
	//IMPLEMENTAR SOLUCION
};

ListaPosInt crearListaPosInt()
{
	//IMPLEMENTAR SOLUCION
	return NULL;
}

void agregar(ListaPosInt& l, int e, unsigned int pos)
{
	//IMPLEMENTAR SOLUCION
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
=======
	int cantElementos;
	unsigned int largo;
	int* vector;
};


/* FUNCIONES AUXILIARES */

void actualizarLargo(ListaPosInt& l) {
	l->largo *= 2;
	int* nuevoVector = new int[l->largo];
}

/* FIN FUNCIONES AUXILIARES */


ListaPosInt crearListaPosInt() {
	ListaPosInt cabezal = new _cabezalListaPosInt;
	cabezal->cantElementos = 0;
	cabezal->largo = 20;
	cabezal->vector = new int[cabezal->largo]();
	return cabezal;
}

void agregar(ListaPosInt& l, int e, unsigned int pos) {
	if (l->cantElementos == l->largo) {
		actualizarLargo(l);
	}
	if (pos < l->cantElementos) {
		for (int cambio = l->cantElementos; cambio >= pos; cambio--) {
			l->vector[cambio + 1] = l->vector[cambio];
		}
		l->vector[pos] = e;
	}
	else {
		l->vector[l->cantElementos] = e;
	}

	l->cantElementos++;
}

void borrar(ListaPosInt& l, unsigned int pos) {
	if (pos <= l->cantElementos - 1 && l->cantElementos != 0) {
		for (int cambio = pos; cambio < l->cantElementos; cambio++) {
			l->vector[cambio] = l->vector[cambio + 1];
		}
		l->cantElementos--;
	}
}

int elemento(ListaPosInt l, unsigned int pos) {	// O(1)
	return l->vector[pos];
}

bool esVacia(ListaPosInt l) {
	return l->cantElementos == 0;
}

unsigned int cantidadElementos(ListaPosInt l) { // O(1)
	return l->cantElementos;
}

ListaPosInt clon(ListaPosInt l) {
	ListaPosInt retorno = crearListaPosInt();
	for (int pos = 0; pos < l->cantElementos; pos++) {
		agregar(retorno, l->vector[pos], pos);
	}

	return retorno;
>>>>>>> Stashed changes
}

void destruir(ListaPosInt& l) {
	delete[] l->vector;
	l->vector = NULL;

	delete l;
	l = NULL;
}


#endif