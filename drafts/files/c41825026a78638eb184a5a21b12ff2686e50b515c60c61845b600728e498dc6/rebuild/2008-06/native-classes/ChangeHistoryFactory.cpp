#include "v8datamodel/ChangeHistoryService.h"
namespace RBX {
template<> Reflection::ClassDescriptor& Reflection::Described<ChangeHistoryService, sChangeHistoryService,
    FactoryProduct<ChangeHistoryService, Instance, sChangeHistoryService> >::classDescriptor() {
    static Reflection::ClassDescriptor descriptor(Instance::classDescriptor(), "ChangeHistoryService");
    return descriptor;
}
// The DescribedCreatable(Arg0Type) template body is defined inline in reflection/reflection.h.
template DescribedCreatable<ChangeHistoryService,Instance,sChangeHistoryService>::DescribedCreatable(const char*);
}
