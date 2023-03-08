/*
 * PruebasHospital.cpp
 *
 *  Created on: 8 mar 2023
 *      Author: Isaac Romanillos
 */

#include "PruebasHospital.h"
#include "Hospital.h"

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void probarConstructoresHospital() {
	cout << "Inicio probarConstructoresHospital" << endl;
	Hospital *h1 = new Hospital();
	if (h1->getNombre() != "")
		cerr << "Error en el constructor por defecto" << endl;
	Hospital *h2 = new Hospital("Hospital Uex");
	if (h2->getNombre() != "Hospital Uex")
		cerr << "Error en el constructor parametrizado" << endl;

	if (h2->getNombre() != "Hospital Uex")
		cerr << "Error al obtener el nombre del hospital" << endl;

	cout << "Fin probarConstructoresHospital" << endl;
}

void probarMetodosCargar() {
	cout << "Inicio probarMetodosCargar" << endl;
	cout << "Fin probarMetodosCargar" << endl;
}

void probarMetodosBuscar() {
	cout << "Inicio probarMetodosBuscar" << endl;
	Hospital *h = new Hospital();
	Paciente *p = new Paciente("Isaac", "Romanillos Deza", "07464970V",
			Genero(0), 22);
	if (h->buscarPaciente("07464970V")->getDNI() != p->getDNI())
		cerr << "Error al buscar paciente" << endl;

	Medico *m = new Medico("Paulino", "Inquietez", "Arregla Pinreles");
	if (h->buscarMedico("Inquietez")->getApellidos() != m->getApellidos())
		cerr << "Error al buscar medico" << endl;

	Consulta *c = new Consulta(p, m, TipoConsulta(0), FechaYHora());
	if (h->buscarConsulta("07464970V") != c)
		cerr << "Error al buscar consulta" << endl;
	cout << "Fin probarMetodosBuscar" << endl;
}

void probarAlmacenar() {
	cout << "Inicio probarAlmacenar" << endl;
	ifstream ifs;
	Hospital *h = new Hospital();
	string DNI = "07464970V";
	h->almacenarPaciente(DNI);
	ifs.open(DNI + ".txt");
	if (ifs.fail())
		cerr << "Error al almacenar un paciente" << endl;
	ifs.close();
	cout << "Fin probarAlmacenar" << endl;

}

void pruebasHospital() {
	cout << "------------------------------------------------------" << endl;
	cout << "Inicio de las pruebas de la clase Hospital" << endl;
	cout << "------------------------------------------------------" << endl;
	probarConstructoresHospital();
	probarMetodosCargar();
	probarMetodosBuscar();
	probarAlmacenar();
	cout << "------------------------------------------------------" << endl;
	cout << "Fin de las pruebas de la clase Hospital" << endl;
	cout << "------------------------------------------------------" << endl;
}

