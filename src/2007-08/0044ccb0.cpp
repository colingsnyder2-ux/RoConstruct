// from server: 100% by Yeetserama
// roc 2007-08 0044ccb0  unit: CAboutRobloxDialog  size: 150 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0044ccb0
//
// 0044ccb0  6aff                 push -1
// 0044ccb2  6807037400           push 0x740307
// 0044ccb7  64a100000000         mov eax, dword ptr fs:[0]
// 0044ccbd  50                   push eax
// 0044ccbe  51                   push ecx
// 0044ccbf  56                   push esi
// 0044ccc0  a188518b00           mov eax, dword ptr [0x8b5188]
// 0044ccc5  33c4                 xor eax, esp
// 0044ccc7  50                   push eax
// 0044ccc8  8d44240c             lea eax, [esp + 0xc]
// 0044cccc  64a300000000         mov dword ptr fs:[0], eax
// 0044ccd2  8bf1                 mov esi, ecx
// 0044ccd4  89742408             mov dword ptr [esp + 8], esi
// 0044ccd8  8b442424             mov eax, dword ptr [esp + 0x24]
// 0044ccdc  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0044cce0  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0044cce4  50                   push eax
// 0044cce5  51                   push ecx
// 0044cce6  52                   push edx
// 0044cce7  8bce                 mov ecx, esi
// 0044cce9  e8d43b1e00           call 0x6308c2
// 0044ccee  8d8e14010000         lea ecx, [esi + 0x114]
// 0044ccf4  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0044ccfc  c706ec0c7900         mov dword ptr [esi], 0x790cec
// 0044cd02  c74674bc0c7900       mov dword ptr [esi + 0x74], 0x790cbc
// 0044cd09  ff15a4e67700         call dword ptr [0x77e6a4]
// 0044cd0f  b801000000           mov eax, 1
// 0044cd14  88442414             mov byte ptr [esp + 0x14], al
// 0044cd18  898690000000         mov dword ptr [esi + 0x90], eax
// 0044cd1e  8b860c010000         mov eax, dword ptr [esi + 0x10c]
// 0044cd24  0d13408401           or eax, 0x1844013
// 0044cd29  50                   push eax
// 0044cd2a  8bce                 mov ecx, esi
// 0044cd2c  e8d7311e00           call 0x62ff08
// 0044cd31  8bc6                 mov eax, esi
// 0044cd33  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0044cd37  64890d00000000       mov dword ptr fs:[0], ecx
// 0044cd3e  59                   pop ecx
// 0044cd3f  5e                   pop esi
// 0044cd40  83c410               add esp, 0x10
// 0044cd43  c20c00               ret 0xc
// copied from an identical function in another client (function ??0S@ns_ROCX000009@@QAE@HHH@Z)

namespace ns_ROCX000009 {
// from server: 100% by king_originala
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
