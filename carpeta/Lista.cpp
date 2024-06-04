/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Lista.cpp
 * Author: aml
 * 
 * Created on 4 de junio de 2024, 08:35 AM
 */

#include "Lista.h"
#include "Persona.h"
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

Lista::Lista() {
    lista = nullptr;
}

Lista::~Lista() {
    elimina();
}

void Lista::crear(const char *nombArch){
    ifstream arch(nombArch, ios::in);
    if(not arch.is_open()){
        cout << "error "<<nombArch << endl;
        exit(1);
    }
    class Persona dato;
    while(true){
        arch >> dato; //sobrecargar
        if(arch.eof())break;
        insertar(dato);
    }
}

void Lista::insertar(const class Persona &dato){
    class Nodo *p = lista, *anterior = nullptr, *nuevo;
    nuevo = new class Nodo;
    nuevo->dato = dato; //sobrecargar
    while(p){
        if(p->dato > dato)break; //sobrecargar
        anterior = p;
        p = p->siguiente;
    }
    nuevo->siguiente = p;
    if(anterior != nullptr) anterior->siguiente = nuevo;
    else lista = nuevo;
}

void Lista::imprimir(const char *nombArch){
    ofstream arch(nombArch, ios::out);
        if(not arch.is_open()){
            cout << "error "<<nombArch << endl;
            exit(1);
    }
    class Nodo *p = lista;
    arch << "Datos de la lista" << endl;
    while(p){
        arch << p->dato;//sobrecargar
        p = p->siguiente;
    }
    arch << endl;
}

void Lista::elimina(){
    class Nodo *sale;
    while(lista){
        sale = lista;
        lista = lista->siguiente;
        delete sale;
    }
    lista = nullptr;
}

void Lista::imprimeR(const char *nombArch){
    ofstream arch(nombArch, ios::out);
        if(not arch.is_open()){
            cout << "error "<<nombArch << endl;
            exit(1);
    }
    imprimeRecursivo(arch, lista);
}

void Lista::imprimeRecursivo(ofstream &arch, class Nodo *p){
    if(p == nullptr)return;
    imprimeRecursivo(arch, p->siguiente);
    arch << p->dato;
}