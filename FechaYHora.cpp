/*
 * fechayhora.cpp
 *
 *  Autor: Juan A. Rico (jarico@unex.es)
 *  Fecha: 1 Marzo 2023
 *  Version: 1.3
 */

#include <iostream>
#include <string>

#include "FechaYHora.h"
using namespace std;

FechaYHora::FechaYHora (int dia, int mes, int anio, int hora, int minutos) {
   this->dia     = dia;
   this->mes     = mes;
   this->anio    = anio;
   this->hora    = hora;
   this->minutos = minutos;
}


FechaYHora::FechaYHora () {
   this->dia     = 0;
   this->mes     = 0;
   this->anio    = 0;
   this->hora    = 0;
   this->minutos = 0;
}


FechaYHora::FechaYHora (const string &fh) {
   
   size_t pos = 0;
   string token;
   string copia = fh;
   
   // Leer dia
   pos = copia.find("/");
   string dia = copia.substr(0, pos);
   copia.erase(0, pos + 1);
   
   // Leer mes
   pos = copia.find("/");
   string mes = copia.substr(0, pos);
   copia.erase(0, pos + 1);
   
   // Leer año
   pos = copia.find(" ");
   string anio = copia.substr(0, pos);
   copia.erase(0, pos + 1);
   
   // Leer hora
   pos = copia.find(":");
   string hora = copia.substr(0, pos);
   copia.erase(0, pos + 1);
   
   // Leer minutos
   pos = copia.find("\n");
   string minutos = copia.substr(0, pos);
   copia.erase(0, pos + 1);
 
   // Atributos
   this->dia     = stoi(dia);
   this->mes     = stoi(mes);
   this->anio    = stoi(anio);
   this->hora    = stoi(hora);
   this->minutos = stoi(minutos);
}


FechaYHora::~FechaYHora () {
}


void FechaYHora::setFechaYHora (int dia, int mes, int anio, int hora, int minutos) {
   this->dia     = dia;
   this->mes     = mes;
   this->anio    = anio;
   this->hora    = hora;
   this->minutos = minutos;
}


bool FechaYHora::operator < (const FechaYHora &fh) {

   bool menor = false;
   
   if (this->anio < fh.anio) {
      
      menor = true;
      
   } else if ((this->anio == fh.anio) &&
              (this->mes  <  fh.mes))   {
      
      menor = true;
      
   } else if ((this->anio == fh.anio) &&
              (this->mes  == fh.mes)  &&
              (this->dia  <  fh.dia))   {
      
      menor = true;
      
   } else if ((this->anio == fh.anio) &&
              (this->mes  == fh.mes)  &&
              (this->dia  == fh.dia)  &&
              (this->hora <  fh.hora))  {
      
      menor = true;
      
   } else if ((this->anio    == fh.anio) &&
              (this->mes     == fh.mes)  &&
              (this->dia     == fh.dia)  &&
              (this->hora    == fh.hora) &&
              (this->minutos < fh.minutos)) {
      
      menor = true;
      
   }

   return menor;
}

bool FechaYHora::operator > (const FechaYHora &fh) {
   
   bool mayor = false;

   if (this->anio > fh.anio) {
      
      mayor = true;
      
   } else if ((this->anio == fh.anio) &&
              (this->mes  >  fh.mes))   {
      
      mayor = true;
      
   } else if ((this->anio == fh.anio) &&
              (this->mes  == fh.mes)  &&
              (this->dia  >  fh.dia))   {
      
      mayor = true;
      
   } else if ((this->anio == fh.anio) &&
              (this->mes  == fh.mes)  &&
              (this->dia  == fh.dia)  &&
              (this->hora >  fh.hora))  {
      
      mayor = true;
      
   } else if ((this->anio    == fh.anio) &&
              (this->mes     == fh.mes)  &&
              (this->dia     == fh.dia)  &&
              (this->hora    == fh.hora) &&
              (this->minutos >  fh.minutos)) {
      
      mayor = true;
      
   }

   return mayor;
}

bool FechaYHora::operator == (const FechaYHora &fh) {
   
   bool igual = false;
   
   if ((this->anio    == fh.anio)     &&
       (this->mes     == fh.mes)      &&
       (this->dia     == fh.dia)      &&
       (this->hora    == fh.hora)     &&
       (this->minutos == fh.minutos))    {
      
      igual = true;
   }
   
   return igual;
}


void FechaYHora::mostrar () const {
   cout << this->dia  << "/" << this->mes     << "/" << this->anio << " "
        << this->hora << ":" << this->minutos << endl;
}
