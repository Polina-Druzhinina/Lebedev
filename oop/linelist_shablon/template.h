#pragma once
#include <ostream>
#include <iostream>
using namespace std;
class LineListException {};
template <class T> 
class LineListElem {
    T data;        
    LineListElem* next;     
public:
    LineListElem(const T& adata, LineListElem* anext);
    const T& getData() const;
    LineListElem* getNext();
    template <class U> friend class LineList;
};

template <class T> 
class LineList {
    LineListElem<T>* start;   
    LineListElem<T>* tail;        //Указатель на последний элемент
    LineList(const LineList& list); 
    int len;      // Добавила размер списка

public:
    LineList();              
    ~LineList();              
    int size();           // Добавила метод, чтобы знать размер списка в main
    LineListElem<T>* getStart(); 
    LineListElem<T>* getTail();   //возвращает конец 
    void deleteFirst();
    void deleteAfter(LineListElem<T>* ptr);                
    void insertFirst(const T& data);                       
    void insertAfter(LineListElem<T>* ptr, const T& data); 
    template <class U> friend ostream& operator<<(ostream& out, LineList<U>& list);
};

template <class T> 
LineListElem<T>::LineListElem(const T& adata, LineListElem* anext) {
    data = adata;
    next = anext;
}

template<class T> 
LineListElem<T>* LineListElem<T>::getNext() {
    return next;
}

template<class T> 
const T& LineListElem<T>::getData() const {
    return data;
}

template<class T> 
int LineList<T>::size() {
    return len;
}

template<class T> 
LineList<T>::LineList() {
    start = nullptr;
    tail = nullptr; 
    len = 0;
}

template<class T> 
LineList<T>::~LineList() {
    while(start) {
        deleteFirst();
    }
}

template<class T> 
LineListElem<T>* LineList<T>::getStart() {
    return start;
}

template<class T> 
LineListElem<T>* LineList<T>::getTail() {
    return tail;
}

template<class T> 
void LineList<T>::deleteFirst() {
    if(start == nullptr) {
        throw LineListException();
    }
    LineListElem<T>* toDelete = start;
    if(start->next == start) {
        start = nullptr;
        tail = nullptr;  
    } 
    else {
        start = start->next;      
        tail->next = start; //Указывает на новый start, делает циклическим
    }
    delete toDelete;
    len--;
}

template<class T> 
void LineList<T>::deleteAfter(LineListElem<T>* ptr) {
    LineListElem<T>* temp = ptr->next;  
    ptr->next = temp->next;             
    if(temp == start) {
        start = ptr->next;
    }
    if(temp == tail) {
        tail = ptr;
    }
    delete temp;
    len--;
}

template<class T> 
void LineList<T>::insertFirst(const T& data) {
    LineListElem<T>* newElem = new LineListElem<T>(data, start);
    if(start == nullptr) {
        start = newElem;
        tail = newElem;
        tail->next = start;  
    } else {
        start = newElem;
        tail->next = start;
    }
    len++;
}

template<class T> 
void LineList<T>::insertAfter(LineListElem<T>* ptr, const T& data) {
    if(ptr == nullptr) {
        throw LineListException();
    }
    ptr->next = new LineListElem<T>(data, ptr->next);
    if(ptr == tail) {
        tail = ptr->next;
    }
    len++;
}

template <class T>
ostream& operator<<(ostream& out, LineList<T>& list) {
    if(!list.start) {
        out << "EMPTY";
        return out;
    }
    LineListElem<T>* temp = list.start;
    do {
        out << temp->getData() << " ";
        temp = temp->getNext();
    } while(temp != list.start);
    return out;
}