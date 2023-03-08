/*
 * PruebasConsulta.cpp
 *
 *  Created on: 7 mar 2023
 *      Author: Isaac Romanillos
 */

#include "PruebasConsulta.h"

void probarConstructorConsulta() {
	cout << "Inicio probarConstructorConsulta" << endl;

	Consulta c1;
	FechaYHora fyh1("0/0/0 0:0");
	if (c1.getPaciente() != nullptr || c1.getMedico() != nullptr
			|| c1.getHora().toString() != fyh1.toString())
		cerr << "Error en el constructor por defecto" << endl;

	Paciente *p1 = new Paciente();
	Consulta c2(p1);
	if (c2.getPaciente() != p1 || c2.getMedico() != nullptr
			|| c2.getHora().toString() != fyh1.toString())
		cerr << "Error en el constructor parametrizado 1" << endl;

	Medico *m1 = new Medico();
	Consulta c3(p1, m1);
	if (c3.getPaciente() != p1 || c3.getMedico() != m1
			|| c3.getHora().toString() != fyh1.toString())
		cerr << "Error en el constructor parametrizado 2" << endl;

	Consulta c4(p1, m1, TipoConsulta(0), fyh1);
	if (c4.getPaciente() != p1 || c4.getMedico() != m1
			|| c4.getHora().toString() != fyh1.toString() || c4.getTipo() != 0)
		cerr << "Error en el constructor parametrizado 3" << endl;

	cout << "Fin probarConstructorConsulta" << endl;
}

void probarAsignarMedico() {
	cout << "Inicio probarAsignarMedico" << endl;
	Consulta c1;
	Medico *m = new Medico();
	c1.asignarMedico(m);
	if (c1.getMedico() != m)
		cerr << "Error al asignar medico" << endl;
	cout << "Fin probarAsignarMedico" << endl;
}

void probarAgendarFecha() {
	cout << "Inicio probarAgendarFecha" << endl;
	cout << "Fin probarAgendarFecha" << endl;
}

void probarToStringConsulta() {
	cout << "Inicio probarToStringConsulta" << endl;
	Paciente *p1 = new Paciente("Isaac", "Romanillos Deza", "07464970V",
			Genero(0), 22);
	Medico *m2 = new Medico("Isaac", "Romanillos Deza", "Ser un matao");
	FechaYHora fyh1("23/03/2023 09:09");

	Consulta c1(p1, m2, TipoConsulta(0), fyh1);
	if (c1.toString()
			!= "Consulta{ Medico{ Nombre: Isaac, Apellidos: Romanillos Deza, Especialidad: Ser un matao } Fecha y hora: 23/3/2023 9:9 } ")
		cerr << "Error toStringConsulta ()" << endl;

	cout << "Fin probarToStringConsulta" << endl;
}

void pruebasConsulta() {
	cout << "------------------------------------------------------" << endl;
	cout << "Inicio de las pruebas de la clase Consulta" << endl;
	cout << "------------------------------------------------------" << endl;
	probarConstructorConsulta();
	probarAsignarMedico();
	probarAgendarFecha();
	probarToStringConsulta();
	cout << "------------------------------------------------------" << endl;
	cout << "Fin de las pruebas de la clase Consulta" << endl;
	cout << "------------------------------------------------------" << endl;
}
