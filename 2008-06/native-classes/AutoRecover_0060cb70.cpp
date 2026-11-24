// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no class headers were available, so minimal local stand-in classes
// are declared here. The disassembly stores the base-class vtable (0x8436bc)
// and calls operator delete when bit 0 of the flag is set. It has no array
// loop, so I write it by hand with an explicit non-virtual base destructor call.
// I did not compile this draft. The earlier version let the compiler generate
// the destructor, and that did not match.

#include <new>

namespace RBX {

// INFERRED: base class with a virtual destructor, whose vtable is at 0x8436bc.
class Contact {
public:
    Contact() {}
    virtual ~Contact() {}
};

class BallBallContact : public Contact {
public:
    BallBallContact() {}
    virtual ~BallBallContact() {}
};

} // namespace RBX

// INFERRED: __thiscall with one stack argument (ret 4), declared as __fastcall
// with a dummy edx per the naming convention for this target.
extern "C" void* __fastcall fn_0060cb70(RBX::BallBallContact* self, int unusedEdx, unsigned int flags)
{
    // The inlined base destructor stores the base vtable (0x8436bc).
    self->RBX::Contact::~Contact();
    if (flags & 1)
        ::operator delete((void*)self);
    return self;
}
