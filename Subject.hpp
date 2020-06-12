#ifndef __Subject_h__
#define __Subject_h__

#include "Observer.hpp"
#include "Message.hpp"

class Subject {
private:
	Observer* m_observer;

public:
	void AddObserver(Observer* o) { m_observer = o; }
	void notifyObservers(Message m) { if(m_observer) m_observer->Update(m);}
};

#endif