#ifndef EX3_EXCEPTIONS_H
#define EX3_EXCEPTIONS_H
using std::exception;

namespace mtm {
    namespace Exceptions {
        //PART A
        class InvalidDate {
        };

        class NegativeDays {
        };

        //PART B
        class InvalidStudent {
        };

        class AlreadyRegistered {
        };

        class RegistrationBlocked {
        };

        class NotRegistered {
        };

        class AlreadyInvited {
        };

        class DateMismatch {
        };

        class InvalidNumber {
        };

        class InvalidInterval {
        };

        class NotSupported {
        };

        //PART C
        class EventAlreadyExists {
        };

        class EventDoesNotExist {
        };
    }
}

#endif //EX3_EXCEPTIONS_H
