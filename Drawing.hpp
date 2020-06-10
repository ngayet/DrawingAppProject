#pragma once
#include "Node.hpp"

/**
* class singleton
*/
class Drawing : public Node
{
private:

public:
	Drawing() {}
	Drawing(const Drawing& n) : Node(n) {}
	virtual ~Drawing() {}
	Drawing& operator=(const Drawing& n) { (Node)*this = (Node)n; }
};