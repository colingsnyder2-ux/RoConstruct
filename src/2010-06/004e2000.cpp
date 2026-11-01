// from server: 100% by Yeetserama
// roc 2010-06 004e2000  unit: G3D::Ray  size: 91 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004e2000
//
// 004e2000  6aff                 push -1
// 004e2002  68095b9800           push 0x985b09
// 004e2007  64a100000000         mov eax, dword ptr fs:[0]
// 004e200d  50                   push eax
// 004e200e  64892500000000       mov dword ptr fs:[0], esp
// 004e2015  83ec1c               sub esp, 0x1c
// 004e2018  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 004e201c  8d0424               lea eax, [esp]
// 004e201f  50                   push eax
// 004e2020  e8fba6f6ff           call 0x44c720
// 004e2025  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 004e2029  50                   push eax
// 004e202a  51                   push ecx
// 004e202b  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 004e2033  e848f3ffff           call 0x4e1380
// 004e2038  83c408               add esp, 8
// 004e203b  8d0c24               lea ecx, [esp]
// 004e203e  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 004e2046  ff1500a49e00         call dword ptr [0x9ea400]
// 004e204c  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004e2050  64890d00000000       mov dword ptr fs:[0], ecx
// 004e2057  83c428               add esp, 0x28
// 004e205a  c3                   ret 
// copied from an identical function in another client (function ?reconstruct@ns_ROCX00001e@@YAXPAUSource@1@PAX@Z)

namespace ns_ROCX00001e {
// from server: 100% by king_originala
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
