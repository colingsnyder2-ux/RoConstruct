// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no native header for RBX::Name was shown, so a minimal local declaration is used.
// It matches the mangled callee ?declare@Name@RBX@@SAABV12@PBDH@Z.
namespace RBX {
    class Name {
    public:
        static const Name& declare(const char* name, int index);
    };
}

// INFERRED: a file-static reference, which is what produces a plain dynamic initializer
// that stores the returned address into a global (0x96ee3c).
static const RBX::Name& tag_description = RBX::Name::declare("description", -1);
