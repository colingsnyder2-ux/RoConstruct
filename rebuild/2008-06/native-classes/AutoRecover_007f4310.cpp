// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
namespace RBX {
class Name {
public:
    // INFERRED: minimal declaration; real header not available.
    static const Name& declare(const char* name, int index);
};
}

// INFERRED: unknown global holding the declared 'Position' name.
extern "C" const RBX::Name* g_009761b4;

extern "C" void fn_007f4310()
{
    g_009761b4 = &RBX::Name::declare("Position", 0x3ea);
}
