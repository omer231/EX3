#include "open_event.h"

namespace mtm {
    OpenEvent::OpenEvent(string name, DateWrap *date) : BaseEvent(name, date)
    {

    }

    void OpenEvent::registerParticipant(int student) const
    {
        int result = studentList->pqInsert(student);
        if (result == INVALID_INSERT) {
            throw Exceptions::InvalidStudent();
        }
        if (result == REPEATED_INSERT) {
            throw Exceptions::AlreadyRegistered();
        }
    }

    BaseEvent * OpenEvent::clone() const
    {
        auto *nDate = new DateWrap(*eventDate);
        string nName = eventName;
        auto *nStudentList = new PriorityQueue(*studentList);
        auto *nEvent = new OpenEvent(nName, nDate);

        //POSSIBLE MEMORY LEAK FROM OPEN EVENT "DEFAULT" STUDENT LIST
        nEvent->studentList = nStudentList;
        return nEvent;
    }
}