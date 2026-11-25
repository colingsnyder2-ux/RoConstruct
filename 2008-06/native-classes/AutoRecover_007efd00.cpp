// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

namespace RBX {
    class Name {
    public:
        static const Name& declare(const char* name, int id);
    };
}

// INFERRED: global-scope const Name& initialized dynamically (name has no namespace).
const RBX::Name& tag_form_factor = RBX::Name::declare("form_factor", -1);
