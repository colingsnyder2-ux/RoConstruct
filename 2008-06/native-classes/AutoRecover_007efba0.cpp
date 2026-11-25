// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no header excerpt was provided, so RBX::Name is declared minimally here.
// Only the static declare(const char*, int) signature, taken from the mangled callee name, is needed.
namespace RBX {
class Name {
public:
    static const Name& declare(const char* name, int index);
};
}

// INFERRED: the global is a reference to a Name; the initializer stores the address returned by declare("color", -1).
const RBX::Name& tag_color = RBX::Name::declare("color", -1);
