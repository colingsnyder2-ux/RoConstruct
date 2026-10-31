// from server: 97% by EspClaude
// from server: 100% by colin
// roc 2008-06 004153b0  unit: RBX::VChangeHistoryService::?$FactoryProduct::Creator  size: 228 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004153b0
//
// 004153b0  64a100000000         mov eax, dword ptr fs:[0]
// 004153b6  6aff                 push -1
// 004153b8  6868917d00           push 0x7d9168
// 004153bd  50                   push eax
// 004153be  64892500000000       mov dword ptr fs:[0], esp
// 004153c5  83ec08               sub esp, 8
// 004153c8  56                   push esi
// 004153c9  8bf1                 mov esi, ecx
// 004153cb  e830feffff           call 0x415200
// 004153d0  85c0                 test eax, eax
// 004153d2  0f85ac000000         jne 0x415484
// 004153d8  53                   push ebx
// 004153d9  8d442408             lea eax, [esp + 8]
// 004153dd  57                   push edi
// 004153de  50                   push eax
// 004153df  e83c42ffff           call 0x409620
// 004153e4  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 004153e8  6830cc9600           push 0x96cc30
// 004153ed  68603a4100           push 0x413a60
// 004153f2  c744242800000000     mov dword ptr [esp + 0x28], 0
// 004153fa  e8311f1400           call 0x557330
// 004153ff  83c40c               add esp, 0xc
// 00415402  e809e4ffff           call 0x413810
// 00415407  8b8ea0010000         mov ecx, dword ptr [esi + 0x1a0]
// 0041540d  2b8e9c010000         sub ecx, dword ptr [esi + 0x19c]
// 00415413  8bf8                 mov edi, eax
// 00415415  c1f903               sar ecx, 3
// 00415418  3bf9                 cmp edi, ecx
// 0041541a  7206                 jb 0x415422
// 0041541c  ff1590288000         call dword ptr [0x802890]
// 00415422  8b969c010000         mov edx, dword ptr [esi + 0x19c]
// 00415428  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0041542c  8d04fa               lea eax, [edx + edi*8]
// 0041542f  8d542410             lea edx, [esp + 0x10]
// 00415433  8908                 mov dword ptr [eax], ecx
// 00415435  52                   push edx
// 00415436  8d4804               lea ecx, [eax + 4]
// 00415439  e872d1feff           call 0x4025b0
// 0041543e  56                   push esi
// 0041543f  8bcb                 mov ecx, ebx
// 00415441  e8aa541400           call 0x55a8f0
// 00415446  8b742410             mov esi, dword ptr [esp + 0x10]
// 0041544a  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 00415452  85f6                 test esi, esi
// 00415454  742a                 je 0x415480
// 00415456  8d4604               lea eax, [esi + 4]
// 00415459  83c9ff               or ecx, 0xffffffff
// 0041545c  f00fc108             lock xadd dword ptr [eax], ecx
// 00415460  751e                 jne 0x415480
// 00415462  8b16                 mov edx, dword ptr [esi]
// 00415464  8b4204               mov eax, dword ptr [edx + 4]
// 00415467  8bce                 mov ecx, esi
// 00415469  ffd0                 call eax
// 0041546b  8d4e08               lea ecx, [esi + 8]
// 0041546e  83caff               or edx, 0xffffffff
// 00415471  f00fc111             lock xadd dword ptr [ecx], edx
// 00415475  7509                 jne 0x415480
// 00415477  8b06                 mov eax, dword ptr [esi]
// 00415479  8b5008               mov edx, dword ptr [eax + 8]
// 0041547c  8bce                 mov ecx, esi
// 0041547e  ffd2                 call edx
// 00415480  5f                   pop edi
// 00415481  8bc3                 mov eax, ebx
// 00415483  5b                   pop ebx
// 00415484  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00415488  5e                   pop esi
// 00415489  64890d00000000       mov dword ptr fs:[0], ecx
// 00415490  83c414               add esp, 0x14
// 00415493  c3                   ret 

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
