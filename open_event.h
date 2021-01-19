#ifndef EX302_OPEN_EVENT_H
#define EX302_OPEN_EVENT_H

#include "base_event.h"

namespace mtm {
    class OpenEvent : public BaseEvent {
    public:
        OpenEvent(DateWrap date, string name);

        ~OpenEvent() override;

        void registerParticipant(int student) override;

        OpenEvent *clone() const override;
    };
}

#endif //EX302_OPEN_EVENT_H
