/*
 * Hospital.cpp
 *
 *  Created on: 27 feb 2023
 *      Author: Isaac Romanillos
 */

#include "Hospital.h"
#include "Paciente.h"
#include "Consulta.h"
#include "Medico.h"
#include "FechaYHora.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

Hospital::Hospital() {
	this->nombre = "";
	this->VOV_Pacientes = new GenericVov<Paciente>();
	this->VOV_Consultas = new GenericVov<Consulta>();
	this->VOV_Medicos = new GenericVov<Medico>();
	this->cargarPaciente();
	this->cargarMedicos();
	this->cargarConsulta();
}

Hospital::Hospital(string nombre) {
	this->nombre = nombre;
	this->VOV_Pacientes = new GenericVov<Paciente>();
	this->VOV_Consultas = new GenericVov<Consulta>();
	this->VOV_Medicos = new GenericVov<Medico>();
	this->cargarPaciente();
	this->cargarMedicos();
	this->cargarConsulta();
}

void Hospital::mostrarPaciente() {
	for (int i = 0; i < this->VOV_Pacientes->getCurrentElements(); ++i) {
		VOV_Pacientes->consultarElemento(i).mostrar();
	}
}

void Hospital::mostrarConsulta() {
	for (int i = 0; i < this->VOV_Consultas->getCurrentElements(); ++i) {
		VOV_Consultas->consultarElemento(i).mostrar();
	}
}

void Hospital::mostrarMedico() {
	for (int i = 0; i < this->VOV_Medicos->getCurrentElements(); ++i) {
		VOV_Medicos->consultarElemento(i).mostrar();
	}
}

Paciente* Hospital::buscarPaciente(string dni) {
	Paciente *p = nullptr;
	bool encontrado;
	int i = 0;
	while (i < this->VOV_Pacientes->getCurrentElements() && !encontrado) {
		if (this->VOV_Pacientes->consultarElemento(i).getDNI() == dni) {
			encontrado = true;
			p = new Paciente(this->VOV_Pacientes->consultarElemento(i));
		} else {
			i++;
		}
	}
	return p;
}

Medico* Hospital::buscarMedico(string apellidos) {
	Medico *m = nullptr;
	bool encontrado;
	int i = 0;
	while (i < this->VOV_Medicos->getCurrentElements() && !encontrado) {
		if (this->VOV_Medicos->consultarElemento(i).getApellidos()
				== apellidos) {
			encontrado = true;
			m = new Medico(this->VOV_Medicos->consultarElemento(i));
		} else {
			i++;
		}
	}
	return m;
}

void Hospital::cargarPaciente() {
	ifstream ifs;
	string nombre, apellidos, DNI, edadString, generoString;
	int genero, edad;
	Paciente *p = nullptr;
	ifs.open("pacientes.csv");
	if (ifs.fail()) {
		cerr << "ERROR: fichero no encontrado." << endl;
	} else {
		while (!ifs.eof()) {
			getline(ifs, DNI, ';');
			if (!ifs.eof()) {
				getline(ifs, nombre, ';');
				getline(ifs, apellidos, ';');
				getline(ifs, generoString, ';');
				getline(ifs, edadString, '\n');
				edad = stoi(edadString);
				genero = stoi(generoString);
				Genero generoGen = Genero(genero);
				p = new Paciente(nombre, apellidos, DNI, generoGen, edad);
				this->VOV_Pacientes->insertarElemento(*p);
			}
		}
		ifs.close();
	}
}

void Hospital::cargarConsulta() {
	ifstream ifs;
	Paciente *p = nullptr;
	Medico *m = nullptr;
	Consulta *c = nullptr;
	FechaYHora fyh;
	string DNI, apellidos, fecha, tipoString;
	int tipoInt = 0;
	ifs.open("consultas.csv");
	if (ifs.fail()) {
		cerr << "ERROR: fichero no encontrado." << endl;
	} else {
		while (!ifs.eof()) {
			getline(ifs, DNI, ';');
			if (!ifs.eof()) {
				getline(ifs, apellidos, ';');
				getline(ifs, tipoString, ';');
				cout << tipoString << endl;
				getline(ifs, fecha, '\n');
//				tipoInt = stoi(tipoString);
				TipoConsulta tipo = TipoConsulta(tipoInt);
				p = buscarPaciente(DNI);
				m = buscarMedico(apellidos);
				fyh = FechaYHora(fecha);

				c = new Consulta(p, m, tipo, fecha);
				this->VOV_Consultas->insertarElemento(*c);
			}
		}
		ifs.close();
	}
}

void Hospital::cargarMedicos() {
	ifstream ifs;
	string nombre, apellidos, especialidad;
	Medico *m = nullptr;
	ifs.open("medicos.csv");
	if (ifs.fail()) {
		cerr << "ERROR: fichero no encontrado." << endl;
	} else {
		while (!ifs.eof()) {
			getline(ifs, nombre, ';');
			if (!ifs.eof()) {
				getline(ifs, apellidos, ';');
				getline(ifs, especialidad, '\n');
				m = new Medico(nombre, apellidos, especialidad);
				this->VOV_Medicos->insertarElemento(*m);
			}
		}
		ifs.close();
	}
}

Hospital::~Hospital() {
	delete this->VOV_Pacientes;
	delete this->VOV_Consultas;
	delete this->VOV_Medicos;
}
