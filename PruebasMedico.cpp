/*
 * PruebasMedico.cpp
 *
 *  Created on: 7 mar 2023
 *      Author: Isaac Romanillos
 */

#include "PruebasMedico.h"

void probarConstructoresMedico() {
	cout << "Inicio probarConstructoresMedico" << endl;

	Medico m1;
	if (m1.getNombre() != "" || m1.getApellidos() != ""
			|| m1.getEspecialidad() != "")
		cerr << "Error en el constructor por defecto" << endl;

	Medico m2("Isaac", "Romanillos Deza", "Ser un matao'");
	if (m2.getNombre() != "Isaac" || m2.getApellidos() != "Romanillos Deza"
			|| m2.getEspecialidad() != "Ser un matao'")
		cerr << "Error en el constructor por defecto" << endl;

	Medico m3 = m2;
	if (m3.getNombre() != "Isaac" || m3.getApellidos() != "Romanillos Deza"
			|| m3.getEspecialidad() != "Ser un matao'")
		cerr << "Error en el constructor por defecto" << endl;

	m1.setNombre("Isaac");
	if (m1.getNombre() != "Isaac")
		cerr << "Error al modificar el nombre del medico" << endl;

	m1.setApellidos("Romanillos Deza");
	if (m1.getApellidos() != "Romanillos Deza")
		cerr << "Error al modificar los apellidos del medico" << endl;

	m1.setEspecialidad("Ser un matao'");
	if (m1.getEspecialidad() != "Ser un matao'")
		cerr << "Error al modificar la especialidad del medico" << endl;
	cout << "Fin probarConstructoresPersona" << endl;
}

void probarToStringMedico() {
	cout << "Inicio probarToStringMedico" << endl;
	Medico m1("Isaac", "Romanillos Deza", "Ser un matao'");
	if (m1.toString()
			!= "Medico{ Nombre: Isaac, Apellidos: Romanillos Deza, Especialidad: Ser un matao' }")
		cerr << "Error toString ()" << endl;

	cout << "Fin probarToStringMedico" << endl;
}

void pruebasMedico() {
	cout << "------------------------------------------------------" << endl;
	cout << "Inicio de las pruebas de la clase Medico" << endl;
	cout << "------------------------------------------------------" << endl;
	probarConstructoresMedico();
	probarToStringMedico();
	cout << "------------------------------------------------------" << endl;
	cout << "Fin de las pruebas de la clase Medico" << endl;
	cout << "------------------------------------------------------" << endl;
}
