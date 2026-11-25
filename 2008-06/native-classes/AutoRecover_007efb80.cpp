// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: Name is declared locally, since the header path is not known.
namespace RBX {
    class Name {
    public:
        static const Name& declare(const char* name, int index);
    };
}

// INFERRED: the global is a reference, so the initializer stores the returned pointer.
static const RBX::Name& tag_color_map = RBX::Name::declare("color_map", -1);
