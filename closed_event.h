#ifndef EX302_CLOSED_EVENT_H
#define EX302_CLOSED_EVENT_H

#include "base_event.h"

namespace mtm {
    class ClosedEvent : public BaseEvent {
        /**
         * invited - IntList with the invited students
         */
        IntList invited;
    public:
        /**
         * ClosedEvent Constructor
         * @param date event_date - date
         * @param name event_name - name
         *             event_participants - empty list
         *             invited - empty_list
         */
        ClosedEvent(DateWrap date, string name);

        /**
         * ClosedEvent Destructor
         */
        ~ClosedEvent() override;

        /**
         * addInvitee
         * @param student student to attempt to add the invited list
         *      (if valid id, not already in list)
         */
        void addInvitee(int student);

        /**
         * registerParticipant
         * @param student student to attempt to insert in event_participants
         *      (if valid id, if in invited list, if not already registered)
         */
        void registerParticipant(int student) override;

        /**
         * clone
         * @return new identical event
         */
        ClosedEvent *clone() const override;
    };
}

#endif //EX302_CLOSED_EVENT_H
