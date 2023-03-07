/*
 * PruebasFechaYHora.cpp
 *
 *  Created on: 7 mar 2023
 *      Author: Isaac Romanillos
 */

#include "PruebasFechaYHora.h"

void probarConstructoresFechaYHora() {
	cout << "Inicio probarConstructoresFechaYHora" << endl;
	FechaYHora fyh1;
	if (fyh1.toString() != "0/0/0 0:0")
		cerr << "Error en el constructor por defecto" << endl;

	FechaYHora fyh2(23, 3, 2023, 9, 9);
	if (fyh2.toString() != "23/3/2023 9:9")
		cerr << "Error en el constructor por parametros 1" << endl;

	FechaYHora fyh3("23/3/2023 9:9");
	if (fyh3.toString() != "23/3/2023 9:9")
		cerr << "Error en el constructor por parametros 2" << endl;

	fyh1.setFechaYHora(23, 3, 2023, 9, 9);
	if (fyh1.toString() != "23/3/2023 9:9")
		cerr << "Error en el modificador" << endl;

	cout << "Fin probarConstructoresFechaYHora" << endl;
}

void probarToStringFechaYHora() {
	cout << "Inicio probarToStringPaciente" << endl;
	FechaYHora fyh(23, 3, 2023, 9, 9);
	if (fyh.toString() != "23/3/2023 9:9")
		cerr << "Error toString ()" << endl;

	cout << "Fin probarToStringPaciente" << endl;
}

void pruebasFechaYHora() {
	cout << "------------------------------------------------------" << endl;
	cout << "Inicio de las pruebas de la clase FechaYHora" << endl;
	cout << "------------------------------------------------------" << endl;
	probarConstructoresFechaYHora();
	probarToStringFechaYHora();
	cout << "------------------------------------------------------" << endl;
	cout << "Fin de las pruebas de la clase FechaYHora" << endl;
	cout << "------------------------------------------------------" << endl;
}
