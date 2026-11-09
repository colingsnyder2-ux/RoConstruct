// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_timerreversecomparison1758a4a34986db57.cpp

// Candidate translation unit (score above; library headers required).
#include <list>
#include <boost/function.hpp>
extern double __cdecl timer_now();
struct Value {double time; boost::function<void()> callback;};
struct Service {char padding[316];std::list<Value> timers;void schedule(boost::function<void()> callback,double delay);};
void Service::schedule(boost::function<void()> callback,double delay) {
 Value value;value.time=timer_now()+delay;value.callback=callback;
 for(std::list<Value>::iterator i=timers.begin();i!=timers.end();++i) {
  if(i->time>value.time) {timers.insert(i,value);goto finished;}
 }
 timers.push_back(value);
finished:;
}
