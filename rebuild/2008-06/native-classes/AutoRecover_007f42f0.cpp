// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
namespace RBX {
class Name {
public:
    static const Name& declare(const char* name, int index);
};
}

// INFERRED: global at 0x976144 holds the address of the declared Name
extern const RBX::Name* g_00976144;

extern "C" void fn_007f42f0()
{
    g_00976144 = &RBX::Name::declare("CFrame", 1001);
}
