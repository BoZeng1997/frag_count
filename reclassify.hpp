#include <list>
void doneighbor(size_t i,Cluster & _all, std::list<size_t> &_candi,Cluster & _broken);
void reclassify(Cluster & _all, std::list<size_t>& _candi,Cluster & _broken,
                std::vector<Cluster *> & clusterlist)
{
    std::cout<<"_all has "<<_all.num_quads()<<std::endl;
    for(size_t i=0;i<_all.num_all_quads();i++)
    {
        while(!_candi.empty())
        {
            //std::cout<<"qaud 8"<<" has "<<_all.quads()[7]->neighbors().size()<<" neighbors"<<std::endl;
            std::cout<<"_all has "<<_all.num_quads()<<std::endl;
            doneighbor(_candi.front(),_all, _candi,_broken);
            std::cout<<"no neighbor left ";
            _all.movequadto(_candi.front(),clusterlist.back());
            std::cout<<"candi remove "<<_candi.front()+1<<" as front"<<std::endl;
            _candi.pop_front();
        }
        if(_all.quads()[i]!=NULL)
        {
            Cluster * acluster=new Cluster(_all.num_all_quads());
            clusterlist.push_back(acluster);
            _candi.push_back(i);
            std::cout<<"candi added "<<i+1<<" as end"<<std::endl;
            ///.movequadto(i,& _candi);
            ///while(_all.num_quads()!=0)
            ///{
            std::cout<<"_all has "<<_all.num_quads()<<std::endl;
            doneighbor(_candi.front(),_all, _candi,_broken);
            std::cout<<"no neighbor left ";
            _all.movequadto(_candi.front(),clusterlist.back());
            std::cout<<"candi remove "<<_candi.front()+1<<" as front"<<std::endl;
            _candi.pop_front();
            ///}
        }
    }
}

void doneighbor(size_t i,Cluster & _all, std::list<size_t> &_candi,Cluster & _broken)
{std::cout<<i<<" ";
std::cout<<_all.quads()[i]->neighbors().size()<<" neighbors"<<std::endl;
    for(size_t k=0;k<_all.quads()[i]->neighbors().size();k++)
    {
        if(_all.quads()[i]->neighbors()[k]->intact()
           &&(_all.quads()[_all.quads()[i]->neighbors()[k]->id()-1]!=NULL))
        {
            ///unsigned int neigid=
            ///_candi.quads()[i]->neighbors()[k]->id();
            ///_all.movequadto(neigid,& _candi);
            _candi.push_back(_all.quads()[i]->neighbors()[k]->id()-1);
            std::cout<<"candi added "<<_candi.back()+1<<" as end"<<std::endl;
        }
    //candi.quads()[i].neighbors()
    /*
        else
        {std::cout<<"broken ";
        unsigned int neigid=
        _candi.quads()[i]->neighbors()[k]->id();
        _all.movequadto(neigid,& _broken);
        }
        */

    }
}
