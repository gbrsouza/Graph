/**
 * Class for Graph representation
 * 
 * author     Gabriel Araújo de Souza
 * e_mail     gabriel_feg@hotmail.com
 * date       Jun 2018 
 */

#include "UGraph.h"

/**
 * @brief      Constructs the object.
 */
UGraph::UGraph ()
{
	Vertex aux = Vertex();
	this->vertices.push_back( aux );
}

/**
 * @brief      Constructs the object.
 *
 * @param[in]  numOfVertices  The number of vertices
 */
UGraph::UGraph ( int numOfVertices )
{
	for (int i=0; i < numOfVertices; i++)
		this->vertices.push_back( Vertex(i) );
}

/**
 * @brief      Adds an edge.
 *
 * @param[in]  source  The source
 * @param[in]  sink    The sink
 */
void UGraph::addEdge (int source, int sink)
{
	auto vSource = getVertex(source);
	auto vSink   = getVertex(sink);
	
	if ( (vSource != 0) and ( vSink != 0) )
	{
		for ( unsigned int i=0; i < vertices.size(); i++)
		{
			if (vertices[i].getId() == source )
				vertices[i].addEdge(vSource);
			else if (vertices[i].getId() == sink)
				vertices[i].addEdge(vSink);
		}
	}
}

/**
 * @brief      Adds a vertex.
 *
 * @param[in]  v    The vertex
 */
void UGraph::addVertex (Vertex v)
{
	vertices.push_back(v);
}

/**
 * @brief      Returns a string representation of the object.
 *
 * @return     String representation of the object.
 */
std::string UGraph::toString ()
{
	std::string value = "";
	for (unsigned int i=0; i < vertices.size(); i++)
		value += vertices[i].toString();
	
	return value;
}

/**
 * @brief      Determines if vertex contained in this graph.
 *
 * @param[in]  idVertex  The vertex identifier
 *
 * @return     True if vertex contained, False otherwise.
 */
bool UGraph::isVertexContained ( int idVertex )
{
	for ( auto i = this->vertices.begin(); i != this->vertices.end(); ++i)
		if ( i->getId() == idVertex ) return true;
	return false;
}


/**
 * @brief      Gets the vertex.
 *
 * @param[in]  id    The identifier
 *
 * @return     The vertex or a null vertex if it is not found.
 */
Vertex UGraph::getVertex ( int id )
{
	for ( int i=0; i < this->getGraphOrder(); i++ )
		if ( vertices[i].getId() == id ) return vertices[i];

	Vertex nullVertex = Vertex();
	return nullVertex;
}

/**
 * @brief      Gets the vertices.
 *
 * @return     The vertices.
 */
std::vector<Vertex> UGraph::getVertices ()
{
	return this->vertices;
}

/**
 * @brief      Gets the graph order.
 *
 * @return     The graph order.
 */
int UGraph::getGraphOrder ()
{
	return this->vertices.size();
}

/**
 * @brief      Gets the vertex-induced subgraph.
 *
 * @param[in]  vertices        A vector containing a set of vertices
 * @param      originalGraph   The original graph
 *
 * @return     The vertex induced subgraph corresponding a set
 *             of vertices. 
 */
UGraph UGraph::getVertexInducedSubgraph ( 
	std::vector<Vertex> vertices )
{
	UGraph vertexInducedSubgraph = UGraph();

	// add vertix in a new graph
	for ( unsigned int i=0; i < vertices.size(); i++)
		vertexInducedSubgraph.addVertex( vertices[i] );

	// add coresponding edges
	std::vector<Vertex> adjList;
	for ( unsigned int i=0; i < vertices.size(); i++)
	{
		adjList = vertices[i].getAdjList();
		for ( unsigned int j=0; j < adjList.size(); j++ )
		{
			if ( vertexInducedSubgraph.getVertex( adjList[j].getId() ).getDegree() != -1 )
				vertexInducedSubgraph.getVertex( vertices[i].getId() ).addEdge(adjList[j]);
		}
	}

	return vertexInducedSubgraph;

}
