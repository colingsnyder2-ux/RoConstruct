// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <ctype.h>
namespace std {
template <class E> struct char_traits {};
template <class E> class allocator {};
template <class E, class Tr, class A>
class basic_string {
public:
    typedef unsigned int size_type;
    static const size_type npos;
    size_type find(E ch, size_type off = 0) const;
    size_type length() const { return _Mysize; }
private:
    int _Myproxy;
    union { E _Buf[16]; E* _Ptr; } _Bx;
    size_type _Mysize;
    size_type _Myres;
};
extern template class __declspec(dllimport) basic_string<char, char_traits<char>, allocator<char> >;
}
template <class Char, class Tr = std::char_traits<Char> >
class char_separator {
    typedef std::basic_string<Char, Tr, std::allocator<Char> > string_type;
public:
    bool is_dropped(Char E) const;
private:
    string_type m_kept_delims;
    string_type m_dropped_delims;
    bool m_use_ispunct;
    bool m_use_isspace;
    int m_empty_tokens;
    bool m_output_done;
};
template <class Char, class Tr>
bool char_separator<Char, Tr>::is_dropped(Char E) const
{
    if (m_dropped_delims.length())
        return m_dropped_delims.find(E) != string_type::npos;
    else if (m_use_isspace) {
        return isspace(E) != 0;
    } else
        return false;
}
template class char_separator<char>;
