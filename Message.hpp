#ifndef __Message_h__
#define __Message_h__
#include "Element.hpp"

enum TypesMessage {
	EMPTY_MESSAGE,
	CONTROL_PANEL,
	MYFRAME_ON_CLOSE,
	MYFRAME_ON_SIZE,
	DRAWING_MOUSE_LEFT_DOWN,
	DRAWING_MOUSE_MOVE,
	DRAWING_ON_PAINT,
	DRAWING_MOUSE_RIGHT_DOWN
};

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

#endif