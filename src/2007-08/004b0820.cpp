// from server: 100% by EspClaude
// from server: 85% by EspClaude
// roc-cl: 50727
// from server: 100% by colin
// roc 2008-06 004b3a50  unit: RBX::Network::VMarker::?$SignalDesc  size: 228 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004b3a50
//
// 004b3a50  64a100000000         mov eax, dword ptr fs:[0]
// 004b3a56  6aff                 push -1
// 004b3a58  6868917d00           push 0x7d9168
// 004b3a5d  50                   push eax
// 004b3a5e  64892500000000       mov dword ptr fs:[0], esp
// 004b3a65  83ec08               sub esp, 8
// 004b3a68  56                   push esi
// 004b3a69  8bf1                 mov esi, ecx
// 004b3a6b  e850faffff           call 0x4b34c0
// 004b3a70  85c0                 test eax, eax
// 004b3a72  0f85ac000000         jne 0x4b3b24
// 004b3a78  53                   push ebx
// 004b3a79  8d442408             lea eax, [esp + 8]
// 004b3a7d  57                   push edi
// 004b3a7e  50                   push eax
// 004b3a7f  e86cd3ffff           call 0x4b0df0
// 004b3a84  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 004b3a88  6894149700           push 0x971494
// 004b3a8d  6810c64a00           push 0x4ac610
// 004b3a92  c744242800000000     mov dword ptr [esp + 0x28], 0
// 004b3a9a  e891380a00           call 0x557330
// 004b3a9f  83c40c               add esp, 0xc
// 004b3aa2  e8297affff           call 0x4ab4d0
// 004b3aa7  8b8ea0010000         mov ecx, dword ptr [esi + 0x1a0]
// 004b3aad  2b8e9c010000         sub ecx, dword ptr [esi + 0x19c]
// 004b3ab3  8bf8                 mov edi, eax
// 004b3ab5  c1f903               sar ecx, 3
// 004b3ab8  3bf9                 cmp edi, ecx
// 004b3aba  7206                 jb 0x4b3ac2
// 004b3abc  ff1590288000         call dword ptr [0x802890]
// 004b3ac2  8b969c010000         mov edx, dword ptr [esi + 0x19c]
// 004b3ac8  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004b3acc  8d04fa               lea eax, [edx + edi*8]
// 004b3acf  8d542410             lea edx, [esp + 0x10]
// 004b3ad3  8908                 mov dword ptr [eax], ecx
// 004b3ad5  52                   push edx
// 004b3ad6  8d4804               lea ecx, [eax + 4]
// 004b3ad9  e8d2eaf4ff           call 0x4025b0
// 004b3ade  56                   push esi
// 004b3adf  8bcb                 mov ecx, ebx
// 004b3ae1  e80a6e0a00           call 0x55a8f0
// 004b3ae6  8b742410             mov esi, dword ptr [esp + 0x10]
// 004b3aea  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 004b3af2  85f6                 test esi, esi
// 004b3af4  742a                 je 0x4b3b20
// 004b3af6  8d4604               lea eax, [esi + 4]
// 004b3af9  83c9ff               or ecx, 0xffffffff
// 004b3afc  f00fc108             lock xadd dword ptr [eax], ecx
// 004b3b00  751e                 jne 0x4b3b20
// 004b3b02  8b16                 mov edx, dword ptr [esi]
// 004b3b04  8b4204               mov eax, dword ptr [edx + 4]
// 004b3b07  8bce                 mov ecx, esi
// 004b3b09  ffd0                 call eax
// 004b3b0b  8d4e08               lea ecx, [esi + 8]
// 004b3b0e  83caff               or edx, 0xffffffff
// 004b3b11  f00fc111             lock xadd dword ptr [ecx], edx
// 004b3b15  7509                 jne 0x4b3b20
// 004b3b17  8b06                 mov eax, dword ptr [esi]
// 004b3b19  8b5008               mov edx, dword ptr [eax + 8]
// 004b3b1c  8bce                 mov ecx, esi
// 004b3b1e  ffd2                 call edx
// 004b3b20  5f                   pop edi
// 004b3b21  8bc3                 mov eax, ebx
// 004b3b23  5b                   pop ebx
// 004b3b24  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004b3b28  5e                   pop esi
// 004b3b29  64890d00000000       mov dword ptr fs:[0], ecx
// 004b3b30  83c414               add esp, 0x14
// 004b3b33  c3                   ret 

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
    char padding[0x134];
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
        if (index >= (unsigned)(first == 0 ? 0 : last - first))
            invalid_parameter_noinfo();
        Entry& entry = first[index];
        entry.value = p.value;
        entry.owner = p.owner;
        result->attach(this);
    }
    return result;
}
