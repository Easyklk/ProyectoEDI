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

}

Hospital::Hospital(string nombre) {
	this->nombre = nombre;
	this->VOV_Pacientes = new GenericVov<Paciente>();
	this->VOV_Consultas = new GenericVov<Consulta>();
	this->VOV_Medicos = new GenericVov<Medico>();
	this->cargarPaciente();

}

void Hospital::mostrarPaciente() {
	for (int i = 0; i < this->VOV_Pacientes->getCurrentElements(); ++i) {
		VOV_Pacientes->consultarElemento(i).mostrar();
	}
}

void Hospital::mostrarConsulta() {
}

void Hospital::mostrarMedico() {
}

Paciente Hospital::buscarP(string apellidos) {
	Paciente p;
	bool encontrado;
	int i = 0;
	while (i < this->VOV_Pacientes->getCurrentElements() && !encontrado) {
		if (this->VOV_Pacientes->consultarElemento(i).getApellidos()
				== apellidos) {
			encontrado = true;
			p = this->VOV_Pacientes->consultarElemento(i);
		} else {
			i++;
		}
	}
	return p;
}

Medico* Hospital::buscarM(string apellidos) {
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
	Paciente p;
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
				p = Paciente(nombre, apellidos, DNI, generoGen, edad);
				this->VOV_Pacientes->insertarElemento(p);
			}
		}
		ifs.close();
	}
}

void Hospital::cargarConsulta() {
//	ifstream ifs;
//	string DNI;
//	int genero, edad;
//	Paciente p;
//	Medico m;
//	FechaYHora fyh;
//
//	ifs.open("pacientes.csv");
//	if (ifs.fail()) {
//		cerr << "ERROR: fichero no encontrado." << endl;
//	} else {
//		while (!ifs.eof()) {
//			getline(ifs, DNI, ';');
//			if (!ifs.eof()) {
//				getline(ifs, nombre, ';');
//				getline(ifs, apellidos, ';');
//				getline(ifs, generoString, ';');
//				getline(ifs, edadString, '\n');
//				edad = stoi(edadString);
//				genero = stoi(generoString);
//				Genero generoGen = Genero(genero);
//				p = Paciente(nombre, apellidos, DNI, generoGen, edad);
//				this->VOV_Pacientes->insertarElemento(p);
//			}
//		}
//		ifs.close();
//	}
}

void Hospital::cargarMedicos() {
}

Hospital::~Hospital() {
	delete this->VOV_Pacientes;
	delete this->VOV_Consultas;
	delete this->VOV_Medicos;
}
