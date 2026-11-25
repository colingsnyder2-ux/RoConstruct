// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
namespace RBX {
class Name {
public:
    static const Name& declare(const char* name, int index);
};
}

// INFERRED: global is a const Name& stored as a pointer
static const RBX::Name& tag_y_offset = RBX::Name::declare("y_offset", -1);
