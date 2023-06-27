#include<bits/stdc++.h>
using namespace std;

vector<string> shortestPath(int n, int m, vector<string>cities, vector<pair<int,pair<string,string>>>& edges) {
        //mapping each city to a 1-based index
        map<string,int>map_city;
        int k=1;
        for(auto it: cities){
            map_city[it] = k;
            k++;
        }

        vector<pair<int,int>> adj[n+1];
        
        for(auto it:edges){
            int dist=it.first;
            string city1=it.second.first;
            string city2=it.second.second;
            adj[map_city[city1]].push_back({map_city[city2], dist});
            adj[map_city[city2]].push_back({map_city[city1], dist});
        }
        
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        
        vector<int>dist(n+1,1e9);
        //source node
        dist[1]=0;
        pq.push({0,1});

        vector<int> path;
        path.push_back(1);
        vector<int>vis(n+1,0);
        vis[1]=1;
        
        while(!pq.empty()){
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();
            
            for(auto it: adj[node]){
                int adjNode = it.first;
                int wt = it.second;
                
                if(dis+wt<dist[adjNode] && !vis[adjNode]){
                    dist[adjNode]=dis+wt;
                    pq.push({dist[adjNode], adjNode});
                    path.push_back(adjNode);
                    vis[adjNode]=1;
                }
            }
        }
        
        if(dist[n]==1e9) 
            return {};
        
        int node=n;

        vector<string>path_cities;
        for(auto it:path){
            for(auto city:map_city){
                if(city.second==it)
                    path_cities.push_back(city.first);
            }
        }
        return path_cities;
    }

int main(){
    //entering the cities
    vector<string>cities = {"Thekkady", "Alleppey", "Munnar", "Trivendrum"};

    int n=cities.size();

    vector<pair<int,pair<string,string>>>edges = {{86, {"Munnar", "Thekkady"}}, {138, {"Alleppey", "Thekkady"}}, {146, {"Trivendrum", "Alleppey"}}, {277, {"Trivendrum", "Munnar"}}, {172, {"Munnar", "Alleppey"}}};
    
    int m=edges.size();
    vector<string>shortest_Path = shortestPath(n, m, cities, edges);

    cout<<"Route is: ";

    int size=shortest_Path.size();
    for(int i=0;i<size;i++){
        if(i==size-1)
            cout<<shortest_Path[i]<<endl;
        else    
            cout<<shortest_Path[i]<<"->";
    }
}