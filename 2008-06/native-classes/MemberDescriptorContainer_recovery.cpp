#include "reflection/reflection.h"
#include "reflection/property.h"

namespace RBX { namespace Reflection {
template void MemberDescriptorContainer<PropertyDescriptor>::mergeMembers(const MemberDescriptorContainer<PropertyDescriptor>*);
template void MemberDescriptorContainer<SignalDescriptor>::mergeMembers(const MemberDescriptorContainer<SignalDescriptor>*);
template void MemberDescriptorContainer<FunctionDescriptor>::mergeMembers(const MemberDescriptorContainer<FunctionDescriptor>*);
template MemberDescriptorContainer<PropertyDescriptor>::CollectionType::const_iterator MemberDescriptorContainer<PropertyDescriptor>::findDescriptor(const Name&) const;
}}
