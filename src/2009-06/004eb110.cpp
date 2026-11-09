// from server: 100% by EspClaude
// from server: 97% by EspClaude
// roc 2009-06 004eb110  unit: std::D::DU?$char_traits::$$A6AXV?$basic_string::?$signal::slot  size: 228 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004eb110
//
// 004eb110  64a100000000         mov eax, dword ptr fs:[0]
// 004eb116  6aff                 push -1
// 004eb118  68e8a68600           push 0x86a6e8
// 004eb11d  50                   push eax
// 004eb11e  64892500000000       mov dword ptr fs:[0], esp
// 004eb125  83ec08               sub esp, 8
// 004eb128  56                   push esi
// 004eb129  8bf1                 mov esi, ecx
// 004eb12b  e8b022fdff           call 0x4bd3e0
// 004eb130  85c0                 test eax, eax
// 004eb132  0f85ac000000         jne 0x4eb1e4
// 004eb138  53                   push ebx
// 004eb139  8d442408             lea eax, [esp + 8]
// 004eb13d  57                   push edi
// 004eb13e  50                   push eax
// 004eb13f  e8dcc5f2ff           call 0x417720
// 004eb144  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 004eb148  68904b4b00           push 0x4b4b90
// 004eb14d  6834d5a300           push 0xa3d534
// 004eb152  c744242800000000     mov dword ptr [esp + 0x28], 0
// 004eb15a  e8b165f1ff           call 0x401710
// 004eb15f  83c40c               add esp, 0xc
// 004eb162  e8a98ffcff           call 0x4b4110
// 004eb167  8b8e9c000000         mov ecx, dword ptr [esi + 0x9c]
// 004eb16d  2b8e98000000         sub ecx, dword ptr [esi + 0x98]
// 004eb173  8bf8                 mov edi, eax
// 004eb175  c1f903               sar ecx, 3
// 004eb178  3bf9                 cmp edi, ecx
// 004eb17a  7206                 jb 0x4eb182
// 004eb17c  ff15ace98900         call dword ptr [0x89e9ac]
// 004eb182  8b9698000000         mov edx, dword ptr [esi + 0x98]
// 004eb188  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004eb18c  8d04fa               lea eax, [edx + edi*8]
// 004eb18f  8d542410             lea edx, [esp + 0x10]
// 004eb193  8908                 mov dword ptr [eax], ecx
// 004eb195  52                   push edx
// 004eb196  8d4804               lea ecx, [eax + 4]
// 004eb199  e86273f1ff           call 0x402500
// 004eb19e  56                   push esi
// 004eb19f  8bcb                 mov ecx, ebx
// 004eb1a1  e8aa6c0e00           call 0x5d1e50
// 004eb1a6  8b742410             mov esi, dword ptr [esp + 0x10]
// 004eb1aa  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 004eb1b2  85f6                 test esi, esi
// 004eb1b4  742a                 je 0x4eb1e0
// 004eb1b6  8d4604               lea eax, [esi + 4]
// 004eb1b9  83c9ff               or ecx, 0xffffffff
// 004eb1bc  f00fc108             lock xadd dword ptr [eax], ecx
// 004eb1c0  751e                 jne 0x4eb1e0
// 004eb1c2  8b16                 mov edx, dword ptr [esi]
// 004eb1c4  8b4204               mov eax, dword ptr [edx + 4]
// 004eb1c7  8bce                 mov ecx, esi
// 004eb1c9  ffd0                 call eax
// 004eb1cb  8d4e08               lea ecx, [esi + 8]
// 004eb1ce  83caff               or edx, 0xffffffff
// 004eb1d1  f00fc111             lock xadd dword ptr [ecx], edx
// 004eb1d5  7509                 jne 0x4eb1e0
// 004eb1d7  8b06                 mov eax, dword ptr [esi]
// 004eb1d9  8b5008               mov edx, dword ptr [eax + 8]
// 004eb1dc  8bce                 mov ecx, esi
// 004eb1de  ffd2                 call edx
// 004eb1e0  5f                   pop edi
// 004eb1e1  8bc3                 mov eax, ebx
// 004eb1e3  5b                   pop ebx
// 004eb1e4  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004eb1e8  5e                   pop esi
// 004eb1e9  64890d00000000       mov dword ptr fs:[0], ecx
// 004eb1f0  83c414               add esp, 0x14
// 004eb1f3  c3                   ret 

// from server: 100% by colin
// roc 2008-06 004b3960  unit: RBX::Network::VMarker::?$SignalDesc  size: 228 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004b3960
//
// 004b3960  64a100000000         mov eax, dword ptr fs:[0]
// 004b3966  6aff                 push -1
// 004b3968  6868917d00           push 0x7d9168
// 004b396d  50                   push eax
// 004b396e  64892500000000       mov dword ptr fs:[0], esp
// 004b3975  83ec08               sub esp, 8
// 004b3978  56                   push esi
// 004b3979  8bf1                 mov esi, ecx
// 004b397b  e8f0d3fdff           call 0x490d70
// 004b3980  85c0                 test eax, eax
// 004b3982  0f85ac000000         jne 0x4b3a34
// 004b3988  53                   push ebx
// 004b3989  8d442408             lea eax, [esp + 8]
// 004b398d  57                   push edi
// 004b398e  50                   push eax
// 004b398f  e86cb0fdff           call 0x48ea00
// 004b3994  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 004b3998  68f8fb9600           push 0x96fbf8
// 004b399d  6880ad4800           push 0x48ad80
// 004b39a2  c744242800000000     mov dword ptr [esp + 0x28], 0
// 004b39aa  e881390a00           call 0x557330
// 004b39af  83c40c               add esp, 0xc
// 004b39b2  e8696bfdff           call 0x48a520
// 004b39b7  8b8ea0010000         mov ecx, dword ptr [esi + 0x1a0]
// 004b39bd  2b8e9c010000         sub ecx, dword ptr [esi + 0x19c]
// 004b39c3  8bf8                 mov edi, eax
// 004b39c5  c1f903               sar ecx, 3
// 004b39c8  3bf9                 cmp edi, ecx
// 004b39ca  7206                 jb 0x4b39d2
// 004b39cc  ff1590288000         call dword ptr [0x802890]
// 004b39d2  8b969c010000         mov edx, dword ptr [esi + 0x19c]
// 004b39d8  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004b39dc  8d04fa               lea eax, [edx + edi*8]
// 004b39df  8d542410             lea edx, [esp + 0x10]
// 004b39e3  8908                 mov dword ptr [eax], ecx
// 004b39e5  52                   push edx
// 004b39e6  8d4804               lea ecx, [eax + 4]
// 004b39e9  e8c2ebf4ff           call 0x4025b0
// 004b39ee  56                   push esi
// 004b39ef  8bcb                 mov ecx, ebx
// 004b39f1  e8fa6e0a00           call 0x55a8f0
// 004b39f6  8b742410             mov esi, dword ptr [esp + 0x10]
// 004b39fa  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 004b3a02  85f6                 test esi, esi
// 004b3a04  742a                 je 0x4b3a30
// 004b3a06  8d4604               lea eax, [esi + 4]
// 004b3a09  83c9ff               or ecx, 0xffffffff
// 004b3a0c  f00fc108             lock xadd dword ptr [eax], ecx
// 004b3a10  751e                 jne 0x4b3a30
// 004b3a12  8b16                 mov edx, dword ptr [esi]
// 004b3a14  8b4204               mov eax, dword ptr [edx + 4]
// 004b3a17  8bce                 mov ecx, esi
// 004b3a19  ffd0                 call eax
// 004b3a1b  8d4e08               lea ecx, [esi + 8]
// 004b3a1e  83caff               or edx, 0xffffffff
// 004b3a21  f00fc111             lock xadd dword ptr [ecx], edx
// 004b3a25  7509                 jne 0x4b3a30
// 004b3a27  8b06                 mov eax, dword ptr [esi]
// 004b3a29  8b5008               mov edx, dword ptr [eax + 8]
// 004b3a2c  8bce                 mov ecx, esi
// 004b3a2e  ffd2                 call edx
// 004b3a30  5f                   pop edi
// 004b3a31  8bc3                 mov eax, ebx
// 004b3a33  5b                   pop ebx
// 004b3a34  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004b3a38  5e                   pop esi
// 004b3a39  64890d00000000       mov dword ptr fs:[0], ecx
// 004b3a40  83c414               add esp, 0x14
// 004b3a43  c3                   ret 

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct S;

struct Ref {
    virtual void reserved();
    virtual void dispose();
    virtual void destroy();

    volatile long strong;
    volatile long weak;

    void attach(S*);
    void release();
};

inline void Ref::release() {
    if (_InterlockedDecrement(&strong) == 0) {
        dispose();
        if (_InterlockedDecrement(&weak) == 0)
            destroy();
    }
}

struct RefSlot {
    Ref* value;
    RefSlot& operator=(const RefSlot&);
};

struct Pair {
    Ref* value;
    RefSlot owner;
    ~Pair();
};

inline Pair::~Pair() {
    if (owner.value)
        owner.value->release();
}

struct Entry {
    Ref* value;
    RefSlot owner;
};

struct S {
    char padding[0x98];
    Entry* first;
    Entry* last;

    Ref* existing();
    Ref* create();
};

Pair __cdecl make_pair();
void __cdecl register_value(void (__cdecl*)(), void*);
void __cdecl cleanup_value();
extern char registration_data;
void* __cdecl func_0057d800();
extern "C" void (__cdecl* invalid_parameter_noinfo)();

Ref* S::create() {
    Ref* result = existing();
    if (!result) {
        Pair p = make_pair();
        result = p.value;
        register_value(cleanup_value, &registration_data);
        unsigned index = (unsigned)func_0057d800();
        if (index >= (unsigned)(last - first))
            invalid_parameter_noinfo();
        Entry& entry = first[index];
        entry.value = p.value;
        entry.owner = p.owner;
        result->attach(this);
    }
    return result;
}
