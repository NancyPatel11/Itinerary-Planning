#include<bits/stdc++.h>
using namespace std;

int TSP(int mask, int pos, int vis_all, int n, map<int, string>&map_city, vector<vector<int>>&dist){
    if(mask==vis_all)
    {
        //to come back to same start point
        // return dist[pos][0];

        //completed visiting all nodes but not returning the first node
        return 0;
    }

    int ans=INT_MAX;
    //trying to visit all unvisited cities
    for(int city=0; city<n; city++){
        if((mask & (1<<city))==0)
        {
            int newAns = dist[pos][city] + TSP(mask | (1<<city), city, vis_all, n, map_city, dist);
            ans=min(ans, newAns);
        }
    }
    return ans;
}

int main(){
    //entering the cities
    vector<string>cities = {"Thekkady", "Alleppey", "Munnar", "Trivendrum"};
    int n=cities.size();

    map<int, string> map_city;

    for(int i=0;i<n;i++)
        map_city[i] = cities[i];

    // for(auto it:map_city)
    //     cout<<it.first<<" "<<it.second<<endl;

    int VISITED_ALL = (1<<n) - 1;
    
    vector<vector<int>>dist = {{0, 138, 86, 207},
                               {138, 0, 172, 146},
                               {86, 172, 0, 277},
                               {207, 146, 277, 0}                           
                                };

    int minDist = TSP(1, 0, VISITED_ALL, n, map_city, dist);

    cout<<"Minimum Distance is: "<<minDist<<endl;
    
}