#include <iostream>
#include "newsSeeker.h"

using namespace std;

void NewsSeeker::agregar(string pAuthor, string pTitle, string pDescription)
{
    list.insertLast(new Node(pAuthor, pTitle, pDescription));
}

void NewsSeeker::buscar(string keyword)
{
    if (!list.isEmpty())
    {
        vector<int> newsFound = list.searchData(keyword);
        int limit = 5;
        if (newsFound.size() < limit)
        {
            limit = newsFound.size();
        }
        for (int i = 0; i < limit; i++)
        {
            cout << newsFound.at(i) << ' ' << list.searchPosition(newsFound.at(i)) << endl;
        }
        cout << endl;
    }
    else
    {
        cout << "La lista está vacía" << endl;
    }
}

void NewsSeeker::eliminar(int position)
{
    if (list.isEmpty())
    {
        cout << "La lista está vacía\n"
             << endl;
    }
    else
    {
        if (position < 0 || position > list.getListSize())
        {
            cout << "Ingresó una posición no válida\n"
                 << endl;
        }
        else
        {
            list.deletePosition(position);
        }
    }
}

void NewsSeeker::reordenar(int position, int offset)
{
    if (list.isEmpty())
    {
        cout << "La lista está vacía\n"
             << endl;
    }
    else
    {
        if (position < 0 || position > list.getListSize())
        {
            cout << "Ingresó una posición no válida\n"
                 << endl;
        }
        else
        {
            int newPosition = position - offset;
            if (newPosition < 0 || newPosition >= list.getListSize())
            {
                cout << "Ingresó un offset que movería la posición fuera de los límites de la lista\n"
                     << endl;
            }
            else
            {
                list.insertPosition(list.deletePosition(position), newPosition);
            }
        }
    }
}