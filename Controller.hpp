#include "main.hpp"
#include "string"
#include "Element.hpp"

#include "Message.hpp"

class Controller
{
private:
	std::string m_id;
	std::string m_fill;
	std::string m_stroke;
	int m_strokeWidth;
	bool m_lock;
	int m_x;
	int m_y;
	DrawingType m_type;

public:
	Controller();
	void traiterMessage(Message msg);
};




