// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no class header was available. The target is the MSVC-generated
// adjustor thunk (sub ecx,14h; jmp MenuSpacer::`vector deleting destructor').
// I model it with a primary base of 20 bytes and a second polymorphic base at
// offset 20, so the compiler emits the {20} thunk when the vtable is built.

namespace RBX {

class PrimaryBase20 {
public:
    virtual ~PrimaryBase20() {}
private:
    char pad[16]; // vptr (4) + 16 = 20 bytes
};

class SecondaryBase {
public:
    virtual ~SecondaryBase() {}
};

class MenuSpacer : public PrimaryBase20, public SecondaryBase {
public:
    MenuSpacer();
    virtual ~MenuSpacer();
private:
    int dummy;
};

MenuSpacer::MenuSpacer() : dummy(0) {}

MenuSpacer::~MenuSpacer() {}

} // namespace RBX
