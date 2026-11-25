// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no header was shown for RBX::Name, so a minimal local declaration is used.
namespace RBX {
    class Name {
    public:
        static const Name& declare(const char* name, int index);
    };
}

// INFERRED: the global is a reference, so the compiler stores the pointer returned by declare.
const RBX::Name& tag_shape = RBX::Name::declare("shape", -1);
