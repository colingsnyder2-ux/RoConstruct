// from server: 100% by Yeetserama
// roc 2007-08 0046a900  unit: RBX::LDraw2Lua::LDraw2RobloxMapRoot  size: 111 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0046a900
//
// 0046a900  6aff                 push -1
// 0046a902  68cc3c7400           push 0x743ccc
// 0046a907  64a100000000         mov eax, dword ptr fs:[0]
// 0046a90d  50                   push eax
// 0046a90e  56                   push esi
// 0046a90f  57                   push edi
// 0046a910  a188518b00           mov eax, dword ptr [0x8b5188]
// 0046a915  33c4                 xor eax, esp
// 0046a917  50                   push eax
// 0046a918  8d44240c             lea eax, [esp + 0xc]
// 0046a91c  64a300000000         mov dword ptr fs:[0], eax
// 0046a922  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0046a926  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0046a92a  3bf7                 cmp esi, edi
// 0046a92c  742f                 je 0x46a95d
// 0046a92e  8bff                 mov edi, edi
// 0046a930  8d4e24               lea ecx, [esi + 0x24]
// 0046a933  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0046a93b  ff15ace67700         call dword ptr [0x77e6ac]
// 0046a941  8d4e08               lea ecx, [esi + 8]
// 0046a944  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 0046a94c  ff15ace67700         call dword ptr [0x77e6ac]
// 0046a952  83c640               add esi, 0x40
// 0046a955  3bf7                 cmp esi, edi
// 0046a957  8974241c             mov dword ptr [esp + 0x1c], esi
// 0046a95b  75d3                 jne 0x46a930
// 0046a95d  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0046a961  64890d00000000       mov dword ptr fs:[0], ecx
// 0046a968  59                   pop ecx
// 0046a969  5f                   pop edi
// 0046a96a  5e                   pop esi
// 0046a96b  83c40c               add esp, 0xc
// 0046a96e  c3                   ret 
// copied from an identical function in another client (function ?destroy_elements@ns_ROCX000003@@YAXPAUElement@1@0@Z)

namespace ns_ROCX000003 {
// from server: 100% by king_originala
extern void (__thiscall *destroy_string)(void*);

namespace std {
    template<class T> struct char_traits;
    template<class T> class allocator;

    template<class C, class T, class A>
    class basic_string {
        unsigned char storage[28];
    public:
        ~basic_string();
    };

    template<class C, class T, class A>
    inline basic_string<C, T, A>::~basic_string()
    {
        destroy_string(this);
    }
}

struct Element {
    unsigned char prefix[8];
    std::basic_string<char, std::char_traits<char>, std::allocator<char> > first;
    std::basic_string<char, std::char_traits<char>, std::allocator<char> > second;
};

void __cdecl destroy_elements(Element* first, Element* last)
{
    for (; first != last; ++first)
        first->~Element();
}
}
