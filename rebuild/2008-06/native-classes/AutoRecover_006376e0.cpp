// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "v8datamodel/Value.h"
#include <new>

// INFERRED: Argument types follow the native BoundProp constructor.
// INFERRED: Byte-exact code generation remains unverified.
extern "C" RBX::Reflection::BoundProp<G3D::CoordinateFrame, 1>* __fastcall
fn_006376e0(
    RBX::Reflection::BoundProp<G3D::CoordinateFrame, 1>* self,
    int unusedEdx,
    const char* name,
    const char* category,
    G3D::CoordinateFrame RBX::CFrameValue::*member,
    void (RBX::CFrameValue::*changed)(const RBX::Reflection::PropertyDescriptor&),
    RBX::Reflection::PropertyDescriptor::Functionality flags)
{
    __assume(self != 0);
    return new (self) RBX::Reflection::BoundProp<G3D::CoordinateFrame, 1>(
        name, category, member, changed, flags);
}
