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
 * @brief      Gets the vertex.
 *
 * @param[in]  id    The identifier
 *
 * @return     The vertex, 0 if it is not found.
 */
Vertex UGraph::getVertex ( int id )
{
	for ( auto i = vertices.begin(); i != vertices.end(); ++i)
		if ( i->getId() == id ) return *i;
	return 0;
}

/**
 * @brief      Gets the vertices.
 *
 * @return     The vertices.
 */
std::vector<Vertex> UGraph::getVertices ()
{
	return vertices;
}


