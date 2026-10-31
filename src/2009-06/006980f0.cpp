// from server: 97% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0063c3a0  unit: RBX::DebrisService  size: 136 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0063c3a0
//
// 0063c3a0  64a100000000         mov eax, dword ptr fs:[0]
// 0063c3a6  6aff                 push -1
// 0063c3a8  68b9fe7c00           push 0x7cfeb9
// 0063c3ad  50                   push eax
// 0063c3ae  8b442410             mov eax, dword ptr [esp + 0x10]
// 0063c3b2  64892500000000       mov dword ptr fs:[0], esp
// 0063c3b9  83ec44               sub esp, 0x44
// 0063c3bc  56                   push esi
// 0063c3bd  8bf1                 mov esi, ecx
// 0063c3bf  3b8650010000         cmp eax, dword ptr [esi + 0x150]
// 0063c3c5  744f                 je 0x63c416
// 0063c3c7  85c0                 test eax, eax
// 0063c3c9  7d34                 jge 0x63c3ff
// 0063c3cb  68389b8400           push 0x849b38
// 0063c3d0  8d4c2408             lea ecx, [esp + 8]
// 0063c3d4  ff1558248000         call dword ptr [0x802458]
// 0063c3da  8d442404             lea eax, [esp + 4]
// 0063c3de  50                   push eax
// 0063c3df  8d4c2424             lea ecx, [esp + 0x24]
// 0063c3e3  c744245400000000     mov dword ptr [esp + 0x54], 0
// 0063c3eb  e860d9dcff           call 0x409d50
// 0063c3f0  68c81b8d00           push 0x8d1bc8
// 0063c3f5  8d4c2424             lea ecx, [esp + 0x24]
// 0063c3f9  51                   push ecx
// 0063c3fa  e88d510600           call 0x6a158c
// 0063c3ff  68fcd49700           push 0x97d4fc
// 0063c404  898650010000         mov dword ptr [esi + 0x150], eax
// 0063c40a  e8f116ddff           call 0x40db00
// 0063c40f  8bce                 mov ecx, esi
// 0063c411  e8baf5ffff           call 0x63b9d0
// 0063c416  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 0063c41a  5e                   pop esi
// 0063c41b  64890d00000000       mov dword ptr fs:[0], ecx
// 0063c422  83c450               add esp, 0x50
// 0063c425  c20400               ret 4

namespace std {
    template<class T> struct char_traits;
    template<class T> struct allocator;

    template<class T, class Traits, class Alloc>
    struct basic_string {
        unsigned int proxy;
        union {
            T buffer[16];
            T* pointer;
        } storage;
        unsigned int length;
        unsigned int capacity;

        basic_string(const T*);
        ~basic_string();
    };

    typedef basic_string<char, char_traits<char>, allocator<char> > string;

    struct runtime_error {
        char storage[40];

        runtime_error(const string&);
        runtime_error(const runtime_error&);
        ~runtime_error();
    };
}

extern void (__thiscall *stringConstructor)(std::string*, const char*);

namespace std {
    template<>
    __forceinline string::basic_string(const char* text)
    {
        stringConstructor(this, text);
    }
}

struct PropertyDescriptor;
extern PropertyDescriptor maxItemsProperty;

struct DebrisService {
    char padding[0x150];
    int maxItems;

    void setMaxItems(int);
    void notify(const PropertyDescriptor*);
    void update();
};

void DebrisService::setMaxItems(int value)
{
    if (value != maxItems) {
        if (value < 0)
            throw std::runtime_error(
                std::string("DebrisService MaxItems must be greater than 0"));

        maxItems = value;
        notify(&maxItemsProperty);
        update();
    }
}
