#ifndef EX302_SCHEDULE_H
#define EX302_SCHEDULE_H
#include "base_event.h"
#include "closed_event.h"
#include "custom_event.h"
#include "date_wrap.h"
#include "event_container.h"
#include "exceptions.h"
#include "festival.h"
#include "one_time_event.h"
#include "open_event.h"
#include "recurring_event.h"
#include <cstdlib>
#include <iostream>
#include <list>
using std::cout;
using std::endl;
using std:: exception;
using namespace std;

namespace mtm 
{
   class Schedule{ 
   private:
   std::list<BaseEvent*> event_lst;
    public:
    //constructor
    Schedule();

    //destructor
    ~Schedule();
    
    /**
* addEvents: recives an EventContainer and adds copies of each event to the shedule 
*
* @return
* 		EventAlreadyExists exception if any of the events already exist in shedule
*/
    void addEvents(const EventContainer& event_container);

    /**
* registerToEvent: recives the date and name of the event and a student
then, it registers the student to the event 
*
* @return
* 		AlreadyRegistered exception if the student is already registered to the event
        RegistrationBlocked exception if the student is not allowed to register to the event
        EventNotDoesNotExist if the event does not exist in shedule
*/
    void registerToEvent(DateWrap date, std::string name, int student); 

     /**
* unregisterToEvent: recives the date and name of the event and a student
then, it unregisters the student to the event 
*
* @return
* 		NotRegistered exception if the student is already unregistered from the event
        EventNotDoesNotExist if the event does not exist in schedule
*/
    void unregisterFromEvent(DateWrap date, std::string name, int student); 

    /**
* printAllEvents: prints all the events in schedule
*/
    void printAllEvents() const;

/**
* printAllEvents: prints all the events in schedule that happen in the recived month and year
*/
    void printMonthEvents(int month, int year) const;

/**
* struct EventFilter for sorting the list of events
*/
    struct EventFilter: BaseEvent{
        bool operator()(const mtm::BaseEvent *event1, const mtm::BaseEvent *event2);
    };

/**
* printSomeEvents: recives a function and a boolean variable
the function prints every event for which the function returns true
the value of the boolean determines if the printed format of the event will be long or short
*/
    template <class Func> void printSomeEvents(Func func, bool verbose) const
    {
        std::list<BaseEvent*> event_filter_lst=event_lst;
        event_filter_lst.sort( []( const mtm::BaseEvent *event1, const mtm::BaseEvent *event2 ) { 
            if(event1->getEventDate()==event2->getEventDate()){
            return event1->getEventName()<event2->getEventName();
        }
        return event1->getEventDate()<event2->getEventDate();} );
       for (std::list<BaseEvent*>::const_iterator schedule_it = event_filter_lst.begin(); 
       schedule_it != event_filter_lst.end(); ++schedule_it){
            Func f;
            const mtm::BaseEvent* event = (*schedule_it);
            if(f(*event))
            {
                if(verbose)
                {
                   (*schedule_it)->printLong(std::cout);
                }
                else
                {
                  (*schedule_it)->printShort(std::cout);
                }
                cout << endl;
            }
        }
    }
    /**
* verbose is optional and therefore this implementation does nto require it
*/
    template <class Func> void printSomeEvents(Func func) const
    {
       printSomeEvents(func, false);
    }

    /**
* printEventDetails: recives a date and a string
the function prints the long description of the event that occurs in the recived date
and matches the recived name
the function throws a EventDoesNotExist if no event of that name occurs in the recived date
*/
    void printEventDetails( DateWrap date, std::string name) const;
   };
}
#endif