#include "closed_event.h"

#include <utility>

namespace mtm {
    ClosedEvent::ClosedEvent(DateWrap date, string name) : BaseEvent(date, std::move(name)),
                                                           invited()
    {}

    /**
    ClosedEvent::ClosedEvent(const ClosedEvent &closed_event) : BaseEvent(closed_event),
                                                                invited(new IntList(*closed_event.invited))
    {}
     */


    ClosedEvent::~ClosedEvent()
    = default;

    void ClosedEvent::addInvitee(int student)
    {
        if (!mtm::IntList::validStudentId(student)) {
            throw InvalidStudent();
        } else {
            bool result = invited.doesStudentExist(student);
            if (result) {
                throw AlreadyInvited();
            } else {
                invited.insertStudent(student);
            }
        }
    }

    void ClosedEvent::registerParticipant(int student)
    {
        if (!mtm::IntList::validStudentId(student)) {
            throw InvalidStudent();
        }
        if (!invited.doesStudentExist(student)) {
            throw RegistrationBlocked();
        } else {
            int result = eventParticipants.insertStudent(student);
            if (result == REPEATED_INSERT) {
                throw AlreadyRegistered();
            }
        }
    }

    ClosedEvent *ClosedEvent::clone() const
    {
        return new ClosedEvent(*this);
    }
}