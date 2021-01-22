#ifndef EX302_CUSTOM_EVENT_H
#define EX302_CUSTOM_EVENT_H

#include "base_event.h"

namespace mtm {
    template<class CanRegister>
    class CustomEvent : public BaseEvent {
    private:
        /**
         * can_register - condition for registering student
         */
        CanRegister can_register;
    public:
        /**
         * CustomEvent Constructor
         * @param date event_date - date
         * @param name event_name - name
         * @param condition can_register - condition
         *                  event_participants - empty list
         */
        CustomEvent(DateWrap date, string name, CanRegister condition) : BaseEvent(date, name),
                                                                         can_register(condition)
        {}

        /**
         * CustomEvent Copy Constructor
         * @param custom_event
         */
        CustomEvent(CustomEvent const &custom_event) : BaseEvent(custom_event), can_register(custom_event.can_register)
        {}

        /**
         * CustomEvent Destructor
         */
        ~CustomEvent() override
        = default;

        /**
         * registerParticipant
         * @param student student to attempt to insert in event_participants
         *      (if valid id, if not already registered, if can_register condition is true)
         */
        void registerParticipant(int student) override
        {
            if (!mtm::IntList::studentIdIsValid(student)) {
                throw InvalidStudent();
            } else {
                if (!can_register(student)) {
                    throw RegistrationBlocked();
                } else {
                    int result = event_participants.insertStudent(student);
                    if (result == REPEATED_INSERT) {
                        throw AlreadyRegistered();
                    }
                }
            }
        }

        /**
         * clone
         * @return new identical event
         */
        CustomEvent *clone() const override
        {
            return new CustomEvent(*this);
        }
    };
}

#endif //EX302_CUSTOM_EVENT_H
