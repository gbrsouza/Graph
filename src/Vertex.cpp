/**
 * Class for Vertex representation
 * 
 * author     Gabriel Araújo de Souza
 * e_mail     gabriel_feg@hotmail.com
 * date       Jun 2018 
 */

#include "Vertex.h"

/**
 * @brief      Constructs the object. Create a null graph
 */
Vertex::Vertex ()
{
	id = -1;
	degree = -1;
}

/**
 * @brief      Basic Construct
 *
 * @param[in]  id    The vertex identifier
 */
Vertex::Vertex ( int id )
{
	this->id = id;
	this->degree = 0;
	adjList = std::vector<Vertex>();
}

/**
 * @brief      Gets the degree.
 *
 * @return     The degree.
 */
int Vertex::getDegree ()
{
	return degree;
}

/**
 * @brief      Gets the identifier.
 *
 * @return     The identifier.
 */
int Vertex::getId ()
{
	return this->id;
}

/**
 * @brief      Gets the adjacency list.
 *
 * @return     The adj vector.
 */
std::vector<Vertex> Vertex::getAdjList ()
{
	return this->adjList;
}

/**
 * @brief      Sets the identifier.
 *
 * @param[in]  newId  The new identifier
 */
void Vertex::setId ( int newId )
{
	this->id = newId;
}

/**
 * @brief      Sets the adj list.
 *
 * @param[in]  newAdjvector  The new adj vector
 */	
void Vertex::setAdjList ( std::vector<Vertex> newAdjList )
{
	this->adjList = newAdjList;
}

/**
 * @brief      Adds an edge.
 *
 * @param[in]  vertex  The vertex
 */
void Vertex::addEdge ( Vertex vertex )
{
	adjList.push_back( vertex );
	degree++;
}

/**
 * @brief      Removes an edge.
 *
 * @param[in]  vertex  The vertex that represent edge 
 */
void Vertex::removeEdge ( Vertex vertex )
{
	if ( adjList.empty() ) return;

	for (auto it = adjList.begin(); it != adjList.end(); ++it )
	{
		if ( *it == vertex )
		{
			adjList.erase(it, it+1);
			break;
		}
	}
}

/**
 * @brief      Determines if adj.
 *
 * @param[in]  vertex  The vertex
 *
 * @return     True if adj, False otherwise.
 */
bool Vertex::isAdj ( Vertex vertex )
{
	for ( int i=0; i < this->getDegree(); i++ )
		if ( this->adjList[i] == vertex ) return true;

	return false;
}

/**
 * @brief      Returns a string representation of the object.
 *
 * @return     String representation of the object.
 */
std::string Vertex::toString()
{
	std::string value = "( ";
	value += std::to_string( this->getId() ) + " ){ ";
	for (unsigned int i = 0; i < adjList.size(); i++)
		value += std::to_string( adjList[i].getId() ) + " ";
	value += "}\n";

	return value;

} 





