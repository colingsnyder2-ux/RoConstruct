// from server: 100% by colin
// from server: 92% by king_originala
// roc 2008-06 00660550  unit: RBX::FilterStairs  size: 369 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00660550
//
// 00660550  6aff                 push -1
// 00660552  682ec07d00           push 0x7dc02e
// 00660557  64a100000000         mov eax, dword ptr fs:[0]
// 0066055d  50                   push eax
// 0066055e  64892500000000       mov dword ptr fs:[0], esp
// 00660565  83ec20               sub esp, 0x20
// 00660568  53                   push ebx
// 00660569  56                   push esi
// 0066056a  57                   push edi
// 0066056b  33db                 xor ebx, ebx
// 0066056d  6a04                 push 4
// 0066056f  895c2438             mov dword ptr [esp + 0x38], ebx
// 00660573  e8a8030400           call 0x6a0920
// 00660578  83c404               add esp, 4
// 0066057b  3bc3                 cmp eax, ebx
// 0066057d  7408                 je 0x660587
// 0066057f  8d4c2414             lea ecx, [esp + 0x14]
// 00660583  8908                 mov dword ptr [eax], ecx
// 00660585  eb02                 jmp 0x660589
// 00660587  33c0                 xor eax, eax
// 00660589  89442414             mov dword ptr [esp + 0x14], eax
// 0066058d  895c2420             mov dword ptr [esp + 0x20], ebx
// 00660591  895c2424             mov dword ptr [esp + 0x24], ebx
// 00660595  895c2428             mov dword ptr [esp + 0x28], ebx
// 00660599  8b442444             mov eax, dword ptr [esp + 0x44]
// 0066059d  8d542414             lea edx, [esp + 0x14]
// 006605a1  52                   push edx
// 006605a2  50                   push eax
// 006605a3  c644243c02           mov byte ptr [esp + 0x3c], 2
// 006605a8  e873e3faff           call 0x60e920
// 006605ad  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 006605b1  2b4c2428             sub ecx, dword ptr [esp + 0x28]
// 006605b5  83c408               add esp, 8
// 006605b8  83e1f8               and ecx, 0xfffffff8
// 006605bb  83f908               cmp ecx, 8
// 006605be  7559                 jne 0x660619
// 006605c0  6a44                 push 0x44
// 006605c2  e859030400           call 0x6a0920
// 006605c7  83c404               add esp, 4
// 006605ca  8944240c             mov dword ptr [esp + 0xc], eax
// 006605ce  c644243403           mov byte ptr [esp + 0x34], 3
// 006605d3  3bc3                 cmp eax, ebx
// 006605d5  7476                 je 0x66064d
// 006605d7  8b4c2450             mov ecx, dword ptr [esp + 0x50]
// 006605db  83ec08               sub esp, 8
// 006605de  8bd4                 mov edx, esp
// 006605e0  890a                 mov dword ptr [edx], ecx
// 006605e2  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 006605e6  894a04               mov dword ptr [edx + 4], ecx
// 006605e9  8b54245c             mov edx, dword ptr [esp + 0x5c]
// 006605ed  89642418             mov dword ptr [esp + 0x18], esp
// 006605f1  3bd3                 cmp edx, ebx
// 006605f3  740c                 je 0x660601
// 006605f5  83c204               add edx, 4
// 006605f8  b901000000           mov ecx, 1
// 006605fd  f00fc10a             lock xadd dword ptr [edx], ecx
// 00660601  8b542454             mov edx, dword ptr [esp + 0x54]
// 00660605  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 00660609  52                   push edx
// 0066060a  8b542448             mov edx, dword ptr [esp + 0x48]
// 0066060e  51                   push ecx
// 0066060f  52                   push edx
// 00660610  8bc8                 mov ecx, eax
// 00660612  e809590000           call 0x665f20
// 00660617  eb36                 jmp 0x66064f
// 00660619  6a38                 push 0x38
// 0066061b  e800030400           call 0x6a0920
// 00660620  83c404               add esp, 4
// 00660623  89442410             mov dword ptr [esp + 0x10], eax
// 00660627  c644243404           mov byte ptr [esp + 0x34], 4
// 0066062c  3bc3                 cmp eax, ebx
// 0066062e  741d                 je 0x66064d
// 00660630  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 00660634  51                   push ecx
// 00660635  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 00660639  8d542418             lea edx, [esp + 0x18]
// 0066063d  52                   push edx
// 0066063e  8b542444             mov edx, dword ptr [esp + 0x44]
// 00660642  51                   push ecx
// 00660643  52                   push edx
// 00660644  8bc8                 mov ecx, eax
// 00660646  e8e59f0000           call 0x66a630
// 0066064b  eb02                 jmp 0x66064f
// 0066064d  33c0                 xor eax, eax
// 0066064f  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 00660653  8b10                 mov edx, dword ptr [eax]
// 00660655  8b5204               mov edx, dword ptr [edx + 4]
// 00660658  51                   push ecx
// 00660659  8bc8                 mov ecx, eax
// 0066065b  c644243802           mov byte ptr [esp + 0x38], 2
// 00660660  ffd2                 call edx
// 00660662  8d4c2414             lea ecx, [esp + 0x14]
// 00660666  8bf8                 mov edi, eax
// 00660668  885c2434             mov byte ptr [esp + 0x34], bl
// 0066066c  e8dffef2ff           call 0x590550
// 00660671  8b442454             mov eax, dword ptr [esp + 0x54]
// 00660675  c7442434ffffffff     mov dword ptr [esp + 0x34], 0xffffffff
// 0066067d  3bc3                 cmp eax, ebx
// 0066067f  742c                 je 0x6606ad
// 00660681  8bf0                 mov esi, eax
// 00660683  83c9ff               or ecx, 0xffffffff
// 00660686  83c004               add eax, 4
// 00660689  f00fc108             lock xadd dword ptr [eax], ecx
// 0066068d  751e                 jne 0x6606ad
// 0066068f  8b16                 mov edx, dword ptr [esi]
// 00660691  8b4204               mov eax, dword ptr [edx + 4]
// 00660694  8bce                 mov ecx, esi
// 00660696  ffd0                 call eax
// 00660698  83caff               or edx, 0xffffffff
// 0066069b  8d4e08               lea ecx, [esi + 8]
// 0066069e  f00fc111             lock xadd dword ptr [ecx], edx
// 006606a2  7509                 jne 0x6606ad
// 006606a4  8b06                 mov eax, dword ptr [esi]
// 006606a6  8b5008               mov edx, dword ptr [eax + 8]
// 006606a9  8bce                 mov ecx, esi
// 006606ab  ffd2                 call edx
// 006606ad  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 006606b1  8bc7                 mov eax, edi
// 006606b3  5f                   pop edi
// 006606b4  5e                   pop esi
// 006606b5  64890d00000000       mov dword ptr fs:[0], ecx
// 006606bc  5b                   pop ebx
// 006606bd  83c42c               add esp, 0x2c
// 006606c0  c3                   ret 

#include <intrin.h>

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Control {
    virtual void unused();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Count {
    Control* control;

    Count(const Count&);
    ~Count();
};

inline Count::Count(const Count& other)
    : control(other.control)
{
    if (control) {
        volatile long* count = &control->strong;
        _InterlockedExchangeAdd(count, 1);
    }
}

inline Count::~Count()
{
    if (control) {
        Control* p = control;
        if (_InterlockedDecrement(&p->strong) == 0) {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

struct Shared {
    void* pointer;
    Count count;

    Shared(const Shared&);
    ~Shared();
};

inline Shared::Shared(const Shared& other)
    : pointer(other.pointer), count(other.count)
{
}

inline Shared::~Shared()
{
}

struct Collection;

struct Proxy {
    Collection* owner;
    Proxy(Collection*);
};

inline Proxy::Proxy(Collection* p) : owner(p) {}

struct ProxyOwner {
    Proxy* proxy;
    ProxyOwner(Collection*);
    ~ProxyOwner();
};

inline ProxyOwner::ProxyOwner(Collection* p) : proxy(new Proxy(p)) {}

struct CollectionVal : ProxyOwner {
    unsigned int reserved[2];
    Shared* first;
    Shared* last;
    Shared* limit;
    CollectionVal(Collection* c) : ProxyOwner(c) {}
};

struct Collection : CollectionVal {
    Collection();
    ~Collection();
    bool buy(unsigned int capacity)
    {
        first = 0; last = 0; limit = 0;
        if (capacity == 0)
            return false;
        first = (Shared*)operator new(capacity * sizeof(Shared));
        last = first;
        limit = first + capacity;
        return true;
    }
};

inline Collection::Collection()
    : CollectionVal(this)
{
    buy(0);
}

extern void __cdecl collect(void*, Collection*);

struct Filter {
    virtual void unused();
    virtual int apply(void*);
};

struct SingleFilter : Filter {
    unsigned char storage[64];
    SingleFilter(void*, void*, void*, Shared);
};

struct MultipleFilter : Filter {
    unsigned char storage[52];
    MultipleFilter(void*, void*, Collection*, void*);
};

int __cdecl makeFilter(void* a, void* b, void* source, void* value,
                       void* context, Shared shared)
{
    Collection collection;
    collect(source, &collection);

    if (collection.last - collection.first == 1)
        return static_cast<Filter*>(new SingleFilter(a, b, context, shared))->apply(value);
    else
        return static_cast<Filter*>(new MultipleFilter(a, b, &collection, context))->apply(value);
}
