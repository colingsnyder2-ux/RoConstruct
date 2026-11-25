// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no header was available, so RBX::Name is declared minimally here.
// Only the static declare(const char*, int) member is needed for this initializer.
namespace RBX {
class Name {
public:
    static const Name& declare(const char* name, int index);
};
}

// INFERRED: the global is a const reference to a Name, which gives the dynamic initializer
// ??__Etag_schema_version@@YAXXZ. It stores the pointer returned by declare into 0x96ee1c.
const RBX::Name& tag_schema_version = RBX::Name::declare("schema_version", -1);
