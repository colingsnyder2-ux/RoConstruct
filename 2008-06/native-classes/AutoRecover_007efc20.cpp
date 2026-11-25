// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: Name is declared locally because no header was shown; the real one is in the RBX headers.
namespace RBX {
class Name {
public:
    static const Name& declare(const char* name, int index);
};
}

// INFERRED: tag_part is a global reference to the interned Name "part" (stored as a pointer at 0x96ee34).
extern const RBX::Name& tag_part;
const RBX::Name& tag_part = RBX::Name::declare("part", -1);
