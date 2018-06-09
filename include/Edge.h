/**
 * Class for Edge representation
 * 
 * author     Gabriel Araújo de Souza
 * e_mail     gabriel_feg@hotmail.com
 * date       Jun 2018 
 */

#ifndef _EDGE_H_
#define _EDGE_H_

#include "Vertex.h"

class Edge 
{
	private:

	Vertex source;
	Vertex sink;
	int weight;

	public:

	/**
	 * @brief      Constructs the object. A null edge
	 */
	Edge ();

	/**
	 * @brief      Constructs the object.
	 *
	 * @param[in]  source  The source
	 * @param[in]  sink    The sink
	 */
	Edge ( Vertex source, Vertex sink );

	/**
	 * @brief      Constructs the object with a weight
	 *
	 * @param[in]  source  The source
	 * @param[in]  sink    The sink
	 * @param[in]  weight  The weight
	 */
	Edge ( Vertex source, Vertex sink, int weight );

	/**
	 * @brief      Destroys the object.
	 */
	~Edge () = default;

	/**
	 * @brief      assigns a new Edge
	 *
	 * @param[in]  rhs   The right hand side
	 *
	 * @return     a new edge equals rhs edge
	 */
	Edge & operator=( const Edge & rhs )
	{
		source = rhs.source;
		sink = rhs.sink;
		weight = rhs.weight;

		return *this;
	}

	/**
	 * @brief      verify if two Edges are equals
	 *
	 * @param[in]  rhs   The right hand side
	 *
	 * @return     true if equals, false otherwise
	 */
	bool operator==( const Edge & rhs )
	{
		if (source == rhs.source and sink == rhs.sink and weight == rhs.weight)
			return true;

		return false;
	}

	/**
	 * @brief      Gets the weight.
	 *
	 * @return     The weight.
	 */
	int getWeight ();

	/**
	 * @brief      Gets the source.
	 *
	 * @return     The source.
	 */
	Vertex getSource ();

	/**
	 * @brief      Gets the sink.
	 *
	 * @return     The sink.
	 */
	Vertex getSink ();

	/**
	 * @brief      Sets the weight.
	 *
	 * @param[in]  weight  The weight
	 */
	void setWeight ( int weight);

	/**
	 * @brief      Sets the source.
	 *
	 * @param[in]  source  The source
	 */
	void setSource ( Vertex source );

	/**
	 * @brief      Sets the sink.
	 *
	 * @param[in]  sink  The sink
	 */
	void setSink ( Vertex sink );

};

#endif