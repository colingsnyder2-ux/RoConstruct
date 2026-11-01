// from server: 100% by EspClaude
// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_ae18e994b19e57c1.cpp

// Candidate translation unit (score above; library headers required).
#define private public
#define protected public
#include <reflection/object.h>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <algorithm>
struct ExeDescribed{void*vtbl;const RBX::Reflection::ClassDescriptor*descriptor;const RBX::Reflection::ClassDescriptor&getDescriptor()const{return *descriptor;}RBX::Reflection::PropertyIterator properties_begin(){return getDescriptor().RBX::Reflection::PropertyContainer::members_begin(reinterpret_cast<RBX::Reflection::DescribedBase*>(this));}RBX::Reflection::PropertyIterator properties_end(){return getDescriptor().RBX::Reflection::PropertyContainer::members_end(reinterpret_cast<RBX::Reflection::DescribedBase*>(this));}};
struct Instance{char prefix[0x18];ExeDescribed described;char gap[0x48-0x18-sizeof(ExeDescribed)];Instance*parent;Instance*getParent()const{return parent;}boost::shared_ptr<Instance> shared_from_this();};
extern boost::shared_ptr<Instance> acquire(Instance*);
struct Record{void*service;boost::shared_ptr<Instance>object;int kind;boost::shared_ptr<Instance>parent;void capture(const RBX::Reflection::Property&);void captureAll();};
void Record::captureAll(){std::for_each(object->described.properties_begin(),object->described.properties_end(),boost::bind(&Record::capture,this,_1));parent=RBX::shared_from(object->getParent());kind=1;}
