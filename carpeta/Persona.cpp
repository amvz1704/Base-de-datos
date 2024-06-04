/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Persona.cpp
 * Author: aml
 * 
 * Created on 4 de junio de 2024, 09:32 AM
 */

#include "Persona.h"

Persona::Persona() {
}

Persona::Persona(const Persona& orig) {
}

Persona::~Persona() {
}

void Persona::SetSueldo(double sueldo) {
    this->sueldo = sueldo;
}

double Persona::GetSueldo() const {
    return sueldo;
}

void Persona::SetNombre(char* nombre) {
    this->nombre = nombre;
}

char* Persona::GetNombre() const {
    return nombre;
}

void Persona::SetDni(int dni) {
    this->dni = dni;
}

int Persona::GetDni() const {
    return dni;
}

