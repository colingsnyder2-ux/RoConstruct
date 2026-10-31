// from server: 100% by EspClaude
// roc 2009-06 0044d0a0  unit: CAboutRobloxDialog  size: 138 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0044d0a0
//
// 0044d0a0  6aff                 push -1
// 0044d0a2  68370e8500           push 0x850e37
// 0044d0a7  64a100000000         mov eax, dword ptr fs:[0]
// 0044d0ad  50                   push eax
// 0044d0ae  64892500000000       mov dword ptr fs:[0], esp
// 0044d0b5  51                   push ecx
// 0044d0b6  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0044d0ba  8b542414             mov edx, dword ptr [esp + 0x14]
// 0044d0be  56                   push esi
// 0044d0bf  8bf1                 mov esi, ecx
// 0044d0c1  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0044d0c5  50                   push eax
// 0044d0c6  51                   push ecx
// 0044d0c7  52                   push edx
// 0044d0c8  8bce                 mov ecx, esi
// 0044d0ca  89742410             mov dword ptr [esp + 0x10], esi
// 0044d0ce  e80fc72c00           call 0x7197e2
// 0044d0d3  8d8e14010000         lea ecx, [esi + 0x114]
// 0044d0d9  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0044d0e1  c706747a8b00         mov dword ptr [esi], 0x8b7a74
// 0044d0e7  c74674447a8b00       mov dword ptr [esi + 0x74], 0x8b7a44
// 0044d0ee  ff15c0e48900         call dword ptr [0x89e4c0]
// 0044d0f4  b801000000           mov eax, 1
// 0044d0f9  88442410             mov byte ptr [esp + 0x10], al
// 0044d0fd  898690000000         mov dword ptr [esi + 0x90], eax
// 0044d103  8b860c010000         mov eax, dword ptr [esi + 0x10c]
// 0044d109  0d13408401           or eax, 0x1844013
// 0044d10e  50                   push eax
// 0044d10f  8bce                 mov ecx, esi
// 0044d111  e8c2bb2c00           call 0x718cd8
// 0044d116  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0044d11a  8bc6                 mov eax, esi
// 0044d11c  5e                   pop esi
// 0044d11d  64890d00000000       mov dword ptr fs:[0], ecx
// 0044d124  83c410               add esp, 0x10
// 0044d127  c20c00               ret 0xc
// copied from an identical function in another client (function ??0S@ns_ROCX000005@@QAE@HHH@Z)

namespace ns_ROCX000005 {
extern void (__thiscall *string_ctor)(void *);

namespace std {
    template<class T> struct char_traits;
    template<class T> class allocator;

    template<class T, class Traits, class Allocator>
    class basic_string {
        unsigned char storage[28];
    public:
        basic_string();
        ~basic_string();
    };

    template<class T, class Traits, class Allocator>
    inline basic_string<T, Traits, Allocator>::basic_string()
    {
        string_ctor(this);
    }
}

struct Primary {
    virtual void vf();
    unsigned char padding[0x70];
};

struct Secondary {
    virtual void vf();
    unsigned char padding0[0x18];
    int state;
    unsigned char padding1[0x78];
    unsigned int flags;
    unsigned char padding2[4];
};

struct Base : Primary, Secondary {
    Base(int, int, int);
    ~Base();
    void setFlags(unsigned int);
};

struct S : Base {
    std::basic_string<char, std::char_traits<char>, std::allocator<char> > text;

    S(int, int, int);
    virtual void vf();
};

S::S(int a, int b, int c) : Base(a, b, c)
{
    state = 1;
    setFlags(flags | 0x01844013);
}
}
