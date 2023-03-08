/*
 * PruebasGenericVov.cpp
 *
 *  Created on: 8 mar 2023
 *      Author: Isaac Romanillos
 */

#include "PruebasGenericVov.h"
#include "GenericVov.h"

void probarConstructoresGenericVov() {
	cout << "Inicio probarConstructoresGenericVov" << endl;
	GenericVov<int> VOV_int;
	if (VOV_int.getCurrentElements() != 0)
		cerr << "Error en el constructor por defecto" << endl;

	VOV_int.insertarElemento(3);
	if (VOV_int.getTop() != 3)
		cerr << "Error al obtener el primer dato de GenericVov" << endl;

	if (VOV_int.getCurrentElements() != 1)
		cerr << "Error al obtener CurrentElements de GenericVov" << endl;

	cout << "Fin probarConstructoresGenericVov" << endl;
}

void probarInsertarElemento() {
	cout << "Inicio probarInsertarBorrarElemento" << endl;
	GenericVov<int> VOV_int;
	int i;
	if (!VOV_int.isEmpty())
		cerr << "ERROR: Un vector recién creado debe estar vacío" << endl;

	if (VOV_int.isFull())
		cerr << "ERROR: Un vector recién creado no puede estar lleno" << endl;

	for (i = 0; i < MAX_ELEMENTS; i++) {
		VOV_int.insertarElemento(i);
	}

	if (VOV_int.isEmpty()) {
		cerr
				<< "ERROR: Un vector en el que se han insertado MAX elementos no puede estar vacío"
				<< endl;
	}
	if (!VOV_int.isFull()) {
		cerr
				<< "ERROR: Un vector en el que se han insertado MAX elementos debe estar lleno"
				<< endl;
	}
	for (i = 0; i < MAX_ELEMENTS; i++) {
		VOV_int.borrarElemento(i);
	}

	VOV_int.insertarElemento(2);
	if (VOV_int.consultarElemento(0) != 2)
		cerr << "Error al obtener el primer dato de GenericVov" << endl;

	VOV_int.borrarElemento(0);
	if (VOV_int.getCurrentElements() != 0)
		cerr << "Error al obtener CurrentElements de GenericVov" << endl;

	cout << "Fin probarInsertarBorrarElemento" << endl;
}

void probarBorrarElemento() {
	cout << "Inicio probarBorrarElemento" << endl;
	GenericVov<int> VOV_int;
	VOV_int.insertarElemento(3);
	cout << "Numero almacenado: " << VOV_int.getTop() << endl;
	VOV_int.borrarElemento(0);
	if (VOV_int.getTop() != 0)
		cerr << "ERROR: elemento de posicion 0 no se ha borrado" << endl;

	cout << "Numero almacenado tras borrar: " << VOV_int.getTop() << endl;

	if (!VOV_int.isEmpty())
		cerr
				<< "ERROR: Un vector del que se borran todos los elementos debería quedar vacio"
				<< endl;

	cout << "Fin probarBorrarElemento" << endl;
}

void probarConsultarElemento() {
	cout << "Inicio probarConsultarElemento" << endl;
	GenericVov<int> VOV_int;
	for (int i = 0; i < 7; ++i) {
		VOV_int.insertarElemento(i);
	}

	if (VOV_int.consultarElemento(3) != 3)
		cerr << "ERROR: al consultar ELmentor por posicion" << endl;
	cout << "Fin probarConsultarElemento" << endl;
}

void pruebasGenericVov() {
	cout << "------------------------------------------------------" << endl;
	cout << "Inicio de las pruebas de la clase GenericVov" << endl;
	cout << "------------------------------------------------------" << endl;
	probarConstructoresGenericVov();
	probarInsertarElemento();
	probarBorrarElemento();
	probarConsultarElemento();
	cout << "------------------------------------------------------" << endl;
	cout << "Fin de las pruebas de la clase GenericVov" << endl;
	cout << "------------------------------------------------------" << endl;
}

