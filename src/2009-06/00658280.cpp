// from server: 100% by EspClaude
// roc 2009-06 00658280  unit: VProfilingItem::?$BoundFuncDesc  size: 296 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00658280
//
// 00658280  6aff                 push -1
// 00658282  6831c48500           push 0x85c431
// 00658287  64a100000000         mov eax, dword ptr fs:[0]
// 0065828d  50                   push eax
// 0065828e  64892500000000       mov dword ptr fs:[0], esp
// 00658295  83ec30               sub esp, 0x30
// 00658298  53                   push ebx
// 00658299  8b5c2444             mov ebx, dword ptr [esp + 0x44]
// 0065829d  56                   push esi
// 0065829e  57                   push edi
// 0065829f  8d442418             lea eax, [esp + 0x18]
// 006582a3  53                   push ebx
// 006582a4  50                   push eax
// 006582a5  894c2414             mov dword ptr [esp + 0x14], ecx
// 006582a9  e832ffffff           call 0x6581e0
// 006582ae  8b7004               mov esi, dword ptr [eax + 4]
// 006582b1  8b38                 mov edi, dword ptr [eax]
// 006582b3  83c408               add esp, 8
// 006582b6  897c2410             mov dword ptr [esp + 0x10], edi
// 006582ba  89742414             mov dword ptr [esp + 0x14], esi
// 006582be  85f6                 test esi, esi
// 006582c0  740c                 je 0x6582ce
// 006582c2  8d4e04               lea ecx, [esi + 4]
// 006582c5  ba01000000           mov edx, 1
// 006582ca  f00fc111             lock xadd dword ptr [ecx], edx
// 006582ce  55                   push ebp
// 006582cf  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 006582d3  c744244800000000     mov dword ptr [esp + 0x48], 0
// 006582db  85ed                 test ebp, ebp
// 006582dd  742c                 je 0x65830b
// 006582df  8d4504               lea eax, [ebp + 4]
// 006582e2  83c9ff               or ecx, 0xffffffff
// 006582e5  f00fc108             lock xadd dword ptr [eax], ecx
// 006582e9  7520                 jne 0x65830b
// 006582eb  8b5500               mov edx, dword ptr [ebp]
// 006582ee  8b4204               mov eax, dword ptr [edx + 4]
// 006582f1  8bcd                 mov ecx, ebp
// 006582f3  ffd0                 call eax
// 006582f5  8d4d08               lea ecx, [ebp + 8]
// 006582f8  83caff               or edx, 0xffffffff
// 006582fb  f00fc111             lock xadd dword ptr [ecx], edx
// 006582ff  750a                 jne 0x65830b
// 00658301  8b4500               mov eax, dword ptr [ebp]
// 00658304  8b5008               mov edx, dword ptr [eax + 8]
// 00658307  8bcd                 mov ecx, ebp
// 00658309  ffd2                 call edx
// 0065830b  83bb38c0000010       cmp dword ptr [ebx + 0xc038], 0x10
// 00658312  5d                   pop ebp
// 00658313  7208                 jb 0x65831d
// 00658315  8b8324c00000         mov eax, dword ptr [ebx + 0xc024]
// 0065831b  eb06                 jmp 0x658323
// 0065831d  8d8324c00000         lea eax, [ebx + 0xc024]
// 00658323  50                   push eax
// 00658324  8d4c2424             lea ecx, [esp + 0x24]
// 00658328  ff15b4e48900         call dword ptr [0x89e4b4]
// 0065832e  8b07                 mov eax, dword ptr [edi]
// 00658330  8b5004               mov edx, dword ptr [eax + 4]
// 00658333  8d4c2420             lea ecx, [esp + 0x20]
// 00658337  51                   push ecx
// 00658338  8bcf                 mov ecx, edi
// 0065833a  c644244801           mov byte ptr [esp + 0x48], 1
// 0065833f  ffd2                 call edx
// 00658341  8d4c2420             lea ecx, [esp + 0x20]
// 00658345  c644244400           mov byte ptr [esp + 0x44], 0
// 0065834a  ff15c4e48900         call dword ptr [0x89e4c4]
// 00658350  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00658354  50                   push eax
// 00658355  8bcf                 mov ecx, edi
// 00658357  e8f49af7ff           call 0x5d1e50
// 0065835c  c7442444ffffffff     mov dword ptr [esp + 0x44], 0xffffffff
// 00658364  85f6                 test esi, esi
// 00658366  742a                 je 0x658392
// 00658368  8d4e04               lea ecx, [esi + 4]
// 0065836b  83caff               or edx, 0xffffffff
// 0065836e  f00fc111             lock xadd dword ptr [ecx], edx
// 00658372  751e                 jne 0x658392
// 00658374  8b06                 mov eax, dword ptr [esi]
// 00658376  8b5004               mov edx, dword ptr [eax + 4]
// 00658379  8bce                 mov ecx, esi
// 0065837b  ffd2                 call edx
// 0065837d  8d4608               lea eax, [esi + 8]
// 00658380  83c9ff               or ecx, 0xffffffff
// 00658383  f00fc108             lock xadd dword ptr [eax], ecx
// 00658387  7509                 jne 0x658392
// 00658389  8b16                 mov edx, dword ptr [esi]
// 0065838b  8b4208               mov eax, dword ptr [edx + 8]
// 0065838e  8bce                 mov ecx, esi
// 00658390  ffd0                 call eax
// 00658392  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 00658396  8bc7                 mov eax, edi
// 00658398  5f                   pop edi
// 00658399  5e                   pop esi
// 0065839a  5b                   pop ebx
// 0065839b  64890d00000000       mov dword ptr fs:[0], ecx
// 006583a2  83c43c               add esp, 0x3c
// 006583a5  c20400               ret 4
// copied from an identical function in another client (function ?f@Item@ns_ROCX00001d@@QAEPAU12@PAUInput@2@@Z)

namespace ns_ROCX00001d {
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

extern void (__thiscall *stringConstruct)(void*, const char*);
extern void (__thiscall *stringDestroy)(void*);

namespace std
{
    template<class T> struct char_traits {};
    template<class T> class allocator {};

    template<class C, class Traits, class Alloc>
    class basic_string
    {
        char allocatorStorage;
        union
        {
            C buffer[16];
            C* pointer;
        } storage;
        unsigned int length;
        unsigned int capacity;

    public:
        basic_string(const C*);
        ~basic_string();
    };

    template<class C, class Traits, class Alloc>
    inline basic_string<C, Traits, Alloc>::basic_string(const C* text)
    {
        stringConstruct(this, text);
    }

    template<class C, class Traits, class Alloc>
    inline basic_string<C, Traits, Alloc>::~basic_string()
    {
        stringDestroy(this);
    }

    typedef basic_string<char, char_traits<char>, allocator<char> > string;
}

struct RefCount
{
    virtual void unused();
    virtual void dispose();
    virtual void destroy();

    volatile long strong;
    volatile long weak;

    void release();
};

inline void RefCount::release()
{
    if (_InterlockedDecrement(&strong) == 0)
    {
        dispose();
        if (_InterlockedDecrement(&weak) == 0)
            destroy();
    }
}

template<class T>
struct Shared
{
    T* object;
    RefCount* count;

    template<class U>
    Shared(const Shared<U>& other);
    ~Shared();
};

template<class T>
template<class U>
inline Shared<T>::Shared(const Shared<U>& other)
    : object(other.object), count(other.count)
{
    if (count)
        _InterlockedIncrement(&count->strong);
}

template<class T>
inline Shared<T>::~Shared()
{
    if (count)
        count->release();
}

struct Input
{
    char padding[0xc024];
    union
    {
        char buffer[16];
        char* pointer;
    } name;
    unsigned int length;
    unsigned int capacity;

    const char* c_str() const;
};

inline const char* Input::c_str() const
{
    if (capacity >= 16)
        return name.pointer;
    return name.buffer;
}

struct Item
{
    Item* f(Input*);
};

struct Node
{
    virtual void unused();
    virtual void setName(const std::string&);
    void attach(Item*);
};

struct TypedMemItem : Node {};

Shared<TypedMemItem> __cdecl create(Input*);

Item* Item::f(Input* input)
{
    Shared<Node> result(create(input));
    {
        std::string name(input->c_str());
        result.object->setName(name);
    }
    result.object->attach(this);
    return reinterpret_cast<Item*>(result.object);
}
}
