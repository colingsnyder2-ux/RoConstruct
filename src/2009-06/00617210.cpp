// from server: 100% by EspClaude
// from server: 100% by colin
// roc 2008-06 0059f310  unit: RBX::VMeshId::?$TypedPropertyDescriptor  size: 227 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0059f310
//
// 0059f310  6aff                 push -1
// 0059f312  68d13a7d00           push 0x7d3ad1
// 0059f317  64a100000000         mov eax, dword ptr fs:[0]
// 0059f31d  50                   push eax
// 0059f31e  64892500000000       mov dword ptr fs:[0], esp
// 0059f325  83ec0c               sub esp, 0xc
// 0059f328  56                   push esi
// 0059f329  8bf1                 mov esi, ecx
// 0059f32b  c744240400000000     mov dword ptr [esp + 4], 0
// 0059f333  8b06                 mov eax, dword ptr [esi]
// 0059f335  8b4008               mov eax, dword ptr [eax + 8]
// 0059f338  57                   push edi
// 0059f339  50                   push eax
// 0059f33a  b968b39400           mov ecx, 0x94b368
// 0059f33f  ff1578288000         call dword ptr [0x802878]
// 0059f345  84c0                 test al, al
// 0059f347  7436                 je 0x59f37f
// 0059f349  83c604               add esi, 4
// 0059f34c  56                   push esi
// 0059f34d  e87efeffff           call 0x59f1d0
// 0059f352  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0059f356  83c404               add esp, 4
// 0059f359  8bf0                 mov esi, eax
// 0059f35b  56                   push esi
// 0059f35c  8bcf                 mov ecx, edi
// 0059f35e  ff155c248000         call dword ptr [0x80245c]
// 0059f364  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 0059f367  894f1c               mov dword ptr [edi + 0x1c], ecx
// 0059f36a  8bc7                 mov eax, edi
// 0059f36c  5f                   pop edi
// 0059f36d  5e                   pop esi
// 0059f36e  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0059f372  64890d00000000       mov dword ptr fs:[0], ecx
// 0059f379  83c418               add esp, 0x18
// 0059f37c  c20400               ret 4
// 0059f37f  8b4e04               mov ecx, dword ptr [esi + 4]
// 0059f382  8b16                 mov edx, dword ptr [esi]
// 0059f384  8954240c             mov dword ptr [esp + 0xc], edx
// 0059f388  85c9                 test ecx, ecx
// 0059f38a  7409                 je 0x59f395
// 0059f38c  8b01                 mov eax, dword ptr [ecx]
// 0059f38e  8b5008               mov edx, dword ptr [eax + 8]
// 0059f391  ffd2                 call edx
// 0059f393  eb02                 jmp 0x59f397
// 0059f395  33c0                 xor eax, eax
// 0059f397  89442410             mov dword ptr [esp + 0x10], eax
// 0059f39b  8d4c240c             lea ecx, [esp + 0xc]
// 0059f39f  c744241c01000000     mov dword ptr [esp + 0x1c], 1
// 0059f3a7  e814630700           call 0x6156c0
// 0059f3ac  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0059f3b0  8bf0                 mov esi, eax
// 0059f3b2  56                   push esi
// 0059f3b3  8bcf                 mov ecx, edi
// 0059f3b5  ff155c248000         call dword ptr [0x80245c]
// 0059f3bb  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0059f3bf  8b461c               mov eax, dword ptr [esi + 0x1c]
// 0059f3c2  89471c               mov dword ptr [edi + 0x1c], eax
// 0059f3c5  c744240801000000     mov dword ptr [esp + 8], 1
// 0059f3cd  c644241c00           mov byte ptr [esp + 0x1c], 0
// 0059f3d2  85c9                 test ecx, ecx
// 0059f3d4  7408                 je 0x59f3de
// 0059f3d6  8b11                 mov edx, dword ptr [ecx]
// 0059f3d8  8b02                 mov eax, dword ptr [edx]
// 0059f3da  6a01                 push 1
// 0059f3dc  ffd0                 call eax
// 0059f3de  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0059f3e2  8bc7                 mov eax, edi
// 0059f3e4  5f                   pop edi
// 0059f3e5  5e                   pop esi
// 0059f3e6  64890d00000000       mov dword ptr fs:[0], ecx
// 0059f3ed  83c418               add esp, 0x18
// 0059f3f0  c20400               ret 4

// from server: 93% by king_originala
struct TypeInfo;
extern bool (__thiscall *typeEqual)(const TypeInfo*, const TypeInfo&);
extern TypeInfo meshType;
extern void (__thiscall *copyString)(void*, const void*);
extern void (__thiscall *destroyString)(void*);

namespace std
{
    template<class T> struct char_traits {};
    template<class T> class allocator {};

    template<class T, class Traits, class Alloc>
    class basic_string
    {
        char storage[28];
    public:
        basic_string(const basic_string&);
        ~basic_string();
    };

    template<class T, class Traits, class Alloc>
    inline basic_string<T, Traits, Alloc>::basic_string(const basic_string& other)
    {
        copyString(this, &other);
    }

    template<class T, class Traits, class Alloc>
    inline basic_string<T, Traits, Alloc>::~basic_string()
    {
        destroyString(this);
    }

    typedef basic_string<char, char_traits<char>, allocator<char> > string;
}

struct MeshId
{
    std::string value;
    unsigned int extra;
};

struct Type
{
    char padding[8];
    TypeInfo* info;
};

struct Holder
{
    virtual ~Holder();
    virtual void slot1() = 0;
    virtual Holder* clone() = 0;
};

inline Holder* cloneHolder(Holder* p)
{
    if (p)
        return p->clone();
    return 0;
}

extern const MeshId& __cdecl getMeshId(Holder* const*);

struct S;

struct Temporary
{
    Type* type;
    Holder* holder;

    Temporary(const S&);
    ~Temporary();
    const MeshId& convert();
};

struct S
{
    Type* type;
    Holder* holder;

    MeshId f();
};

inline Temporary::Temporary(const S& source)
    : type(source.type), holder(cloneHolder(source.holder))
{
}

inline Temporary::~Temporary()
{
    if (holder)
        delete holder;
}

MeshId S::f()
{
    const TypeInfo* t = type->info;
    if (typeEqual(&meshType, *t))
        return getMeshId(&holder);

    Temporary temporary(*this);
    return temporary.convert();
}
