/*
 * Consulta.cpp
 *
 *  Created on: 13 feb 2023
 *      Author: Isaac Romanillos
 */

#include "Consulta.h"
#include "Medico.h"
#include "Paciente.h"
#include "fechayhora.h"

#include <iostream>
#include <string>

using namespace std;

Consulta::Consulta() {
	// TODO Auto-generated constructor stub
	p = nullptr;
	m = nullptr;
	tipo = Vacio;
	alta = false;
	informe = "";
}

Consulta::Consulta(Paciente *p) {
	this->p = p;
	m = nullptr;
	tipo = Vacio;
	alta = false;
	informe = "";
}

Consulta::Consulta(Paciente *p, Medico *m) {
	this->p = p;
	this->m = m;
	tipo = Vacio;
	alta = false;
	informe = "";
}

Consulta::Consulta(Paciente *p, Medico *m, const TipoConsulta &tc,
		const FechaYHora &f) {
	this->p = p;
	this->m = m;
	hora = f;
	tipo = tc;
	alta = false;
	informe = "";
}

void Consulta::asignarMedico(Medico *m) {
	this->m = m;
}

void Consulta::agendarFecha(FechaYHora f) {
}

void Consulta::darDeAlta() {
	this->alta = true;
}

void Consulta::adjuntarInforme() {
}

void Consulta::mostrar() {
	string tipo;

	if (this->tipo == Vacio) {
		tipo = "Vacio";
	} else if (this->tipo == Pendiente) {
		tipo = "Pendiente";
	} else if (this->tipo == Urgente) {
		tipo = "Urgente";
	} else {
		tipo = "Externa";
	}

	cout << "Consulta{ ";
	p->mostrar();
	m->mostrar();
	hora.mostrar();
	cout << ", Tipo de Consulta: " << tipo << "Alta: " << alta << ", Informe: "
			<< informe << "}" << endl << endl;

}

FechaYHora Consulta::getHora() {
	return this->hora;
}

bool Consulta::operator <(const Consulta &consulta) {
	return (this->hora < consulta.hora);
}

bool Consulta::operator ==(const Consulta &consulta) {
	return (this->hora == consulta.hora);

}

bool Consulta::operator >(const Consulta &consulta) {
	return (this->hora > consulta.hora);
}
Consulta::~Consulta() {
	// TODO Auto-generated destructor stub
}
