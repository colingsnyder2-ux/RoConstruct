// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
namespace RBX {
class Name {
public:
    static const Name& declare(const char* name, int index);
};
}

// INFERRED: global reference to the declared Name at 0x96ee54
const RBX::Name& tag_size_vect3 = RBX::Name::declare("size_vect3", -1);
