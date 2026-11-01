// from server: 97% by EspClaude
// from server: 100% by colin
// roc 2008-06 00458610  unit: RBX::VInstance::?$NonFactoryProduct  size: 228 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00458610
//
// 00458610  64a100000000         mov eax, dword ptr fs:[0]
// 00458616  6aff                 push -1
// 00458618  6868917d00           push 0x7d9168
// 0045861d  50                   push eax
// 0045861e  64892500000000       mov dword ptr fs:[0], esp
// 00458625  83ec08               sub esp, 8
// 00458628  56                   push esi
// 00458629  8bf1                 mov esi, ecx
// 0045862b  e830f5ffff           call 0x457b60
// 00458630  85c0                 test eax, eax
// 00458632  0f85ac000000         jne 0x4586e4
// 00458638  53                   push ebx
// 00458639  8d442408             lea eax, [esp + 8]
// 0045863d  57                   push edi
// 0045863e  50                   push eax
// 0045863f  e84cffffff           call 0x458590
// 00458644  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 00458648  689cdd9600           push 0x96dd9c
// 0045864d  6800644500           push 0x456400
// 00458652  c744242800000000     mov dword ptr [esp + 0x28], 0
// 0045865a  e8d1ec0f00           call 0x557330
// 0045865f  83c40c               add esp, 0xc
// 00458662  e839d8ffff           call 0x455ea0
// 00458667  8b8ea0010000         mov ecx, dword ptr [esi + 0x1a0]
// 0045866d  2b8e9c010000         sub ecx, dword ptr [esi + 0x19c]
// 00458673  8bf8                 mov edi, eax
// 00458675  c1f903               sar ecx, 3
// 00458678  3bf9                 cmp edi, ecx
// 0045867a  7206                 jb 0x458682
// 0045867c  ff1590288000         call dword ptr [0x802890]
// 00458682  8b969c010000         mov edx, dword ptr [esi + 0x19c]
// 00458688  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0045868c  8d04fa               lea eax, [edx + edi*8]
// 0045868f  8d542410             lea edx, [esp + 0x10]
// 00458693  8908                 mov dword ptr [eax], ecx
// 00458695  52                   push edx
// 00458696  8d4804               lea ecx, [eax + 4]
// 00458699  e8129ffaff           call 0x4025b0
// 0045869e  56                   push esi
// 0045869f  8bcb                 mov ecx, ebx
// 004586a1  e84a221000           call 0x55a8f0
// 004586a6  8b742410             mov esi, dword ptr [esp + 0x10]
// 004586aa  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 004586b2  85f6                 test esi, esi
// 004586b4  742a                 je 0x4586e0
// 004586b6  8d4604               lea eax, [esi + 4]
// 004586b9  83c9ff               or ecx, 0xffffffff
// 004586bc  f00fc108             lock xadd dword ptr [eax], ecx
// 004586c0  751e                 jne 0x4586e0
// 004586c2  8b16                 mov edx, dword ptr [esi]
// 004586c4  8b4204               mov eax, dword ptr [edx + 4]
// 004586c7  8bce                 mov ecx, esi
// 004586c9  ffd0                 call eax
// 004586cb  8d4e08               lea ecx, [esi + 8]
// 004586ce  83caff               or edx, 0xffffffff
// 004586d1  f00fc111             lock xadd dword ptr [ecx], edx
// 004586d5  7509                 jne 0x4586e0
// 004586d7  8b06                 mov eax, dword ptr [esi]
// 004586d9  8b5008               mov edx, dword ptr [eax + 8]
// 004586dc  8bce                 mov ecx, esi
// 004586de  ffd2                 call edx
// 004586e0  5f                   pop edi
// 004586e1  8bc3                 mov eax, ebx
// 004586e3  5b                   pop ebx
// 004586e4  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004586e8  5e                   pop esi
// 004586e9  64890d00000000       mov dword ptr fs:[0], ecx
// 004586f0  83c414               add esp, 0x14
// 004586f3  c3                   ret 

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
