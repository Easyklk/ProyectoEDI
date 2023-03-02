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
	DataType vector[MAX_ELEMENTS];
	int currentElements;
public:
	GenericVov();
	DataType getTop();
	void insertarElemento(DataType data);
	void borrarElemento(int pos);
	DataType consultarElemento(int pos);
	int getCurrentElements();
	bool isEmpty();
	bool isFull();
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
