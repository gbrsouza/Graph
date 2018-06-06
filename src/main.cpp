#include <iostream>
#include "UGraph.h"

int main ()
{
	UGraph myGraph = UGraph(1);
	Vertex v1 = Vertex(1);
	Vertex v2 = Vertex(2);

	myGraph.addVertex(v1);
	myGraph.addVertex(v2);

	std::cout << "BEFORE\n";
	std::cout << myGraph.toString();

	myGraph.addEdge( 1, 2 );

	std::cout << "AFTER\n";
	std::cout << myGraph.toString();
	
	return 0;
}