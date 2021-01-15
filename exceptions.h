#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_

#include <iostream>
using std::cout;
using std::endl;
using namespace std;

namespace mtm 
{ 
    struct NegativeDays : public std::exception{};
}

#endif //EXCEPTIONS_H_