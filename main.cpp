/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: aml
 *
 * Created on 4 de junio de 2024, 08:34 AM
 */

#include <iostream>
#include "Lista.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    class Lista lista;
    lista.crear("datos.txt");
    lista.imprimir("prueba.txt");
    lista.imprimeR("pruebaRec.txt");
    return 0;
}

