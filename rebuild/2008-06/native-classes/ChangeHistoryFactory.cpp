// >>> native-status (generated) -- do not edit >>>
// ChangeHistoryFactory | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src 8cace1d5 | roc native-status --write
#include "v8datamodel/ChangeHistoryService.h"
namespace RBX {
template<> Reflection::ClassDescriptor& Reflection::Described<ChangeHistoryService, sChangeHistoryService,
    FactoryProduct<ChangeHistoryService, Instance, sChangeHistoryService> >::classDescriptor() {
    static Reflection::ClassDescriptor descriptor(Instance::classDescriptor(), "ChangeHistoryService");
    return descriptor;
}
template<class C, class D, const char* N> template<class A>
DescribedCreatable<C,D,N>::DescribedCreatable(A value) : Reflection::Described<C,N,FactoryProduct<C,D,N> >(value) {}
template DescribedCreatable<ChangeHistoryService,Instance,sChangeHistoryService>::DescribedCreatable(const char*);
}
