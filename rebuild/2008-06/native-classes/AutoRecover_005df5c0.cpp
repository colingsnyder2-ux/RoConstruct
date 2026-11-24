// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no headers were shown, so the types below are minimal local stand-ins.
// The vtable stores in the disassembly (0x83dbe4 and the rest) are compiler-generated
// from the real Instance layout. A single call to Instance::Instance() plus those stores
// is what this constructor body reproduces.

namespace RBX {

class Script;
extern char* sScript;

// INFERRED: stand-in for the real RBX::Instance; the real one has several vtable subobjects.
class Instance {
public:
    Instance();
    virtual ~Instance() {}
};

template<class T, class Base, char** Name>
class FactoryProduct : public Base {
protected:
    FactoryProduct() : Base() {}
};

} // namespace RBX

// Force emission of the constructor for this instantiation.
template RBX::FactoryProduct<RBX::Script, RBX::Instance, &RBX::sScript>::FactoryProduct();
