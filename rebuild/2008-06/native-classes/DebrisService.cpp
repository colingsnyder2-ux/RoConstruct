#include "v8datamodel/DebrisService.h"
#include "util/standardout.h"

// Donor helper; target 0063b5c0 (native-asm inspection 2026-11-04).
static void cleanup(boost::weak_ptr<RBX::Instance> item)
{
    try {
        boost::shared_ptr<RBX::Instance> i = item.lock();
        if (i) i->setParent(NULL);
    }
    catch (std::exception& e) {
        RBX::StandardOut::singleton()->print(RBX::MESSAGE_WARNING, e);
    }
}
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

namespace RBX {
void DebrisService::cleanup()
{
    while ((int)queue.size() > maxItems) {
        ::cleanup(queue.front());
        queue.pop();
    }
}
void DebrisService::onServiceProvider(const ServiceProvider*, const ServiceProvider* newProvider)
{
    while ((int)queue.size() > 0) {
        ::cleanup(queue.front());
        queue.pop();
    }
    // 0063c280 has no Instance::onServiceProvider call.
    timer = ServiceProvider::create<TimerService>(newProvider);
}
}
