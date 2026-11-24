// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no class headers were provided. The target is a compiler-generated
// adjustor thunk (sub ecx,16 / jmp to the real vector deleting destructor).
// The layout below is a stand-in: a 16-byte primary base plus a polymorphic
// secondary base at offset 16, which produces the adjustor{16} thunk.
namespace RBX {

    class VDebugSettings;

    // INFERRED: stand-in for the primary base chain (vptr + 12 bytes of data = 16 bytes).
    struct DebugSettingsPrimaryBase {
        int pad[3];
        virtual ~DebugSettingsPrimaryBase() {}
    };

    // INFERRED: secondary base located at offset 16 (unit name hints GlobalSettingsItem<VDebugSettings>).
    template<class T>
    struct GlobalSettingsItem {
        virtual ~GlobalSettingsItem() {}
    };

    class DebugSettings : public DebugSettingsPrimaryBase, public GlobalSettingsItem<VDebugSettings> {
    public:
        DebugSettings() {}
        virtual ~DebugSettings() {}
    };

    // Forces instantiation of the vftable and the compiler-generated
    // deleting destructors and adjustor thunks.
    DebugSettings* CreateDebugSettings_forceEmit()
    {
        return new DebugSettings();
    }
}
