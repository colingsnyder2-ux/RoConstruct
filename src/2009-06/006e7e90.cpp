// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00658170  unit: RBX::ArrowButton  size: 140 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00658170
//
// 00658170  6aff                 push -1
// 00658172  6805be7d00           push 0x7dbe05
// 00658177  64a100000000         mov eax, dword ptr fs:[0]
// 0065817d  50                   push eax
// 0065817e  64892500000000       mov dword ptr fs:[0], esp
// 00658185  51                   push ecx
// 00658186  56                   push esi
// 00658187  8bf1                 mov esi, ecx
// 00658189  57                   push edi
// 0065818a  89742408             mov dword ptr [esp + 8], esi
// 0065818e  33ff                 xor edi, edi
// 00658190  6a04                 push 4
// 00658192  897c2418             mov dword ptr [esp + 0x18], edi
// 00658196  e885870400           call 0x6a0920
// 0065819b  83c404               add esp, 4
// 0065819e  3bc7                 cmp eax, edi
// 006581a0  7404                 je 0x6581a6
// 006581a2  8930                 mov dword ptr [eax], esi
// 006581a4  eb02                 jmp 0x6581a8
// 006581a6  33c0                 xor eax, eax
// 006581a8  8906                 mov dword ptr [esi], eax
// 006581aa  897e0c               mov dword ptr [esi + 0xc], edi
// 006581ad  897e10               mov dword ptr [esi + 0x10], edi
// 006581b0  897e14               mov dword ptr [esi + 0x14], edi
// 006581b3  8d7e18               lea edi, [esi + 0x18]
// 006581b6  8bcf                 mov ecx, edi
// 006581b8  c644241402           mov byte ptr [esp + 0x14], 2
// 006581bd  ff1560248000         call dword ptr [0x802460]
// 006581c3  8d44241c             lea eax, [esp + 0x1c]
// 006581c7  50                   push eax
// 006581c8  8bcf                 mov ecx, edi
// 006581ca  c644241803           mov byte ptr [esp + 0x18], 3
// 006581cf  ff150c248000         call dword ptr [0x80240c]
// 006581d5  8d4c241c             lea ecx, [esp + 0x1c]
// 006581d9  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 006581e1  ff1568248000         call dword ptr [0x802468]
// 006581e7  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 006581eb  5f                   pop edi
// 006581ec  8bc6                 mov eax, esi
// 006581ee  5e                   pop esi
// 006581ef  64890d00000000       mov dword ptr fs:[0], ecx
// 006581f6  83c410               add esp, 0x10
// 006581f9  c21c00               ret 0x1c

typedef unsigned int size_t;
void* __cdecl operator new(size_t);
void __cdecl operator delete(void*);

namespace std {
    template<class T> struct char_traits;
    template<class T> class allocator;

    template<class T, class Traits, class Allocator>
    class basic_string {
        unsigned char storage[28];
    public:
        basic_string();
        ~basic_string();
        basic_string& operator=(const basic_string&);
    };

    typedef basic_string<char, char_traits<char>, allocator<char> > string;
}

extern std::string* (__thiscall *string_construct)(std::string*);
extern void (__thiscall *string_destroy)(std::string*);
extern std::string& (__thiscall *string_assign)(std::string*, const std::string&);

namespace std {
    template<class T, class Traits, class Allocator>
    inline basic_string<T, Traits, Allocator>::basic_string()
    {
        string_construct(this);
    }

    template<class T, class Traits, class Allocator>
    inline basic_string<T, Traits, Allocator>::~basic_string()
    {
        string_destroy(this);
    }

    template<class T, class Traits, class Allocator>
    inline basic_string<T, Traits, Allocator>&
    basic_string<T, Traits, Allocator>::operator=(const basic_string& value)
    {
        return string_assign(this, value);
    }
}

struct S;

struct OwnerStorage {
    S** pointer;
    explicit OwnerStorage(S* value);
    ~OwnerStorage();
};

inline OwnerStorage::OwnerStorage(S* value) : pointer(new S*(value)) {}
inline OwnerStorage::~OwnerStorage() { delete pointer; }

struct Owner : OwnerStorage {
    explicit Owner(S* value);
    ~Owner();
};

inline Owner::Owner(S* value) : OwnerStorage(value) {}
inline Owner::~Owner() {}

struct Storage {
    void* pointer;
    unsigned int unused;
    ~Storage();
};

inline Storage::~Storage()
{
    operator delete(pointer);
}

struct S {
    Owner owner;
    Storage unused;
    unsigned int first;
    unsigned int second;
    unsigned int third;
    std::string text;

    S(std::string value);
};

S::S(std::string value)
    : owner(this), first(0), second(0), third(0), text()
{
    text = value;
}
