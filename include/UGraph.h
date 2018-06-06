#ifndef _UGRAPH_H_
#define _GRAPH_H_

#include <vector>
#include <string>
#include "Vertex.h"

class UGraph
{
	private:

	// Attributes
	std::vector<Vertex> vertices; // vertices in a graph

	public:

	/**
	 * @brief      Constructs the object.
	 */
	UGraph ();
	
	/**
	 * @brief      Constructs the object.
	 *
	 * @param[in]  numOfVertices  The number of vertices
	 */
	UGraph ( int numOfVertices );
	
	/**
	 * @brief      Destroys the object.
	 */
	~UGraph () = default;

	/**
	 * @brief      Adds an edge.
	 *
	 * @param[in]  source  The source
	 * @param[in]  sink    The sink
	 */
	void addEdge (int source, int sink);
	
	/**
	 * @brief      Adds a vertex.
	 *
	 * @param[in]  v    The vertex
	 */
	void addVertex (Vertex v);

	/**
	 * @brief      Returns a string representation of the object.
	 *
	 * @return     String representation of the object.
	 */
	std::string toString ();

	/**
	 * @brief      Gets the vertex.
	 *
	 * @param[in]  id    The identifier
	 *
	 * @return     The vertex, 0 if it is not found.
	 */
	Vertex getVertex ( int id );

	/**
	 * @brief      Gets the vertices.
	 *
	 * @return     The vertices.
	 */
	std::vector<Vertex> getVertices ();

};

#endif