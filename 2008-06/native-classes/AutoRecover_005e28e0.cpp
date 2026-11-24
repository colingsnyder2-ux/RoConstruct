// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "v8world/Joints2008.h"
#include "v8world/World2008.h"
#include "v8kernel/Kernel.h"

// INFERRED: RotateJoint::removeFromKernel is private in the headers, so it cannot be
// called from a free function. The same code at 0x645ad0 is reached through the
// fixed-name extern "C" helper instead. The declaration takes only the object
// pointer, so the compiler does not materialise an edx value before the call.
extern "C" void __fastcall fn_00645ad0(void* self);

// INFERRED: RotateVJoint has no user-declared destructor in the available
// headers, so its compiler-generated vector deleting destructor cannot be
// defined as a class member. It is written as a free function with the
// fixed naming convention instead.
// Body: call the base teardown (0x645ad0), then operator delete(this) if
// (flags & 1), then return this.
extern "C" void* __fastcall fn_005e28e0(RBX::RotateVJoint* self, int unusedEdx, unsigned int flags)
{
    fn_00645ad0((void*)self);
    if (flags & 1)
        operator delete((void*)self);
    return self;
}
