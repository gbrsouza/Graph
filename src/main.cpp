#include <iostream>
#include <cassert>
#include "classes/DFSTree.h"
#include "algorithms/tarjan.h"
#include "classes/Edge.h"
#include <vector>

int main ()
{
	std::vector<Vertex> vertices  = {1,2,3,4,5,6,7,8,9,10,11,12};
	std::vector<Edge> edges = {{1,2,0}, {2,3,0}, {3,4,0}, {2,5,0}, 
							{5,6,0}, {6,7,0}, {7,8,0},
							{8,9,0}, {6,9,0},  {5,10,0},
							{10,11,0}, {10,12,0}};

	UGraph graph = UGraph(vertices, edges);
	// std::cout << graph.toString();

	std::cout << "----------------------------\n";
	std::cout << "DFS Tree\n";
	
	auto bridges = UGraphBridges(graph);

	std::cout << "Bridges\n";
	for (unsigned int i =0; i < bridges.size(); i++)
			std::cout << bridges[i].getId() << " ";
	std::cout << std::endl;
	return 0;
}