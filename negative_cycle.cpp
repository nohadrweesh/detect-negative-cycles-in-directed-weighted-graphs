#include <iostream>
#include <vector>

int oo = 0x3f3f3f;
using std::vector;

int negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost) {
	//write your code here
	vector<int>dist(adj.size(), oo);
	vector<int>prev(adj.size(), -1);
	dist[0] = 0;
	for (int i = 0; i < adj.size() - 1; i++){
		for (int j = 0; j < adj.size(); j++){
			for (int k = 0; k < adj[j].size(); k++){
				if (dist[adj[j][k]]>(dist[j] + cost[j][k]))
					dist[adj[j][k]] = (dist[j] + cost[j][k]);
				prev[adj[j][k]] = j;
			}
		}
	}
	bool isNegativeCyclic = false;
	for (int j = 0; j < adj.size(); j++){
		for (int k = 0; k < adj[j].size(); k++){
			if (dist[adj[j][k]] >(dist[j] + cost[j][k]))
				return 1;
			/*isNegativeCyclic = true;
			break;*/
			/*dist[adj[j][k]] = (dist[j] + cost[j][k]);
			prev[adj[j][k]] = j;*/
		}
	}
	return 0;
}

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int n, m;
	std::cin >> n >> m;
	vector<vector<int> > adj(n, vector<int>());
	vector<vector<int> > cost(n, vector<int>());
	for (int i = 0; i < m; i++) {
		int x, y, w;
		std::cin >> x >> y >> w;
		adj[x - 1].push_back(y - 1);
		cost[x - 1].push_back(w);
	}
	std::cout << negative_cycle(adj, cost);
}
