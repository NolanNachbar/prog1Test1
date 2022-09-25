#ifndef MYLIST_
#define MYLIST_
#include "node.h"


template <class T>
class myList
{
    private:
    node<T> * head;
    int size;

    public:
        myList()
        {
            head = nullptr; 
            size = 0;
        }
        ~myList()
        {
            while(!isEmpty())
            {
                remove();
            }
        }
        void insert(T item);
        void remove();
        T front();
        T frontMod();
        //void print();
        bool find(T item);
        bool isEmpty()
        {
            
            return size == 0;
        }
        int getSize()
        {
            return size;
        }
};
template <class T>
void myList<T>::insert(T item)
{
    node<T> * tmp = new node<T>(item);
    tmp->next=head;
    head = tmp;

    size++;
};

template <class T>
void myList<T>::remove()
{
    node<T> * tmp;
    if(head != nullptr)
    {
        tmp = head;
        head = head -> next;
     size--;
    }
};

template <class T>
bool myList<T>:: find (T item)
{
    node<T> * tmp;
    std::string stringTemp;

    tmp = head;
    int compares;
    while(tmp != nullptr)
    {
        stringTemp = tmp->data;

        int compareVal = stringTemp.compare(item);

        if(compareVal == 0)
        {
            return true;
        }

        tmp = tmp ->next;
    }

    return false;
    
    
}

template <class T>
T myList<T>::front()
{
    if(head != nullptr)
    {
        return head -> data;
    }
    else
    {
        return T(0);
    }
}

template <class T>
T myList<T>::frontMod()
{
    std::string returnVal;
    if(head != nullptr)
    {
        returnVal = head -> data;
        head = head -> next;
        return returnVal;
    }
    return T(0);
}
#endif
