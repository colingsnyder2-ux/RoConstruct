// from server: 100% by Xemicl
// roc 2012-06 00479cb0  unit: CAboutRobloxDialog  size: 138 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00479cb0
//
// 00479cb0  6aff                 push -1
// 00479cb2  68770eaa00           push 0xaa0e77
// 00479cb7  64a100000000         mov eax, dword ptr fs:[0]
// 00479cbd  50                   push eax
// 00479cbe  64892500000000       mov dword ptr fs:[0], esp
// 00479cc5  51                   push ecx
// 00479cc6  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00479cca  8b542414             mov edx, dword ptr [esp + 0x14]
// 00479cce  56                   push esi
// 00479ccf  8bf1                 mov esi, ecx
// 00479cd1  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00479cd5  50                   push eax
// 00479cd6  51                   push ecx
// 00479cd7  52                   push edx
// 00479cd8  8bce                 mov ecx, esi
// 00479cda  89742410             mov dword ptr [esp + 0x10], esi
// 00479cde  e8e1915000           call 0x982ec4
// 00479ce3  8d8e14010000         lea ecx, [esi + 0x114]
// 00479ce9  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00479cf1  c706d4b5b500         mov dword ptr [esi], 0xb5b5d4
// 00479cf7  c74674a4b5b500       mov dword ptr [esi + 0x74], 0xb5b5a4
// 00479cfe  ff155426b200         call dword ptr [0xb22654]
// 00479d04  b801000000           mov eax, 1
// 00479d09  88442410             mov byte ptr [esp + 0x10], al
// 00479d0d  898690000000         mov dword ptr [esi + 0x90], eax
// 00479d13  8b860c010000         mov eax, dword ptr [esi + 0x10c]
// 00479d19  0d13408401           or eax, 0x1844013
// 00479d1e  50                   push eax
// 00479d1f  8bce                 mov ecx, esi
// 00479d21  e88e865000           call 0x9823b4
// 00479d26  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00479d2a  8bc6                 mov eax, esi
// 00479d2c  5e                   pop esi
// 00479d2d  64890d00000000       mov dword ptr fs:[0], ecx
// 00479d34  83c410               add esp, 0x10
// 00479d37  c20c00               ret 0xc
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