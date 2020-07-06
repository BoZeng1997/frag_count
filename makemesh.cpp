#include "Quad.hpp"
#include <iostream>
#pragma once
void makemesh(std::vector<Node *> & nodelist,
              std::vector<Quad *> & quadlist)
{
        for (unsigned int i=0;i<25;i++){
        double x=i%5;
        double y = i/5;
        double d;
        if(i==7||i==11||i==12){d=0.7;}
        else{d = 0.5;}
        unsigned int id =i+1;
        Node * anode = new Node(id, x, y, d);
            nodelist.push_back(anode);
        std::cout<<"Node "<<nodelist.back()->id()<<
                " ("<<nodelist.back()->x()<<","<<nodelist.back()->y()<<
                ") damage is "<<nodelist.back()->d()<<std::endl;
    }

        unsigned int j=0;
    for (unsigned int i=0;i<16;i++){
        if(i==4||i==8||i==12){
            ++j;
            //continue;
        }
        unsigned int id =i+1;
        Node * n1=nodelist[i+j];
        Node * n2=nodelist[i+j+1];
        Node * n3=nodelist[i+j+5];
        Node * n4=nodelist[i+j+6];
        Quad * aquad = new Quad(id, n1, n2, n3, n4);
        quadlist.push_back(aquad);
        std::cout<<"Quad "<<quadlist.back()->id()<<
                " ["<<quadlist.back()->n1()->id()<<","<<
                quadlist.back()->n2()->id()<<","<<
                quadlist.back()->n3()->id()<<","<<
                quadlist.back()->n4()->id()<<"]"<<std::endl;
    }
}
