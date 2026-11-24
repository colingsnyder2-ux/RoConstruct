// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no headers were provided for this class. The target is a compiler-generated
// `vector deleting destructor'`adjustor{16}' thunk (sub ecx,16 ; jmp real vdtor).
// It cannot be written by hand, so this declares a layout whose virtual destructor
// overrides a secondary-base virtual destructor at offset 16, and the compiler then
// emits the thunk itself. The base names and sizes are guesses.

namespace RBX {

namespace Network {
    // Mangled as ?sPlayer@Network@RBX@@3PADA, i.e. a plain char*.
    extern char* sPlayer;
}

// INFERRED: primary base, 16 bytes (vptr + 3 dwords)
class Instance {
public:
    int pad0, pad1, pad2;
    Instance() : pad0(0), pad1(0), pad2(0) {}
    virtual ~Instance() {}
    virtual void instanceVirtual() {}
};

// INFERRED: secondary base at offset 16 with its own virtual destructor
class SecondaryBase {
public:
    SecondaryBase() {}
    virtual ~SecondaryBase() {}
    virtual void secondaryVirtual() {}
};

namespace Network {
    class Player : public Instance, public SecondaryBase {
    public:
        Player() {}
        virtual ~Player() {}
    };
}

// INFERRED: the third template parameter is a pointer to the name variable (char**),
// matching the $1?sPlayer@23@3PADA mangling.
template<class T, class Base, char** name>
class FactoryProduct : public T {
public:
    FactoryProduct() {}
protected:
    virtual ~FactoryProduct() {}
};

// Explicit instantiation emits the vtable and the adjustor{16} thunk at 0x00492850.
template class FactoryProduct<Network::Player, Instance, &Network::sPlayer>;

} // namespace RBX
