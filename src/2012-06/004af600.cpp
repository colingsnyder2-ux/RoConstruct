// from server: 100% by Xemicl
// roc 2012-06 004af600  unit: VerbBinderJob  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004af600
//
// 004af600  83793000             cmp dword ptr [ecx + 0x30], 0
// 004af604  7422                 je 0x4af628
// 004af606  8b442404             mov eax, dword ptr [esp + 4]
// 004af60a  6a00                 push 0
// 004af60c  50                   push eax
// 004af60d  83c11c               add ecx, 0x1c
// 004af610  ff158c25b200         call dword ptr [0xb2258c]
// 004af616  8b15ec26b200         mov edx, dword ptr [0xb226ec]
// 004af61c  33c9                 xor ecx, ecx
// 004af61e  3b02                 cmp eax, dword ptr [edx]
// 004af620  0f95c1               setne cl
// 004af623  8ac1                 mov al, cl
// 004af625  c20400               ret 4
// 004af628  80793900             cmp byte ptr [ecx + 0x39], 0
// 004af62c  7418                 je 0x4af646
// 004af62e  0fbe442404           movsx eax, byte ptr [esp + 4]
// 004af633  50                   push eax
// 004af634  ff158c29b200         call dword ptr [0xb2298c]
// 004af63a  83c404               add esp, 4
// 004af63d  f7d8                 neg eax
// 004af63f  1bc0                 sbb eax, eax
// 004af641  f7d8                 neg eax
// 004af643  c20400               ret 4
// 004af646  32c0                 xor al, al
// 004af648  c20400               ret 4
// copied from an identical function in another client (function ?is_dropped@?$char_separator@DU?$char_traits@D@std@@@@QBE_ND@Z)

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