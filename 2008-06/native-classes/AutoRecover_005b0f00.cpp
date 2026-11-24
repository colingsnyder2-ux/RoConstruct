// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no class headers were available. The target is the compiler-generated
// adjustor{36} thunk for a secondary base subobject at offset 36 of RBX::Accoutrement:
//   sub ecx, 0x24
//   jmp <real vector deleting destructor>
// The class layout below is a minimal stand-in that makes the compiler emit that thunk.

namespace RBX {

// INFERRED: primary base occupying 36 bytes (vptr + 32 bytes of data).
class AccoutrementPrimaryBase {
public:
    int data[8];
    AccoutrementPrimaryBase() {}
    virtual ~AccoutrementPrimaryBase() {}
};

// INFERRED: secondary base with a virtual destructor, located at offset 36.
class AccoutrementSecondaryBase {
public:
    int more;
    AccoutrementSecondaryBase() : more(0) {}
    virtual ~AccoutrementSecondaryBase() {}
};

class Accoutrement : public AccoutrementPrimaryBase, public AccoutrementSecondaryBase {
public:
    Accoutrement() {}
    virtual ~Accoutrement() {}
};

// Forces the vtable, including the `vector deleting destructor'`adjustor{36}' thunk, to be emitted.
Accoutrement* makeAccoutrementForVtable()
{
    return new Accoutrement();
}

} // namespace RBX
