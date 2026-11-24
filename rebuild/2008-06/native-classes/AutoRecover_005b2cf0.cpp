// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no headers were provided, so the class layout below is a stand-in.
// The target is a compiler-generated adjustor thunk: sub ecx,0x44 then jmp to the vector deleting dtor.
// It is emitted for the secondary-base vtable slot at offset 68 of
// DescribedCreatable<Hat, Accoutrement, &sHat>.
// The mangled name "$1?sHat@2@3QBDB" is the address of RBX::sHat (const char* const).

namespace RBX {

extern const char* const sHat;

// INFERRED: first polymorphic base, vptr + 64 bytes = 68 bytes
class AccPrimary {
public:
    char data[64];
    AccPrimary() {}
    virtual ~AccPrimary() {}
};

// INFERRED: second polymorphic base, placed at offset 68
class AccSecondary {
public:
    int d;
    AccSecondary() : d(0) {}
    virtual ~AccSecondary() {}
};

class Accoutrement : public AccPrimary, public AccSecondary {
public:
    Accoutrement() {}
    virtual ~Accoutrement() {}
};

class Hat;

template<class T, class Base, const char* const* name>
class DescribedCreatable : public Base {
public:
    DescribedCreatable() {}
    virtual ~DescribedCreatable() {}
};

class Hat : public DescribedCreatable<Hat, Accoutrement, &sHat> {
public:
    Hat() {}
};

// Explicit instantiation emits the vector deleting destructor and its adjustor{68} thunk.
template class DescribedCreatable<Hat, Accoutrement, &sHat>;

} // namespace RBX
