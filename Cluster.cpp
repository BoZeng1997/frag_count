#include "Cluster.hpp"
#include <iostream>
_x_y Cluster::centroid()
{
    _x_y p0(_xc,_yc);
    return p0;
}

Cluster::Cluster(size_t num_all_quad): _num_all_quads(num_all_quad), _num_quads(0)
{
    _quads.resize(_num_all_quads);
    _num_quads=0;
    _area=0;
    std::cout<<"all "<<num_all_quads()<<" , "<<num_quads()<<std::endl;
}

Cluster::Cluster(std::vector<Quad *> q):_quads(q), _num_quads(0)
{
    _num_all_quads=q.size();
    _area=0;
    for(size_t i=0;i<_num_all_quads;i++)
    {
        if(quads()[i]){_num_quads++;}
    }
    std::cout<<"all "<<num_all_quads()<<" , "<<num_quads()<<std::endl;
}

void Cluster::movequadto(size_t i, Cluster * to)
{
    //to->push_back(quads[i]);
    ///std::cout<<"Moving quad "<<quads()[i]->id()<<std::endl;
    to->_quads[i]=quads()[i];
    //quads.erase(quads.begin()+i);
    _quads[i]=NULL;
    if(quads()[i]==NULL){std::cout<<" NULLED ";}
    _num_quads--;
    to->_num_quads++;
    ///std::cout<<"current "<<num_quads()<<" broken "<<to->num_quads()<<std::endl;
    std::cout<<"Moved quad "<<to->quads()[i]->id()<<std::endl;
    ///        " to Cluster "<<std::endl;
}
void Cluster::moveclusto(Cluster * to)
{
    for (size_t i=0;i<num_all_quads();i++)
    {
        if(quads()[i]!=NULL)
        {
            movequadto(i, to);
        }
    }
}

void Cluster::area_c()
{
    double x_numerator=0;
    double y_numerator=0;
    for (size_t i=0;i<num_all_quads();i++)
    {
        if(quads()[i]!=NULL)
        {
        _area+=quads()[i]->area();
        x_numerator+=quads()[i]->area()*quads()[i]->xc();
        y_numerator+=quads()[i]->area()*quads()[i]->yc();
        }
    }
    _xc=x_numerator/_area;
    _yc=y_numerator/_area;
    std::cout<<"area "<<_area<<" centroid ( "<<_xc<<" , "<<_yc<<" )"<<std::endl;
}
