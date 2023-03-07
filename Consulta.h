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
	// PRE: ---
	// DES: Constructor por defecto
	// COM: O(1)
	Consulta();

	// PRE: p correctamente inicializada
	// DES: Constructor parametrizado 1
	// COM: O(1)
	Consulta(Paciente *p);

	// PRE: p y m correctamente inicializada
	// DES: Constructor parametrizado 2
	// COM: O(1)
	Consulta(Paciente *p, Medico *m);

	// PRE: p, m y f correctamente inicializada, tc >= 0 <= 2
	// DES: Constructor parametrizado 3
	// COM: O(1)
	Consulta(Paciente *p, Medico *m, const TipoConsulta &tc,
			const FechaYHora &f);

	// PRE: ---
	// DES: devuelve this->p
	// COM: O(1)
	Paciente* getPaciente();

	// PRE: ---
	// DES: devuelve this->m
	// COM: O(1)
	Medico* getMedico();

	// PRE: ---
	// DES: devuelve this->hora
	// COM: O(1)
	FechaYHora getHora();

	// PRE: ---
	// DES: devuelve this->tipo
	// COM: O(1)
	TipoConsulta getTipo();

	// PRE: m != nullptr
	// DES: asigna un medico a un paciente
	// COM: O(1)
	void asignarMedico(Medico *m);

	void agendarFecha(FechaYHora f);

	// PRE: ---
	// DES: muestra por consola todos los atributos de la consulta
	// COM: O(1)
	void mostrar();

	bool operator <(const Consulta &consulta);
	bool operator ==(const Consulta &consulta);
	bool operator >(const Consulta &consulta);

	// PRE: ---
	// DES: devuelve un string con todos los atributos de la consulta
	// COM: O(1)
	string toString();

	// PRE: ---
	// DES: Destructor
	// COM: O(1)
	~Consulta();
};

#endif /* CONSULTA_H_ */
