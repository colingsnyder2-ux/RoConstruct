// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no Name header was shown, so RBX::Name is declared locally with only the static declare() the initializer calls.
namespace RBX {
class Name {
public:
    static const Name& declare(const char* name, int index);
};
}

// INFERRED: tag_ldraw_code is a global const RBX::Name& (the mangled name has no namespace).
// The compiler generates its dynamic initializer, which calls declare("ldraw_code", -1)
// and stores the returned reference.
const RBX::Name& tag_ldraw_code = RBX::Name::declare("ldraw_code", -1);
