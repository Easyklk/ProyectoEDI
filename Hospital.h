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
	GenericVov<Paciente> *VOV_Pacientes;
	GenericVov<Consulta> *VOV_Consultas;
	GenericVov<Medico> *VOV_Medicos;
public:
	Hospital();
	Hospital(string nombre);
	void mostrarPacientes();
	void mostrarConsultas();
	void mostrarMedicos();
	Paciente* buscarPaciente(string apellidos);
	Medico* buscarMedico(string apellidos);
	Consulta* buscarConsulta(string DNI);
	void cargarPaciente();
	void cargarConsulta();
	void cargarMedicos();
	void almacenarPaciente(Paciente *p);
	~Hospital();
};

#endif /* HOSPITAL_H_ */
