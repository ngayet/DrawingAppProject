#pragma once
#include <vector>

/**
* @brief Encapsulation of the depth concept.
*/
class Node
{
private:
	std::vector<Node*> m_childs;
	Node* m_parent;
	int m_level; /*!< start to 0, same as the corresponding index in m_parent->m_childs */

public:
	Node();
	Node(const Node &n);
	virtual ~Node();
	Node& operator=(const Node &n);

	Node(Node& parent);

	std::vector<Node*> GetChilds() { return m_childs; }
	int GetLevel() { return m_level; }

	bool AddChild(Node* child);
	bool RemoveChild(Node* child);
	bool MoveTo(Node& dest, int level);
};