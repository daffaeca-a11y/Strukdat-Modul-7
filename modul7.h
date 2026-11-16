#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <iostream>
using namespace std;

const int MAX_STACK = 20;

typedef int infotype;

struct Stack {
    infotype info[MAX_STACK];
    int top;           
};

void createStack(Stack &S);
bool isEmpty(const Stack &S);
bool isFull(const Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(const Stack &S);
void balikStack(Stack &S);
void pushAscending(Stack &S, infotype x);
void getInputStream(Stack &S);

#endif 