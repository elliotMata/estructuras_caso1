#include "doubleList.h"
#include <iostream>

using namespace std;

void DoubleList::insertFirst(Node *newNode)
{
    if (isEmpty())
    {
        first = newNode;
        last = first;
        listSize++;
    }
    else
    {
        first->previous = newNode;
        newNode->next = first;
        first = newNode;
        listSize++;
    }
}

void DoubleList::insertLast(Node *newNode)
{
    if (isEmpty())
    {
        first = newNode;
        last = first;
        listSize++;
    }
    else
    {
        last->next = newNode;
        newNode->previous = last;
        last = newNode;
        listSize++;
    }
}

void DoubleList::insertPosition(Node *newNode, int position)
{
    if (isEmpty())
    {
        first = newNode;
        last = first;
        listSize++;
    }
    else
    {
        if (position == 0)
        {
            first->previous = newNode;
            newNode->next = first;
            first = first->previous;
        }
        else
        {
            if (position > listSize)
            {
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
            cout << temp->title << endl;
            temp = temp->next;
        }
    }
}

Node *DoubleList::deleteFirst()
{
    Node *temp = first;
    Node *result = new Node(first->author, first->title, first->description);
    first = first->next;
    if (first != nullptr)
    {
        first->previous = nullptr;
    }
    listSize--;
    delete temp;
    return result;
}

Node *DoubleList::deleteLast()
{
    Node *temp = last;
    Node *result = new Node(last->author, last->title, last->description);
    last = last->previous;
    if (last != nullptr)
    {
        last->next = nullptr;
    }
    listSize--;
    delete temp;
    return result;
}

Node *DoubleList::deletePosition(int position)
{
    Node *result = nullptr;
    if (position == 0)
    {
        Node *temp = first;
        result = new Node(first->author, first->title, first->description);
        first = first->next;
        first->previous = nullptr;
        listSize--;
        delete temp;
        return result;
    }
    Node *temp = first;
    while (position-- > 0)
    {
        temp = temp->next;
    }
    temp->previous->next = temp->next;
    if (temp->next != nullptr)
    {
        temp->next->previous = temp->previous;
    }
    result = new Node(temp->author, temp->title, temp->description);
    listSize--;
    delete temp;
    return result;
}

string DoubleList::searchPosition(int position)
{
    vector<string> result;
    if (position == 0)
    {
        return first->title;
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
            return temp->title;
        }
        else
        {
            return "Esa posición no existe";
        }
    }
}

vector<int> DoubleList::searchData(string keyword)
{
    vector<int> result;
    int count = 0;
    Node *temp = first;
    while (temp != nullptr)
    {
        if (temp->title.find(keyword) != string::npos)
        {
            result.push_back(count);
        }
        count++;
        temp = temp->next;
    }
    return result;
}