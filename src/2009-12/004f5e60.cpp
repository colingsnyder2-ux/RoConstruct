// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_service_debris_native_08bb5b501c1290e0.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("util/Name.h", "../roc_name_native_declare_header_cb8db0995b353ca7.cpp")
#pragma include_alias("v8tree/Instance.h", "../roc_unit_b34763c2f3d3f398.cpp")
#pragma include_alias("v8tree/Service.h", "../roc_service_native_const_header_8a80459f3e46bdc7.cpp")
#undef _RELEASEASSERT
#include <boost/thread/once.hpp>
#include "v8datamodel/DebrisService.h"
namespace RBX {
// The native factory is a separate call. This unit does not compile its allocation or claim DebrisService layout.
template<> template<> boost::shared_ptr<DebrisService> Creatable<Instance>::create<DebrisService>();
const char* sDebrisService = "Debris";

template<typename Class, typename DerivedClass, const char** ClassName>
const Name& FactoryProduct<Class,DerivedClass,ClassName>::className() { return Name::declare<ClassName>(); }
template<typename DerivedClass, const char** ClassName>
const Name& NonFactoryProduct<DerivedClass,ClassName>::className() { return Name::declare<ClassName>(); }

template<typename Class> size_t ServiceProvider::doGetClassIndex() { static size_t index=newIndex(); return index; }
template<typename Class> void ServiceProvider::callDoGetClassIndex() { doGetClassIndex<Class>(); }
template<typename Class> size_t ServiceProvider::getClassIndex() {
 static boost::once_flag flag=BOOST_ONCE_INIT;
 boost::call_once(&callDoGetClassIndex<Class>,flag);
 return doGetClassIndex<Class>();
}
template<typename Class> Class* ServiceProvider::find() const {
 size_t index=getClassIndex<Class>();
 Class* service;
 if(index+1>serviceArray.size()) {
  serviceArray.resize(index+1,boost::shared_ptr<Instance>());
  service=NULL;
 } else {
  service=static_cast<Class*>(serviceArray[index].get());
  if(service!=NULL) return service;
 }
 boost::shared_ptr<Instance> i=findServiceByClassName(Class::className());
 if(!i) return NULL;
 service=static_cast<Class*>(i.get());
 serviceArray[index]=i;
 return service;
}
template<typename Class> Class* ServiceProvider::create() const {
 Class* service=this->find<Class>();
 if(service==NULL) {
  boost::shared_ptr<Class> s=Creatable<Instance>::create<Class>();
  service=s.get();
  size_t index=getClassIndex<Class>();
  serviceArray[index]=s;
  service->setParent(const_cast<ServiceProvider*>(this));
 }
 return service;
}
template DebrisService* ServiceProvider::find<DebrisService>() const;
template DebrisService* ServiceProvider::create<DebrisService>() const;
}
