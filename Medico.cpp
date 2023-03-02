/*
 * Medico.cpp
 *
 *  Created on: 12 feb 2023
 *      Author: Isaac Romanillos
 */

#include "Medico.h"
#include <iostream>

Medico::Medico() {
	this->nombre = "";
	this->apellidos = "";
	this->especialidad = "";
}

Medico::Medico(string nombre, string apellidos, string especialidad) {
	this->nombre = nombre;
	this->apellidos = apellidos;
	this->especialidad = especialidad;
}

Medico::Medico(const Medico &orig) {
	this->nombre = orig.nombre;
	this->apellidos = orig.apellidos;
	this->especialidad = orig.especialidad;
}
string Medico::getNombre() {
	return nombre;
}
string Medico::getApellidos() {
	return apellidos;
}
string Medico::getEspecialidad() {
	return especialidad;
}

void Medico::setNombre(string nombre) {
	this->nombre = nombre;
}

void Medico::setApellidos(string apellidos) {
	this->apellidos = apellidos;
}

void Medico::setEspecialidad(string especialidad) {
	this->especialidad = especialidad;
}

void Medico::mostrar() {
	cout << "Medico{ Nombre: " << nombre << ", Apellidos: " << apellidos
			<< ", Especialidad: " << especialidad << "}" << endl;
}

bool Medico::operator <(const Medico &medico) {
	return (this->apellidos < medico.apellidos);
}

bool Medico::operator ==(const Medico &medico) {
	return (this->apellidos == medico.apellidos);
}

bool Medico::operator >(const Medico &medico) {
	return (this->apellidos > medico.apellidos);
}

Medico::~Medico() {
}
