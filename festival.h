#ifndef EX302_FESTIVAL_H
#define EX302_FESTIVAL_H

#include "event_container.h"

namespace mtm {
    class Festival : public EventContainer {
        DateWrap festivalDate;
    public:
        explicit Festival(DateWrap date);

        ~Festival() override;

        void add(const BaseEvent &event) override;
    };
}


#endif //EX302_FESTIVAL_H
