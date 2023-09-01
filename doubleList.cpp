#include "doubleList.h"
#include <iostream>

using namespace std;

void DoubleList::insertFirst(string data)
{
    if (isEmpty())
    {
        first = new Node(data);
        last = first;
        listSize++;
    }
    else
    {
        Node *newNode = new Node(data);
        first->previous = newNode;
        newNode->next = first;
        first = newNode;
        listSize++;
    }
}

void DoubleList::insertLast(string data)
{
    if (isEmpty())
    {
        first = new Node(data);
        last = first;
        listSize++;
    }
    else
    {
        Node *newNode = new Node(data);
        last->next = newNode;
        newNode->previous = last;
        last = newNode;
        listSize++;
    }
}

void DoubleList::insertPosition(string data, int position)
{
    if (isEmpty())
    {
        first = new Node(data);
        last = first;
        listSize++;
    }
    else
    {
        if (position == 0)
        {
            Node *newNode = new Node(data);
            first->previous = newNode;
            newNode->next = first;
            first = first->previous;
        }
        else
        {
            if (position > listSize)
            {
                Node *newNode = new Node(data);
                last->next = newNode;
                newNode->previous = last;
                last = newNode;
                listSize++;
            }
            else
            {
                Node *temp = first;
                while (position-- > 0)
                {
                    temp = temp->next;
                }
                Node *temp2 = temp->previous;
                Node *newNode = new Node(data);
                temp2->next = newNode;
                newNode->previous = temp2;
                newNode->next = temp;
                temp->previous = newNode;
                listSize++;
            }
        }
    }
}

void DoubleList::display()
{
    if (isEmpty())
    {
        cout << "Lista vacía" << endl;
    }
    else
    {
        Node *temp = first;
        while (temp != nullptr)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
}

void DoubleList::deleteFirst()
{
    if (!isEmpty())
    {
        Node *temp = first;
        first = first->next;
        if (first != nullptr)
        {
            first->previous = nullptr;
        }
        listSize--;
        delete temp;
    }
}

void DoubleList::deleteLast()
{
    if (!isEmpty())
    {
        Node *temp = last;
        last = last->previous;
        if (last != nullptr)
        {
            last->next = nullptr;
        }
        listSize--;
        delete temp;
    }
}

void DoubleList::deletePosition(int position)
{
    if (!isEmpty())
    {
        if (position == 0)
        {
            Node *temp = first;
            first = first->next;
            first->previous = nullptr;
            listSize--;
            delete temp;
        }
        else
        {
            Node *temp = first;
            while (temp != nullptr && position-- > 0)
            {
                temp = temp->next;
            }
            if (temp == nullptr)
            {
                return;
            }
            temp->previous->next = temp->next;
            if (temp->next != nullptr)
            {
                temp->next->previous = temp->previous;
            }
            listSize--;
            delete temp;
        }
    }
}

string DoubleList::searchPosition(int position)
{
    if (!isEmpty())
    {
        if (position == 0)
        {
            return first->data;
        }
        else
        {
            if (position < listSize)
            {
                Node *temp = first;
                while (position-- > 0)
                {
                    temp = temp->next;
                }
                return temp->data;
            }
            else
            {
                return "Esa posición no existe";
            }
        }
    }
}

vector<int> DoubleList::searchData(string keyword)
{
    if (!isEmpty())
    {
        vector<int> result;
        int count = 0;
        Node *temp = first;
        while (temp != nullptr)
        {
            if (temp->data.find(keyword) != string::npos)
            {
                result.push_back(count);
            }
            count++;
            temp = temp->next;
        }
        return result;
    }
}