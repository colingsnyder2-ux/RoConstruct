// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_timeoutnativememberpragmab71776252c466022.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
#include <boost/scoped_ptr.hpp>
#include <boost/function.hpp>
#include <boost/bind.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/condition.hpp>
#include <boost/thread/thread.hpp>
#pragma pointers_to_members(full_generality, multiple_inheritance)
struct ScriptContext;
extern boost::shared_ptr<ScriptContext> getReference(ScriptContext*);
extern boost::function0<void> nameTask(const boost::function0<void>&,const char*,int);
extern double clockSeconds();
extern void interruptTask(void*);
extern void setInterrupt(void*,void (*)(void*),int,int);
struct ScriptContext {
 char pad0[0x138];void* state;char pad13c[0x7c];double timeout;double deadline;
 char pad1c8[4];boost::scoped_ptr<boost::thread> thread;boost::mutex mutex;boost::condition event;
 void timeoutTask();void setTimeout(double);
};
void ScriptContext::setTimeout(double value) {
 boost::mutex::scoped_lock guard(mutex);
 timeout=value;
 deadline=value!=0.0?clockSeconds()+timeout:0.0;
 if(timeout!=0.0) {
  if(!thread) {
   thread.reset(new boost::thread(nameTask(boost::bind(&ScriptContext::timeoutTask,getReference(this)),"ScriptContext Timeout",0)));
   if(state) setInterrupt(state,interruptTask,8,1000);
  } else event.notify_all();
 }
}
