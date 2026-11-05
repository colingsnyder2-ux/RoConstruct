// from server: 100% by Yeetserama
// roc 2010-06 00482610  unit: RBX::LDraw2Lua::LDraw2RobloxMapRoot  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00482610
//
// 00482610  6aff                 push -1
// 00482612  68b4599800           push 0x9859b4
// 00482617  64a100000000         mov eax, dword ptr fs:[0]
// 0048261d  50                   push eax
// 0048261e  64892500000000       mov dword ptr fs:[0], esp
// 00482625  51                   push ecx
// 00482626  56                   push esi
// 00482627  8bf1                 mov esi, ecx
// 00482629  89742404             mov dword ptr [esp + 4], esi
// 0048262d  c706982fa100         mov dword ptr [esi], 0xa12f98
// 00482633  8d4e5c               lea ecx, [esi + 0x5c]
// 00482636  c744241002000000     mov dword ptr [esp + 0x10], 2
// 0048263e  e8adfbffff           call 0x4821f0
// 00482643  8d4e3c               lea ecx, [esi + 0x3c]
// 00482646  c644241001           mov byte ptr [esp + 0x10], 1
// 0048264b  ff1500a49e00         call dword ptr [0x9ea400]
// 00482651  8d4e20               lea ecx, [esi + 0x20]
// 00482654  c644241000           mov byte ptr [esp + 0x10], 0
// 00482659  ff1500a49e00         call dword ptr [0x9ea400]
// 0048265f  8d4e04               lea ecx, [esi + 4]
// 00482662  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 0048266a  ff1500a49e00         call dword ptr [0x9ea400]
// 00482670  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00482674  5e                   pop esi
// 00482675  64890d00000000       mov dword ptr fs:[0], ecx
// 0048267c  83c410               add esp, 0x10
// 0048267f  c3                   ret 
// copied from an identical function in another client (function ??1S@ns_ROCX00001a@@UAE@XZ)

namespace ns_ROCX00001a {
// from server: 100% by king_originala
namespace std {
    template<class T> struct char_traits;
    template<class T> class allocator;

    template<class T, class Traits, class Alloc>
    class basic_string {
        char storage[28];
    public:
        __forceinline ~basic_string();
    };
}

typedef std::basic_string<char, std::char_traits<char>,
                          std::allocator<char> > String;

extern void (__thiscall *destroyString)(String *);

namespace std {
    template<class T, class Traits, class Alloc>
    __forceinline basic_string<T, Traits, Alloc>::~basic_string()
    {
        destroyString(reinterpret_cast<String *>(this));
    }
}

struct Map {
    ~Map();
};

struct S {
    virtual ~S();
    String first;
    String second;
    String third;
    int value;
    Map map;
};

S::~S()
{
}
}
