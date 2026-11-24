// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no class headers were provided, so the layout is reconstructed.
// The target is a compiler-generated adjustor thunk: sub ecx,0x288 followed by
// a jmp to Workspace::`vector deleting destructor'. The compiler emits it
// because a secondary base at offset 648 has a virtual destructor that
// Workspace overrides. Defining Workspace with that layout and a virtual
// destructor makes the compiler emit the thunk. The constructor is only
// there to force the vtable to be emitted.

namespace RBX {

// INFERRED: primary base, 648 bytes in total (vptr plus 644 bytes of data).
class WorkspacePrimaryBase {
public:
    virtual ~WorkspacePrimaryBase() {}
    char pad[644];
};

// INFERRED: secondary base placed at offset 0x288 (648).
class WorkspaceSecondaryBase {
public:
    virtual ~WorkspaceSecondaryBase() {}
    int field;
};

class Workspace : public WorkspacePrimaryBase, public WorkspaceSecondaryBase {
public:
    Workspace();
    virtual ~Workspace();
    int extra;
};

Workspace::Workspace()
{
    extra = 0;
}

Workspace::~Workspace()
{
}

} // namespace RBX
