// from server: 97% by EspClaude
// from server: 100% by colin
// roc 2008-06 0041eea0  unit: RBX::VSpecialShape::?$FactoryProduct::Creator  size: 228 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0041eea0
//
// 0041eea0  64a100000000         mov eax, dword ptr fs:[0]
// 0041eea6  6aff                 push -1
// 0041eea8  6868917d00           push 0x7d9168
// 0041eead  50                   push eax
// 0041eeae  64892500000000       mov dword ptr fs:[0], esp
// 0041eeb5  83ec08               sub esp, 8
// 0041eeb8  56                   push esi
// 0041eeb9  8bf1                 mov esi, ecx
// 0041eebb  e8a0feffff           call 0x41ed60
// 0041eec0  85c0                 test eax, eax
// 0041eec2  0f85ac000000         jne 0x41ef74
// 0041eec8  53                   push ebx
// 0041eec9  8d442408             lea eax, [esp + 8]
// 0041eecd  57                   push edi
// 0041eece  50                   push eax
// 0041eecf  e8fcf6ffff           call 0x41e5d0
// 0041eed4  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0041eed8  68d0d09600           push 0x96d0d0
// 0041eedd  6820e24100           push 0x41e220
// 0041eee2  c744242800000000     mov dword ptr [esp + 0x28], 0
// 0041eeea  e841841300           call 0x557330
// 0041eeef  83c40c               add esp, 0xc
// 0041eef2  e859f1ffff           call 0x41e050
// 0041eef7  8b8ea0010000         mov ecx, dword ptr [esi + 0x1a0]
// 0041eefd  2b8e9c010000         sub ecx, dword ptr [esi + 0x19c]
// 0041ef03  8bf8                 mov edi, eax
// 0041ef05  c1f903               sar ecx, 3
// 0041ef08  3bf9                 cmp edi, ecx
// 0041ef0a  7206                 jb 0x41ef12
// 0041ef0c  ff1590288000         call dword ptr [0x802890]
// 0041ef12  8b969c010000         mov edx, dword ptr [esi + 0x19c]
// 0041ef18  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0041ef1c  8d04fa               lea eax, [edx + edi*8]
// 0041ef1f  8d542410             lea edx, [esp + 0x10]
// 0041ef23  8908                 mov dword ptr [eax], ecx
// 0041ef25  52                   push edx
// 0041ef26  8d4804               lea ecx, [eax + 4]
// 0041ef29  e88236feff           call 0x4025b0
// 0041ef2e  56                   push esi
// 0041ef2f  8bcb                 mov ecx, ebx
// 0041ef31  e8bab91300           call 0x55a8f0
// 0041ef36  8b742410             mov esi, dword ptr [esp + 0x10]
// 0041ef3a  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 0041ef42  85f6                 test esi, esi
// 0041ef44  742a                 je 0x41ef70
// 0041ef46  8d4604               lea eax, [esi + 4]
// 0041ef49  83c9ff               or ecx, 0xffffffff
// 0041ef4c  f00fc108             lock xadd dword ptr [eax], ecx
// 0041ef50  751e                 jne 0x41ef70
// 0041ef52  8b16                 mov edx, dword ptr [esi]
// 0041ef54  8b4204               mov eax, dword ptr [edx + 4]
// 0041ef57  8bce                 mov ecx, esi
// 0041ef59  ffd0                 call eax
// 0041ef5b  8d4e08               lea ecx, [esi + 8]
// 0041ef5e  83caff               or edx, 0xffffffff
// 0041ef61  f00fc111             lock xadd dword ptr [ecx], edx
// 0041ef65  7509                 jne 0x41ef70
// 0041ef67  8b06                 mov eax, dword ptr [esi]
// 0041ef69  8b5008               mov edx, dword ptr [eax + 8]
// 0041ef6c  8bce                 mov ecx, esi
// 0041ef6e  ffd2                 call edx
// 0041ef70  5f                   pop edi
// 0041ef71  8bc3                 mov eax, ebx
// 0041ef73  5b                   pop ebx
// 0041ef74  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0041ef78  5e                   pop esi
// 0041ef79  64890d00000000       mov dword ptr fs:[0], ecx
// 0041ef80  83c414               add esp, 0x14
// 0041ef83  c3                   ret 

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
