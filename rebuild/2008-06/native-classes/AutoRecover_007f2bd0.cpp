// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
namespace RBX {
class Name {
public:
    static const Name& declare(const char* name, int index);
};
}

// INFERRED: global holding the declared Name's address at 0x00973ec4
extern const RBX::Name* g_00973ec4;

extern "C" void fn_007f2bd0()
{
    g_00973ec4 = &RBX::Name::declare("Name", 3000);
}
