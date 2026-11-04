#include "v8datamodel/DebrisService.h"
namespace RBX {
char sDebrisService[] = "Debris";
template<> Reflection::ClassDescriptor& Reflection::Described<DebrisService, sDebrisService,
    FactoryProduct<DebrisService, Instance, sDebrisService> >::classDescriptor() {
    static Reflection::ClassDescriptor descriptor(Instance::classDescriptor(), "Debris");
    return descriptor;
}

// The argument-forwarding FactoryProduct constructor is defined in util/Object.h.
template FactoryProduct<DebrisService,Instance,sDebrisService>::FactoryProduct(const char*);

template<class C,class D,const char* N> FactoryProduct<C,D,N>::FactoryProduct():D() {}
template<class C,class D,const char* N> const Name& FactoryProduct<C,D,N>::className() { return Name::declare<N>(); }
template<class C,class D,const char* N> const Name& FactoryProduct<C,D,N>::getClassName() const { return className(); }
template<class C,class D,const char* N> DescribedCreatable<C,D,N>::DescribedCreatable():Reflection::Described<C,N,FactoryProduct<C,D,N> >() {}
template<class C,class D,const char* N> template<class A>
DescribedCreatable<C,D,N>::DescribedCreatable(A value):Reflection::Described<C,N,FactoryProduct<C,D,N> >(value) {}

template DescribedCreatable<DebrisService,Instance,sDebrisService>::DescribedCreatable(const char*);

DebrisService::DebrisService():DescribedCreatable<DebrisService,Instance,sDebrisService>("Debris"),maxItems(300),timer(0) {}
}
