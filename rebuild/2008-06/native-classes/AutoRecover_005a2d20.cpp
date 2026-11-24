// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no class header was available. The target is the compiler-generated
// vector-deleting-destructor adjustor thunk: it subtracts 748 from `this`, then
// jumps to the real Workspace vector deleting destructor. A hand-written function
// cannot have that ABI. Instead, this file rebuilds a class layout that makes the
// compiler emit the thunk itself. The layout is a 748-byte primary base plus a
// second polymorphic base at offset 748. Workspace overrides the virtual destructor.
namespace RBX {

// INFERRED: primary base occupying bytes [0, 748) (vptr + 744 bytes of data)
struct WorkspacePrimaryBase {
    virtual ~WorkspacePrimaryBase() {}
    char pad[744];
};

// INFERRED: secondary polymorphic base at offset 748 (0x2ec)
struct WorkspaceSecondaryBase {
    virtual ~WorkspaceSecondaryBase() {}
    int dummy;
};

class Workspace : public WorkspacePrimaryBase, public WorkspaceSecondaryBase {
public:
    Workspace();
    virtual ~Workspace();
};

Workspace::Workspace()
{
}

Workspace::~Workspace()
{
}

} // namespace RBX

// Forces the vftable (and the adjustor{748} deleting-destructor thunk) to be emitted.
RBX::Workspace* rbx_make_workspace_for_thunk()
{
    return new RBX::Workspace();
}
