#include "Controller.hpp"


Controller::Controller() {
    m_id = "";
    m_fill = "#FFFFFF";
    m_stroke = "#000000";
    m_strokeWidht = "1";
    m_lock = false;
}

void Controller::traiterMessage(Message msg) {

    switch (msg.type) {
    case TypesMessage::CONTROL_PANEL:
        if (msg.m_id != "\n") {
            m_id = msg.m_id;
        }

        if (msg.m_fill != "") {
            m_fill = msg.m_fill;
        }

        if (msg.m_stroke != "") {
            m_stroke = msg.m_stroke;
        }

        if (msg.m_strokeWidht != "") {
            m_strokeWidht = msg.m_strokeWidht;
        }

        if (msg.m_lock) {
            m_lock = true;
        }
        else {
            m_lock = false;
        }

        break;
    default:
        break;
    }

    //TODO -> REFRESH    
}
	
