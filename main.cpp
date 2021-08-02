//
//  main.cpp
//  Priority_Queue
//
//  Created by Mark Moreno on 2021-07-23.
//  Copyright © 2021 Mark Moreno. All rights reserved.
//
#include "queue.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;


int main() {
    string line = "enqueue 7 -7";
    string max = "3";
    //int i = 0;
    Queue q;
    //while (getline(cin, line)) {
    
    cout << line << endl;
    
    q.setMax(stoi(max));
    cout<<stoi(max)<<endl;
    
        
    int d, p;
    //stringstream in{line};
    stringstream in;
    in <<line;
    string token;
    getline(in, token,' ');
    in>>d;
    in>>p;
    cout<<d<<"><"<<p<<endl;
    
    Node *n = new Node(d, p);
    //cout<<d<<p<<endl;
    //n->setData(d);
    //n->setPriority(p);
    
    string enq = "e";
    string deq = "d";
    string qu(1, line[0]);
    
    if(!qu.compare(enq)){
        q.enqueue(n);
    }else if(!qu.compare(deq)){
        q.dequeue();
    }
    Node *a = new Node(3, 2);
    Node *b = new Node(4, 2);
    Node *c = new Node(5, 2);
    q.enqueue(a);
    q.enqueue(b);
    q.enqueue(c);
    //q.dequeue();
    
        //i++;
    //}
    q.printQueue();
}