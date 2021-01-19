#ifndef EX302_EXCEPTIONS_H
#define EX302_EXCEPTIONS_H
namespace mtm {
    class Exceptions : public std::exception {
    };

    //PART A
    class InvalidDate : public Exceptions {
    };

    class NegativeDays : public Exceptions {
    };

    //PART B
    class InvalidStudent : public Exceptions {
    };

    class AlreadyRegistered : public Exceptions {
    };

    class RegistrationBlocked : public Exceptions {
    };

    class NotRegistered : public Exceptions {
    };

    class AlreadyInvited : public Exceptions {
    };

    class DateMismatch : public Exceptions {
    };

    class InvalidNumber : public Exceptions {
    };

    class InvalidInterval : public Exceptions {
    };

    class NotSupported : public Exceptions {
    };

    //PART C
    class EventAlreadyExists : public Exceptions {
    };

    class EventDoesNotExist : public Exceptions {
    };
}
#endif //EX302_EXCEPTIONS_H
