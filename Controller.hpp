#include "main.hpp"
#include "string"

#include "Message.hpp"

class Controller
{
private:
	std::string m_id;
	std::string m_fill;
	std::string m_stroke;
	std::string m_strokeWidht;
	bool m_lock;

public:
	Controller();
	void traiterMessage(Message msg);
};




