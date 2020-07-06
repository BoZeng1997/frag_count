#include <iostream>
#include <fstream>
#include <limits>
#include <cstdlib>
#include "Cluster.hpp"
#include "makemesh.hpp"
#include "declassifybroken.hpp"
#include "reclassify.hpp"
#include "classifybroken.hpp"


int main()
{
    std::vector<Node *> nodelist;

    std::vector<Quad *> quadlist;
    makemesh(nodelist,quadlist);
    //for(size_t c=1;c<17;c++)
    //{
    //    std::cout<<"qaud "<<c<<" has "<<quadlist[c-1]->neighbors().size()<<" neighbors"<<std::endl;
    //}

    Cluster _all=Cluster(quadlist.size());
    Cluster _broken=Cluster(quadlist.size());
    //Cluster _candi=Cluster(quadlist.size());
    std::list<size_t> _candi;

    Cluster * acluster=new Cluster(quadlist);
    std::vector<Cluster *> clusterlist;
    clusterlist.push_back(acluster);
    //std::cout<<clusterlist[0]->quads()[0]->id()<<std::endl;

    declassifybroken(clusterlist, _broken, _all);


    //while(_all.num_quads()!=0)
    //{
        reclassify(_all, _candi, _broken,clusterlist);
        std::cout<<"obtained "<<clusterlist.size()<<" fragments"<<std::endl;
    //}
    classifybroken(_broken,clusterlist);

/*
    ifstream fin;
    fin.open("input.txt");
    int score;
    for (int i=0;i<5;i++){
        fin>>score;
        cout<<"the score is"<<score<<endl;
    }
double dist = std::numeric_limits<double>::max();
    cout<<dist<<endl;
    cout << "Hello world!" << endl;

    for(unsigned i=0;i<16;i++){
        free (nodelist[i]);
    }
    for(unsigned i=0;i<9;i++){
        free (quadlist[i]);
    }
    */
    //free(acluster);
    //free(_broken);
    return 0;
}
