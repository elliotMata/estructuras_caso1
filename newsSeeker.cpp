#include <iostream>
#include "newsSeeker.h"

using namespace std;

void NewsSeeker::agregar(string data)
{
    list.insertLast(data);
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
    }
    else
    {
        cout << "La lista está vacía" << endl;
    }
}

void NewsSeeker::eliminar(int position)
{
    if (!list.isEmpty())
    {
        list.deletePosition(position);
    }
    else
    {
        cout << "La lista está vacía" << endl;
    }
}

void NewsSeeker::reordenar(int position, int offset)
{
    if (!list.isEmpty())
    {
        int newPosition = position - offset;
        string temp = list.searchPosition(position);
        list.deletePosition(position);
        list.insertPosition(temp, newPosition);
    }
    else
    {
        cout << "La lista está vacía" << endl;
    }
}