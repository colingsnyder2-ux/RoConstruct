// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no class headers were available. The target is a compiler-generated
// adjustor thunk (sub ecx,0xc4 ; jmp real vector-deleting dtor) for a
// secondary base with a virtual destructor located at offset 196 of
// FactoryProduct<Hat,Accoutrement,&sHat>. The layout below is a minimal guess.

namespace RBX {

extern const char* const sHat;

class Accoutrement {
public:
    Accoutrement() {}
    virtual ~Accoutrement() {}
    // INFERRED: pad so that the secondary base starts at offset 196 (vptr + 192)
    char pad[192];
};

class Hat : public Accoutrement {
public:
    Hat() {}
    virtual ~Hat() {}
};

// INFERRED: secondary polymorphic base placed after Hat at offset 196
class IFactoryBase {
public:
    IFactoryBase() {}
    virtual ~IFactoryBase() {}
};

template<class T, class Base, const char* const* Name>
class FactoryProduct : public T, public IFactoryBase {
public:
    FactoryProduct() {}
protected:
    virtual ~FactoryProduct() {}
};

const char* const sHat = "Hat";

template class FactoryProduct<Hat, Accoutrement, &sHat>;

} // namespace RBX
