// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: 0x00401a00 is the unnamed shared callee; the target is a bare tail-call thunk to it.
extern "C" void fn_00401a00();

namespace RBX {

extern char* sRunService;

// INFERRED: util/Name.h has no callDoDeclare declaration (C2244), so this file declares a minimal
// Name with only the private static template; the template arg is the address of a char* (mangled $1...3PADA).
class Name {
private:
    template<char** N>
    static void callDoDeclare();
};

template<char** N>
void Name::callDoDeclare()
{
    fn_00401a00();
}

template void Name::callDoDeclare<&sRunService>();

}
