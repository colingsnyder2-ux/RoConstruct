// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lang: cpp
// roc-lib: rbxgs-net roc_unit_68b4596921dad51a.cpp

// Candidate translation unit (score above; library headers required).
#include "Streaming.h"
#include "reflection/property.h"
namespace RBX { namespace Network {
void IdSerializer::serializeRef(const Reflection::ConstProperty& property, RakNet::BitStream& bitStream)
{
    const Reflection::RefPropertyDescriptor& prop = static_cast<const Reflection::RefPropertyDescriptor&>(property.getDescriptor());
    typedef Reflection::DescribedBase* (__thiscall *GetRef)(const Reflection::RefPropertyDescriptor*, const Reflection::DescribedBase*);
    // Target dispatches getRefValue at vtable+0x30, then projects the DescribedBase subobject back by0x14.
    Reflection::DescribedBase* value = reinterpret_cast<GetRef const*>(*reinterpret_cast<void* const* const*>(&prop))[12](&prop, property.getInstance());
    serializeId(bitStream, value ? reinterpret_cast<Instance*>(reinterpret_cast<char*>(value) - 0x14) : 0);
}
} }
