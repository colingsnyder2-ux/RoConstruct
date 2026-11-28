// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "reflection/property.h"

extern "C" int __fastcall fn_004ad060(void*, int);
extern "C" float __fastcall fn_004ad0c0(void*, int);
extern "C" double __fastcall fn_004adc90(void*, int);
extern "C" void fn_00612220(void*, int);
extern "C" void fn_006123f0(void*, int);
extern "C" void fn_00612200(void*, double);

// INFERRED: Partial recovery; not byte-exact. The original uses ESI for
// the Lua state, and the remaining branches are unresolved.
extern "C" void fn_0061abe0(RBX::Reflection::ConstProperty p, void* state)
{
    using RBX::Reflection::Type;

    if (&p.getDescriptor().type == &Type::singleton<int>())
    {
        fn_00612220(state, fn_004ad060(&p, 0));
        return;
    }
    if (&p.getDescriptor().type == &Type::singleton<bool>())
    {
        fn_006123f0(state, p.getValue<bool>());
        return;
    }
    if (&p.getDescriptor().type == &Type::singleton<float>())
    {
        fn_00612200(state, fn_004ad0c0(&p, 0));
        return;
    }
    if (&p.getDescriptor().type == &Type::singleton<double>())
    {
        fn_00612200(state, fn_004adc90(&p, 0));
        return;
    }
}
