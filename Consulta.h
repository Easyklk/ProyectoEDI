/*
 * Consulta.h
 *
 *  Created on: 13 feb 2023
 *      Author: Isaac Romanillos
 */

#ifndef CONSULTA_H_
#define CONSULTA_H_

#include "Paciente.h"
#include "Medico.h"
#include "fechayhora.h"

enum TipoConsulta {
	Pendiente, Urgente, Externa
};
class Consulta {
private:
	Paciente *p;
	Medico *m;
	FechaYHora hora;
	TipoConsulta tipo;

public:
	Consulta();
	Consulta(Paciente *p);
	Consulta(Paciente *p, Medico *m);
	Consulta(Paciente *p, Medico *m, const TipoConsulta &tc,
			const FechaYHora &f);
	void asignarMedico(Medico *m);
	void agendarFecha(FechaYHora f);
	void mostrar();
	Paciente* getPaciente();
	Medico* getMedico();
	FechaYHora getHora();
	bool operator <(const Consulta &consulta);
	bool operator ==(const Consulta &consulta);
	bool operator >(const Consulta &consulta);
	~Consulta();
};

#endif /* CONSULTA_H_ */
