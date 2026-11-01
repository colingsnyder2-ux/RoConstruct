// from server: 97% by EspClaude
// from server: 100% by colin
// roc 2008-06 004531e0  unit: CRobloxDoc  size: 228 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004531e0
//
// 004531e0  64a100000000         mov eax, dword ptr fs:[0]
// 004531e6  6aff                 push -1
// 004531e8  6868917d00           push 0x7d9168
// 004531ed  50                   push eax
// 004531ee  64892500000000       mov dword ptr fs:[0], esp
// 004531f5  83ec08               sub esp, 8
// 004531f8  56                   push esi
// 004531f9  8bf1                 mov esi, ecx
// 004531fb  e8c0fbffff           call 0x452dc0
// 00453200  85c0                 test eax, eax
// 00453202  0f85ac000000         jne 0x4532b4
// 00453208  53                   push ebx
// 00453209  8d442408             lea eax, [esp + 8]
// 0045320d  57                   push edi
// 0045320e  50                   push eax
// 0045320f  e86cd7feff           call 0x440980
// 00453214  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 00453218  6874dd9600           push 0x96dd74
// 0045321d  6870084500           push 0x450870
// 00453222  c744242800000000     mov dword ptr [esp + 0x28], 0
// 0045322a  e801411000           call 0x557330
// 0045322f  83c40c               add esp, 0xc
// 00453232  e8e9c1ffff           call 0x44f420
// 00453237  8b8ea0010000         mov ecx, dword ptr [esi + 0x1a0]
// 0045323d  2b8e9c010000         sub ecx, dword ptr [esi + 0x19c]
// 00453243  8bf8                 mov edi, eax
// 00453245  c1f903               sar ecx, 3
// 00453248  3bf9                 cmp edi, ecx
// 0045324a  7206                 jb 0x453252
// 0045324c  ff1590288000         call dword ptr [0x802890]
// 00453252  8b969c010000         mov edx, dword ptr [esi + 0x19c]
// 00453258  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0045325c  8d04fa               lea eax, [edx + edi*8]
// 0045325f  8d542410             lea edx, [esp + 0x10]
// 00453263  8908                 mov dword ptr [eax], ecx
// 00453265  52                   push edx
// 00453266  8d4804               lea ecx, [eax + 4]
// 00453269  e842f3faff           call 0x4025b0
// 0045326e  56                   push esi
// 0045326f  8bcb                 mov ecx, ebx
// 00453271  e87a761000           call 0x55a8f0
// 00453276  8b742410             mov esi, dword ptr [esp + 0x10]
// 0045327a  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 00453282  85f6                 test esi, esi
// 00453284  742a                 je 0x4532b0
// 00453286  8d4604               lea eax, [esi + 4]
// 00453289  83c9ff               or ecx, 0xffffffff
// 0045328c  f00fc108             lock xadd dword ptr [eax], ecx
// 00453290  751e                 jne 0x4532b0
// 00453292  8b16                 mov edx, dword ptr [esi]
// 00453294  8b4204               mov eax, dword ptr [edx + 4]
// 00453297  8bce                 mov ecx, esi
// 00453299  ffd0                 call eax
// 0045329b  8d4e08               lea ecx, [esi + 8]
// 0045329e  83caff               or edx, 0xffffffff
// 004532a1  f00fc111             lock xadd dword ptr [ecx], edx
// 004532a5  7509                 jne 0x4532b0
// 004532a7  8b06                 mov eax, dword ptr [esi]
// 004532a9  8b5008               mov edx, dword ptr [eax + 8]
// 004532ac  8bce                 mov ecx, esi
// 004532ae  ffd2                 call edx
// 004532b0  5f                   pop edi
// 004532b1  8bc3                 mov eax, ebx
// 004532b3  5b                   pop ebx
// 004532b4  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004532b8  5e                   pop esi
// 004532b9  64890d00000000       mov dword ptr fs:[0], ecx
// 004532c0  83c414               add esp, 0x14
// 004532c3  c3                   ret 

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
