#ifndef __Observer_h__
#define __Observer_h__

#include "Message.hpp"

class Observer {
public:
	virtual void Update(Message m) = 0;
};

#endif