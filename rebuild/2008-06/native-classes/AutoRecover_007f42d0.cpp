// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
namespace RBX {
class Name {
public:
    static const Name& declare(const char* name, int index);
};
}

// INFERRED: global at 0x976038 holds a pointer to a declared Name; string literal at 0x94a240
extern const char g_0094a240[];
extern const RBX::Name* g_00976038;

extern "C" void fn_007f42d0()
{
    g_00976038 = &RBX::Name::declare(g_0094a240, 1000);
}
