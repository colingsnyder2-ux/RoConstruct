// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 native rows of the reflection-metadata unit inside the application range 00440000..00444000 (inactive).
// Verified by tests/record_native_app_unit440.py. Every header is read-only here: reflection/Metadata.h (Reflection
// 0x134 with the Classes child at +0x130), v8tree/Instance.h (findFirstChildOfType, findFirstChildByName 00557950)
// and reflection/reflection.h (MemberDescriptor: name +4, owner +0xc).
//
// The original unit runs 00442f90..0044521f: askAddChild bodies, the FactoryProduct<Reflection> constructor and
// destructor, Classes::lookup 00443140, Reflection::lookup 00443210, the reflection descriptor instances of the
// metadata properties, findFirstChildOfType<C> 004436e0 / 00443780 / 00443820 / 004438c0 and the member lookups
// 00443ab0 / 00443b00 / 00443b50, then the MergeBinder rows and Reflection::load / singleton.
//
// This file adds what the committed Metadata*.cpp sources do not define:
//   * the member lookups Reflection::lookup(const PropertyDescriptor& / FunctionDescriptor& / SignalDescriptor&),
//     which reflection/Metadata.h declares: the owner class (descriptor.owner.name, +0xc then +4) is looked up in the
//     Classes child (+0x130), then its Properties / Functions / Events child (findFirstChildOfType), then the member
//     by its own name (+4). Each body is 73 bytes and ends in a tail call;
//   * the explicit instantiations of Instance::findFirstChildOfType<Classes / Properties / Functions / Events>, which
//     the original emits in this unit (the RTTI each one dynamic_casts to names the class).
#include "reflection/Metadata.h"
#include "reflection/reflection.h"

namespace RBX { namespace Metadata {

// The class lookup is Reflection::lookup(owner, false) 00443210 with Classes::lookup 00443140 inlined (the recorder
// compiles this file after the committed MetadataClassesLookup.cpp / MetadataReflectionLookup.cpp in one generated
// unit, as in the original): the classes == NULL branch materializes NULL before the shared test (xor eax, eax;
// test eax, eax), which a direct `classes ? classes->findFirstChildByName(...) : NULL` does not reproduce.
RBX::Reflection::Metadata::Member* Reflection::lookup(const RBX::Reflection::PropertyDescriptor& descriptor) const
{
    if (RBX::Reflection::Metadata::Class* item = lookup(descriptor.owner, false))
        if (RBX::Reflection::Metadata::Properties* members = item->findFirstChildOfType<RBX::Reflection::Metadata::Properties>())
            return static_cast<RBX::Reflection::Metadata::Member*>(members->findFirstChildByName(descriptor.name.toString()));
    return NULL;
}

RBX::Reflection::Metadata::Member* Reflection::lookup(const RBX::Reflection::FunctionDescriptor& descriptor) const
{
    if (RBX::Reflection::Metadata::Class* item = lookup(descriptor.owner, false))
        if (RBX::Reflection::Metadata::Functions* members = item->findFirstChildOfType<RBX::Reflection::Metadata::Functions>())
            return static_cast<RBX::Reflection::Metadata::Member*>(members->findFirstChildByName(descriptor.name.toString()));
    return NULL;
}

RBX::Reflection::Metadata::Member* Reflection::lookup(const RBX::Reflection::SignalDescriptor& descriptor) const
{
    if (RBX::Reflection::Metadata::Class* item = lookup(descriptor.owner, false))
        if (RBX::Reflection::Metadata::Events* members = item->findFirstChildOfType<RBX::Reflection::Metadata::Events>())
            return static_cast<RBX::Reflection::Metadata::Member*>(members->findFirstChildByName(descriptor.name.toString()));
    return NULL;
}

}} // namespace RBX::Metadata

template RBX::Reflection::Metadata::Classes* RBX::Instance::findFirstChildOfType<RBX::Reflection::Metadata::Classes>() const;
template RBX::Reflection::Metadata::Properties* RBX::Instance::findFirstChildOfType<RBX::Reflection::Metadata::Properties>() const;
template RBX::Reflection::Metadata::Functions* RBX::Instance::findFirstChildOfType<RBX::Reflection::Metadata::Functions>() const;
template RBX::Reflection::Metadata::Events* RBX::Instance::findFirstChildOfType<RBX::Reflection::Metadata::Events>() const;
