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
	// PRE: ---
	// DES: Constructor por defecto
	// COM: O(1)
	Medico();

	// PRE: ---
	// DES: Constructor parametrizado
	// COM: O(1)
	Medico(string nombre, string apellidos, string especialidad);

	// PRE: orig correctamente inicializada
	// DES: Constructor por copia
	// COM: O(1)
	Medico(const Medico &orig);

	// PRE: ---
	// DES: devuelve this->nombre
	// COM: O(1)
	string getNombre();

	// PRE: ---
	// DES: devuelve this->apellidos
	// COM: O(1)
	string getApellidos();

	// PRE: ---
	// DES: devuelve this->especialidad
	// COM: O(1)
	string getEspecialidad();

	// PRE: ---
	// DES: modifica this->nombre = nombre
	// COM: O(1)
	void setNombre(string nombre);

	// PRE: ---
	// DES: modifica this->apellidos = apellidos
	// COM: O(1)
	void setApellidos(string apellidos);

	// PRE: ---
	// DES: modifica this->especialidad = especialidad
	// COM: O(1)
	void setEspecialidad(string especialidad);

	bool operator <(const Medico &medico);
	bool operator ==(const Medico &medico);
	bool operator >(const Medico &medico);

	// PRE: ---
	// DES: muestra por consola todos los atributos del medico
	// COM: O(1)
	void mostrar();

	// PRE: ---
	// DES: devuelve un string con todos los atributos del medico
	// COM: O(1)
	string toString();

	~Medico();
};

#endif /* MEDICO_H_ */
