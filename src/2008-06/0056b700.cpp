// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_member_registry_native_family_2f6c824474218c1a.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("util/Name.h", "../roc_member_name_const_header_435e0dbf905df038.cpp")
#pragma include_alias("reflection/member.h", "../roc_member_registry_native_header_9d65f5dc84cdc322.cpp")
#undef _RELEASEASSERT
#include "reflection/object.h"
template void RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::PropertyDescriptor>::declare(RBX::Reflection::PropertyDescriptor*);
template void RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::SignalDescriptor>::declare(RBX::Reflection::SignalDescriptor*);
template void RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::FunctionDescriptor>::declare(RBX::Reflection::FunctionDescriptor*);
