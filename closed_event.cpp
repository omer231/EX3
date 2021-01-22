#include "closed_event.h"

#include <utility>

namespace mtm {
    ClosedEvent::ClosedEvent(DateWrap date, string name) : BaseEvent(date, name),
                                                           invited()
    {}

    ClosedEvent::~ClosedEvent()
    = default;

    void ClosedEvent::addInvitee(int student)
    {
        if (!mtm::IntList::studentIdIsValid(student)) {
            throw InvalidStudent();
        } else {
            bool result = invited.studentExists(student);
            if (result) {
                throw AlreadyInvited();
            } else {
                invited.insertStudent(student);
            }
        }
    }

    void ClosedEvent::registerParticipant(int student)
    {
        if (!mtm::IntList::studentIdIsValid(student)) {
            throw InvalidStudent();
        } else {
            if (!invited.studentExists(student)) {
                throw RegistrationBlocked();
            } else {
                int result = event_participants.insertStudent(student);
                if (result == REPEATED_INSERT) {
                    throw AlreadyRegistered();
                }
            }
        }
    }

    ClosedEvent *ClosedEvent::clone() const
    {
        return new ClosedEvent(*this);
    }
}