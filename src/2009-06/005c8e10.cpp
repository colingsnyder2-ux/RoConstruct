// from server: 100% by EspClaude
// roc 2009-06 005c8e10  unit: seg_005c0000  size: 126 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005c8e10
//
// 005c8e10  6aff                 push -1
// 005c8e12  68eb218600           push 0x8621eb
// 005c8e17  64a100000000         mov eax, dword ptr fs:[0]
// 005c8e1d  50                   push eax
// 005c8e1e  64892500000000       mov dword ptr fs:[0], esp
// 005c8e25  81ec88000000         sub esp, 0x88
// 005c8e2b  56                   push esi
// 005c8e2c  8d4c2408             lea ecx, [esp + 8]
// 005c8e30  c744240400000000     mov dword ptr [esp + 4], 0
// 005c8e38  e8d3c6f9ff           call 0x565510
// 005c8e3d  8bb4249c000000       mov esi, dword ptr [esp + 0x9c]
// 005c8e44  83c010               add eax, 0x10
// 005c8e47  50                   push eax
// 005c8e48  8bce                 mov ecx, esi
// 005c8e4a  c784249800000001000000 mov dword ptr [esp + 0x98], 1
// 005c8e55  ff15b8e48900         call dword ptr [0x89e4b8]
// 005c8e5b  8d4c2408             lea ecx, [esp + 8]
// 005c8e5f  c744240401000000     mov dword ptr [esp + 4], 1
// 005c8e67  c684249400000000     mov byte ptr [esp + 0x94], 0
// 005c8e6f  e85cfdffff           call 0x5c8bd0
// 005c8e74  8b8c248c000000       mov ecx, dword ptr [esp + 0x8c]
// 005c8e7b  8bc6                 mov eax, esi
// 005c8e7d  5e                   pop esi
// 005c8e7e  64890d00000000       mov dword ptr fs:[0], ecx
// 005c8e85  81c494000000         add esp, 0x94
// 005c8e8b  c20400               ret 4
// copied from an identical function in another client (function ?f@ns_ROCX00001d@@YG?AV?$basic_string@DU?$char_traits@D@std@ns_ROCX00001d@@V?$allocator@D@23@@std@1@XZ)

namespace ns_ROCX00001d {
namespace std {
    template<class T> struct char_traits;
    template<class T> class allocator;

    template<class T, class Traits, class Alloc>
    class basic_string {
        char storage[28];
    public:
        basic_string(const basic_string&);
        ~basic_string();
    };

    typedef basic_string<char, char_traits<char>, allocator<char> > string;
}

extern void (__thiscall *copy_string)(void*, const void*);

template<class T, class Traits, class Alloc>
__forceinline std::basic_string<T, Traits, Alloc>::basic_string(
    const std::basic_string<T, Traits, Alloc>& source)
{
    copy_string(this, &source);
}

struct S {
    char prefix[16];
    std::string text;
    char suffix[88];

    S();
    ~S();
};

std::string __stdcall f()
{
    return S().text;
}
}
