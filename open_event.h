#ifndef EX302_OPEN_EVENT_H
#define EX302_OPEN_EVENT_H

#include "base_event.h"

namespace mtm {
    class OpenEvent : public BaseEvent {
    public:
        /**
         * OpenEvent Constructor
         * @param date event_date - date
         * @param name event_name - name
         *             event_participants - empty list
         */
        OpenEvent(DateWrap date, string name);

        /**
         * OpenEvent Copy Constructor
         * @param open_event
         */
        OpenEvent(OpenEvent const &open_event);

        /**
         * OpenEvent Destructor
         */
        ~OpenEvent() override;

        /**
         * registerParticipant
         * @param student student to attempt to insert in event_participants
         *      (if valid id, if not already registered)
         */
        void registerParticipant(int student) override;

        /**
         * clone
         * @return new identical event
         */
        OpenEvent *clone() const override;
    };
}

#endif //EX302_OPEN_EVENT_H
