/*
 * Medico.h
 *
 *  Created on: 12 feb 2023
 *      Author: Isaac Romanillos
 */

#ifndef MEDICO_H_
#define MEDICO_H_

#include <string>
using namespace std;
class Medico {
private:
	string nombre;
	string apellidos;
	string especialidad;
public:
	Medico();
	Medico(string nombre, string apellidos, string especialidad);
	Medico(const Medico &orig);
	~Medico();

	string getApellidos();
	string getEspecialidad();
	string getNombre();

	void setApellidos(string apellidos);
	void setEspecialidad(string especialidad);
	void setNombre(string nombre);

	bool operator <(const Medico &medico);
	bool operator ==(const Medico &medico);
	bool operator >(const Medico &medico);

	void mostrar();
};

#endif /* MEDICO_H_ */
