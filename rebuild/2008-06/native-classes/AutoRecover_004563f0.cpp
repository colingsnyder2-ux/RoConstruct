// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no Name/Stats headers were supplied, so both classes are declared minimally here.
// INFERRED: the target is a bare jmp, so the callee at 0x00455dc0 takes no arguments. It is probably the matching doDeclare instance.
// INFERRED: the template parameter is a pointer to the static (char**), so &Stats::sStats is a valid argument. Mangling $1?sStats@Stats@RBX@@3PADA is address-of-variable.
extern "C" void fn_00455dc0();

namespace RBX {

class Stats {
public:
    static char* sStats;
};

class Name {
private:
    template<char** N>
    static void callDoDeclare();
public:
    static void instantiateStats();
};

template<char** N>
void Name::callDoDeclare()
{
    fn_00455dc0();
}

// Explicit instantiation emits ??$callDoDeclare@$1?sStats@Stats@RBX@@3PADA@Name@RBX@@CAXXZ
template void Name::callDoDeclare<&Stats::sStats>();

}
