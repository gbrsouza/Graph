/**
 * Class for Graph representation
 * 
 * author     Gabriel Araújo de Souza
 * e_mail     gabriel_feg@hotmail.com
 * date       Jun 2018 
 */

#ifndef _UGRAPH_H_
#define _GRAPH_H_

#include <vector>
#include <string>
#include "Vertex.h"
#include "Edge.h"

class UGraph
{
	private:

	// Attributes
	std::vector<Vertex> vertices; // vertices in a graph
	std::vector<Edge> edges;

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
	 * @brief      Adds an edge.
	 *
	 * @param[in]  source  The source
	 */
	void addEdge (Vertex source, Vertex sink);

	/**
	 * @brief      Adds an edge.
	 *
	 * @param[in]  edge  The edge
	 */
	void addEdge (Edge edge);

	
	/**
	 * @brief      Adds a vertex.
	 *
	 * @param[in]  v    The vertex
	 */
	void addVertex (Vertex v);

	/**
	 * @brief      Removes an edge.
	 *
	 * @param[in]  source  The source
	 * @param[in]  sink    The sink
	 *
	 * @return     True if it could remove, false otherwise
	 */
	bool removeEdge ( Edge edge );


	/**
	 * @brief      Removes a vertex.
	 *
	 * @param[in]  idVertex  vertex identifier
	 *
	 * @return     True if it could remove, false otherwise
	 */
	bool removeVertex ( int idVertex );

	/**
	 * @brief      Returns a string representation of the object.
	 *
	 * @return     String representation of the object.
	 */
	std::string toString ();

	/**
	 * @brief      Determines if vertex contained in this graph.
	 *
	 * @param[in]  idVertex  The vertex identifier
	 *
	 * @return     True if vertex contained, False otherwise.
	 */
	bool isVertexContained ( int idVertex );

	/**
	 * @brief      Gets the vertex.
	 *
	 * @param[in]  id    The identifier
	 *
	 * @return     The vertex or a null vertex if it is not found.
	 */
	Vertex & getVertex ( int id );

	/**
	 * @brief      Gets the vertices.
	 *
	 * @return     The vertices.
	 */
	std::vector<Vertex> getVertices ();

	/**
	 * @brief      Gets the graph order.
	 *
	 * @return     The graph order.
	 */
	int getGraphOrder ();
	
	/**
	 * @brief      Gets the vertex-induced subgraph.
	 *
	 * @param[in]  vertices        A vector containing a set of vertices
	 * @param      originalGraph   The original graph
	 *
	 * @return     The vertex induced subgraph corresponding a set
	 *             of vertices. 
	 */
	UGraph getVertexInducedSubgraph ( std::vector<Vertex> vertices );
	

};

#endif