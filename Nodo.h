/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Nodo.h
 * Author: aml
 *
 * Created on 4 de junio de 2024, 08:34 AM
 */

#ifndef NODO_H
#define NODO_H
#include "Lista.h"
class Nodo {
public:
    Nodo();
    friend class Lista;
private:
    class Nodo *siguiente;
    int dato;
};

#endif /* NODO_H */

