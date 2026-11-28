// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "v8datamodel/Value.h"
#include <new>

// INFERRED: The supplied analog is empty. This draft is unverified and does
// not establish byte-exact code generation.
extern "C" RBX::Reflection::BoundProp<std::string, 1>* __fastcall
fn_00637540(
    RBX::Reflection::BoundProp<std::string, 1>* self,
    int unusedEdx,
    const char* name,
    const char* category,
    int member,
    int changed,
    int changedAdjustment,
    RBX::Reflection::PropertyDescriptor::Functionality flags)
{
    typedef RBX::StringValue Value;
    typedef std::string Value::* Member;
    typedef void (Value::*Changed)(const RBX::Reflection::PropertyDescriptor&);

    __assume(self != 0);
    return new (self) RBX::Reflection::BoundProp<std::string, 1>(
        name, category, *reinterpret_cast<Member*>(&member),
        *reinterpret_cast<Changed*>(&changed), flags);
}
