#include "Ejercicios.h"

//EJERCICIO 1
//FUNCION AUXILIAR
void recorrerArbol(NodoABInt* a, ListaOrdInt l) {
	if (a == NULL) {
		return;
	}

	recorrerArbol(a->izq, l);
	recorrerArbol(a->der, l);

	agregar(l, a->dato);
}

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
//FUNCION AUXILIAR
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

ListaOrdInt UnionListaOrd(ListaOrdInt l1, ListaOrdInt l2)
{
	ListaOrdInt retorno = crearListaOrdInt();
	ListaOrdInt aux1 = clon(l1);
	ListaOrdInt aux2 = clon(l2);

	agregarALista(aux1, aux2, retorno);
	return retorno;
}

<<<<<<< Updated upstream
//EJERCICIO 3
bool EstaContenida(PilaInt p1, PilaInt p2)
{
	//IMPLEMENTAR SOLUCION
=======

bool EstaContenida(PilaInt p1, PilaInt p2) {
	
>>>>>>> Stashed changes
	return false;
}


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

