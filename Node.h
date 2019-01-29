//
// Created by Olcayto Turker on 12/12/2018.
//

#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

class Node{
public:

    int X;
    int Y;
   // int height;
    int distTo;
   // bool visited;

//    Node(int x,int y, int height){
//
//        this->X=x;
//        this->Y=y;
//        this->height=height;
//        this->visited=false;
//        this->distTo=0;
//
//    }

    Node(int x,int y, int distTo){

        this->X=x;
        this->Y=y;
        this->distTo=distTo;

    }

    struct compareNode {

        bool operator()(Node *e1, Node *e2) {

          return e1->distTo>e2->distTo;


        }

    };

};

#endif
