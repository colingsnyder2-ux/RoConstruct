// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 006156c0  unit: RBX::VContentId::?$TypedPropertyDescriptor  size: 191 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006156c0
//
// 006156c0  64a100000000         mov eax, dword ptr fs:[0]
// 006156c6  6aff                 push -1
// 006156c8  68118f7d00           push 0x7d8f11
// 006156cd  50                   push eax
// 006156ce  64892500000000       mov dword ptr fs:[0], esp
// 006156d5  83ec40               sub esp, 0x40
// 006156d8  57                   push edi
// 006156d9  8bf9                 mov edi, ecx
// 006156db  8b07                 mov eax, dword ptr [edi]
// 006156dd  8b4008               mov eax, dword ptr [eax + 8]
// 006156e0  50                   push eax
// 006156e1  b9f8be9200           mov ecx, 0x92bef8
// 006156e6  ff1578288000         call dword ptr [0x802878]
// 006156ec  84c0                 test al, al
// 006156ee  7478                 je 0x615768
// 006156f0  56                   push esi
// 006156f1  8d7704               lea esi, [edi + 4]
// 006156f4  8d4c240c             lea ecx, [esp + 0xc]
// 006156f8  56                   push esi
// 006156f9  51                   push ecx
// 006156fa  e8110ae0ff           call 0x416110
// 006156ff  83c408               add esp, 8
// 00615702  50                   push eax
// 00615703  8d4c242c             lea ecx, [esp + 0x2c]
// 00615707  c744245400000000     mov dword ptr [esp + 0x54], 0
// 0061570f  e82cfdffff           call 0x615440
// 00615714  50                   push eax
// 00615715  8d4c240c             lea ecx, [esp + 0xc]
// 00615719  c644245401           mov byte ptr [esp + 0x54], 1
// 0061571e  e86d98f8ff           call 0x59ef90
// 00615723  3bc6                 cmp eax, esi
// 00615725  7408                 je 0x61572f
// 00615727  8b16                 mov edx, dword ptr [esi]
// 00615729  8b08                 mov ecx, dword ptr [eax]
// 0061572b  8910                 mov dword ptr [eax], edx
// 0061572d  890e                 mov dword ptr [esi], ecx
// 0061572f  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00615733  5e                   pop esi
// 00615734  85c9                 test ecx, ecx
// 00615736  7408                 je 0x615740
// 00615738  8b01                 mov eax, dword ptr [ecx]
// 0061573a  8b10                 mov edx, dword ptr [eax]
// 0061573c  6a01                 push 1
// 0061573e  ffd2                 call edx
// 00615740  8d4c2424             lea ecx, [esp + 0x24]
// 00615744  c644244c00           mov byte ptr [esp + 0x4c], 0
// 00615749  ff1568248000         call dword ptr [0x802468]
// 0061574f  8d4c2408             lea ecx, [esp + 8]
// 00615753  c744244cffffffff     mov dword ptr [esp + 0x4c], 0xffffffff
// 0061575b  ff1568248000         call dword ptr [0x802468]
// 00615761  e81a76f5ff           call 0x56cd80
// 00615766  8907                 mov dword ptr [edi], eax
// 00615768  8bcf                 mov ecx, edi
// 0061576a  e871fdffff           call 0x6154e0
// 0061576f  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 00615773  5f                   pop edi
// 00615774  64890d00000000       mov dword ptr fs:[0], ecx
// 0061577b  83c44c               add esp, 0x4c
// 0061577e  c3                   ret 

struct TypeInfo;
extern bool (__thiscall *typeEqual)(const TypeInfo*, const TypeInfo&);
extern void (__thiscall *destroyString)(void*);

namespace std
{
    template<class T> struct char_traits;
    template<class T> class allocator;

    template<class T, class Traits, class Allocator>
    class basic_string
    {
        char storage[28];
    public:
        ~basic_string();
    };

    template<class T, class Traits, class Allocator>
    inline basic_string<T, Traits, Allocator>::~basic_string()
    {
        destroyString(this);
    }

    typedef basic_string<char, char_traits<char>, allocator<char> > string;
}

struct TypeInfo
{
    bool operator==(const TypeInfo&) const;
};

inline bool TypeInfo::operator==(const TypeInfo& other) const
{
    return typeEqual(this, other);
}

struct Object
{
    virtual ~Object();
};

struct Value : std::string
{
    char extra[4];
    Value(const std::string&);
};

struct Holder
{
    Object* value;
    Holder(const Value&);
    ~Holder();
    void swap(Holder& other);
};

inline Holder::~Holder()
{
    if (value)
        delete value;
}

inline void Holder::swap(Holder& other)
{
    if (&other != this)
    {
        Object* saved = other.value;
        other.value = value;
        value = saved;
    }
}

struct Descriptor
{
    unsigned int unused[2];
    TypeInfo* type;
};

extern TypeInfo stringType;
extern std::string __cdecl convert(const Holder&);
extern Descriptor* __cdecl valueDescriptor();

struct S
{
    Descriptor* descriptor;
    Holder holder;

    void finish();
    void f();
};

extern int changeCount;
void S::f()
{
    if (stringType == *descriptor->type)
    {
        holder.swap(Holder(Value(convert(holder))));
        ++changeCount;
        descriptor = valueDescriptor();
    }
    finish();
}
