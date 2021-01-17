#include "custom_event.h"

namespace mtm {

    template<typename CanRegister>
    CustomEvent<CanRegister>::CustomEvent(string name, DateWrap *date, CanRegister registerBool) :
            BaseEvent(name, date)
    {
        canRegister = registerBool;
    }

    template<typename CanRegister>
    void CustomEvent<CanRegister>::registerParticipant(int student) const
    {
        if (!canRegister(student)) {
            throw Exceptions::RegistrationBlocked();
        } else {
            int result = studentList->pqInsert(student);
            if (result == INVALID_INSERT) {
                throw Exceptions::InvalidStudent();
            }
            if (result == REPEATED_INSERT) {
                throw Exceptions::AlreadyRegistered();
            }
        }
    }

    template<typename CanRegister>
    BaseEvent *CustomEvent<CanRegister>::clone() const
    {
        auto *nDate = new DateWrap(*eventDate);
        string nName = eventName;
        auto *nStudentList = new PriorityQueue(*studentList);
        CanRegister can_register = new CanRegister;
        auto *nEvent = new CustomEvent<CanRegister>(nName, nDate, can_register);

        //POSSIBLE MEMORY LEAK FROM CUSTOM EVENT "DEFAULT" STUDENT LIST
        nEvent->studentList = nStudentList;
        return nEvent;
    }


}