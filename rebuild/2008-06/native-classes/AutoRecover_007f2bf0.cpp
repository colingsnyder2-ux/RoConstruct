// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
namespace RBX {
class Name {
public:
    static const Name& declare(const char* name, int index);
};
}

extern const RBX::Name* g_00973cd4;

extern "C" void fn_007f2bf0()
{
    g_00973cd4 = &RBX::Name::declare("Parent", 3001);
}
