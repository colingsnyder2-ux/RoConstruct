// from server: 100% by Yeetserama
// roc 2010-06 00480bf0  unit: RBX::LDraw2Lua::LDraw2RobloxColorMap  size: 241 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00480bf0
//
// 00480bf0  6aff                 push -1
// 00480bf2  68fb569800           push 0x9856fb
// 00480bf7  64a100000000         mov eax, dword ptr fs:[0]
// 00480bfd  50                   push eax
// 00480bfe  64892500000000       mov dword ptr fs:[0], esp
// 00480c05  83ec1c               sub esp, 0x1c
// 00480c08  53                   push ebx
// 00480c09  68942ea100           push 0xa12e94
// 00480c0e  8d4c2408             lea ecx, [esp + 8]
// 00480c12  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 00480c1a  ff1510a49e00         call dword ptr [0x9ea410]
// 00480c20  8d442404             lea eax, [esp + 4]
// 00480c24  50                   push eax
// 00480c25  8d4c2434             lea ecx, [esp + 0x34]
// 00480c29  51                   push ecx
// 00480c2a  c644243001           mov byte ptr [esp + 0x30], 1
// 00480c2f  e88c2b0000           call 0x4837c0
// 00480c34  83c408               add esp, 8
// 00480c37  85c0                 test eax, eax
// 00480c39  8d4c2404             lea ecx, [esp + 4]
// 00480c3d  0f94c3               sete bl
// 00480c40  c644242800           mov byte ptr [esp + 0x28], 0
// 00480c45  ff1500a49e00         call dword ptr [0x9ea400]
// 00480c4b  84db                 test bl, bl
// 00480c4d  7426                 je 0x480c75
// 00480c4f  8d4c2430             lea ecx, [esp + 0x30]
// 00480c53  c7442428ffffffff     mov dword ptr [esp + 0x28], 0xffffffff
// 00480c5b  ff1500a49e00         call dword ptr [0x9ea400]
// 00480c61  33c0                 xor eax, eax
// 00480c63  5b                   pop ebx
// 00480c64  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00480c68  64890d00000000       mov dword ptr fs:[0], ecx
// 00480c6f  83c428               add esp, 0x28
// 00480c72  c21c00               ret 0x1c
// 00480c75  688c2ea100           push 0xa12e8c
// 00480c7a  8d4c2408             lea ecx, [esp + 8]
// 00480c7e  ff1510a49e00         call dword ptr [0x9ea410]
// 00480c84  8d542404             lea edx, [esp + 4]
// 00480c88  52                   push edx
// 00480c89  8d442434             lea eax, [esp + 0x34]
// 00480c8d  50                   push eax
// 00480c8e  c644243002           mov byte ptr [esp + 0x30], 2
// 00480c93  e8282b0000           call 0x4837c0
// 00480c98  83c408               add esp, 8
// 00480c9b  85c0                 test eax, eax
// 00480c9d  8d4c2404             lea ecx, [esp + 4]
// 00480ca1  0f94c3               sete bl
// 00480ca4  c644242800           mov byte ptr [esp + 0x28], 0
// 00480ca9  ff1500a49e00         call dword ptr [0x9ea400]
// 00480caf  8d4c2430             lea ecx, [esp + 0x30]
// 00480cb3  c7442428ffffffff     mov dword ptr [esp + 0x28], 0xffffffff
// 00480cbb  ff1500a49e00         call dword ptr [0x9ea400]
// 00480cc1  b801000000           mov eax, 1
// 00480cc6  84db                 test bl, bl
// 00480cc8  7505                 jne 0x480ccf
// 00480cca  b802000000           mov eax, 2
// 00480ccf  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00480cd3  5b                   pop ebx
// 00480cd4  64890d00000000       mov dword ptr fs:[0], ecx
// 00480cdb  83c428               add esp, 0x28
// 00480cde  c21c00               ret 0x1c
// copied from an identical function in another client (function ?classify@ns_ROCX000013@@YGHV?$basic_string@DU?$char_traits@D@std@ns_ROCX000013@@V?$allocator@D@23@@std@1@@Z)

namespace ns_ROCX000013 {
// from server: 100% by king_originala
extern void (__thiscall *string_construct)(void*, const char*);
extern void (__thiscall *string_destroy)(void*);

namespace std {
    template<class T> struct char_traits;
    template<class T> class allocator;

    template<class T, class Traits, class Allocator>
    class basic_string {
        unsigned char allocator_storage[4];
        union {
            T buffer[16];
            T* pointer;
        } storage;
        unsigned int length;
        unsigned int capacity;

    public:
        basic_string(const T*);
        ~basic_string();
    };

    template<class T, class Traits, class Allocator>
    inline basic_string<T, Traits, Allocator>::basic_string(const T* text)
    {
        string_construct(this, text);
    }

    template<class T, class Traits, class Allocator>
    inline basic_string<T, Traits, Allocator>::~basic_string()
    {
        string_destroy(this);
    }

    typedef basic_string<char, char_traits<char>, allocator<char> > string;
}

int __cdecl compare(const std::string&, const std::string&);

int __stdcall classify(std::string value)
{
    if (compare(value, std::string("symmetric")) == 0)
        return 0;
    if (compare(value, std::string("brick")) == 0)
        return 1;
    return 2;
}
}
