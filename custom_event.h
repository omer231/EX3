#ifndef EX302_CUSTOM_EVENT_H
#define EX302_CUSTOM_EVENT_H

#include "base_event.h"

namespace mtm {
    template<class CanRegister>
    class CustomEvent : public BaseEvent {
    private:
        CanRegister canRegister;
    public:
        CustomEvent(DateWrap date, string name, CanRegister condition) :
                BaseEvent(date, name), canRegister(condition)
        {}

        ~CustomEvent() override
        = default;

        void registerParticipant(int student) override
        {
            if (!canRegister(student)) {
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

        CustomEvent *clone() const override
        {
            return new CustomEvent(*this);
        }
    };
}

#endif //EX302_CUSTOM_EVENT_H
