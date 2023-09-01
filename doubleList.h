#ifndef LISTADOBLE_H
#define LISTADOBLE_H

#include <string>
#include <vector>

using namespace std;

class Node
{
public:
    string data;
    Node *next;
    Node *previous;

    Node(string pData) : data(pData), next(nullptr), previous(nullptr) {}
};

class DoubleList
{
private:
    Node *first;
    Node *last;
    int listSize;

public:
    DoubleList() : first(nullptr), last(nullptr), listSize(0) {}
    ~DoubleList()
    {
        while (first != nullptr)
        {
            Node *temp = first;
            first = first->next;
            delete temp;
        }
    }

    void insertFirst(string data);                  // insercion al inicio
    void insertLast(string data);                   // insercion al final
    void insertPosition(string data, int position); // insercion en la posicion indicada
    void display();                                 // despliegue lista completa
    void deleteFirst();                             // elimina el primer nodo
    void deleteLast();                              // elimina el ultimo nodo
    void deletePosition(int position);              // elimina el nodo en la posicion indicada
    string searchPosition(int position);            // retorna el dato del nodo en la posicion indicada
    vector<int> searchData(string keyword);         // retorna las posiciones de los nodos que contengan el keyword indicado
    bool isEmpty() { return listSize == 0; }        // revisa si la lista esta vacia
};

#endif