#ifndef __Message_h__
#define __Message_h__

#include "TypesMessage.hpp"
#include "Element.hpp"

class Message {

public:
	Message();
	TypesMessage m_msgType;

	std::string m_id;
	std::string m_fill;
	std::string m_stroke;
	int m_strokeWidth;
	bool m_lock;
	int m_x;
	int m_y;
	DrawingType m_type;
};

Message::Message() {
	m_msgType = TypesMessage::EMPTY_MESSAGE;
	m_id = "\n";
	m_fill = "";
	m_stroke = "";
	m_strokeWidth = 0;
	m_lock = false;
	m_x = 0;
	m_y = 0;
	m_type = DrawingType::EMPTY;
}

#endif