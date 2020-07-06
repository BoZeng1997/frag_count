#include "Quad.hpp"
#include <cmath>
#include <iostream>

_x_y  Quad::centroid()
{
    _x_y p0(_xc,_yc);
    return p0;
}
double magnitude(_x_y v1){
  return sqrt(v1.first*v1.first+v1.second*v1.second);
}

_x_y makev(_x_y v1,_x_y v2){
  return _x_y(v2.first-v1.first,v2.second-v1.second);
}
double Quad::tri2()
{
    double _tri2=0;
    _x_y p1(_n1->x(),_n1->y());
    _x_y q1(_n2->x(),_n2->y());
    _x_y p2(_n3->x(),_n3->y());
    _x_y q2(_n4->x(),_n4->y());

    _x_y v1=makev(p1,p2);
    _x_y v2=makev(p1,q1);
    _x_y v3=makev(p1,q2);
    _x_y v4=makev(q1,q2);
    _x_y v5=makev(q1,p1);
    _x_y v6=makev(q1,p2);
    double d1=v1.first*v2.second-v1.second*v2.first;
    double d2=v1.first*v3.second-v1.second*v3.first;
    double d3=v4.first*v5.second-v4.second*v5.first;
    double d4=v4.first*v6.second-v4.second*v6.first;
    if((d1*d2)<0&&(d3*d4)<0)
    {
        _tri2=std::abs(0.5 * (_n1->x() * (_n4->y() - _n3->y())
                    + _n4->x() * (_n3->y() - _n1->y())
                    + _n3->x() * (_n1->y() - _n4->y())));
    }
    else
    {
        _tri2=std::abs(0.5 * (_n1->x() * (_n2->y() - _n4->y())
                        + _n2->x() * (_n4->y() - _n1->y())
                        + _n4->x() * (_n1->y() - _n2->y())));
    }
    return _tri2;
}
double Quad::calarea()
{
    double _tri1 = std::abs(0.5 * (_n1->x() * (_n2->y() - _n3->y())
                            + _n2->x() * (_n3->y() - _n1->y())
                            + _n3->x() * (_n1->y() - _n2->y())));
    double _tri2=tri2();
    return _tri1+_tri2;
}
Quad::Quad(unsigned int id, Node * n1, Node * n2,
    Node * n3, Node * n4)
    : _id(id), _n1(n1), _n2(n2), _n3(n3), _n4(n4)
{
    _area=calarea();
    double _cutoff=0.6;
    if(_n1->d() > _cutoff || _n2->d() > _cutoff ||
        _n3->d() > _cutoff|| _n4->d() > _cutoff)
    {
        _intact=false;//broken
        std::cout<<"broken ";
    }
    else{_intact=true;}
    _xc=(n1->x()+n2->x()+n3->x()+n4->x())/4;
    _yc=(n1->y()+n2->y()+n3->y()+n4->y())/4;

}

bool Quad::isneighbor(Quad * q)
{
    if((sharenode(q->n1())&&sharenode(q->n2()))||
       (sharenode(q->n1())&&sharenode(q->n3()))||
       (sharenode(q->n1())&&sharenode(q->n4()))||
       (sharenode(q->n2())&&sharenode(q->n3()))||
       (sharenode(q->n2())&&sharenode(q->n4()))||
       (sharenode(q->n3())&&sharenode(q->n4()))
       )
    {
        return true;
    }
    else{return false;}
}

bool Quad::sharenode(Node * n)
{
    if(_n1==n||_n2==n||_n3==n||_n4==n)
    {
        return true;
    }
    //if(n1()==n||n2()==n||n3()==n)
    else{return false;}
}
