#include "PruebasPropias.h"

PruebasPropias::PruebasPropias(ConductorPrueba* conductor)
:Prueba(conductor)
{
}

PruebasPropias::~PruebasPropias()
{
}

const char* PruebasPropias::getNombre() const
{
	return "PruebasPropias";
}


void PruebasPropias::correrPruebaConcreta()
{
	ListaPosInt lista = crearListaPosInt();
	agregar(lista, 50, 2);
	agregar(lista, 49, 1);
	cout << elemento(lista, 1);
}

