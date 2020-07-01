void gen_solution(int node){
    bool end[100];
    roadmap ro;
    r.clear();
    for(int i=0;i<node;i++){
        end[i]=true;
        ro.dst=0;
        ro.path.clear();
        ro.path.push_back(source);
        ro.sta=source;
        ro.en=dest;
        r.push_back(ro);
    }
    int it=1;
    while(it){
        for(int i=0;i<node;i++){
            //while(r[i].sta!=r[i].en){
            if(end[i]){
            int l=edge[r[i].sta].size();
            double div_fact=0.0;

            //Transition probability rule
            for(int j=0;j<l;j++){
                if(find(r[i].path.begin(),r[i].path.end(),edge[r[i].sta][j])==r[i].path.end()){
                double a=pow(pheromone[r[i].sta][j],alpha);
                double b=pow((1.0/cost[r[i].sta][j]),beta);
                double c=a*b;
                //cout<<a<<" "<<b<<" "<<c<<endl;
                div_fact=div_fact+c;
                }
                //div_fact=div_fact+(pow(pheromone[r[i].sta][j],alpha)* pow((1.0/cost[r[i].sta][j]),beta));
            }
            double min=0.0;
            int res_node,res_dist;
            for(int j=0;j<l;j++){
                 if(find(r[i].path.begin(),r[i].path.end(),edge[r[i].sta][j])==r[i].path.end()){
                 double a=pow(pheromone[r[i].sta][j],alpha);
                double b=pow((1.0/cost[r[i].sta][j]),beta);
                double c=a*b;
                c=c/div_fact;
                double temp=c+(rand()%9);
                //double temp=((double)(pow(pheromone[r[i].sta][j],alpha)* pow((1.0/cost[r[i].sta][j]),beta))/div_fact)+((double)(rand()%9));
                if(temp>min){
                    min=temp;
                    res_node=edge[r[i].sta][j];
                    res_dist=cost[r[i].sta][j];
                }
                }
                //end of transition probability
            }
            r[i].dst=r[i].dst+res_dist;
            r[i].sta=res_node;
            r[i].path.push_back(res_node);
            if(r[i].sta==r[i].en)
            end[i]=false;
            }
        }
            int j;
            for(j=0;j<node;j++){
                if(end[j])
                break;
            }
            if(j==node)
            it=0;
    }
}
