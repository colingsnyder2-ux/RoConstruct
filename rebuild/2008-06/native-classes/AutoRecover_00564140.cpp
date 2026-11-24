// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no class header was available. The target is the this-adjusting
// thunk: it subtracts 0x14 from this, then jumps to the primary vector deleting
// destructor. MSVC emits such a thunk when a class overrides a virtual
// destructor that comes from a secondary base at offset 20. The layout below
// is a minimal local reconstruction that makes the compiler generate that thunk.

namespace RBX {

// INFERRED: primary base, 20 bytes (vptr + 16 bytes of data)
struct DebugSettingsPrimaryBase {
    virtual void primaryVirtual() {}
    char pad[16];
};

// INFERRED: secondary base at offset 20 with the virtual destructor
struct DebugSettingsSecondaryBase {
    virtual ~DebugSettingsSecondaryBase() {}
};

class DebugSettings : public DebugSettingsPrimaryBase, public DebugSettingsSecondaryBase {
public:
    DebugSettings();
    virtual ~DebugSettings();
    virtual void primaryVirtual() {}
};

DebugSettings::~DebugSettings() {}

// The out-of-line constructor forces the vtable to be emitted, and with it
// the `adjustor{20}' vector deleting destructor thunk.
DebugSettings::DebugSettings() {}

} // namespace RBX
