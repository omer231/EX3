#ifndef EX3_OPEN_EVENT_H
#define EX3_OPEN_EVENT_H

#include "base_event.h"

namespace mtm {
    class OpenEvent : public BaseEvent {
    public:
        OpenEvent(string name, DateWrap *date);

        void registerParticipant(int student) const override;

        BaseEvent * clone() const override;
    };
}

#endif //EX3_OPEN_EVENT_H
