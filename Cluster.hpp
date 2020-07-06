#include "Quad.hpp"
#pragma once
typedef std::pair<double, double> _x_y;
class Cluster
{
public:
    Cluster(size_t num_all_quads);
    //Cluster(){}
    Cluster(std::vector<Quad *> quads);
    void movequadto(size_t i, Cluster * to);
    void moveclusto(Cluster * to);
    size_t num_all_quads(){return _num_all_quads;}
    size_t num_quads(){return _num_quads;}
    std::vector<Quad *> & quads(){return _quads;}
    double area(){return _area;}
    void area_c();
    double xc(){return _xc;}
    double yc(){return _yc;}
    _x_y centroid();
private:
    std::vector<Quad *> _quads;
    size_t _num_all_quads;
    size_t _num_quads;
    double _area;
    double _xc;
    double _yc;
};
