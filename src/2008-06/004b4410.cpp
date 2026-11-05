// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.35.0-dll roc_espeon_humanoidstateslotff087c81fef193c1.cpp

// Candidate translation unit (score above; library headers required).
#define NDEBUG
#include <boost/function.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/signals/slot.hpp>
struct Instance;
struct BaseA{virtual void a();};struct BaseB{virtual void b();};
struct State:BaseA,BaseB{void callback(boost::shared_ptr<Instance>);};
typedef boost::slot<boost::function<void(boost::shared_ptr<Instance>)> > Slot;
void bindState(State* state,Slot* output){new(output)Slot(boost::bind(&State::callback,state,_1));}
