// from server: 100% by EspClaude
// roc 2009-06 005e0920  unit: RBX::ContentProvider  size: 120 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005e0920
//
// 005e0920  6aff                 push -1
// 005e0922  68b8ac8600           push 0x86acb8
// 005e0927  64a100000000         mov eax, dword ptr fs:[0]
// 005e092d  50                   push eax
// 005e092e  64892500000000       mov dword ptr fs:[0], esp
// 005e0935  51                   push ecx
// 005e0936  53                   push ebx
// 005e0937  56                   push esi
// 005e0938  57                   push edi
// 005e0939  8bf9                 mov edi, ecx
// 005e093b  6a00                 push 0
// 005e093d  6a00                 push 0
// 005e093f  83ec20               sub esp, 0x20
// 005e0942  8bf4                 mov esi, esp
// 005e0944  8d442448             lea eax, [esp + 0x48]
// 005e0948  89642434             mov dword ptr [esp + 0x34], esp
// 005e094c  50                   push eax
// 005e094d  8bce                 mov ecx, esi
// 005e094f  c744244400000000     mov dword ptr [esp + 0x44], 0
// 005e0957  ff15b8e48900         call dword ptr [0x89e4b8]
// 005e095d  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 005e0961  894e1c               mov dword ptr [esi + 0x1c], ecx
// 005e0964  8bcf                 mov ecx, edi
// 005e0966  e8b5f4ffff           call 0x5dfe20
// 005e096b  85c0                 test eax, eax
// 005e096d  8d4c2420             lea ecx, [esp + 0x20]
// 005e0971  0f95c3               setne bl
// 005e0974  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 005e097c  ff15c4e48900         call dword ptr [0x89e4c4]
// 005e0982  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005e0986  5f                   pop edi
// 005e0987  5e                   pop esi
// 005e0988  8ac3                 mov al, bl
// 005e098a  64890d00000000       mov dword ptr fs:[0], ecx
// 005e0991  5b                   pop ebx
// 005e0992  83c410               add esp, 0x10
// 005e0995  c22000               ret 0x20
// copied from an identical function in another client (function ?f@S@ns_ROCX000011@@QAE_NUArgument@2@@Z)

namespace ns_ROCX000011 {
extern void (__thiscall *string_copy)(void *, const void *);
extern void (__thiscall *string_destroy)(void *);

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

    template<class T, class Traits, class Alloc>
    inline basic_string<T, Traits, Alloc>::basic_string(
        const basic_string& other)
    {
        string_copy(this, &other);
    }

    template<class T, class Traits, class Alloc>
    inline basic_string<T, Traits, Alloc>::~basic_string()
    {
        string_destroy(this);
    }

    typedef basic_string<char, char_traits<char>, allocator<char> > string;
}

struct Argument {
    std::string name;
    int mode;
};

struct S {
    int open(Argument, int, int);
    bool f(Argument);
};

bool S::f(Argument arg)
{
    return open(arg, 0, 0) != 0;
}
}
