#include <iostream>
#include <cassert>
#include "algorithms/tarjan.h"
#include "algorithms/dijkstra.h"
#include "classes/UGraph.h"
#include <vector>

int main ()
{
	std::vector<Vertex> vertices  = {1,2,3,4,5,6,7,8,9,10,11,12};
	std::vector<Edge> edges = {{1,2,3}, {2,3,4}, {3,4,8}, {2,5,2}, 
							{5,6,1}, {6,7,7}, {7,8,3},
							{8,9,5}, {6,9,4},  {5,10,9},
							{10,11,5}, {10,12,2}};

	UGraph graph = UGraph(vertices, edges);
	// std::cout << graph.toString();

	std::cout << "----------------------------\n";
	std::cout << "DFS Tree\n";
	
	auto bridges = UGraphBridges(graph);

	std::cout << "Bridges\n";
	for (unsigned int i =0; i < bridges.size(); i++)
			std::cout << bridges[i].getId() << " ";
	std::cout << std::endl;

	std::cout << "Rotulação por dijkstra\n";
	graph = dijkstra(graph);
	graph.toStringDijkstra();

	return 0;
}