// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005c5380  unit: RBX::VVisit::?$BoundFuncDesc  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005c5380
//
// 005c5380  6aff                 push -1
// 005c5382  68814a7d00           push 0x7d4a81
// 005c5387  64a100000000         mov eax, dword ptr fs:[0]
// 005c538d  50                   push eax
// 005c538e  64892500000000       mov dword ptr fs:[0], esp
// 005c5395  83ec20               sub esp, 0x20
// 005c5398  56                   push esi
// 005c5399  8bf1                 mov esi, ecx
// 005c539b  68b08f8300           push 0x838fb0
// 005c53a0  8d4c240c             lea ecx, [esp + 0xc]
// 005c53a4  89742408             mov dword ptr [esp + 8], esi
// 005c53a8  ff1558248000         call dword ptr [0x802458]
// 005c53ae  8b442434             mov eax, dword ptr [esp + 0x34]
// 005c53b2  6880318300           push 0x833180
// 005c53b7  50                   push eax
// 005c53b8  8d4c2410             lea ecx, [esp + 0x10]
// 005c53bc  51                   push ecx
// 005c53bd  8bce                 mov ecx, esi
// 005c53bf  c744243800000000     mov dword ptr [esp + 0x38], 0
// 005c53c7  e864a1fbff           call 0x57f530
// 005c53cc  8d4c2408             lea ecx, [esp + 8]
// 005c53d0  c644242c02           mov byte ptr [esp + 0x2c], 2
// 005c53d5  ff1568248000         call dword ptr [0x802468]
// 005c53db  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 005c53df  c7069c8f8300         mov dword ptr [esi], 0x838f9c
// 005c53e5  8bc6                 mov eax, esi
// 005c53e7  5e                   pop esi
// 005c53e8  64890d00000000       mov dword ptr fs:[0], ecx
// 005c53ef  83c42c               add esp, 0x2c
// 005c53f2  c20400               ret 4

extern void (__thiscall *string_construct)(void *, const char *);
extern void (__thiscall *string_destroy)(void *);

namespace std {
    template<class T> struct char_traits {};
    template<class T> class allocator {};

    template<class T, class Traits, class Allocator>
    class basic_string {
        unsigned char storage[28];
    public:
        basic_string(const T *);
        ~basic_string();
    };

    template<class T, class Traits, class Allocator>
    inline basic_string<T, Traits, Allocator>::basic_string(const T *text)
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

struct Base {
    Base(const std::string &, int, const char *);
    virtual ~Base();
};

struct S : Base {
    S(int);
    virtual ~S();
};

S::S(int value)
    : Base(std::string("CanCollideVerb"), value, "CanCollide")
{
}
