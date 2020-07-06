
void declassifybroken(std::vector<Cluster *> &clusterlist,
                      Cluster & _broken,Cluster & _all)
{
    bool changed=false;
    for(size_t i=0;i<clusterlist.size();i++)
    {
        for(size_t k=0;k<clusterlist[i]->num_all_quads();k++)
        {
            if(clusterlist[i]->num_quads()==0){continue;}
            if(!(clusterlist[i]->quads()[k]->intact()))
            {
                std::cout<<"broken ";
                clusterlist[i]->movequadto(k, & _broken);
                changed=true;
            }
        }
        if(changed)
        {
            std::cout<<"rest into _all ";
            clusterlist[i]->moveclusto(& _all);
            free(clusterlist[i]);
            clusterlist.erase(clusterlist.begin()+i);
            std::cout<<"clusterlist size "<<clusterlist.size()<<std::endl;
        }
    }

}
