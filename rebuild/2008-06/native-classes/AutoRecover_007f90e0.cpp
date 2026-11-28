// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <new>
#include <cstdlib>

// INFERRED: Minimal declarations for the imported string constructor.
namespace std {
    template<class T> struct char_traits;
    template<class T> class allocator;

    template<class T, class Traits, class Allocator>
    class basic_string {
    public:
        __declspec(dllimport) basic_string(const T*);
    };
}

extern char g_0097dba8;
extern "C" void __cdecl fn_00801570();

extern "C" void __cdecl fn_007f90e0()
{
    new (&g_0097dba8) std::basic_string<char, std::char_traits<char>, std::allocator<char> >("Entity");
    atexit(fn_00801570);
}
