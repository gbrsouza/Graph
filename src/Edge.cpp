/**
 * Class for Edge representation
 * 
 * author     Gabriel Araújo de Souza
 * e_mail     gabriel_feg@hotmail.com
 * date       Jun 2018 
 */

#include "Edge.h"


/**
 * @brief      Constructs the object. A null edge
 */
Edge::Edge ()
{
	source = Vertex();
	sink = Vertex();
	weight = -1;
}

/**
 * @brief      Constructs the object.
 *
 * @param[in]  source  The source
 * @param[in]  sink    The sink
 */
Edge::Edge ( Vertex source, Vertex sink )
{
	this->source = source;
	this->sink = sink;
	this->weight = 0;
}

/**
 * @brief      Constructs the object with a weight
 *
 * @param[in]  source  The source
 * @param[in]  sink    The sink
 * @param[in]  weight  The weight
 */
Edge::Edge ( Vertex source, Vertex sink, int weight )
{
	this->source = source;
	this->sink = sink;
	this->weight = weight;
}


/**
 * @brief      Gets the weight.
 *
 * @return     The weight.
 */
int Edge::getWeight ()
{
	return weight;
}

/**
 * @brief      Gets the source.
 *
 * @return     The source.
 */
Vertex Edge::getSource ()
{
	return source;
}

/**
 * @brief      Gets the sink.
 *
 * @return     The sink.
 */
Vertex Edge::getSink ()
{
	return sink;
}

/**
 * @brief      Sets the weight.
 *
 * @param[in]  weight  The weight
 */
void Edge::setWeight ( int weight )
{
	this->weight = weight;
}

/**
 * @brief      Sets the source.
 *
 * @param[in]  source  The source
 */
void Edge::setSource ( Vertex source )
{
	this->source = source;
}

/**
 * @brief      Sets the sink.
 *
 * @param[in]  sink  The sink
 */
void Edge::setSink ( Vertex sink )
{
	this->sink = sink;
}