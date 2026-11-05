// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_historycaptureparentgetterb0184755a4b4368c.cpp

// Candidate translation unit (score above; library headers required).
#define private public
#define protected public
#include <reflection/object.h>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <algorithm>
struct Instance{char prefix[0x14];RBX::Reflection::DescribedBase described;char gap[0x104-0x14-sizeof(RBX::Reflection::DescribedBase)];Instance*parent;Instance*getParent()const{return parent;}boost::shared_ptr<Instance> shared_from_this();};
extern boost::shared_ptr<Instance> acquire(Instance*);
struct Record{void*service;boost::shared_ptr<Instance>object;int kind;boost::shared_ptr<Instance>parent;void capture(const RBX::Reflection::Property&);void captureAll();};
void Record::captureAll(){std::for_each(object->described.properties_begin(),object->described.properties_end(),boost::bind(&Record::capture,this,_1));parent=RBX::shared_from(object->getParent());kind=1;}
