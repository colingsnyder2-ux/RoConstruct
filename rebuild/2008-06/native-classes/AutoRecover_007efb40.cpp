// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: minimal local declaration of RBX::Name; no header path was shown.
namespace RBX {
class Name {
public:
    static const Name& declare(const char* name, int index);
};
}

// INFERRED: global at 0x96ee18 holds the pointer to the declared Name (LDraw2RobloxMap).
extern const RBX::Name* g_0096ee18;

extern "C" void fn_007efb40()
{
    g_0096ee18 = &RBX::Name::declare("LDraw2RobloxMap", -1);
}
