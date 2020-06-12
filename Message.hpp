#include "TypesMessage.hpp"

class Message {

public:
	Message();
	TypesMessage type;

	std::string m_id;
	std::string m_fill;
	std::string m_stroke;
	std::string m_strokeWidht;
	bool m_lock;
	int m_x;
	int m_y;
};

Message::Message() {
	type = EMPTY;
	m_id = "\n";
	m_fill = "";
	m_stroke = "";
	m_strokeWidht = "";
	m_lock = false;
}