// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no Workspace header was available, so the class layout is rebuilt here so that
// MSVC generates this thunk itself.
// The layout is a 20-byte primary base (vptr + 16 bytes) followed by a secondary
// polymorphic base at offset 0x14.
// Workspace overrides the virtual destructor. That makes the compiler emit, in the secondary
// vtable, the `vector deleting destructor'`adjustor{20}' thunk
// (sub ecx,14h / jmp to the primary deleting destructor).
namespace RBX {

// INFERRED: placeholder base types; the real bases are unknown.
struct WorkspacePrimaryBase {
    virtual ~WorkspacePrimaryBase() {}
    int pad[4];
};

struct WorkspaceSecondaryBase {
    virtual ~WorkspaceSecondaryBase() {}
};

class Workspace : public WorkspacePrimaryBase, public WorkspaceSecondaryBase {
public:
    Workspace();
    virtual ~Workspace();
};

// Defining the constructor and destructor forces the vtable and its thunks to be emitted.
Workspace::Workspace() {}
Workspace::~Workspace() {}

}
