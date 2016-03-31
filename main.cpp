#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Edge {

public:
	Edge(int _source, int _destination, int _cost):source(_source), destination(_destination),cost(_cost) {
	}
	int source;
	int destination;
	int cost;
};

vector<int> dijkstra(int nodes,vector<Edge> edges, int source) {
	vector<int> distance(nodes, INT_MAX);
	vector<bool> used(nodes, false);
	distance[source] = 0;
	used[source] = true;
	int rest = nodes - 1;

	for (auto &p : edges) {
		if (p.source == source) {
			distance[p.destination] = p.cost;
		}
	}

	while (rest) {
		int min = INT_MAX, index = -1;
		for (int i = 0; i < nodes; ++i) {
			if (!used[i] && min > distance[i]) {
				min = distance[i];
				index = i;
			}
		}
		if (index < 0)
			break;
	
		for (auto &p : edges) {
			if (p.source == index) {
				distance[p.destination] = std::min(distance[p.destination], distance[p.source] + p.cost);
			}
		}
		used[index] = true;
		rest--;
	}

	return distance;
}

int main() {

	vector<Edge> edges;
	edges.push_back(Edge(0, 1, 7));
	edges.push_back(Edge(0, 2, 9));
	edges.push_back(Edge(0, 5, 14));
	edges.push_back(Edge(1, 2, 10));
	edges.push_back(Edge(1, 3, 15));
	edges.push_back(Edge(2, 3, 11));
	edges.push_back(Edge(2, 5, 2));
	edges.push_back(Edge(3, 4, 6));
	edges.push_back(Edge(4, 5, 9));

	auto dis = dijkstra(6,edges,0);
	for (auto &i : dis)
		cout << i << " ";

	getchar();
	return 0;

}