#include "limits.h"
#include "float.h"
double distance(_x_y p1, _x_y p2)
{
    return sqrt((p1.first-p2.first)*(p1.first-p2.first)+
                (p1.second-p2.second)*(p1.second-p2.second));
}
std::pair<size_t,double> mindist(std::pair<size_t,double> d0, std::pair<size_t,double> d1)
{
    if(d0.second<d1.second){return d0;}
    else{return d1;}
}
void classifybroken(Cluster & _broken,
                std::vector<Cluster *> & clusterlist)
{
    for (size_t i=0;i<clusterlist.size();i++)
    {
        clusterlist[i]->area_c();
        /*
    for(std::vector<Quad *>::iterator it=clusterlist[i]->quads().begin();
        it!=clusterlist[i]->quads().end();++it)
    {
        if((*it)!=NULL)
        {
        std::cout<<"quad "<<(*it)->id()<<
        " area of "<<(*it)->area()<<std::endl;
        }

    }
*/
    }
    for(size_t k=0;k<_broken.num_all_quads();k++)
    {
        if(_broken.quads()[k]!=NULL)
        {
            std::pair<size_t,double> dist0(UINT_MAX,DBL_MAX);
            for(size_t i=0;i<clusterlist.size();i++)
            {
                std::pair<size_t,double> dist1(i,distance(
                        _broken.quads()[k]->centroid(),clusterlist[i]->centroid()));
                dist0=mindist(dist0,dist1);
            }
            std::cout<<"to cluster "<<dist0.first;
            _broken.movequadto(k,clusterlist[dist0.first]);
        }
    }
}
