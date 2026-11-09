// from server: 100% by EspClaude
// roc 2009-06 00470550  unit: RBX::LDraw2Lua::LDraw2RobloxColorMap  size: 241 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00470550
//
// 00470550  6aff                 push -1
// 00470552  687b3a8500           push 0x853a7b
// 00470557  64a100000000         mov eax, dword ptr fs:[0]
// 0047055d  50                   push eax
// 0047055e  64892500000000       mov dword ptr fs:[0], esp
// 00470565  83ec1c               sub esp, 0x1c
// 00470568  53                   push ebx
// 00470569  685cd88b00           push 0x8bd85c
// 0047056e  8d4c2408             lea ecx, [esp + 8]
// 00470572  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 0047057a  ff15b4e48900         call dword ptr [0x89e4b4]
// 00470580  8d442404             lea eax, [esp + 4]
// 00470584  50                   push eax
// 00470585  8d4c2434             lea ecx, [esp + 0x34]
// 00470589  51                   push ecx
// 0047058a  c644243001           mov byte ptr [esp + 0x30], 1
// 0047058f  e8cc2d0000           call 0x473360
// 00470594  83c408               add esp, 8
// 00470597  85c0                 test eax, eax
// 00470599  8d4c2404             lea ecx, [esp + 4]
// 0047059d  0f94c3               sete bl
// 004705a0  c644242800           mov byte ptr [esp + 0x28], 0
// 004705a5  ff15c4e48900         call dword ptr [0x89e4c4]
// 004705ab  84db                 test bl, bl
// 004705ad  7426                 je 0x4705d5
// 004705af  8d4c2430             lea ecx, [esp + 0x30]
// 004705b3  c7442428ffffffff     mov dword ptr [esp + 0x28], 0xffffffff
// 004705bb  ff15c4e48900         call dword ptr [0x89e4c4]
// 004705c1  33c0                 xor eax, eax
// 004705c3  5b                   pop ebx
// 004705c4  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004705c8  64890d00000000       mov dword ptr fs:[0], ecx
// 004705cf  83c428               add esp, 0x28
// 004705d2  c21c00               ret 0x1c
// 004705d5  6854d88b00           push 0x8bd854
// 004705da  8d4c2408             lea ecx, [esp + 8]
// 004705de  ff15b4e48900         call dword ptr [0x89e4b4]
// 004705e4  8d542404             lea edx, [esp + 4]
// 004705e8  52                   push edx
// 004705e9  8d442434             lea eax, [esp + 0x34]
// 004705ed  50                   push eax
// 004705ee  c644243002           mov byte ptr [esp + 0x30], 2
// 004705f3  e8682d0000           call 0x473360
// 004705f8  83c408               add esp, 8
// 004705fb  85c0                 test eax, eax
// 004705fd  8d4c2404             lea ecx, [esp + 4]
// 00470601  0f94c3               sete bl
// 00470604  c644242800           mov byte ptr [esp + 0x28], 0
// 00470609  ff15c4e48900         call dword ptr [0x89e4c4]
// 0047060f  8d4c2430             lea ecx, [esp + 0x30]
// 00470613  c7442428ffffffff     mov dword ptr [esp + 0x28], 0xffffffff
// 0047061b  ff15c4e48900         call dword ptr [0x89e4c4]
// 00470621  b801000000           mov eax, 1
// 00470626  84db                 test bl, bl
// 00470628  7505                 jne 0x47062f
// 0047062a  b802000000           mov eax, 2
// 0047062f  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00470633  5b                   pop ebx
// 00470634  64890d00000000       mov dword ptr fs:[0], ecx
// 0047063b  83c428               add esp, 0x28
// 0047063e  c21c00               ret 0x1c
// copied from an identical function in another client (function ?classify@ns_ROCX00003d@@YGHV?$basic_string@DU?$char_traits@D@std@ns_ROCX00003d@@V?$allocator@D@23@@std@1@@Z)

namespace ns_ROCX00003d {
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
