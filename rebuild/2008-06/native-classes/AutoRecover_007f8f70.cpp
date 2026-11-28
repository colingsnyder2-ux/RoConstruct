// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

namespace RBX {
class Name {
public:
    static const Name& declare(const char* name, int index);
};
}

// INFERRED: global holding pointer to declared Name (reference-like)
extern const RBX::Name* g_0097d948;
const RBX::Name* g_0097d948;

extern "C" void fn_007f8f70()
{
    g_0097d948 = &RBX::Name::declare("utterance", -1);
}
