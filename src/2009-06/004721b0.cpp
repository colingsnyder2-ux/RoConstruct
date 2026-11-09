// from server: 100% by EspClaude
// roc 2009-06 004721b0  unit: RBX::LDraw2Lua::LDraw2RobloxMapRoot  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004721b0
//
// 004721b0  6aff                 push -1
// 004721b2  68343d8500           push 0x853d34
// 004721b7  64a100000000         mov eax, dword ptr fs:[0]
// 004721bd  50                   push eax
// 004721be  64892500000000       mov dword ptr fs:[0], esp
// 004721c5  51                   push ecx
// 004721c6  56                   push esi
// 004721c7  8bf1                 mov esi, ecx
// 004721c9  89742404             mov dword ptr [esp + 4], esi
// 004721cd  c70660d98b00         mov dword ptr [esi], 0x8bd960
// 004721d3  8d4e5c               lea ecx, [esi + 0x5c]
// 004721d6  c744241002000000     mov dword ptr [esp + 0x10], 2
// 004721de  e8adfbffff           call 0x471d90
// 004721e3  8d4e3c               lea ecx, [esi + 0x3c]
// 004721e6  c644241001           mov byte ptr [esp + 0x10], 1
// 004721eb  ff15c4e48900         call dword ptr [0x89e4c4]
// 004721f1  8d4e20               lea ecx, [esi + 0x20]
// 004721f4  c644241000           mov byte ptr [esp + 0x10], 0
// 004721f9  ff15c4e48900         call dword ptr [0x89e4c4]
// 004721ff  8d4e04               lea ecx, [esi + 4]
// 00472202  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 0047220a  ff15c4e48900         call dword ptr [0x89e4c4]
// 00472210  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00472214  5e                   pop esi
// 00472215  64890d00000000       mov dword ptr fs:[0], ecx
// 0047221c  83c410               add esp, 0x10
// 0047221f  c3                   ret 
// copied from an identical function in another client (function ??1S@ns_ROCX000005@@UAE@XZ)

namespace ns_ROCX000005 {
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
