// from server: 100% by colin
// from server: 98% by king_originala
// roc 2008-06 0045fbe0  unit: RBX::Stats::Item  size: 406 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0045fbe0
//
// 0045fbe0  6aff                 push -1
// 0045fbe2  68ba307c00           push 0x7c30ba
// 0045fbe7  64a100000000         mov eax, dword ptr fs:[0]
// 0045fbed  50                   push eax
// 0045fbee  64892500000000       mov dword ptr fs:[0], esp
// 0045fbf5  51                   push ecx
// 0045fbf6  56                   push esi
// 0045fbf7  8bf1                 mov esi, ecx
// 0045fbf9  57                   push edi
// 0045fbfa  89742408             mov dword ptr [esp + 8], esi
// 0045fbfe  c706f4998100         mov dword ptr [esi], 0x8199f4
// 0045fc04  c74654e8998100       mov dword ptr [esi + 0x54], 0x8199e8
// 0045fc0b  c74658dc998100       mov dword ptr [esi + 0x58], 0x8199dc
// 0045fc12  6a00                 push 0
// 0045fc14  c744241809000000     mov dword ptr [esp + 0x18], 9
// 0045fc1c  e88ffbffff           call 0x45f7b0
// 0045fc21  8b8eb4000000         mov ecx, dword ptr [esi + 0xb4]
// 0045fc27  c644241408           mov byte ptr [esp + 0x14], 8
// 0045fc2c  85c9                 test ecx, ecx
// 0045fc2e  7408                 je 0x45fc38
// 0045fc30  8b01                 mov eax, dword ptr [ecx]
// 0045fc32  8b10                 mov edx, dword ptr [eax]
// 0045fc34  6a01                 push 1
// 0045fc36  ffd2                 call edx
// 0045fc38  8b8eb0000000         mov ecx, dword ptr [esi + 0xb0]
// 0045fc3e  c644241407           mov byte ptr [esp + 0x14], 7
// 0045fc43  85c9                 test ecx, ecx
// 0045fc45  7408                 je 0x45fc4f
// 0045fc47  8b01                 mov eax, dword ptr [ecx]
// 0045fc49  8b10                 mov edx, dword ptr [eax]
// 0045fc4b  6a01                 push 1
// 0045fc4d  ffd2                 call edx
// 0045fc4f  8bbeac000000         mov edi, dword ptr [esi + 0xac]
// 0045fc55  c644241406           mov byte ptr [esp + 0x14], 6
// 0045fc5a  85ff                 test edi, edi
// 0045fc5c  7410                 je 0x45fc6e
// 0045fc5e  8bcf                 mov ecx, edi
// 0045fc60  e85bc20100           call 0x47bec0
// 0045fc65  57                   push edi
// 0045fc66  e80f0a2400           call 0x6a067a
// 0045fc6b  83c404               add esp, 4
// 0045fc6e  8b8e98000000         mov ecx, dword ptr [esi + 0x98]
// 0045fc74  c644241405           mov byte ptr [esp + 0x14], 5
// 0045fc79  85c9                 test ecx, ecx
// 0045fc7b  7408                 je 0x45fc85
// 0045fc7d  8b01                 mov eax, dword ptr [ecx]
// 0045fc7f  8b10                 mov edx, dword ptr [eax]
// 0045fc81  6a01                 push 1
// 0045fc83  ffd2                 call edx
// 0045fc85  8b8684000000         mov eax, dword ptr [esi + 0x84]
// 0045fc8b  c644241404           mov byte ptr [esp + 0x14], 4
// 0045fc90  85c0                 test eax, eax
// 0045fc92  740c                 je 0x45fca0
// 0045fc94  8d4828               lea ecx, [eax + 0x28]
// 0045fc97  8b01                 mov eax, dword ptr [ecx]
// 0045fc99  8b5004               mov edx, dword ptr [eax + 4]
// 0045fc9c  6a01                 push 1
// 0045fc9e  ffd2                 call edx
// 0045fca0  8b7e7c               mov edi, dword ptr [esi + 0x7c]
// 0045fca3  c644241403           mov byte ptr [esp + 0x14], 3
// 0045fca8  85ff                 test edi, edi
// 0045fcaa  742a                 je 0x45fcd6
// 0045fcac  8d4704               lea eax, [edi + 4]
// 0045fcaf  83c9ff               or ecx, 0xffffffff
// 0045fcb2  f00fc108             lock xadd dword ptr [eax], ecx
// 0045fcb6  751e                 jne 0x45fcd6
// 0045fcb8  8b17                 mov edx, dword ptr [edi]
// 0045fcba  8b4204               mov eax, dword ptr [edx + 4]
// 0045fcbd  8bcf                 mov ecx, edi
// 0045fcbf  ffd0                 call eax
// 0045fcc1  8d4f08               lea ecx, [edi + 8]
// 0045fcc4  83caff               or edx, 0xffffffff
// 0045fcc7  f00fc111             lock xadd dword ptr [ecx], edx
// 0045fccb  7509                 jne 0x45fcd6
// 0045fccd  8b07                 mov eax, dword ptr [edi]
// 0045fccf  8b5008               mov edx, dword ptr [eax + 8]
// 0045fcd2  8bcf                 mov ecx, edi
// 0045fcd4  ffd2                 call edx
// 0045fcd6  8b7e74               mov edi, dword ptr [esi + 0x74]
// 0045fcd9  c644241402           mov byte ptr [esp + 0x14], 2
// 0045fcde  85ff                 test edi, edi
// 0045fce0  742a                 je 0x45fd0c
// 0045fce2  8d4704               lea eax, [edi + 4]
// 0045fce5  83c9ff               or ecx, 0xffffffff
// 0045fce8  f00fc108             lock xadd dword ptr [eax], ecx
// 0045fcec  751e                 jne 0x45fd0c
// 0045fcee  8b17                 mov edx, dword ptr [edi]
// 0045fcf0  8b4204               mov eax, dword ptr [edx + 4]
// 0045fcf3  8bcf                 mov ecx, edi
// 0045fcf5  ffd0                 call eax
// 0045fcf7  8d4f08               lea ecx, [edi + 8]
// 0045fcfa  83caff               or edx, 0xffffffff
// 0045fcfd  f00fc111             lock xadd dword ptr [ecx], edx
// 0045fd01  7509                 jne 0x45fd0c
// 0045fd03  8b07                 mov eax, dword ptr [edi]
// 0045fd05  8b5008               mov edx, dword ptr [eax + 8]
// 0045fd08  8bcf                 mov ecx, edi
// 0045fd0a  ffd2                 call edx
// 0045fd0c  8b466c               mov eax, dword ptr [esi + 0x6c]
// 0045fd0f  c644241401           mov byte ptr [esp + 0x14], 1
// 0045fd14  85c0                 test eax, eax
// 0045fd16  7408                 je 0x45fd20
// 0045fd18  8b08                 mov ecx, dword ptr [eax]
// 0045fd1a  8b5108               mov edx, dword ptr [ecx + 8]
// 0045fd1d  50                   push eax
// 0045fd1e  ffd2                 call edx
// 0045fd20  8b7e68               mov edi, dword ptr [esi + 0x68]
// 0045fd23  c644241400           mov byte ptr [esp + 0x14], 0
// 0045fd28  85ff                 test edi, edi
// 0045fd2a  742a                 je 0x45fd56
// 0045fd2c  8d4704               lea eax, [edi + 4]
// 0045fd2f  83c9ff               or ecx, 0xffffffff
// 0045fd32  f00fc108             lock xadd dword ptr [eax], ecx
// 0045fd36  751e                 jne 0x45fd56
// 0045fd38  8b17                 mov edx, dword ptr [edi]
// 0045fd3a  8b4204               mov eax, dword ptr [edx + 4]
// 0045fd3d  8bcf                 mov ecx, edi
// 0045fd3f  ffd0                 call eax
// 0045fd41  8d4f08               lea ecx, [edi + 8]
// 0045fd44  83caff               or edx, 0xffffffff
// 0045fd47  f00fc111             lock xadd dword ptr [ecx], edx
// 0045fd4b  7509                 jne 0x45fd56
// 0045fd4d  8b07                 mov eax, dword ptr [edi]
// 0045fd4f  8b5008               mov edx, dword ptr [eax + 8]
// 0045fd52  8bcf                 mov ecx, edi
// 0045fd54  ffd2                 call edx
// 0045fd56  8bce                 mov ecx, esi
// 0045fd58  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 0045fd60  e811132400           call 0x6a1076
// 0045fd65  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0045fd69  5f                   pop edi
// 0045fd6a  5e                   pop esi
// 0045fd6b  64890d00000000       mov dword ptr fs:[0], ecx
// 0045fd72  83c410               add esp, 0x10
// 0045fd75  c3                   ret 

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)
extern "C" void __cdecl _ReadWriteBarrier();
#pragma intrinsic(_ReadWriteBarrier)

struct RefCount {
    virtual void unused();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Shared {
    void* object;
    RefCount* count;
    ~Shared();
};

inline Shared::~Shared()
{
    RefCount* p = count;
    if (p && _InterlockedDecrement(&p->strong) == 0) {
        p->dispose();
        if (_InterlockedDecrement(&p->weak) == 0)
            p->destroy();
    }
}

struct CustomObject {
    void (__stdcall **table)(CustomObject*);
};

struct CustomOwner {
    CustomObject* pointer;
    ~CustomOwner();
};

inline CustomOwner::~CustomOwner()
{
    CustomObject* p = pointer;
    if (p)
        p->table[2](p);
}

struct VirtualObject {
    virtual ~VirtualObject();
};

struct VirtualOwner {
    VirtualObject* pointer;
    ~VirtualOwner();
};

inline VirtualOwner::~VirtualOwner()
{
    if (pointer)
        delete pointer;
}

struct AdjustedObject {
    virtual void unused();
    virtual void destroy(unsigned int);
};

struct AdjustedOwner {
    char* pointer;
    ~AdjustedOwner();
};

inline AdjustedOwner::~AdjustedOwner()
{
    if (pointer)
        reinterpret_cast<AdjustedObject*>(pointer + 0x28)->destroy(1);
}

struct NameItem {
    ~NameItem();
};

struct NameOwner {
    NameItem* pointer;
    ~NameOwner();
};

inline NameOwner::~NameOwner()
{
    if (pointer)
        delete pointer;
}

struct Base {
    virtual void base0();
    char padding04[0x50];
    ~Base();
};

struct Interface54 {
    virtual void interface54();
};

struct Interface58 {
    virtual void interface58();
};

struct S : Base, Interface54, Interface58 {
    char padding5c[8];
    Shared member64;
    CustomOwner member6c;
    Shared member70;
    Shared member78;
    unsigned long padding80;
    AdjustedOwner member84;
    char padding88[0x10];
    VirtualOwner member98;
    char padding9c[0x10];
    NameOwner memberac;
    VirtualOwner memberb0;
    VirtualOwner memberb4;

    void reset(int);
    ~S();
};

S::~S()
{
    reset(0);
}
