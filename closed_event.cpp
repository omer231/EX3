#include "closed_event.h"

#include <utility>

namespace mtm {
    ClosedEvent::ClosedEvent(DateWrap date, string name) : BaseEvent(date, std::move(name)), invited(new IntList)
    {}

    ClosedEvent::~ClosedEvent()
    = default;

    void ClosedEvent::addInvitee(int student)
    {
        if (!mtm::IntList::validStudentId(student)) {
            throw InvalidStudent();
        } else {
            bool result = invited->doesStudentExist(student);
            if (result) {
                throw AlreadyInvited();
            } else {
                invited->insertStudent(student);
            }
        }
    }

    void ClosedEvent::registerParticipant(int student)
    {
        if (!invited->doesStudentExist(student)) {
            throw RegistrationBlocked();
        } else {
            int result = eventParticipants->insertStudent(student);
            if (result == INVALID_INSERT) {
                throw InvalidStudent();
            }
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