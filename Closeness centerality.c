#include <queue>
#include <stack>
#include <vector>
#include <iostream>
#include <iomanip>
#define INF 1e9
using namespace std;


vector<int>  shortest_distance(int src, vector<vector<pair<int,int> > > adj_list){

	// Create queue
	priority_queue<pair<int, pair<int, int> >,
				   vector<pair<int, pair<int, int>> >,
				   greater<pair<int, pair<int, int> > > >nodes_q;

	// Create d and p arrays
	int n = adj_list.size();
	vector<int> d(n, INF);
	vector<int> p(n, -1);

	nodes_q.push({0, {src, src}});

	while(!nodes_q.empty()){
		pair<int,pair<int, int> > cur_p = nodes_q.top();
		nodes_q.pop();
		int cur_node = cur_p.second.first;
		int cur_prev_node = cur_p.second.second;
		int cur_dis = cur_p.first;

		if (d[cur_node] != INF)
			continue;

		d[cur_node] = cur_dis;
		p[cur_node] = cur_prev_node;

		// Add the nodes connected to current one
		for (int i=0;i< adj_list[cur_node].size();i++)
		{
			int next_node = adj_list[cur_node][i].first;
			int weight = adj_list[cur_node][i].second;
			if (d[next_node] !=INF)
				continue;
			nodes_q.push({cur_dis + weight,{next_node, cur_node}});
		}
	}

	return d;
}



int main()
{

    cout<<fixed<<setprecision(8);

    int nodes;
    int edges;

    cin>>nodes>>edges;
    vector<vector<pair<int,int> > > adj_list(nodes);
    //vector< list <int> > adj_list(nodes, list<int> ());

    for(int i=0;i<edges;i++)
    {
        int a,b,w;
        cin>>a>>b>>w;
        adj_list[a].push_back({b,w});
        adj_list[b].push_back({a,w});
    }




   float sum=0.00000000;
   float avg=0.00000000;


   for(int l=0; l< nodes; l++)
   {

        vector<int> distance = shortest_distance(l, adj_list);



        for (int k =0 ; k <nodes; k++)
        {
            if(l==k)
            {
                continue;
            }

            sum=sum+distance[k];
        }
         avg=(nodes-1)/sum;
        cout<<avg<<'\n';
        sum=0.00000000;

   }



    return 0;
}
