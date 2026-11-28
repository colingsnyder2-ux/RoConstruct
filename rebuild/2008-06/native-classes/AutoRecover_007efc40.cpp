// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no Name header was shown, so RBX::Name is declared locally with just the
// static declare() that the mangled callee name ?declare@Name@RBX@@SAABV12@PBDH@Z implies.
namespace RBX {
class Name {
public:
    static const Name& declare(const char* name, int index);
};
}

// INFERRED: tag_name is a namespace-scope reference initialised from Name::declare("name", -1).
// The compiler emits this dynamic initializer, which stores the returned address in the global.
const RBX::Name& tag_name = RBX::Name::declare("name", -1);
