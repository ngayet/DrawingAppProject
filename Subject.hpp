#ifndef __Subject_h__
#define __Subject_h__

#include "Observer.hpp"
#include "Message.hpp"

class Subject {
private:
	Observer* m_observer;

public:
	Subject() { m_observer = NULL; }
	void AddObserver(Observer* o) { m_observer = o; }
	void notifyObservers(Message* m) { if(m_observer) m_observer->Update(m);}
	bool ObserveurIsSet() { return m_observer != NULL; }
};

#endif