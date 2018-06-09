#include <iostream>
#include <cassert>
#include "UGraph.h"
#include <vector>

int main ()
{
	std::vector<Vertex> vertices = {1,2,3,4};
	std::vector<Edge> edges = {{1,2,6}, {2,3,2}, {2,4,8}, {3,4,2}};

	UGraph graph = UGraph(vertices, edges);
	std::cout << graph.toString();

	return 0;
}