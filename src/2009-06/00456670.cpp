// from server: 100% by EspClaude
// from server: 97% by EspClaude
// roc 2009-06 00456670  unit: RBX::VInstance::?$NonFactoryProduct  size: 228 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00456670
//
// 00456670  64a100000000         mov eax, dword ptr fs:[0]
// 00456676  6aff                 push -1
// 00456678  68e8a68600           push 0x86a6e8
// 0045667d  50                   push eax
// 0045667e  64892500000000       mov dword ptr fs:[0], esp
// 00456685  83ec08               sub esp, 8
// 00456688  56                   push esi
// 00456689  8bf1                 mov esi, ecx
// 0045668b  e850fbffff           call 0x4561e0
// 00456690  85c0                 test eax, eax
// 00456692  0f85ac000000         jne 0x456744
// 00456698  53                   push ebx
// 00456699  8d442408             lea eax, [esp + 8]
// 0045669d  57                   push edi
// 0045669e  50                   push eax
// 0045669f  e82cffffff           call 0x4565d0
// 004566a4  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 004566a8  68b0484500           push 0x4548b0
// 004566ad  68e8b3a300           push 0xa3b3e8
// 004566b2  c744242800000000     mov dword ptr [esp + 0x28], 0
// 004566ba  e851b0faff           call 0x401710
// 004566bf  83c40c               add esp, 0xc
// 004566c2  e849dbffff           call 0x454210
// 004566c7  8b8e9c000000         mov ecx, dword ptr [esi + 0x9c]
// 004566cd  2b8e98000000         sub ecx, dword ptr [esi + 0x98]
// 004566d3  8bf8                 mov edi, eax
// 004566d5  c1f903               sar ecx, 3
// 004566d8  3bf9                 cmp edi, ecx
// 004566da  7206                 jb 0x4566e2
// 004566dc  ff15ace98900         call dword ptr [0x89e9ac]
// 004566e2  8b9698000000         mov edx, dword ptr [esi + 0x98]
// 004566e8  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004566ec  8d04fa               lea eax, [edx + edi*8]
// 004566ef  8d542410             lea edx, [esp + 0x10]
// 004566f3  8908                 mov dword ptr [eax], ecx
// 004566f5  52                   push edx
// 004566f6  8d4804               lea ecx, [eax + 4]
// 004566f9  e802befaff           call 0x402500
// 004566fe  56                   push esi
// 004566ff  8bcb                 mov ecx, ebx
// 00456701  e84ab71700           call 0x5d1e50
// 00456706  8b742410             mov esi, dword ptr [esp + 0x10]
// 0045670a  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 00456712  85f6                 test esi, esi
// 00456714  742a                 je 0x456740
// 00456716  8d4604               lea eax, [esi + 4]
// 00456719  83c9ff               or ecx, 0xffffffff
// 0045671c  f00fc108             lock xadd dword ptr [eax], ecx
// 00456720  751e                 jne 0x456740
// 00456722  8b16                 mov edx, dword ptr [esi]
// 00456724  8b4204               mov eax, dword ptr [edx + 4]
// 00456727  8bce                 mov ecx, esi
// 00456729  ffd0                 call eax
// 0045672b  8d4e08               lea ecx, [esi + 8]
// 0045672e  83caff               or edx, 0xffffffff
// 00456731  f00fc111             lock xadd dword ptr [ecx], edx
// 00456735  7509                 jne 0x456740
// 00456737  8b06                 mov eax, dword ptr [esi]
// 00456739  8b5008               mov edx, dword ptr [eax + 8]
// 0045673c  8bce                 mov ecx, esi
// 0045673e  ffd2                 call edx
// 00456740  5f                   pop edi
// 00456741  8bc3                 mov eax, ebx
// 00456743  5b                   pop ebx
// 00456744  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00456748  5e                   pop esi
// 00456749  64890d00000000       mov dword ptr fs:[0], ecx
// 00456750  83c414               add esp, 0x14
// 00456753  c3                   ret 

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
