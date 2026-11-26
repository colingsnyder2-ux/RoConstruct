// from server: 100% by Xemicl
// roc 2012-06 007ab150  unit: RBX::VLighting::?$FactoryProduct  size: 201 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007ab150
//
// 007ab150  6aff                 push -1
// 007ab152  68b06dac00           push 0xac6db0
// 007ab157  64a100000000         mov eax, dword ptr fs:[0]
// 007ab15d  50                   push eax
// 007ab15e  64892500000000       mov dword ptr fs:[0], esp
// 007ab165  83ec60               sub esp, 0x60
// 007ab168  8d4c241c             lea ecx, [esp + 0x1c]
// 007ab16c  ff15e824b200         call dword ptr [0xb224e8]
// 007ab172  c744241c10a9ba00     mov dword ptr [esp + 0x1c], 0xbaa910
// 007ab17a  8b442470             mov eax, dword ptr [esp + 0x70]
// 007ab17e  83781810             cmp dword ptr [eax + 0x18], 0x10
// 007ab182  c744246800000000     mov dword ptr [esp + 0x68], 0
// 007ab18a  7205                 jb 0x7ab191
// 007ab18c  8b4804               mov ecx, dword ptr [eax + 4]
// 007ab18f  eb03                 jmp 0x7ab194
// 007ab191  8d4804               lea ecx, [eax + 4]
// 007ab194  8b4014               mov eax, dword ptr [eax + 0x14]
// 007ab197  894c2458             mov dword ptr [esp + 0x58], ecx
// 007ab19b  03c8                 add ecx, eax
// 007ab19d  8d0424               lea eax, [esp]
// 007ab1a0  894c245c             mov dword ptr [esp + 0x5c], ecx
// 007ab1a4  50                   push eax
// 007ab1a5  8d4c2420             lea ecx, [esp + 0x20]
// 007ab1a9  e8d2f9ffff           call 0x7aab80
// 007ab1ae  84c0                 test al, al
// 007ab1b0  7431                 je 0x7ab1e3
// 007ab1b2  56                   push esi
// 007ab1b3  8b742404             mov esi, dword ptr [esp + 4]
// 007ab1b7  57                   push edi
// 007ab1b8  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 007ab1bc  8d4c2424             lea ecx, [esp + 0x24]
// 007ab1c0  c7442470ffffffff     mov dword ptr [esp + 0x70], 0xffffffff
// 007ab1c8  ff15b424b200         call dword ptr [0xb224b4]
// 007ab1ce  8b4c2468             mov ecx, dword ptr [esp + 0x68]
// 007ab1d2  8bd7                 mov edx, edi
// 007ab1d4  5f                   pop edi
// 007ab1d5  8bc6                 mov eax, esi
// 007ab1d7  5e                   pop esi
// 007ab1d8  64890d00000000       mov dword ptr fs:[0], ecx
// 007ab1df  83c46c               add esp, 0x6c
// 007ab1e2  c3                   ret 
// 007ab1e3  682841b400           push 0xb44128
// 007ab1e8  8d4c240c             lea ecx, [esp + 0xc]
// 007ab1ec  ff15202ab200         call dword ptr [0xb22a20]
// 007ab1f2  c74424087ca8ba00     mov dword ptr [esp + 8], 0xbaa87c
// 007ab1fa  c7442414500bd600     mov dword ptr [esp + 0x14], 0xd60b50
// 007ab202  c7442418d872dc00     mov dword ptr [esp + 0x18], 0xdc72d8
// 007ab20a  8d4c2408             lea ecx, [esp + 8]
// 007ab20e  51                   push ecx
// 007ab20f  c644246c01           mov byte ptr [esp + 0x6c], 1
// 007ab214  e8b796f9ff           call 0x7448d0
// copied from an identical function in another client (function ??$lexical_cast@_JV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@$0A@D@detail@boost@@YA_JABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PADI@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
#include <streambuf>
#include <typeinfo>
namespace boost {
class bad_lexical_cast : public std::bad_cast {
public:
    bad_lexical_cast() : source(&typeid(void)), target(&typeid(void)) {}
    bad_lexical_cast(const std::type_info& s, const std::type_info& t) : source(&s), target(&t) {}
    const std::type_info& source_type() const { return *source; }
    virtual const char* what() const throw() { return "bad lexical cast: source type value could not be interpreted as target"; }
    virtual ~bad_lexical_cast() throw() {}
private:
    const std::type_info* source;
    const std::type_info* target;
};
template<class E> __declspec(noreturn) void throw_exception(E const& e);
namespace detail {
template<class CharT, class Base, class Traits>
class lexical_stream_limited_src : public Base {
    CharT* start;
    CharT* finish;
public:
    lexical_stream_limited_src(CharT* sta, CharT* fin) : start(sta), finish(fin) {}
    bool operator<<(std::basic_string<CharT, Traits> const& str)
    {
        start = const_cast<CharT*>(str.data());
        finish = start + str.length();
        return true;
    }
    template<class InputStreamable> bool operator>>(InputStreamable& output);
};
template<class Target, class Source, bool Unlimited, class CharT>
Target lexical_cast(Source const& arg, CharT* buf, std::size_t src_len)
{
    typedef std::char_traits<CharT> traits;
    lexical_stream_limited_src<CharT, std::basic_streambuf<CharT, traits>, traits> interpreter(buf, buf + src_len);
    Target result;
    if (!(interpreter << arg && interpreter >> result))
        throw_exception(bad_lexical_cast(typeid(Source), typeid(Target)));
    return result;
}
}
template<class Target, class Source>
inline Target lexical_cast(const Source& arg)
{
    char buf[2];
    return detail::lexical_cast<Target, Source, false>(arg, buf, 1);
}
}
template __int64 boost::lexical_cast<__int64, std::string>(const std::string&);