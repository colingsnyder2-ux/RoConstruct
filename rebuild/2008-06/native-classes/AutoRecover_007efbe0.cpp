// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: minimal local declaration of RBX::Name; no header was provided for it.
namespace RBX {
class Name {
public:
    static const Name& declare(const char* name, int index);
};
}

// INFERRED: the global is a reference to a declared Name (stored as a pointer at 0x96ee2c).
const RBX::Name& tag_roblox_code = RBX::Name::declare("roblox_code", -1);
