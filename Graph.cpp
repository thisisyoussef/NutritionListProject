#include "Graph.h"

void Graph::insertEdge(node from, node to, int weight) {
	nodeStore[from.ID] = from;
	nodeStore[to.ID] = to;
	pair<int, int> toWeight;
	toWeight.first = to.ID;
	toWeight.second = weight;
	adjList[from.ID].push_back(toWeight);
}

void Graph::printGraph() {
	for (auto it: adjList) {
		cout << it.first << " Name: " << nodeStore[it.first].name <<" connects to: ";
		for (int i = 0; i < it.second.size(); i++) {
			cout << it.second.at(i).first << " Name: " << nodeStore[it.second.at(i).first].name << " ";
			cout << "with a weight of: " << it.second.at(i).second;
		}
		cout << endl;
	}
}

//vector<int> Graph::BFSsearch(string Uinput) {
//	vector<int> searchRes;
//	int Vsize = nodeStore.size();
//	vector<bool> visited(Vsize, false);
//
//	unordered_map<int, vector<pair<int, int>>>;
//}
