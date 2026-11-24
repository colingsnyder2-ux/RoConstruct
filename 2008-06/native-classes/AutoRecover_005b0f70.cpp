// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: the target is a compiler-generated adjustor{20} thunk for the vector
// deleting destructor (sub ecx,14h / jmp to the primary vector deleting destructor).
// Ordinary C++ cannot write such a thunk directly. Instead this file reproduces the
// class layout so the compiler emits the thunk itself: a primary polymorphic base of
// 0x14 bytes, then a secondary polymorphic base at offset 0x14. Accoutrement
// overrides the secondary base's virtual destructor.
// INFERRED: the real Accoutrement headers were not provided, so these base classes
// are stand-ins that only reproduce the layout.

namespace RBX {

class AccoutrementPrimaryBase {
public:
    virtual ~AccoutrementPrimaryBase() {}
    int pad[4];                 // vptr (4) + 16 = 0x14 bytes
};

class AccoutrementSecondaryBase {
public:
    virtual ~AccoutrementSecondaryBase() {}
    int data;
};

class Accoutrement : public AccoutrementPrimaryBase, public AccoutrementSecondaryBase {
public:
    Accoutrement();
    virtual ~Accoutrement();
    int extra;
};

// Defining the constructor makes the compiler emit the vftables and the
// adjustor{20} thunk.
Accoutrement::Accoutrement()
{
    extra = 0;
}

Accoutrement::~Accoutrement()
{
}

} // namespace RBX
