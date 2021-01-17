#include "closed_event.h"

namespace mtm {

    ClosedEvent::ClosedEvent(string name, DateWrap *date) : BaseEvent(name, date)
    {
        invited = new PriorityQueue();
    }

    void ClosedEvent::addInvitee(int student)
    {
        int result = invited->pqInsert(student);
        if (result == INVALID_INSERT) {
            throw Exceptions::InvalidStudent();
        }
        if (result == REPEATED_INSERT) {
            throw Exceptions::AlreadyInvited();
        }
    }

    void ClosedEvent::registerParticipant(int student) const
    {
        if (!invited->pqDoesValueExist(student)){
            throw Exceptions::RegistrationBlocked();
        } else{
            int result = studentList->pqInsert(student);
            if (result == INVALID_INSERT) {
                throw Exceptions::InvalidStudent();
            }
            if (result == REPEATED_INSERT) {
                throw Exceptions::AlreadyRegistered();
            }
        }
    }

    BaseEvent *ClosedEvent::clone() const
    {
        auto *nDate = new DateWrap(*eventDate);
        string nName = eventName;
        auto *nStudentList = new PriorityQueue(*studentList);
        auto *nInvited = new PriorityQueue(*invited);
        auto *nEvent = new ClosedEvent(nName, nDate);

        //POSSIBLE MEMORY LEAK FROM CLOSED EVENT "DEFAULT" STUDENT LIST, INVITED
        nEvent->studentList = nStudentList;
        nEvent->invited = nInvited;
        return nEvent;
    }
}