// from server: 100% by Xemicl
// roc 2012-06 007ab220  unit: RBX::VLighting::?$FactoryProduct  size: 194 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007ab220
//
// 007ab220  6aff                 push -1
// 007ab222  68b06dac00           push 0xac6db0
// 007ab227  64a100000000         mov eax, dword ptr fs:[0]
// 007ab22d  50                   push eax
// 007ab22e  64892500000000       mov dword ptr fs:[0], esp
// 007ab235  83ec58               sub esp, 0x58
// 007ab238  8d4c2414             lea ecx, [esp + 0x14]
// 007ab23c  ff15e824b200         call dword ptr [0xb224e8]
// 007ab242  c744241410a9ba00     mov dword ptr [esp + 0x14], 0xbaa910
// 007ab24a  8b442468             mov eax, dword ptr [esp + 0x68]
// 007ab24e  83781810             cmp dword ptr [eax + 0x18], 0x10
// 007ab252  c744246000000000     mov dword ptr [esp + 0x60], 0
// 007ab25a  7205                 jb 0x7ab261
// 007ab25c  8b4804               mov ecx, dword ptr [eax + 4]
// 007ab25f  eb03                 jmp 0x7ab264
// 007ab261  8d4804               lea ecx, [eax + 4]
// 007ab264  8b4014               mov eax, dword ptr [eax + 0x14]
// 007ab267  894c2450             mov dword ptr [esp + 0x50], ecx
// 007ab26b  03c8                 add ecx, eax
// 007ab26d  8d442468             lea eax, [esp + 0x68]
// 007ab271  894c2454             mov dword ptr [esp + 0x54], ecx
// 007ab275  50                   push eax
// 007ab276  8d4c2418             lea ecx, [esp + 0x18]
// 007ab27a  e861f7ffff           call 0x7aa9e0
// 007ab27f  84c0                 test al, al
// 007ab281  742b                 je 0x7ab2ae
// 007ab283  56                   push esi
// 007ab284  0fb774246c           movzx esi, word ptr [esp + 0x6c]
// 007ab289  8d4c2418             lea ecx, [esp + 0x18]
// 007ab28d  c7442464ffffffff     mov dword ptr [esp + 0x64], 0xffffffff
// 007ab295  ff15b424b200         call dword ptr [0xb224b4]
// 007ab29b  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 007ab29f  668bc6               mov ax, si
// 007ab2a2  5e                   pop esi
// 007ab2a3  64890d00000000       mov dword ptr fs:[0], ecx
// 007ab2aa  83c464               add esp, 0x64
// 007ab2ad  c3                   ret 
// 007ab2ae  682841b400           push 0xb44128
// 007ab2b3  8d4c2404             lea ecx, [esp + 4]
// 007ab2b7  ff15202ab200         call dword ptr [0xb22a20]
// 007ab2bd  c704247ca8ba00       mov dword ptr [esp], 0xbaa87c
// 007ab2c4  c744240c500bd600     mov dword ptr [esp + 0xc], 0xd60b50
// 007ab2cc  c7442410e472dc00     mov dword ptr [esp + 0x10], 0xdc72e4
// 007ab2d4  8d0c24               lea ecx, [esp]
// 007ab2d7  51                   push ecx
// 007ab2d8  c644246401           mov byte ptr [esp + 0x64], 1
// 007ab2dd  e8ee95f9ff           call 0x7448d0
// copied from an identical function in another client (function ??$lexical_cast@GV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@$0A@D@detail@boost@@YAGABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PADI@Z)

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
    if (interpreter << arg) {
        Target result;
        if (interpreter >> result)
            return result;
    }
    throw_exception(bad_lexical_cast(typeid(Source), typeid(Target)));
    return Target();
}
}
template<class Target, class Source>
inline Target lexical_cast(const Source& arg)
{
    char buf[2];
    return detail::lexical_cast<Target, Source, false>(arg, buf, 1);
}
}
template unsigned short boost::lexical_cast<unsigned short, std::string>(const std::string&);