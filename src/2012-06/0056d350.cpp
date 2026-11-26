// from server: 100% by Xemicl
// roc 2012-06 0056d350  unit: RBX::Network::IdSerializer  size: 91 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0056d350
//
// 0056d350  6aff                 push -1
// 0056d352  684961ab00           push 0xab6149
// 0056d357  64a100000000         mov eax, dword ptr fs:[0]
// 0056d35d  50                   push eax
// 0056d35e  64892500000000       mov dword ptr fs:[0], esp
// 0056d365  83ec1c               sub esp, 0x1c
// 0056d368  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0056d36c  8d0424               lea eax, [esp]
// 0056d36f  50                   push eax
// 0056d370  e8fbf2efff           call 0x46c670
// 0056d375  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0056d379  50                   push eax
// 0056d37a  51                   push ecx
// 0056d37b  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 0056d383  e8c8f2ffff           call 0x56c650
// 0056d388  83c408               add esp, 8
// 0056d38b  8d0c24               lea ecx, [esp]
// 0056d38e  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 0056d396  ff153c26b200         call dword ptr [0xb2263c]
// 0056d39c  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0056d3a0  64890d00000000       mov dword ptr fs:[0], ecx
// 0056d3a7  83c428               add esp, 0x28
// 0056d3aa  c3                   ret 
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