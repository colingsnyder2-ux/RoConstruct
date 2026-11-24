// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no class header was available, so both classes below are guesses.
// The target stores one vtable pointer (0x83d1f4) and then calls operator delete
// only if bit 0 of the flags is set. It has no array-delete loop, so it is the
// usual MSVC vtable-slot `vector deleting destructor` for a class whose
// destructors are trivial apart from the vptr reset.
namespace RBX {

class Connector {
public:
    Connector() {}
    virtual ~Connector() {}
    virtual void step() {}
};

class ContactConnector : public Connector {
public:
    ContactConnector();
    // INFERRED: implicit destructor (virtual via base); the vptr reset folds
    // down to the single store of the base vtable.
    virtual void step();
};

// INFERRED: out-of-line constructor anchors emission of the vtable and of
// ??_EContactConnector@RBX@@UAEPAXI@Z in this unit.
ContactConnector::ContactConnector() {}

void ContactConnector::step() {}

} // namespace RBX
