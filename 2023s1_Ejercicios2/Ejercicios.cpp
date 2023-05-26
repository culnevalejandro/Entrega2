#include "Ejercicios.h"



/* FUNCIONES AUXILIARES */


void recorrerArbol(NodoABInt* a, ListaOrdInt l) {
	if (a == NULL) {
		return;
	}

	recorrerArbol(a->izq, l);
	recorrerArbol(a->der, l);

	agregar(l, a->dato);
}

void agregarALista(ListaOrdInt l1, ListaOrdInt l2, ListaOrdInt retorno) {

	int min1;
	int min2;

	while (!esVacia(l1) && !esVacia(l2)) {
		min1 = minimo(l1);
		min2 = minimo(l2);

		if (min1 > min2) {
			agregar(retorno, min1);
			borrarMinimo(l1);
		}
		else if (min1 < min2) {
			agregar(retorno, min2);
			borrarMinimo(l2);
		}
		else {
			agregar(retorno, min1);
			agregar(retorno, min2);
			borrarMinimo(l1);
			borrarMinimo(l2);
		}
	}

	while (!esVacia(l1)) {
		agregar(retorno, minimo(l1));
		borrarMinimo(l1);
	}

	while (!esVacia(l2)) {
		agregar(retorno, minimo(l2));
		borrarMinimo(l2);
	}
}

/* FIN FUNCIONES AUXILIARES */


//EJERCICIO 1
ListaOrdInt Enlistar(NodoABInt* a)
{
	if (a == NULL) {
		return NULL;
	}
	
	ListaOrdInt l = crearListaOrdInt();
	recorrerArbol(a, l);
	return l;
}


//EJERCICIO 2
ListaOrdInt UnionListaOrd(ListaOrdInt l1, ListaOrdInt l2)
{
	ListaOrdInt retorno = crearListaOrdInt();
	ListaOrdInt aux1 = clon(l1);
	ListaOrdInt aux2 = clon(l2);

	agregarALista(aux1, aux2, retorno);
	return retorno;
}


bool EstaContenida(PilaInt p1, PilaInt p2) {
	PilaInt pilaAux1 = clon(p1);
	PilaInt pilaAux2 = clon(p2);

	ListaOrdInt lista1 = crearListaOrdInt();
	ListaOrdInt lista2 = crearListaOrdInt();

	while (!esVacia(pilaAux1)) {
		agregar(lista1, top(pilaAux1));
		pop(pilaAux1);
	}
	destruir(pilaAux1);

	while (!esVacia(pilaAux2)) {
		agregar(lista2, top(pilaAux2));
		pop(pilaAux2);
	}
	destruir(pilaAux2);

	while (!esVacia(lista1) && existe(lista2, minimo(lista1))) {
		borrar(lista2, minimo(lista1));
		borrarMinimo(lista1);
	}

	bool retorno = esVacia(lista1);
	destruir(lista1);
	destruir(lista2);

	return retorno;
}

/*
	Implemente la funcion EstaContenida que dadas dos pilas: p1 y p2, de tipo PilaInt retorne true si y solo
	si todos los elementos de p1 se encuentran en p2.
	Si hay valores repetidos en p1, entonces se tienen que encontrar como minimo la misma cantidad
	de repetidos de ese valor en p2.
	Las pilas parametro no deberan ser modificadas.
	La pila vacia esta contenida en cualquier pila.
*/


ListaOrdInt ObtenerRepetidos(MultisetInt m) 
{
	//IMPLEMENTAR SOLUCION
	return NULL;
}

MultisetInt Xor(MultisetInt m1, MultisetInt m2)
{
	//IMPLEMENTAR SOLUCION
	return NULL;
}

ColaPrioridadInt MenorPrioridad(ColaPrioridadInt c) {
	//IMPLEMENTAR SOLUCION
	return NULL;
}

