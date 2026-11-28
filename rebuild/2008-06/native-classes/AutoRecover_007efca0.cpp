// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: the real Name header path is unknown, so RBX::Name is declared minimally here to avoid guessing an include.
namespace RBX {
    class Name {
    public:
        static const Name& declare(const char* name, int index);
    };
}

// INFERRED: global is a reference to the interned Name (stores the returned pointer at 0x96ee44).
const RBX::Name& tag_mapping_fidelity = RBX::Name::declare("mapping_fidelity", -1);
