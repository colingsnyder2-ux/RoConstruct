// from server: 100% by EspClaude
// roc 2009-06 005c92a0  unit: seg_005c0000  size: 126 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005c92a0
//
// 005c92a0  6aff                 push -1
// 005c92a2  68eb218600           push 0x8621eb
// 005c92a7  64a100000000         mov eax, dword ptr fs:[0]
// 005c92ad  50                   push eax
// 005c92ae  64892500000000       mov dword ptr fs:[0], esp
// 005c92b5  81ec88000000         sub esp, 0x88
// 005c92bb  56                   push esi
// 005c92bc  8d4c2408             lea ecx, [esp + 8]
// 005c92c0  c744240400000000     mov dword ptr [esp + 4], 0
// 005c92c8  e843c2f9ff           call 0x565510
// 005c92cd  8bb4249c000000       mov esi, dword ptr [esp + 0x9c]
// 005c92d4  83c048               add eax, 0x48
// 005c92d7  50                   push eax
// 005c92d8  8bce                 mov ecx, esi
// 005c92da  c784249800000001000000 mov dword ptr [esp + 0x98], 1
// 005c92e5  ff15b8e48900         call dword ptr [0x89e4b8]
// 005c92eb  8d4c2408             lea ecx, [esp + 8]
// 005c92ef  c744240401000000     mov dword ptr [esp + 4], 1
// 005c92f7  c684249400000000     mov byte ptr [esp + 0x94], 0
// 005c92ff  e8ccf8ffff           call 0x5c8bd0
// 005c9304  8b8c248c000000       mov ecx, dword ptr [esp + 0x8c]
// 005c930b  8bc6                 mov eax, esi
// 005c930d  5e                   pop esi
// 005c930e  64890d00000000       mov dword ptr fs:[0], ecx
// 005c9315  81c494000000         add esp, 0x94
// 005c931b  c20400               ret 4
// copied from an identical function in another client (function ?f@ns_ROCX00001e@@YG?AV?$basic_string@DU?$char_traits@D@std@ns_ROCX00001e@@V?$allocator@D@23@@std@1@XZ)

namespace ns_ROCX00001e {
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
    char prefix[0x48];
    std::string text;
    char suffix[0x20];

    S();
    ~S();
};

std::string __stdcall f()
{
    return S().text;
}
}
