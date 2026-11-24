// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no class header was provided, so this is a minimal model of the layout.
// The target is a compiler-generated `vector deleting destructor'`adjustor{20}' thunk.
// It belongs to a secondary base at offset 0x14: sub ecx,0x14; jmp ScriptContext::`vector deleting destructor'.

namespace RBX {

// INFERRED: primary base occupying 0x14 bytes (vptr + 16 bytes of data)
struct ScriptContextPrimaryBase {
    char data[16];
    virtual ~ScriptContextPrimaryBase() {}
};

// INFERRED: secondary base located at offset 0x14 with a virtual destructor
struct ScriptContextSecondaryBase {
    virtual ~ScriptContextSecondaryBase() {}
};

class ScriptContext : public ScriptContextPrimaryBase, public ScriptContextSecondaryBase {
public:
    virtual ~ScriptContext();
};

// Out-of-line destructor references the vftable, causing emission of the
// deleting destructor and its adjustor thunk.
ScriptContext::~ScriptContext()
{
}

} // namespace RBX
