/*
 * GenericVov.h
 *
 *  Created on: 23 feb 2023
 *      Author: Isaac Romanillos
 */

#ifndef GENERICVOV_H_
#define GENERICVOV_H_

#include <iostream>
#include <string>

using namespace std;

const int MAX_ELEMENTS = 250;
template<class DataType>
class GenericVov {
private:
	DataType vector[MAX_ELEMENTS]; // Vector para un máximo de MAX punteros

	int currentElements; 		// Elementos útiles actualmente en el vector;
								// también indica la primera posción libre en el vector
public:

	// PRE: ---
	// DES: Constructor por defecto (currentElements = 0)
	// COM: O(1)
	GenericVov();

	// PRE: ---
	// DES: Devuelve this->vector[this->currentElements - 1]
	// COM: O(1)
	DataType getTop();

	// PRE: this->currentElements < MAX_ELEMENTS (el vector no está lleno)
	// DES: Inserta en orden el puntero al final de this->vector; incrementa this->currentElements en 1
	// COM: O(n)
	void insertarElemento(DataType data);

	// PRE: 0 <= pos < this->currentElements; this->currentElements > 0 (el vector no está vacío)
	// DES: Elimina de this->vector el puntero de la posición pos y decrementa this->currentElements en 1
	// COM: O(n) - Tamaño del problema = this->currentElements
	void borrarElemento(int pos);

	// PRE: 0 <= pos < this->currentElements.
	// DES: Devuelve this->vector[pos]
	// COM: O(1)
	DataType consultarElemento(int pos);

	// PRE: ---
	// DES: Devuelve this->currentElements
	// COM: O(1)
	int getCurrentElements();

	// PRE: ---
	// DES: Devuelve true si this->currentElements = 0; false en caso contrario
	// COM: O(1)
	bool isEmpty();

	// PRE: ---
	// DES: Devuelve true si this->currentElements = MAX_ELEMENTS; false en caso contrario
	// COM: O(1)
	bool isFull();

	// PRE: ---
	// DES: Destructor
	// COM: O(1)
	~GenericVov();
};

template<class DataType> GenericVov<DataType>::GenericVov() {
	this->currentElements = 0;
}

template<class DataType> DataType GenericVov<DataType>::getTop() {
	return this->vector[this->currentElements - 1];
}

template<class DataType> void GenericVov<DataType>::insertarElemento(
		DataType data) {
	bool encontrado = false;
	int pos = 0, i = 0;
	if (!this->isEmpty()) {
		while (i < this->currentElements && !encontrado) {
			if (vector[i] > data) {
				encontrado = true;
			} else {
				i++;
			}
			pos = i;
		}
		for (i = this->currentElements; i > pos; i--) {
			vector[i] = vector[i - 1];
		}
		vector[pos] = data;
		this->currentElements++;
	} else {
		vector[this->currentElements] = data;
		this->currentElements++;
	}
}

template<class DataType> void GenericVov<DataType>::borrarElemento(int pos) {
	for (int i = pos; i < this->currentElements; i++) {
		vector[i] = vector[i + 1];
	}
	this->currentElements--;
}

template<class DataType> DataType GenericVov<DataType>::consultarElemento(
		int pos) {
	return this->vector[pos];
}

template<class DataType> int GenericVov<DataType>::getCurrentElements() {
	return this->currentElements;
}
template<class DataType> bool GenericVov<DataType>::isEmpty() {
	return this->currentElements == 0;
}

template<class DataType> bool GenericVov<DataType>::isFull() {
	return this->currentElements == MAX_ELEMENTS;
}

template<class DataType>
inline GenericVov<DataType>::~GenericVov() {
}

#endif /* GENERICVOV_H_ */
