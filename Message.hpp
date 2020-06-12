#include "TypesMessage.hpp"
#include "Element.hpp"

class Message {

public:
	Message();
	TypesMessage m_msgType;

	std::string m_id;
	std::string m_fill;
	std::string m_stroke;
	std::string m_strokeWidht;
	bool m_lock;
	int m_x;
	int m_y;
	DrawingType m_type;
};

Message::Message() {
	m_msgType = TypesMessage::EMPTY;
	m_id = "\n";
	m_fill = "";
	m_stroke = "";
	m_strokeWidht = "";
	m_lock = false;
	m_x = 0;
	m_y = 0;
	m_type = DrawingType::EMPTY;
}