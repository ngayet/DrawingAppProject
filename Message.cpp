#include "Message.hpp"

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