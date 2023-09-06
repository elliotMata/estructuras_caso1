#ifndef LISTADOBLE_H
#define LISTADOBLE_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Node
{
public:
    string author;
    string title;
    string description;
    Node *next;
    Node *previous;

    Node(string pAuthor, string pTitle, string pDescription) : author(pAuthor), title(pTitle), description(pDescription), next(nullptr), previous(nullptr) {}
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

    void insertFirst(Node *newNode);                  // insercion al inicio
    void insertLast(Node *newNode);                   // insercion al final
    void insertPosition(Node *newNode, int position); // insercion en la posicion indicada
    void display();                                   // despliegue lista completa
    Node *deleteFirst();                              // elimina el primer nodo
    Node *deleteLast();                               // elimina el ultimo nodo
    Node *deletePosition(int position);               // elimina el nodo en la posicion indicada
    string searchPosition(int position);              // retorna el dato del nodo en la posicion indicada
    vector<int> searchData(string keyword);           // retorna las posiciones de los nodos que contengan el keyword indicado
    bool isEmpty() { return listSize == 0; }          // revisa si la lista esta vacia
    void showListSize() { cout << listSize << std::endl; }
    int getListSize() { return listSize; }
};

#endif