//
//  queue.h
//  interview
//
//  Created by Mark Moreno on 2021-08-01.
//  Copyright © 2021 Mark Moreno. All rights reserved.
//

#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Node{
private:
    Node* next;
    Node* prev;
    int priority;
    int data;
    
public:
    Node();
    Node(int d, int p);
    void setNext(Node* n);
    void setPrev(Node* n);
    Node* getNext();
    int getPriority();
    int getData();
    void setPriority(int p);
    void setData(int d);
    
};
class Queue{
private:
    Node* head;
    Node* tail;
    int max;
    int size;
    
public:
    Queue();
    Queue(int m);
    void setMax(int m);
    void enqueue(Node* n);
    void dequeue();
    void printQueue();
};
#endif /* queue_hpp */