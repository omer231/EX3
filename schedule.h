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
    Schedule();
    ~Schedule();
    void addEvents(const EventContainer& event_container);
    void registerToEvent(DateWrap date, std::string name, int student); 
    void unregisterFromEvent(DateWrap date, std::string name, int student); 
    void printAllEvents() const;
    void printMonthEvents(int month, int year) const;

    struct EventFilter: BaseEvent{
        bool operator()(const mtm::BaseEvent *event1, const mtm::BaseEvent *event2);
    };
    template <class Func> void printSomeEvents(Func func, bool verbose) const
    {
        std::list<BaseEvent*> event_filter_lst=event_lst;
        event_filter_lst.sort( []( const mtm::BaseEvent *event1, const mtm::BaseEvent *event2 ) { 
            if(event1->getEventDate()==event2->getEventDate()){
            return event1->getEventName()<event2->getEventName();
        }
        return event1->getEventDate()<event2->getEventDate();} );
       for (std::list<BaseEvent*>::const_iterator schedule_it = event_filter_lst.begin(); schedule_it != event_filter_lst.end(); ++schedule_it){
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
    template <class Func> void printSomeEvents(Func func) const
    {
       for (std::list<BaseEvent*>::const_iterator schedule_it = event_lst.begin(); schedule_it != event_lst.end(); ++schedule_it){
            Func f;
            const mtm::BaseEvent* event = (*schedule_it);
            if(f(*event))
            {
                (*schedule_it)->printLong(std::cout);
                cout << endl;
            }
        }
    }
    void printEventDetails( DateWrap date, std::string name) const;
   };
}
#endif