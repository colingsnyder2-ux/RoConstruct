// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <exception>

// INFERRED: the original calls the imported MSVCP90 basic_string::c_str rather than inlining it.
// <string> would inline it, so a minimal basic_string with a dllimport c_str is declared here.
// The names and template shape produce the exact mangled import name.
namespace std {

template<class T> struct char_traits;
template<> struct char_traits<char> {};
template<class T> class allocator;
template<> class allocator<char> {};

template<class C, class T = char_traits<C>, class A = allocator<C> >
class basic_string
{
public:
    __declspec(dllimport) const C* c_str() const;
private:
    // INFERRED: VC9 string layout is 28 bytes (alloc, union buf/ptr, size, reserve).
    char _pad[28];
};

// INFERRED: exception base is 12 bytes (vptr, what pointer, dofree flag), so _Str is at 0xc.
class logic_error : public exception
{
public:
    virtual const char* what() const throw();
private:
    basic_string<char> _Str;
};

const char* logic_error::what() const throw()
{
    return _Str.c_str();
}

}
