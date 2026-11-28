// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

namespace std {
template<class T> struct char_traits;
template<> struct char_traits<char> {};
template<class T> class allocator;
template<> class allocator<char> {};

template<class C, class T = char_traits<C>, class A = allocator<C> >
class basic_string
{
public:
    __declspec(dllimport) ~basic_string();
};
}

// INFERRED: A cdecl argument requires a stack load; the target instead uses ECX directly.
extern "C" void __fastcall fn_0043d0c0(char* self, int)
{
    reinterpret_cast<std::basic_string<char>*>(self + 12)->~basic_string();
}
