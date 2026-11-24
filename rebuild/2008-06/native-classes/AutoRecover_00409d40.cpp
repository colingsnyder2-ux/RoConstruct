// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

namespace RBX {

// INFERRED: no class header was available, so these are minimal stand-ins.
// The target is the compiler-generated thunk
// `Instance::`vector deleting destructor'`adjustor{20}'.
// The compiler emits it when a secondary base with a virtual destructor sits
// at offset 20 inside Instance. The thunk does `sub ecx,14h` and then jumps to
// Instance's own vector deleting destructor.

// INFERRED: the primary base is 20 bytes (vfptr + 16 bytes) and has no
// virtual destructor.
class Base0 {
public:
    virtual void describe() {}
    int pad[4];
};

// INFERRED: the secondary base at offset 20 owns the virtual destructor that
// Instance overrides. Everything here is inline so that the unit contains
// only Instance's out-of-line members.
class Base1 {
public:
    virtual ~Base1() {}
    int x;
};

class Instance : public Base0, public Base1 {
public:
    Instance();
    virtual ~Instance();
    int y;
};

// Defining these out of line emits Instance's vftables and with them the
// adjustor{20} vector deleting destructor thunk.
Instance::Instance() : y(0) {}
Instance::~Instance() {}

}
