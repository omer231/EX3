#ifndef EX302_FESTIVAL_H
#define EX302_FESTIVAL_H

#include "event_container.h"

namespace mtm {
    class Festival : public EventContainer {
        /**
         * festival_date - DateWrap with the festival date
         */
        DateWrap festival_date;
    public:
        /**
         * Festival Constructor
         * @param date festival_date - date
         */
        explicit Festival(DateWrap date);

        /**
         * Festival Destructor
         */
        ~Festival() override;

        /**
         * add
         * @param event event to attempt to insert in container
         *      (if event is on the same date as festival)
         */
        void add(const BaseEvent &event) override;
    };
}


#endif //EX302_FESTIVAL_H
