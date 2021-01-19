#include "open_event.h"

#include <utility>

namespace mtm {
    OpenEvent::OpenEvent(DateWrap date, string name) : BaseEvent(date, std::move(name))
    {}

    OpenEvent::~OpenEvent()
    = default;

    void OpenEvent::registerParticipant(int student)
    {
        int result = eventParticipants->insertStudent(student);
        if (result == INVALID_INSERT) {
            throw InvalidStudent();
        }
        if (result == REPEATED_INSERT) {
            throw AlreadyRegistered();
        }
    }

    OpenEvent *OpenEvent::clone() const
    {
        return new OpenEvent(*this);
    }
}