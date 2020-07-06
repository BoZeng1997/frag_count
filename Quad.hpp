#include "Node.hpp"
#include <math.h>
#include <vector>
#pragma once
typedef std::pair<double, double> _x_y;
class Quad
{
private:
    unsigned int _id;
    Node * _n1;
    Node * _n2;
    Node * _n3;
    Node * _n4;
    bool _intact;
    double _area;
    double _xc, _yc;
    std::vector<Quad*> _neighbors;
public:
    Quad(unsigned int id, Node * n1, Node * n2,
         Node * n3, Node * n4);
    unsigned int id(){return _id;}
    Node * n1(){return _n1;}
    Node * n2(){return _n2;}
    Node * n3(){return _n3;}
    Node * n4(){return _n4;}
    bool intact(){return _intact;}
    double area(){return _area;}
    double xc(){return _xc;}
    double yc(){return _yc;}
    _x_y centroid();
    std::vector<Quad*> & neighbors(){return _neighbors;}
    bool isneighbor(Quad * q);
    bool sharenode(Node * n);
    double tri2();
    double calarea();
};
