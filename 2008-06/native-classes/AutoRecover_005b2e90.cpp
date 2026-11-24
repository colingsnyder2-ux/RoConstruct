// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no class headers were available, so the hierarchy below is a stand-in.
// The target is a compiler-generated `vector deleting destructor'`adjustor{20}' thunk:
//   sub ecx, 14h ; jmp DescribedCreatable<Hat,Accoutrement,&sHat>::`vector deleting destructor'
// It is emitted as an entry of the secondary vftable (subobject at offset 20) of
// DescribedCreatable<Hat,Accoutrement,&sHat>. The explicit instantiation below
// instantiates the (inline) constructor and destructor, which emits the vftables
// and therefore the adjustor thunk.

namespace RBX {

extern const char* const sHat;

class Hat;

// INFERRED: primary polymorphic base, vptr plus 16 bytes of data, so the next base is at offset 20.
struct PrimaryBase {
    virtual ~PrimaryBase() {}
    int pad[4];
};

// INFERRED: secondary polymorphic base at offset 20 with a virtual destructor.
struct SecondaryBase {
    virtual ~SecondaryBase() {}
    int pad2;
};

class Accoutrement : public PrimaryBase, public SecondaryBase {
public:
    Accoutrement() {}
    virtual ~Accoutrement() {}
};

template<class T, class Base, const char* const* Name>
class DescribedCreatable : public Base {
public:
    DescribedCreatable() {}
    virtual ~DescribedCreatable() {}
};

} // namespace RBX

// Explicit instantiation forces emission of the constructor, destructor, vftables and thunk.
template class RBX::DescribedCreatable<RBX::Hat, RBX::Accoutrement, &RBX::sHat>;
