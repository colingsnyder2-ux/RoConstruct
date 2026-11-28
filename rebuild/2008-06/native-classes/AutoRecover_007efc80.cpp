// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no Name header was shown, so I declare a minimal RBX::Name locally for the call.
namespace RBX {
class Name {
public:
    static const Name& declare(const char* name, int index);
};
}

// INFERRED: the global at 0x96ee40 holds the returned reference, so it is a reference to Name.
// Its initializer is the dynamic initializer this file defines.
const RBX::Name& tag_ldraw_filename = RBX::Name::declare("ldraw_filename", -1);
