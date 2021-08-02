//
//  queue.cpp
//  interview
//
//  Created by Mark Moreno on 2021-08-01.
//  Copyright © 2021 Mark Moreno. All rights reserved.
//

#include "queue.h"

#include <iostream>
#include <string>
#include <sstream>
using namespace std;


Node::Node(){
    next = NULL;
    prev = NULL;
}
Node::Node(int d, int p){
    priority = p;
    data = d;
    next = NULL;
    prev = NULL;
}
void Node::setNext(Node* n){
    next = n;
}
void Node::setPrev(Node* n){
    prev = n;
}
Node* Node::getNext(){
    return next;
}
int Node::getPriority(){
    return priority;
}
int Node::getData(){
    return data;
}
void Node::setPriority(int p){
    priority = p;
}
void Node::setData(int d){
    data = d;
}
    

Queue::Queue(){
    size = 0;
    head = NULL;
    tail = NULL;
}
Queue::Queue(int m){
    max = m;
    size = 0;
    head = NULL;
    tail = NULL;
}
void Queue::setMax(int m){
    max = m;
}
void Queue::enqueue(Node* n){
    //cout<<"HEre"<<endl;
    if(head==NULL&&tail==NULL){
        head =n;
        tail =n;
        n->setNext(NULL);
        size++;
        cout<<"HEre"<<endl;
        
    }else if(tail->getPriority()>n->getPriority()){
        if(size<max){
            tail->setNext(n);
            tail = n;
            size++;
        }
        
    }else{
        bool inserted = false;
        Node* tempNode = head;
        Node* tempPrevNode = NULL;
        while(tempNode!=NULL){
            
            if(tempNode->getPriority()>=n->getPriority()||inserted==true){
                cout<<"hhh666"<<endl;
                tempPrevNode = tempNode;
                tempNode=tempNode->getNext();
                
            }else if(tempNode->getPriority()<n->getPriority()){
                cout<<"hhzzzzre"<<endl;
                
                //->[tPN]->[n]->
                if(tempPrevNode!=NULL)tempPrevNode->setNext(n);//if tempPrevNode = Null then tempNode = head
                else head = n;
                
                //->[tPN]->[n]->[tN]->
                n->setNext(tempNode);
                
                size++;
                if(size<=max)break;  //check if queue is full
                inserted =true;
                tempPrevNode = tempNode;
                tempNode=tempNode->getNext();
                
            }
            if(tempNode==tail&&size>max){  //removes last element if queue is full
                cout<<"hhhhere"<<endl;
                tail = tempPrevNode;
                tempNode = NULL;
                tail->setNext(NULL);
                size--;
            }
        }
    }
    
}
void Queue::dequeue(){
    Node* tempNode = head;
    head = tempNode->getNext();
    tempNode = NULL;
    size--;
}
void Queue::printQueue(){
    Node* tempNode = head;
    
    while(tempNode!=NULL){
        cout<<tempNode->getData()<<" "<<tempNode->getPriority()<<endl;
        tempNode=tempNode->getNext();
    }
}
