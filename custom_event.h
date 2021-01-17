#ifndef EX3_CUSTOM_EVENT_H
#define EX3_CUSTOM_EVENT_H

#include "base_event.h"

namespace mtm {
    template<typename CanRegister>
    class CustomEvent : public BaseEvent {
    protected:
        CanRegister canRegister;
    public:
        CustomEvent(string name, DateWrap *date, CanRegister registerBool);

        void registerParticipant(int student) const override;

        BaseEvent *clone() const override;
    };
}

#endif //EX3_CUSTOM_EVENT_H
