#ifndef EX3_CLOSED_EVENT_H
#define EX3_CLOSED_EVENT_H

#include "base_event.h"

namespace mtm {
    class ClosedEvent : public BaseEvent {
    protected:
        PriorityQueue *invited;
    public:
        ClosedEvent(string name, DateWrap *date);

        void addInvitee(int student);

        void registerParticipant(int student) const override;

        BaseEvent *clone() const override;
    };
}

#endif //EX3_CLOSED_EVENT_H
