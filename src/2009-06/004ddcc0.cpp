// from server: 100% by EspClaude
// roc 2009-06 004ddcc0  unit: RBX::Network::ConcurrentRakPeer::PacketJob  size: 91 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004ddcc0
//
// 004ddcc0  6aff                 push -1
// 004ddcc2  68d9b88500           push 0x85b8d9
// 004ddcc7  64a100000000         mov eax, dword ptr fs:[0]
// 004ddccd  50                   push eax
// 004ddcce  64892500000000       mov dword ptr fs:[0], esp
// 004ddcd5  83ec1c               sub esp, 0x1c
// 004ddcd8  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 004ddcdc  8d0424               lea eax, [esp]
// 004ddcdf  50                   push eax
// 004ddce0  e8fb6ff6ff           call 0x444ce0
// 004ddce5  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 004ddce9  50                   push eax
// 004ddcea  51                   push ecx
// 004ddceb  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 004ddcf3  e8b8f7ffff           call 0x4dd4b0
// 004ddcf8  83c408               add esp, 8
// 004ddcfb  8d0c24               lea ecx, [esp]
// 004ddcfe  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 004ddd06  ff15c4e48900         call dword ptr [0x89e4c4]
// 004ddd0c  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004ddd10  64890d00000000       mov dword ptr fs:[0], ecx
// 004ddd17  83c428               add esp, 0x28
// 004ddd1a  c3                   ret 
// copied from an identical function in another client (function ?reconstruct@ns_ROCX000068@@YAXPAUSource@1@PAX@Z)

namespace ns_ROCX000068 {
extern void (__thiscall *destroyString)(void *);

namespace std {
    template<class T> struct char_traits {};
    template<class T> struct allocator {};

    template<class T, class Traits, class Alloc>
    class basic_string {
        unsigned char storage[28];
    public:
        ~basic_string();
    };

    template<class T, class Traits, class Alloc>
    inline basic_string<T, Traits, Alloc>::~basic_string()
    {
        destroyString(this);
    }
}

typedef std::basic_string<char, std::char_traits<char>,
                         std::allocator<char> > String;

struct Source {
    String get();
};

extern void __cdecl consume(void *, const String &);

void __cdecl reconstruct(Source *source, void *destination)
{
    consume(destination, source->get());
}
}
