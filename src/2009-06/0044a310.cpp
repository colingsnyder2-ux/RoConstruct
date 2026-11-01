// from server: 97% by EspClaude
// from server: 100% by colin
// roc 2008-06 00453000  unit: CRobloxDoc  size: 228 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00453000
//
// 00453000  64a100000000         mov eax, dword ptr fs:[0]
// 00453006  6aff                 push -1
// 00453008  6868917d00           push 0x7d9168
// 0045300d  50                   push eax
// 0045300e  64892500000000       mov dword ptr fs:[0], esp
// 00453015  83ec08               sub esp, 8
// 00453018  56                   push esi
// 00453019  8bf1                 mov esi, ecx
// 0045301b  e8e0f9ffff           call 0x452a00
// 00453020  85c0                 test eax, eax
// 00453022  0f85ac000000         jne 0x4530d4
// 00453028  53                   push ebx
// 00453029  8d442408             lea eax, [esp + 8]
// 0045302d  57                   push edi
// 0045302e  50                   push eax
// 0045302f  e89c20fcff           call 0x4150d0
// 00453034  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 00453038  686cdd9600           push 0x96dd6c
// 0045303d  6850084500           push 0x450850
// 00453042  c744242800000000     mov dword ptr [esp + 0x28], 0
// 0045304a  e8e1421000           call 0x557330
// 0045304f  83c40c               add esp, 0xc
// 00453052  e809c3ffff           call 0x44f360
// 00453057  8b8ea0010000         mov ecx, dword ptr [esi + 0x1a0]
// 0045305d  2b8e9c010000         sub ecx, dword ptr [esi + 0x19c]
// 00453063  8bf8                 mov edi, eax
// 00453065  c1f903               sar ecx, 3
// 00453068  3bf9                 cmp edi, ecx
// 0045306a  7206                 jb 0x453072
// 0045306c  ff1590288000         call dword ptr [0x802890]
// 00453072  8b969c010000         mov edx, dword ptr [esi + 0x19c]
// 00453078  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0045307c  8d04fa               lea eax, [edx + edi*8]
// 0045307f  8d542410             lea edx, [esp + 0x10]
// 00453083  8908                 mov dword ptr [eax], ecx
// 00453085  52                   push edx
// 00453086  8d4804               lea ecx, [eax + 4]
// 00453089  e822f5faff           call 0x4025b0
// 0045308e  56                   push esi
// 0045308f  8bcb                 mov ecx, ebx
// 00453091  e85a781000           call 0x55a8f0
// 00453096  8b742410             mov esi, dword ptr [esp + 0x10]
// 0045309a  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 004530a2  85f6                 test esi, esi
// 004530a4  742a                 je 0x4530d0
// 004530a6  8d4604               lea eax, [esi + 4]
// 004530a9  83c9ff               or ecx, 0xffffffff
// 004530ac  f00fc108             lock xadd dword ptr [eax], ecx
// 004530b0  751e                 jne 0x4530d0
// 004530b2  8b16                 mov edx, dword ptr [esi]
// 004530b4  8b4204               mov eax, dword ptr [edx + 4]
// 004530b7  8bce                 mov ecx, esi
// 004530b9  ffd0                 call eax
// 004530bb  8d4e08               lea ecx, [esi + 8]
// 004530be  83caff               or edx, 0xffffffff
// 004530c1  f00fc111             lock xadd dword ptr [ecx], edx
// 004530c5  7509                 jne 0x4530d0
// 004530c7  8b06                 mov eax, dword ptr [esi]
// 004530c9  8b5008               mov edx, dword ptr [eax + 8]
// 004530cc  8bce                 mov ecx, esi
// 004530ce  ffd2                 call edx
// 004530d0  5f                   pop edi
// 004530d1  8bc3                 mov eax, ebx
// 004530d3  5b                   pop ebx
// 004530d4  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004530d8  5e                   pop esi
// 004530d9  64890d00000000       mov dword ptr fs:[0], ecx
// 004530e0  83c414               add esp, 0x14
// 004530e3  c3                   ret 

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
