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
	void cargarPaciente();
	void cargarConsulta();
	void cargarMedicos();
public:
	Hospital();
	Hospital(string nombre);
	string getNombre();

	void mostrarPacientes();
	void mostrarConsultas();
	void mostrarMedicos();
	void mostrarEstadisticas();

	Paciente* buscarPaciente(string DNI);
	Medico* buscarMedico(string apellidos);
	Consulta* buscarConsulta(string DNI);

	void almacenarPaciente(string DNI);

	~Hospital();

};

#endif /* HOSPITAL_H_ */
