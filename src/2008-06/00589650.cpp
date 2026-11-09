// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_historyupdatenativegetter84b03300b09671ad.cpp

// Candidate translation unit (score above; library headers required).
#define private public
#define protected public
#include <reflection/object.h>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <algorithm>
struct Instance{char prefix[0x14];RBX::Reflection::DescribedBase described;char gap[0x104-0x14-sizeof(RBX::Reflection::DescribedBase)];Instance*parent;Instance*getParent()const{return parent;}boost::shared_ptr<Instance> shared_from_this();};
extern boost::shared_ptr<Instance> acquire(Instance*);
struct Record{void*service;boost::shared_ptr<Instance>object;int kind;boost::shared_ptr<Instance>parent;void capture(const RBX::Reflection::Property&);void captureAll();void notify(const void*);void update(const void*);};
void Record::captureAll(){std::for_each(object->described.properties_begin(),object->described.properties_end(),boost::bind(&Record::capture,this,_1));parent=RBX::shared_from(object->getParent());kind=1;}

extern char parentProperty;
void Record::update(const void*key){notify(key);if(kind!=1){kind=2;return;}if(key==&parentProperty)parent=RBX::shared_from(object->getParent());}
