// from server: 85% by EspClaude
// from server: 100% by colin
// roc 2008-06 0042dfd0  unit: RBX::VScriptContext::?$FactoryProduct::Creator  size: 228 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0042dfd0
//
// 0042dfd0  64a100000000         mov eax, dword ptr fs:[0]
// 0042dfd6  6aff                 push -1
// 0042dfd8  6868917d00           push 0x7d9168
// 0042dfdd  50                   push eax
// 0042dfde  64892500000000       mov dword ptr fs:[0], esp
// 0042dfe5  83ec08               sub esp, 8
// 0042dfe8  56                   push esi
// 0042dfe9  8bf1                 mov esi, ecx
// 0042dfeb  e8a0feffff           call 0x42de90
// 0042dff0  85c0                 test eax, eax
// 0042dff2  0f85ac000000         jne 0x42e0a4
// 0042dff8  53                   push ebx
// 0042dff9  8d442408             lea eax, [esp + 8]
// 0042dffd  57                   push edi
// 0042dffe  50                   push eax
// 0042dfff  e8ecf3ffff           call 0x42d3f0
// 0042e004  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0042e008  6830d19600           push 0x96d130
// 0042e00d  6880d14200           push 0x42d180
// 0042e012  c744242800000000     mov dword ptr [esp + 0x28], 0
// 0042e01a  e811931200           call 0x557330
// 0042e01f  83c40c               add esp, 0xc
// 0042e022  e809f0ffff           call 0x42d030
// 0042e027  8b8ea0010000         mov ecx, dword ptr [esi + 0x1a0]
// 0042e02d  2b8e9c010000         sub ecx, dword ptr [esi + 0x19c]
// 0042e033  8bf8                 mov edi, eax
// 0042e035  c1f903               sar ecx, 3
// 0042e038  3bf9                 cmp edi, ecx
// 0042e03a  7206                 jb 0x42e042
// 0042e03c  ff1590288000         call dword ptr [0x802890]
// 0042e042  8b969c010000         mov edx, dword ptr [esi + 0x19c]
// 0042e048  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0042e04c  8d04fa               lea eax, [edx + edi*8]
// 0042e04f  8d542410             lea edx, [esp + 0x10]
// 0042e053  8908                 mov dword ptr [eax], ecx
// 0042e055  52                   push edx
// 0042e056  8d4804               lea ecx, [eax + 4]
// 0042e059  e85245fdff           call 0x4025b0
// 0042e05e  56                   push esi
// 0042e05f  8bcb                 mov ecx, ebx
// 0042e061  e88ac81200           call 0x55a8f0
// 0042e066  8b742410             mov esi, dword ptr [esp + 0x10]
// 0042e06a  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 0042e072  85f6                 test esi, esi
// 0042e074  742a                 je 0x42e0a0
// 0042e076  8d4604               lea eax, [esi + 4]
// 0042e079  83c9ff               or ecx, 0xffffffff
// 0042e07c  f00fc108             lock xadd dword ptr [eax], ecx
// 0042e080  751e                 jne 0x42e0a0
// 0042e082  8b16                 mov edx, dword ptr [esi]
// 0042e084  8b4204               mov eax, dword ptr [edx + 4]
// 0042e087  8bce                 mov ecx, esi
// 0042e089  ffd0                 call eax
// 0042e08b  8d4e08               lea ecx, [esi + 8]
// 0042e08e  83caff               or edx, 0xffffffff
// 0042e091  f00fc111             lock xadd dword ptr [ecx], edx
// 0042e095  7509                 jne 0x42e0a0
// 0042e097  8b06                 mov eax, dword ptr [esi]
// 0042e099  8b5008               mov edx, dword ptr [eax + 8]
// 0042e09c  8bce                 mov ecx, esi
// 0042e09e  ffd2                 call edx
// 0042e0a0  5f                   pop edi
// 0042e0a1  8bc3                 mov eax, ebx
// 0042e0a3  5b                   pop ebx
// 0042e0a4  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0042e0a8  5e                   pop esi
// 0042e0a9  64890d00000000       mov dword ptr fs:[0], ecx
// 0042e0b0  83c414               add esp, 0x14
// 0042e0b3  c3                   ret 

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
