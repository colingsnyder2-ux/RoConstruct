// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <new>
#include <stddef.h>

namespace std {
template<class T> struct char_traits;
template<class T> class allocator;
template<class T, class Traits, class Allocator>
class __declspec(dllimport) basic_string {
public:
    basic_string(const T*);
};
}

inline void* operator new(size_t, void* p) { return p; }

extern char g_0084d688[];
extern char g_0097db0c[];
extern "C" void __cdecl fn_00801490();
extern "C" int __cdecl atexit(void (__cdecl*)());

extern "C" void __cdecl fn_007f9030()
{
    new (g_0097db0c) std::basic_string<char, std::char_traits<char>, std::allocator<char> >(g_0084d688);
    atexit(fn_00801490);
}
