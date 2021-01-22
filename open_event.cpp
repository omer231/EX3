#include "open_event.h"

namespace mtm {
    OpenEvent::OpenEvent(DateWrap date, string name) : BaseEvent(date, std::move(name))
    {}

    OpenEvent::OpenEvent(OpenEvent const &open_event) : BaseEvent(open_event)
    {}

    OpenEvent::~OpenEvent()
    = default;

    void OpenEvent::registerParticipant(int student)
    {
        int result = event_participants.insertStudent(student);
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