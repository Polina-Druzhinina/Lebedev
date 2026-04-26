#include <iostream>
#include "template.h"
#include <ctime>
using namespace std;
int main(void){
    int N, k = 2;
    cout<<"ENter N: ";
    cin>>N;
    LineList<int> list;
    for(int i = N; i > 0; i--){
        list.insertFirst(i);
    }
    LineListElem<int>* current = list.getStart(); 
    LineListElem<int>* prev = list.getTail();

    clock_t start = clock();
    while (list.size() > 1) {
        for (int i = 1; i < k; i++) {
            prev = current;
            current = current->getNext();
        }
        if (current == list.getStart()) {
            list.deleteFirst();   
        } else {
            list.deleteAfter(prev); 
        }
        current = prev->getNext();
    }

    clock_t end = clock();
    double time = (double)(end - start) / CLOCKS_PER_SEC;
    int answer = list.getStart() -> getData();
    cout<<"Time: "<<time<<" Answer: "<< answer;
    return 0;
}