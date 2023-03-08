/*
 * prog_principal.cpp
 *
 *  Created on: 13 feb 2023
 *      Author: Isaac Romanillos
 */

#include <iostream>
#include <string>

#include "paciente.h"
#include "medico.h"
#include "consulta.h"
#include "hospital.h"
using namespace std;

int menu(string nombre) {
	int opcion;
	do {
		cout << endl;
		cout << "*---------  " << nombre << "  ---------*" << endl << endl;
		cout << "     1. Mostrar Estadísticas               " << endl;
		cout << "     2. Mostrar Pacientes                  " << endl;
		cout << "     3. Mostrar Médicos                    " << endl;
		cout << "     4. Mostrar Consultas                  " << endl;
		cout << "     5. Mostrar Paciente por DNI           " << endl;
		cout << "     6. Mostrar Medico por apellido		" << endl;
		cout << "     7. Guardar Paciente en Fichero		" << endl;
		cout << endl;
		cout << "     0. Finalizar.                         " << endl;
		cout << "*---------  " << nombre << "  ---------*" << endl << endl;
		cout << "                        Opción:  ";
		cin >> opcion;
		cin.ignore();

	} while ((opcion < 0) || (opcion > 7));

	return opcion;
}

int main() {
	string aux;
	Hospital *hospital = nullptr;
	Paciente *p = nullptr;
	bool fin = false;
	int opcion;
	hospital = new Hospital("Hospital Uex");

	do {
		opcion = menu(hospital->getNombre());
		switch (opcion) {
		case 1:
			hospital->mostrarEstadisticas();
			break;

		case 2:
			hospital->mostrarPacientes();
			break;

		case 3:
			hospital->mostrarMedicos();
			break;

		case 4:
			hospital->mostrarConsultas();
			break;

		case 5:
			cout << "Introduzca el DNI a consultar: ";
			cin >> aux;
			hospital->buscarPaciente(aux)->mostrar();
			break;

		case 6:
			cout << "Introduzca el apellido a consultar: ";
			cin >> aux;
			hospital->buscarMedico(aux)->mostrar();
			break;

		case 7:
			cout << "Introduzca el DNI a almacenar: ";
			cin >> aux;
			p = hospital->buscarPaciente(aux);
			hospital->almacenarPaciente(p);
			break;

		case 0:
			fin = true;
			break;

		default:
			break;

		}

	} while (!fin);

	delete hospital;

	return 0;
}
