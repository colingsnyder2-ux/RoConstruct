// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005805d0  unit: RBX::VVelocityMotor::?$FactoryProduct::Creator  size: 228 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005805d0
//
// 005805d0  64a100000000         mov eax, dword ptr fs:[0]
// 005805d6  6aff                 push -1
// 005805d8  6868917d00           push 0x7d9168
// 005805dd  50                   push eax
// 005805de  64892500000000       mov dword ptr fs:[0], esp
// 005805e5  83ec08               sub esp, 8
// 005805e8  56                   push esi
// 005805e9  8bf1                 mov esi, ecx
// 005805eb  e830f7ffff           call 0x57fd20
// 005805f0  85c0                 test eax, eax
// 005805f2  0f85ac000000         jne 0x5806a4
// 005805f8  53                   push ebx
// 005805f9  8d442408             lea eax, [esp + 8]
// 005805fd  57                   push edi
// 005805fe  50                   push eax
// 005805ff  e80cf1ffff           call 0x57f710
// 00580604  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 00580608  68c4539700           push 0x9753c4
// 0058060d  68a0dd5700           push 0x57dda0
// 00580612  c744242800000000     mov dword ptr [esp + 0x28], 0
// 0058061a  e8116dfdff           call 0x557330
// 0058061f  83c40c               add esp, 0xc
// 00580622  e8d9d1ffff           call 0x57d800
// 00580627  8b8ea0010000         mov ecx, dword ptr [esi + 0x1a0]
// 0058062d  2b8e9c010000         sub ecx, dword ptr [esi + 0x19c]
// 00580633  8bf8                 mov edi, eax
// 00580635  c1f903               sar ecx, 3
// 00580638  3bf9                 cmp edi, ecx
// 0058063a  7206                 jb 0x580642
// 0058063c  ff1590288000         call dword ptr [0x802890]
// 00580642  8b969c010000         mov edx, dword ptr [esi + 0x19c]
// 00580648  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0058064c  8d04fa               lea eax, [edx + edi*8]
// 0058064f  8d542410             lea edx, [esp + 0x10]
// 00580653  8908                 mov dword ptr [eax], ecx
// 00580655  52                   push edx
// 00580656  8d4804               lea ecx, [eax + 4]
// 00580659  e8521fe8ff           call 0x4025b0
// 0058065e  56                   push esi
// 0058065f  8bcb                 mov ecx, ebx
// 00580661  e88aa2fdff           call 0x55a8f0
// 00580666  8b742410             mov esi, dword ptr [esp + 0x10]
// 0058066a  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 00580672  85f6                 test esi, esi
// 00580674  742a                 je 0x5806a0
// 00580676  8d4604               lea eax, [esi + 4]
// 00580679  83c9ff               or ecx, 0xffffffff
// 0058067c  f00fc108             lock xadd dword ptr [eax], ecx
// 00580680  751e                 jne 0x5806a0
// 00580682  8b16                 mov edx, dword ptr [esi]
// 00580684  8b4204               mov eax, dword ptr [edx + 4]
// 00580687  8bce                 mov ecx, esi
// 00580689  ffd0                 call eax
// 0058068b  8d4e08               lea ecx, [esi + 8]
// 0058068e  83caff               or edx, 0xffffffff
// 00580691  f00fc111             lock xadd dword ptr [ecx], edx
// 00580695  7509                 jne 0x5806a0
// 00580697  8b06                 mov eax, dword ptr [esi]
// 00580699  8b5008               mov edx, dword ptr [eax + 8]
// 0058069c  8bce                 mov ecx, esi
// 0058069e  ffd2                 call edx
// 005806a0  5f                   pop edi
// 005806a1  8bc3                 mov eax, ebx
// 005806a3  5b                   pop ebx
// 005806a4  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005806a8  5e                   pop esi
// 005806a9  64890d00000000       mov dword ptr fs:[0], ecx
// 005806b0  83c414               add esp, 0x14
// 005806b3  c3                   ret 

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
