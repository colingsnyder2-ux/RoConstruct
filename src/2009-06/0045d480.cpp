// from server: 100% by EspClaude
// from server: 100% by colin
// roc 2008-06 0045de20  unit: RBX::VCamera::?$FactoryProduct::Creator  size: 228 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0045de20
//
// 0045de20  64a100000000         mov eax, dword ptr fs:[0]
// 0045de26  6aff                 push -1
// 0045de28  6868917d00           push 0x7d9168
// 0045de2d  50                   push eax
// 0045de2e  64892500000000       mov dword ptr fs:[0], esp
// 0045de35  83ec08               sub esp, 8
// 0045de38  56                   push esi
// 0045de39  8bf1                 mov esi, ecx
// 0045de3b  e8a0feffff           call 0x45dce0
// 0045de40  85c0                 test eax, eax
// 0045de42  0f85ac000000         jne 0x45def4
// 0045de48  53                   push ebx
// 0045de49  8d442408             lea eax, [esp + 8]
// 0045de4d  57                   push edi
// 0045de4e  50                   push eax
// 0045de4f  e82ce7ffff           call 0x45c580
// 0045de54  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0045de58  6894de9600           push 0x96de94
// 0045de5d  6820b84500           push 0x45b820
// 0045de62  c744242800000000     mov dword ptr [esp + 0x28], 0
// 0045de6a  e8c1940f00           call 0x557330
// 0045de6f  83c40c               add esp, 0xc
// 0045de72  e839d4ffff           call 0x45b2b0
// 0045de77  8b8ea0010000         mov ecx, dword ptr [esi + 0x1a0]
// 0045de7d  2b8e9c010000         sub ecx, dword ptr [esi + 0x19c]
// 0045de83  8bf8                 mov edi, eax
// 0045de85  c1f903               sar ecx, 3
// 0045de88  3bf9                 cmp edi, ecx
// 0045de8a  7206                 jb 0x45de92
// 0045de8c  ff1590288000         call dword ptr [0x802890]
// 0045de92  8b969c010000         mov edx, dword ptr [esi + 0x19c]
// 0045de98  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0045de9c  8d04fa               lea eax, [edx + edi*8]
// 0045de9f  8d542410             lea edx, [esp + 0x10]
// 0045dea3  8908                 mov dword ptr [eax], ecx
// 0045dea5  52                   push edx
// 0045dea6  8d4804               lea ecx, [eax + 4]
// 0045dea9  e80247faff           call 0x4025b0
// 0045deae  56                   push esi
// 0045deaf  8bcb                 mov ecx, ebx
// 0045deb1  e83aca0f00           call 0x55a8f0
// 0045deb6  8b742410             mov esi, dword ptr [esp + 0x10]
// 0045deba  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 0045dec2  85f6                 test esi, esi
// 0045dec4  742a                 je 0x45def0
// 0045dec6  8d4604               lea eax, [esi + 4]
// 0045dec9  83c9ff               or ecx, 0xffffffff
// 0045decc  f00fc108             lock xadd dword ptr [eax], ecx
// 0045ded0  751e                 jne 0x45def0
// 0045ded2  8b16                 mov edx, dword ptr [esi]
// 0045ded4  8b4204               mov eax, dword ptr [edx + 4]
// 0045ded7  8bce                 mov ecx, esi
// 0045ded9  ffd0                 call eax
// 0045dedb  8d4e08               lea ecx, [esi + 8]
// 0045dede  83caff               or edx, 0xffffffff
// 0045dee1  f00fc111             lock xadd dword ptr [ecx], edx
// 0045dee5  7509                 jne 0x45def0
// 0045dee7  8b06                 mov eax, dword ptr [esi]
// 0045dee9  8b5008               mov edx, dword ptr [eax + 8]
// 0045deec  8bce                 mov ecx, esi
// 0045deee  ffd2                 call edx
// 0045def0  5f                   pop edi
// 0045def1  8bc3                 mov eax, ebx
// 0045def3  5b                   pop ebx
// 0045def4  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0045def8  5e                   pop esi
// 0045def9  64890d00000000       mov dword ptr fs:[0], ecx
// 0045df00  83c414               add esp, 0x14
// 0045df03  c3                   ret 

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
