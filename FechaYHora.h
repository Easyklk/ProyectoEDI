/*
 * FechaYHora.h
 *
 *  Autor: Juan A. Rico (jarico@unex.es)
 *  Fecha: 1 Marzo 2023
 *  Version: 1.3
 *  Cambios: (1.1) unsigned int -> int: de acuerdo a las recomendaciones de C++
 *                 mostrar() es un metodo const
 *           (1.2) sustitución de los métodos menor e igual por los operadores
 *                 sobrecargados < e ==. Añadido operador >. Revisadas algunas
 *                 descripciones. Cambiado el nombre de los ficheros para que
 *                 se corresponda con el de la clase.
 *           (1.3) Corregidos errores en los operadores > y <.
 *                 Por seguridad: eliminación de "__" en macros (recomendación estándar C++).
 */

#ifndef _FECHAYHORA_H_
#define _FECHAYHORA_H_

#include <iostream>
#include <string>

using namespace std;


class FechaYHora {

private:
   
   int dia;
   int mes;
   int anio;
   int hora;
   int minutos;

public:
   // Pre   = { }
   // Compl = O(1)
   // Desc: Constructor por defecto.
          FechaYHora    ();

   // Pre   = { }
   // Compl = O(1)
   // Desc: Constructor parametrizado (hora completa).
          FechaYHora    (int dia, int mes, int anio, int hora, int minutos);

   // Pre   = { }
   // Compl = O(1)
   // Desc: Constructor parametrizado.
   //       Hora completa a partir de formato cadena: "02/04/2023 9:45"
   //       No comprueba errores en la fecha ni en el formato.
          FechaYHora    (const string &fh);
   
   // Pre   = { }
   // Compl = O(1)
   // Desc: Destructor.
         ~FechaYHora    ();
   
   // Pre   = { }
   // Compl = O(1)
   // Desc: Establece una fecha y hora completa. No comprueba errores.
   void   setFechaYHora (int dia, int mes, int anio, int hora, int minutos);
   
   // Pre   = { }
   // Compl = O(1)
   // Desc: TRUE si la fecha/hora actual (this) es estrictamente menor que fh,
   //        FALSE en otro caso
   bool operator < (const FechaYHora &fh);

   // Pre   = { }
   // Compl = O(1)
   // Desc: TRUE si la fecha/hora actual (this) es estrictamente mayor que fh,
   //       FALSE en otro caso
   bool operator > (const FechaYHora &fh);

   // Pre   = { }
   // Compl = O(1)
   // Desc: TRUE si la fecha/hora actual (this) es igual que fh,
   //       FALSE en otro caso
   bool operator == (const FechaYHora &fh);

   // Pre   = { }
   // Compl = O(1)
   // Desc: Muestra la fecha/hora en pantalla
   void   mostrar       () const;

};

#endif /* _FECHAYHORA_H_ */
