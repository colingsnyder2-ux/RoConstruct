// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0048ab70  unit: RBX::Network::P8Player::?$GetSetImpl  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0048ab70
//
// 0048ab70  6aff                 push -1
// 0048ab72  68d3607c00           push 0x7c60d3
// 0048ab77  64a100000000         mov eax, dword ptr fs:[0]
// 0048ab7d  50                   push eax
// 0048ab7e  64892500000000       mov dword ptr fs:[0], esp
// 0048ab85  83ec20               sub esp, 0x20
// 0048ab88  8bc1                 mov eax, ecx
// 0048ab8a  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 0048ab8e  c7042400000000       mov dword ptr [esp], 0
// 0048ab95  85c9                 test ecx, ecx
// 0048ab97  7405                 je 0x48ab9e
// 0048ab99  8d51ec               lea edx, [ecx - 0x14]
// 0048ab9c  eb02                 jmp 0x48aba0
// 0048ab9e  33d2                 xor edx, edx
// 0048aba0  56                   push esi
// 0048aba1  8d4c2408             lea ecx, [esp + 8]
// 0048aba5  51                   push ecx
// 0048aba6  8b480c               mov ecx, dword ptr [eax + 0xc]
// 0048aba9  03ca                 add ecx, edx
// 0048abab  8b5008               mov edx, dword ptr [eax + 8]
// 0048abae  ffd2                 call edx
// 0048abb0  8b742434             mov esi, dword ptr [esp + 0x34]
// 0048abb4  50                   push eax
// 0048abb5  8bce                 mov ecx, esi
// 0048abb7  c744243001000000     mov dword ptr [esp + 0x30], 1
// 0048abbf  ff155c248000         call dword ptr [0x80245c]
// 0048abc5  8d4c2408             lea ecx, [esp + 8]
// 0048abc9  c744240401000000     mov dword ptr [esp + 4], 1
// 0048abd1  c644242c00           mov byte ptr [esp + 0x2c], 0
// 0048abd6  ff1568248000         call dword ptr [0x802468]
// 0048abdc  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0048abe0  8bc6                 mov eax, esi
// 0048abe2  5e                   pop esi
// 0048abe3  64890d00000000       mov dword ptr fs:[0], ecx
// 0048abea  83c42c               add esp, 0x2c
// 0048abed  c20800               ret 8

namespace std
{
    template<class T> struct char_traits {};
    template<class T> class allocator {};

    template<class C, class T, class A>
    class basic_string
    {
        unsigned int proxy;
        union
        {
            C buffer[16];
            C* pointer;
        } storage;
        unsigned int length;
        unsigned int capacity;

    public:
        basic_string(const basic_string&);
        ~basic_string();
    };
}

typedef std::basic_string<char, std::char_traits<char>, std::allocator<char> > String;

extern String* (__thiscall *string_copy)(String*, const String&);
extern void (__thiscall *string_destroy)(String*);

namespace std
{
    template<class C, class T, class A>
    __forceinline basic_string<C, T, A>::basic_string(const basic_string& other)
    {
        string_copy(this, other);
    }

    template<class C, class T, class A>
    __forceinline basic_string<C, T, A>::~basic_string()
    {
        string_destroy(this);
    }
}

struct __multiple_inheritance Getter;

struct S
{
    unsigned int reserved[2];
    String (Getter::*getter)();

    String f(void* object);
};

String S::f(void* object)
{
    Getter* base = object
        ? reinterpret_cast<Getter*>(static_cast<char*>(object) - 24)
        : 0;
    return (base->*getter)();
}
