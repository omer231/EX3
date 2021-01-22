#ifndef EX302_CLOSED_EVENT_H
#define EX302_CLOSED_EVENT_H

#include "base_event.h"

namespace mtm {
    class ClosedEvent : public BaseEvent {
        IntList invited;
    public:
        ClosedEvent(DateWrap date, string name);

        //ClosedEvent(ClosedEvent const &closed_event);

        ~ClosedEvent() override;

        void addInvitee(int student);

        void registerParticipant(int student) override;

        ClosedEvent *clone() const override;
    };
}

#endif //EX302_CLOSED_EVENT_H
