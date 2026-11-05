// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_historystartnativee7064b3c8f23925a.cpp

// Candidate translation unit (score above; library headers required).
#include <list>
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <boost/signals/slot.hpp>
#include <boost/signals/connection.hpp>
struct Service;struct Descriptor;
struct Instance{template<class F>void visit(F);};
struct Records{char data[64];Records(Service*);};
typedef boost::shared_ptr<Instance> Shared;
template<class F>struct Signal{boost::signals::connection connect(void*,const boost::slot<boost::function<F> >&,int);};
extern Signal<void(Shared)>added,removed;extern Signal<void(Shared,const Descriptor*)>changed;
struct A{virtual ~A();};struct B{virtual ~B();};
struct Service:A,B{char prefix[0x128];Instance*context;Records*current;std::list<Records*>records;std::list<Records*>::iterator forward,backward;bool blocked,enabled;boost::signals::scoped_connection cAdded,cRemoved,cChanged;
virtual void f1();virtual void f2();virtual void f3();virtual void f4();virtual void f5();virtual void f6();virtual void f7();virtual void f8();virtual void f9();virtual void f10();virtual void f11();virtual void f12();virtual void f13();virtual void f14();virtual void f15();
virtual void onAdded(Shared);virtual void onRemoved(Shared);virtual void onChanged(Shared,const Descriptor*);void commit(const char*);void mergeFirst();void start();};
void Service::start(){current=new Records(this);forward=records.end();backward=records.begin();context->visit(boost::bind(&Service::onAdded,this,_1));if(enabled){commit("base");while(records.size()>1)mergeFirst();}cAdded=added.connect(context?(char*)context+0x14:0,boost::bind(&Service::onAdded,this,_1),10);cRemoved=removed.connect(context?(char*)context+0x14:0,boost::bind(&Service::onRemoved,this,_1),10);cChanged=changed.connect(context?(char*)context+0x14:0,boost::bind(&Service::onChanged,this,_1,_2),10);}
