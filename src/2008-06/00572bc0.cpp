// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_serviceaddlisteneroffset174fb19dd5160504.cpp

// Candidate translation unit (score above; library headers required).
#include "v8tree/Service.h"
typedef std::vector<boost::shared_ptr<RBX::Instance> > Children;
typedef RBX::Listener<RBX::ServiceProvider,RBX::ServiceAdded> Listener;
struct Provider {virtual void onAddListener(Listener*)const;const Children* getChildren()const;void raise(RBX::ServiceAdded,Listener*)const;};
struct Prefix {virtual ~Prefix();const Children* children;char gap[0x44];};struct Complete:Prefix,Provider {};
inline const Children* Provider::getChildren()const{return *reinterpret_cast<const Children*const*>(reinterpret_cast<const char*>(this)-0x48);}
void Provider::onAddListener(Listener* listener)const{if(getChildren()){Children::const_iterator end=getChildren()->end();Children::const_iterator iter=getChildren()->begin();for(;iter!=end;iter++){if(dynamic_cast<RBX::Service*>(iter->get()))raise(RBX::ServiceAdded(iter->get()),listener);}}}
