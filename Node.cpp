#include "Node.hpp"

Node::Node() : m_childs()
{
	m_parent = NULL;
	m_level = 0;
}

Node::~Node()
{

}

Node::Node(const Node& n) : m_childs(n.m_childs)
{
	m_parent = n.m_parent;
	m_level = n.m_childs.size();
}

bool Node::AddChild(Node* child)
{
	m_childs.push_back(child);
	return false;
}

bool Node::RemoveChild(Node* child)
{
	m_childs.erase(m_childs.begin()+child->GetLevel());
	return true;
}

bool Node::MoveTo(Node& dest, int level)
{
	m_parent->RemoveChild(this);
	m_parent = &dest;
	dest.GetChilds().insert(dest.GetChilds().begin()+level, this);
	return true;
}

Node& Node::operator=(const Node& n)
{
	m_childs = n.m_childs;
	m_parent = n.m_parent;
	m_level = n.m_childs.size();
	return *this;
}


