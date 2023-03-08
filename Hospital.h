/*
 * Hospital.h
 *
 *  Created on: 27 feb 2023
 *      Author: Isaac Romanillos
 */

#ifndef HOSPITAL_H_
#define HOSPITAL_H_

#include "GenericVov.h"
#include "Consulta.h"
#include "Paciente.h"
#include "Medico.h"

class Hospital {
private:
	string nombre;
	GenericVov<Paciente*> *VOV_Pacientes;
	GenericVov<Consulta*> *VOV_Consultas;
	GenericVov<Medico*> *VOV_Medicos;

	// PRE: ---
	// DES: carga desde un fichero todos los pacientes en VOV_Pacientes
	// COM: O(n)
	void cargarPaciente();

	// PRE: ---
	// DES: carga desde un fichero todos los medicos en VOV_Medicos
	// COM: O(n)
	void cargarMedicos();

	// PRE: ---
	// DES: carga desde un fichero todas las consultas en VOV_Consultas
	// COM: O(n)
	void cargarConsulta();

public:

	// PRE: ---
	// DES: Constructor por defecto
	// COM: O(1)
	Hospital();

	// PRE: ---
	// DES: Constructor por defecto
	// COM: O(1)
	Hospital(string nombre);

	// PRE: ---
	// DES: devuelve this->nombre
	// COM: O(1)
	string getNombre();

	// PRE: ---
	// DES: muestra por consola todos los pacientes
	// COM: O(n)
	void mostrarPacientes();

	// PRE: ---
	// DES: muestra por consola todos los medicos
	// COM: O(n)
	void mostrarMedicos();

	// PRE: ---
	// DES: muestra por consola todas las consultas
	// COM: O(n)
	void mostrarConsultas();

	// PRE: ---
	// DES: muestra por consola el nº total de pacientes, medicos y consultas
	// COM: O(n)
	void mostrarEstadisticas();

	// PRE: que exista un paciente con ese DNI
	// DES: devuelve el paciente con el DNI facilitado
	// COM: O(n)
	Paciente* buscarPaciente(string DNI);

	// PRE: que exista un medico con ese apellido
	// DES: devuelve el Medico con el apellido facilitado
	// COM: O(n)
	Medico* buscarMedico(string apellidos);

	// PRE: que exista alguna consulta con ese DNI de paciente
	// DES: devuelve la consulta con el DNI de paciente facilitado
	// COM: O(n)
	Consulta* buscarConsulta(string DNI);

	// PRE: ---
	// DES: crea un fichero de texto con la informacion de un paciente con el DNI facilitado
	// COM: O(n)
	void almacenarPaciente(string DNI);

	// PRE: ---
	// DES: Destructor
	// COM: O(1)
	~Hospital();

};

#endif /* HOSPITAL_H_ */
