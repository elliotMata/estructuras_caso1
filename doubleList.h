#ifndef LISTADOBLE_H
#define LISTADOBLE_H

#include <string>

using namespace std;

class Node {
    public:
        string data;
        Node* next;
        Node* previous;

        Node(int value);
};

class DoubleList {
    private:
        Node* first;
        Node* last;

    public:
        DoubleList() {first=nullptr;last=nullptr;}
        ~DoubleList();

        void insertFirst(string data); //insercion al inicio
        void insertLast(string data); //insercion al final
        void insertPosition(string data, int position); //insercion en la posicion indicada
        void display(); //despliegue lista completa
        void deleteFirst(); //elimina el primer nodo
        void deleteLast(); //elimina el ultimo nodo
        void deletePosition(int position); //elimina el nodo en la posicion indicada
        int searchPosition(int position); //retorna el dato del nodo en la posicion indicada
        int searchData(string data); //retorna la posicion del nodo con el dato indicado
        bool isEmpty() {return first==nullptr;} //revisa si la lista esta vacia
        int[] topFive(string keyword); //retorna un array con las posiciones de los 5 nodos con mayor prioridad (aka posicion)
};

#endif