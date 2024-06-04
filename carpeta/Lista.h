/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Lista.h
 * Author: aml
 *
 * Created on 4 de junio de 2024, 08:35 AM
 */

#ifndef LISTA_H
#define LISTA_H
#include "Nodo.h"
#include "Persona.h"
#include <fstream>
using namespace std;
class Lista {
public:
    Lista();
    virtual ~Lista();
    void crear(const char *nombArch);
    void insertar(const class Persona &dato);
    void imprimir(const char *nombArch);
    void elimina();
    void imprimeR(const char *nombArch);
private:
    void imprimeRecursivo(ofstream &arch, class Nodo *p);
    class Nodo *lista;
};

#endif /* LISTA_H */

