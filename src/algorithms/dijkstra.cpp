#include "algorithms/dijkstra.h"

void removeVertex (std::vector<Vertex> &freeSet, Vertex vertex)
{
	for (auto it = freeSet.begin(); it != freeSet.end(); ++it )
	{
		if (it->getId() == vertex.getId()) 
		{
			freeSet.erase(it,it+1);
			break;
		}
	}
}

UGraph dijkstra (UGraph graph)
{
	//inicializate free set
	auto freeSet = graph.getVertices();

	graph.getVertices()[0].setPathWeight(0);
	removeVertex(freeSet, graph.getVertices()[0]);

	// inicializate
	auto adjList = graph.getVertices()[0].getAdjList();
	for (unsigned int i=0; i < adjList.size(); i++)
	{
		graph.getVertex(adjList[i].getId()).setLabeledBy(graph.getVertices()[0].getId());
		graph.getVertex(adjList[i].getId()).setPathWeight(graph.getEdgeWeight(graph.getVertices()[0],adjList[i]));
	}

	while ( !(freeSet.empty()) )
	{	
		// choose the minimum
		Vertex min = freeSet[0];
		for (unsigned int i=0; i < freeSet.size(); i++)
		{
			if ( freeSet[i].getPathWeight() < min.getPathWeight() )
				min = freeSet[i];
		}
		auto vertexMin = graph.getVertex(min.getId());

		//mark min
		removeVertex(freeSet, min);
		
		for (unsigned int i=0; i < vertexMin.getAdjList().size(); i++)
		{
			for ( unsigned int j=0; j < freeSet.size(); j++)
			{
				if (vertexMin.getAdjList()[i].getId() == freeSet[j].getId())
				{
					int pathWeight = vertexMin.getPathWeight() + graph.getEdgeWeight(vertexMin, vertexMin.getAdjList()[i]);
					if (vertexMin.getAdjList()[i].getPathWeight() > pathWeight)
					{
						vertexMin.getAdjList()[i].setLabeledBy(vertexMin.getId());
						vertexMin.getAdjList()[i].setPathWeight(pathWeight);
					}
				}	
			}
		}
	}
	return graph;
}