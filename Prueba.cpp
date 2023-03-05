/*
 * Prueba.cpp
 *
 *  Created on: 13 feb 2023
 *      Author: Isaac Romanillos
 */
#include "Consulta.h"
#include "Hospital.h"
#include "Medico.h"
#include "Paciente.h"
#include "fechayhora.h"
#include "GenericVov.h"

#include <iostream>
#include <string>

using namespace std;

int main() {
//	GenericVov<Consulta> *VovOfConsultas = new GenericVov<Consulta>();

//	Paciente *p1 = new Paciente("Juan", "Alvarez", "1919A", Masculino, 22);
//	Paciente *p2 = new Paciente("Alba", "Sanchez", "1818B", Femenino, 21);
//	Medico *m1 = new Medico("Medico1", "apellidos1", "especialidad1");
//	Medico *m2 = new Medico("Medico2", "apellidos2", "especialidad2");
//	Consulta a(p1, m1, Pendiente, FechaYHora(22, 2, 2023, 10, 30));
//	Consulta b(p2, m2, Externa, FechaYHora(21, 2, 2023, 10, 30));

	Hospital *h = new Hospital("Hospital Santa Justa");

	Paciente *p3 = h->buscarPaciente("07464970V");

	h->almacenarPaciente(p3);

//	Medico *m3 = h->buscarMedico("Perez");

//	m3 = h.buscarMedico("Perez");
//	m3->mostrar();
//	p3 = h.buscarPaciente("07464970V");
//	p3->mostrar();

//	h->mostrarPacientes();
//	h->mostrarMedicos();
//	h->mostrarConsultas();

	delete h;

	return 0;
}
