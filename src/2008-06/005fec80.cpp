// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_espeon_touchconnectionsibling7a6e61bbb007f58a.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <boost/signals/slot.hpp>
#include <boost/signals/connection.hpp>
struct Instance;
typedef boost::slot<boost::function<void(boost::shared_ptr<Instance>)> > Slot;
struct EmitterPrimary {char padding[0x14];};struct SignalSource{int storage;};struct Emitter:EmitterPrimary,SignalSource {};
struct Event {boost::signals::connection connect(SignalSource*,const Slot&,int);};
extern Event event;
struct Primary {virtual void method();};struct VirtualBase {int unused;};
struct S:Primary,virtual VirtualBase {char padding[0x204-8];boost::signals::scoped_connection connection;Emitter*getHandle();void callback(boost::shared_ptr<Instance>);void f();};
void S::f(){if(Emitter*handle=getHandle()){connection=event.connect(handle,boost::bind(&S::callback,this,_1),10);}else connection.disconnect();}
