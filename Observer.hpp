#ifndef __Observer_h__
#define __Observer_h__

class Observer {
public:
	virtual void Update(Message m) = 0;
};

#endif