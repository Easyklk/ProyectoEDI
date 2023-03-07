/*
 * PruebasPaciente.cpp
 *
 *  Created on: 7 mar 2023
 *      Author: Isaac Romanillos
 */

#include "PruebasPaciente.h"

void probarConstructoresPaciente() {
	cout << "Inicio probarConstructoresPaciente" << endl;
	Paciente p1;
	if (p1.getNombre() != "" || p1.getApellidos() != "" || p1.getDNI() != ""
			|| p1.getGenero() != 2 || p1.getEdad() != 0) {
		cerr << "Error en el constructor por defecto" << endl;
	}

	Paciente p2("Isaac", "Romanillos Deza", "07464970V", Genero(0), 22);
	if (p2.getNombre() != "Isaac" || p2.getApellidos() != "Romanillos Deza"
			|| p2.getDNI() != "07464970V" || p2.getGenero() != 0
			|| p2.getEdad() != 22) {
		cerr << "Error en el constructor parametrizado" << endl;
	}

	Paciente p3 = p2;
	if (p3.getNombre() != "Isaac" || p3.getApellidos() != "Romanillos Deza"
			|| p3.getDNI() != "07464970V" || p3.getGenero() != 0
			|| p3.getEdad() != 22) {
		cerr << "Error en el constructor por copia" << endl;
	}

	p1.setNombre("Isaac");
	if (p1.getNombre() != "Isaac")
		cerr << "Error al modificar el nombre del paciente" << endl;

	p1.setApellidos("Romanillos Deza");
	if (p1.getApellidos() != "Romanillos Deza")
		cerr << "Error al modificar los apellidos del paciente" << endl;

	p1.setDNI("07464970V");
	if (p1.getDNI() != "07464970V")
		cerr << "Error al modificar el DNI del paciente" << endl;

	p1.setGenero(Genero(0));
	if (p1.getGenero() != 0)
		cerr << "Error al modificar el genero del paciente" << endl;

	p1.setEdad(22);
	if (p1.getEdad() != 22)
		cerr << "Error al modificar la edad del paciente" << endl;
	cout << "Fin probarConstructoresPersona" << endl;
}

void probarToStringPaciente() {
	cout << "Inicio probarToStringPaciente" << endl;
	Paciente p1("Isaac", "Romanillos Deza", "07464970V", Genero(0), 22);
	if (p1.toString()
			!= "Paciente{ Nombre: Isaac, Apellidos: Romanillos Deza, DNI: 22, Genero: Masculino }")
		cerr << "Error toString ()" << endl;

	cout << "Fin probarToStringPaciente" << endl;
}

void pruebasPaciente() {
	cout << "------------------------------------------------------" << endl;
	cout << "Inicio de las pruebas de la clase Persona" << endl;
	cout << "------------------------------------------------------" << endl;
	probarConstructoresPaciente();
	probarToStringPaciente();
	cout << "------------------------------------------------------" << endl;
	cout << "Fin de las pruebas de la clase Persona" << endl;
	cout << "------------------------------------------------------" << endl;
}
