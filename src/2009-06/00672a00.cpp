// from server: 97% by EspClaude
// from server: 100% by colin
// roc 2008-06 005d33a0  unit: RBX::VSpawnLocation::?$FactoryProduct  size: 228 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005d33a0
//
// 005d33a0  64a100000000         mov eax, dword ptr fs:[0]
// 005d33a6  6aff                 push -1
// 005d33a8  6868917d00           push 0x7d9168
// 005d33ad  50                   push eax
// 005d33ae  64892500000000       mov dword ptr fs:[0], esp
// 005d33b5  83ec08               sub esp, 8
// 005d33b8  56                   push esi
// 005d33b9  8bf1                 mov esi, ecx
// 005d33bb  e870d8ebff           call 0x490c30
// 005d33c0  85c0                 test eax, eax
// 005d33c2  0f85ac000000         jne 0x5d3474
// 005d33c8  53                   push ebx
// 005d33c9  8d442408             lea eax, [esp + 8]
// 005d33cd  57                   push edi
// 005d33ce  50                   push eax
// 005d33cf  e84cbeebff           call 0x48f220
// 005d33d4  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 005d33d8  68f4fb9600           push 0x96fbf4
// 005d33dd  6870ad4800           push 0x48ad70
// 005d33e2  c744242800000000     mov dword ptr [esp + 0x28], 0
// 005d33ea  e8413ff8ff           call 0x557330
// 005d33ef  83c40c               add esp, 0xc
// 005d33f2  e8c970ebff           call 0x48a4c0
// 005d33f7  8b8ea0010000         mov ecx, dword ptr [esi + 0x1a0]
// 005d33fd  2b8e9c010000         sub ecx, dword ptr [esi + 0x19c]
// 005d3403  8bf8                 mov edi, eax
// 005d3405  c1f903               sar ecx, 3
// 005d3408  3bf9                 cmp edi, ecx
// 005d340a  7206                 jb 0x5d3412
// 005d340c  ff1590288000         call dword ptr [0x802890]
// 005d3412  8b969c010000         mov edx, dword ptr [esi + 0x19c]
// 005d3418  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005d341c  8d04fa               lea eax, [edx + edi*8]
// 005d341f  8d542410             lea edx, [esp + 0x10]
// 005d3423  8908                 mov dword ptr [eax], ecx
// 005d3425  52                   push edx
// 005d3426  8d4804               lea ecx, [eax + 4]
// 005d3429  e882f1e2ff           call 0x4025b0
// 005d342e  56                   push esi
// 005d342f  8bcb                 mov ecx, ebx
// 005d3431  e8ba74f8ff           call 0x55a8f0
// 005d3436  8b742410             mov esi, dword ptr [esp + 0x10]
// 005d343a  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 005d3442  85f6                 test esi, esi
// 005d3444  742a                 je 0x5d3470
// 005d3446  8d4604               lea eax, [esi + 4]
// 005d3449  83c9ff               or ecx, 0xffffffff
// 005d344c  f00fc108             lock xadd dword ptr [eax], ecx
// 005d3450  751e                 jne 0x5d3470
// 005d3452  8b16                 mov edx, dword ptr [esi]
// 005d3454  8b4204               mov eax, dword ptr [edx + 4]
// 005d3457  8bce                 mov ecx, esi
// 005d3459  ffd0                 call eax
// 005d345b  8d4e08               lea ecx, [esi + 8]
// 005d345e  83caff               or edx, 0xffffffff
// 005d3461  f00fc111             lock xadd dword ptr [ecx], edx
// 005d3465  7509                 jne 0x5d3470
// 005d3467  8b06                 mov eax, dword ptr [esi]
// 005d3469  8b5008               mov edx, dword ptr [eax + 8]
// 005d346c  8bce                 mov ecx, esi
// 005d346e  ffd2                 call edx
// 005d3470  5f                   pop edi
// 005d3471  8bc3                 mov eax, ebx
// 005d3473  5b                   pop ebx
// 005d3474  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005d3478  5e                   pop esi
// 005d3479  64890d00000000       mov dword ptr fs:[0], ecx
// 005d3480  83c414               add esp, 0x14
// 005d3483  c3                   ret 

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
    char padding[0x19c];
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
