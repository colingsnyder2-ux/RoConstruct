// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no class headers were available, so this is a minimal layout model.
// Accoutrement has a primary polymorphic base of 0x130 bytes and a second
// polymorphic base at offset 0x130 (304). FactoryProduct<Hat,Accoutrement,&sHat>
// derives from Accoutrement and overrides the virtual destructor (protected,
// per the 'O' access code in the mangled thunk name). The compiler emits the
// `vector deleting destructor'`adjustor{304}' thunk (sub ecx,0x130; jmp) for
// the secondary vtable.

namespace RBX {

extern const char* const sHat;

// INFERRED: primary base, 0x130 bytes including its vptr
struct AccPrimary {
    virtual ~AccPrimary() {}
    char pad[0x12C];
};

// INFERRED: secondary base at offset 0x130 with a virtual destructor
struct AccSecondary {
    virtual ~AccSecondary() {}
};

class Accoutrement : public AccPrimary, public AccSecondary {
public:
    virtual ~Accoutrement() {}
};

class Hat;

template<class T, class Base, const char* const* Name>
class FactoryProduct : public Base {
public:
    FactoryProduct() {}
    static FactoryProduct* create() { return new FactoryProduct; }
protected:
    virtual ~FactoryProduct() {}
};

}

const char* const RBX::sHat = "Hat";

// Forces emission of the vftables (and hence the adjustor{304} thunk).
void* createHatForVtable()
{
    return RBX::FactoryProduct<RBX::Hat, RBX::Accoutrement, &RBX::sHat>::create();
}
