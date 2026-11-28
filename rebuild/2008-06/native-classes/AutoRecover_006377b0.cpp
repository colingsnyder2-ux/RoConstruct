// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "v8datamodel/Value.h"
#include <new>

// INFERRED: Constructor signature follows the observed argument and member-pointer layout.
// INFERRED: Exact code generation is unverified; supplied analog source was empty.
extern "C" RBX::Reflection::BoundProp<int, 1>* __fastcall fn_006377b0(
    RBX::Reflection::BoundProp<int, 1>* self,
    int unusedEdx,
    const char* name,
    const char* category,
    int RBX::Color3Value::* member,
    void (RBX::Color3Value::*changed)(const RBX::Reflection::PropertyDescriptor&),
    RBX::Reflection::PropertyDescriptor::Functionality flags)
{
    return new (self) RBX::Reflection::BoundProp<int, 1>(
        name, category, member, changed, flags);
}
