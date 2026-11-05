// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_flagstandservicelocalaa4966d7c1be1498.cpp

// Candidate translation unit (score above; library headers required).
#define private public
#define protected public
#include <v8datamodel/FlagStand.h>
#include <boost/bind.hpp>
#include <boost/function.hpp>
struct Provider {RBX::FlagStandService* get()const;};
static RBX::FlagStandService* findService(const RBX::ServiceProvider* p){return p?reinterpret_cast<const Provider*>(p)->get():0;}
struct Dispatcher{boost::signals::connection connect(void*,const boost::slot<boost::function<void(boost::shared_ptr<RBX::Instance>)> >&,int);};
extern Dispatcher dispatcher;
void RBX::FlagStand::onServiceProvider(const ServiceProvider* oldProvider,const ServiceProvider* newProvider){
 if(!oldProvider){FlagStandService* service=findService(newProvider);(*reinterpret_cast<std::list<FlagStand*>*>(reinterpret_cast<char*>(service)+0x130)).push_back(this);(*reinterpret_cast<boost::signals::scoped_connection*>(reinterpret_cast<char*>(this)+0x3e8))=dispatcher.connect(this?reinterpret_cast<char*>(this)+0x14:0,boost::bind(&FlagStand::onEvent_standTouched,this,_1),10);}
 if(!newProvider){FlagStandService* service=findService(oldProvider);(*reinterpret_cast<std::list<FlagStand*>*>(reinterpret_cast<char*>(service)+0x130)).remove(this);(*reinterpret_cast<boost::signals::scoped_connection*>(reinterpret_cast<char*>(this)+0x3e8)).disconnect();}
}
