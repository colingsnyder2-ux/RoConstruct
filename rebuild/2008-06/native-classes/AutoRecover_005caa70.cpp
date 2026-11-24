// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no class headers were available, so this file builds a minimal
// stand-in class layout. The 0x14-byte adjustor thunk is not written by hand.
// The compiler should emit it (sub ecx,14h / jmp <vector deleting dtor>) when it
// builds the vftable of the secondary base at +0x14.
// The explicit instantiation below instantiates every member, including the
// constructor. That should make the compiler emit the vftables and their thunks.
// Not compiled or compared against the original bytes.

namespace RBX {

// INFERRED: Instance is 20 bytes (vptr + 16 bytes of data), so the next base starts at +0x14.
class Instance {
public:
    Instance() {}
    virtual ~Instance() {}
    int pad[4];
};

class ControllerService;

// INFERRED: the template argument sControllerService is a global `char*` (mangled 3PADA).
extern char* sControllerService;
char* sControllerService = 0;

// INFERRED: secondary base at +0x14 with a virtual destructor. Its vtable slot gets the
// adjustor{20} thunk to FactoryProduct's vector deleting destructor.
class DtorBase {
public:
    DtorBase() {}
protected:
    virtual ~DtorBase() {}
    int pad2;
};

template<class T, class Base, char*& name>
class FactoryProduct : public Base, public DtorBase {
public:
    FactoryProduct() {}
protected:
    virtual ~FactoryProduct() {}
};

template class FactoryProduct<ControllerService, Instance, sControllerService>;

}
