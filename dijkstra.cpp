void dijkstra(int src){  //O(E*log(V)) -> for shortest path with given cost

    priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq; //min acc to wt
    pq.push({0,src});
    dis[src]=0;
    
    while(!pq.empty()){
        pair<int,int> tp = pq.top();
        pq.pop();
        int W = tp.first;   //min cost wise sorted
        int V = tp.second;
        if(vis[V]==true)  continue;
        vis[V] = true;              //explored

        for(int i=0;i<gra[V].size();i++){
            pair<int,int> pr = gra[V][i];
            int u = pr.first;        //child node
            int w = pr.second;       //cost
            // cout<<w<<" "<<u<<endl;
            if(dis[u]>W+w){    //update possible(try to minimize)
                dis[u]= W+w;
                pq.push({W+w,u});
            }
        }
    }
    
}
