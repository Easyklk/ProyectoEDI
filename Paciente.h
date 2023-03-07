/*
 * Paciente.h
 *
 *  Created on: 6 feb 2023
 *      Author: Isaac Romanillos
 */

#ifndef PACIENTE_H_
#define PACIENTE_H_
#include <string>

using namespace std;

enum Genero {
	Masculino, Femenino, Indefinido
};

class Paciente {
private:
	string nombre;
	string apellidos;
	string DNI;
	Genero genero;
	int edad;
public:

	// PRE: ---
	// DES: Constructor por defecto
	// COM: O(1)
	Paciente();

	// PRE: genero >= 0 <= 2, edad >= 0
	// DES: Constructor parametrizado
	// COM: O(1)
	Paciente(string nombre, string apellidos, string DNI, Genero genero,
			int edad);

	// PRE: orig correctamente inicializada
	// DES: Constructor por copia
	// COM: O(1)
	Paciente(const Paciente &orig);

	// PRE: ---
	// DES: modifica this->nombre = nombre
	// COM: O(1)
	void setNombre(string nombre);

	// PRE: ---
	// DES: modifica this->apellidos = apellidos
	// COM: O(1)
	void setApellidos(string apellidos);

	// PRE: ---
	// DES: modifica this->dni = dni
	// COM: O(1)
	void setDNI(string dni);

	// PRE: ---
	// DES: modifica this->genero = genero
	// COM: O(1)
	void setGenero(Genero genero);

	// PRE: ---
	// DES: modifica this->edad = eda
	// COM: O(1)
	void setEdad(int edad);

	// PRE: ---
	// DES: devuelve this->nombre
	// COM: O(1)
	string getNombre();

	// PRE: ---
	// DES: devuelve this->apellidos
	// COM: O(1)
	string getApellidos();

	// PRE: ---
	// DES: devuelve this->DNI
	// COM: O(1)
	string getDNI();

	// PRE: ---
	// DES: devuelve this->genero
	// COM: O(1)
	int getGenero();

	// PRE: ---
	// DES: devuelve this->edad
	// COM: O(1)
	int getEdad();

	bool operator <(const Paciente &paciente);
	bool operator ==(const Paciente &paciente);
	bool operator >(const Paciente &paciente);

	// PRE: ---
	// DES: muestra por consola todos los atributos del paciente
	// COM: O(1)
	void mostrar();

	// PRE: ---
	// DES: devuelve un string con todos los atributos del Paciente
	// COM: O(1)
	string toString();

	// PRE: ---
	// DES: Destructor
	// COM: O(1)
	~Paciente();
};

#endif /* PACIENTE_H_ */
