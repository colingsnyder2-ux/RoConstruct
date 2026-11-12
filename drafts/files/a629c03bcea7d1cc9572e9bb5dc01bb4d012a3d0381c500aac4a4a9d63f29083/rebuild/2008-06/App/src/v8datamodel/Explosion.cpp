#include "v8datamodel/Explosion.h"
namespace RBX {
char sExplosion[] = "Explosion";
template<class C,class D,const char* N> FactoryProduct<C,D,N>::FactoryProduct():D() {}
template<class C,class D,const char* N> const Name& FactoryProduct<C,D,N>::className() { return Name::declare<N>(); }
template<class C,class D,const char* N> const Name& FactoryProduct<C,D,N>::getClassName() const { return className(); }
template<class C,class D,const char* N> DescribedCreatable<C,D,N>::DescribedCreatable():Reflection::Described<C,N,FactoryProduct<C,D,N> >() {}
Explosion::Explosion():blastRadius(4.0f),blastPressure(500000.0f),age(0.0f) { setName("Explosion"); }

// 0062b030: attach/detach the Stepped listener through each provider's RunService (Notifier +0x150).
void Explosion::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider)
{
	Notifier<RunService, Stepped>::disconnect(ServiceProvider::find<RunService>(oldProvider), dynamic_cast<Listener<RunService, Stepped>*>(this));
	Notifier<RunService, Stepped>::connect(ServiceProvider::find<RunService>(newProvider), dynamic_cast<Listener<RunService, Stepped>*>(this));
}
}
