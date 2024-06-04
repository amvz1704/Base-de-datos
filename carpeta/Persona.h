/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Persona.h
 * Author: aml
 *
 * Created on 4 de junio de 2024, 09:32 AM
 */

#ifndef PERSONA_H
#define PERSONA_H

class Persona {
public:
    Persona();
    Persona(const Persona& orig);
    virtual ~Persona();
    void SetSueldo(double sueldo);
    double GetSueldo() const;
    void SetNombre(char* nombre);
    char* GetNombre() const;
    void SetDni(int dni);
    int GetDni() const;
private:
    int dni;
    char *nombre;
    double sueldo;
};

#endif /* PERSONA_H */

