#include <iostream>
#include <cassert>
#include "UGraph.h"

int main ()
{
	/// create a null graph
	UGraph myGraph = UGraph();
	
	// create two vertices
	Vertex v1 = Vertex(1);
	Vertex v2 = Vertex(2);

	// add vertices in a graph
	myGraph.addVertex(v1);
	myGraph.addVertex(v2);

	// create edge
	Edge edge1 = Edge(v1, v2);

	std::cout << "BEFORE\n";
	std::cout << myGraph.toString();

	myGraph.addEdge( edge1 );

	std::cout << "AFTER\n";
	std::cout << myGraph.toString();

	// assert(myGraph.removeEdge (edge1));
	assert(myGraph.removeVertex (v1));

	std::cout << "REMOVED\n";
	std::cout << myGraph.toString();

	return 0;
}