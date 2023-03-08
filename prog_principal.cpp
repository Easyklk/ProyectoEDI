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
#include "PruebasPaciente.h"
#include "PruebasMedico.h"
#include "PruebasConsulta.h"
#include "PruebasFechaYHora.h"
#include "PruebasHospital.h"
#include "PruebasGenericVov.h"

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
//	-------Pruebas-------
//	pruebasPaciente();
//	pruebasMedico();
//	pruebasConsulta();
//	pruebasFechaYHora();
//	pruebasHospital();
//	pruebasGenericVov();
//	-------Pruebas-------

	string respuesta;
	Hospital *hospital = nullptr;
	Paciente *p = nullptr;
	Medico *m = nullptr;
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
			cin >> respuesta;
			p = hospital->buscarPaciente(respuesta);
			if (p != nullptr)
				p->mostrar();
			else
				cerr << " No hay ningun paciente asociado a ese DNI " << endl;

			break;

		case 6:
			cout << "Introduzca el apellido a consultar: ";
//			Intente usar el getline para apellidos compuestos pero no funcionaba
//			---------------------------
//			cin.ignore();
//			getline(cin, respuesta);
//			---------------------------
			cin >> respuesta;
			m = hospital->buscarMedico(respuesta);
			if (m != nullptr)
				m->mostrar();
			else
				cerr << " No hay ningun medico con ese Apellido" << endl;

			break;

		case 7:
			cout << "Introduzca el DNI a almacenar: ";
			cin >> respuesta;
			if (hospital->buscarPaciente(respuesta) != nullptr) {
				if (hospital->buscarConsulta(respuesta) != nullptr) {
					hospital->almacenarPaciente(respuesta);
				} else {
					cerr << "El paciente no tiene ninguna consulta asociada"
							<< endl;
				}
			} else
				cerr << "No hay ningun paciente asociado a ese DNI " << endl;

			break;

		case 0:
			fin = true;
			break;

		default:
			break;
		}

	} while (!fin);

	delete p;
	delete m;
	delete hospital;

	return 0;
}
