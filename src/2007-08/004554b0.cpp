// from server: 100% by EspClaude
// from server: 85% by EspClaude
// roc 2007-08 004554b0  unit: RBX::NullController  size: 246 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004554b0
//
// 004554b0  6aff                 push -1
// 004554b2  68c8a77400           push 0x74a7c8
// 004554b7  64a100000000         mov eax, dword ptr fs:[0]
// 004554bd  50                   push eax
// 004554be  83ec08               sub esp, 8
// 004554c1  53                   push ebx
// 004554c2  56                   push esi
// 004554c3  57                   push edi
// 004554c4  a188518b00           mov eax, dword ptr [0x8b5188]
// 004554c9  33c4                 xor eax, esp
// 004554cb  50                   push eax
// 004554cc  8d442418             lea eax, [esp + 0x18]
// 004554d0  64a300000000         mov dword ptr fs:[0], eax
// 004554d6  8bf1                 mov esi, ecx
// 004554d8  e8b3f4ffff           call 0x454990
// 004554dd  85c0                 test eax, eax
// 004554df  0f85ae000000         jne 0x455593
// 004554e5  8d442410             lea eax, [esp + 0x10]
// 004554e9  50                   push eax
// 004554ea  e831ffffff           call 0x455420
// 004554ef  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 004554f3  6814bf8b00           push 0x8bbf14
// 004554f8  6890394500           push 0x453990
// 004554fd  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 00455505  e816002d00           call 0x725520
// 0045550a  83c40c               add esp, 0xc
// 0045550d  e80ee1ffff           call 0x453620
// 00455512  8b8e34010000         mov ecx, dword ptr [esi + 0x134]
// 00455518  85c9                 test ecx, ecx
// 0045551a  8bf8                 mov edi, eax
// 0045551c  740f                 je 0x45552d
// 0045551e  8b8638010000         mov eax, dword ptr [esi + 0x138]
// 00455524  2bc1                 sub eax, ecx
// 00455526  c1f803               sar eax, 3
// 00455529  3bf8                 cmp edi, eax
// 0045552b  7206                 jb 0x455533
// 0045552d  ff15d8e67700         call dword ptr [0x77e6d8]
// 00455533  8b8e34010000         mov ecx, dword ptr [esi + 0x134]
// 00455539  8b542410             mov edx, dword ptr [esp + 0x10]
// 0045553d  8d04f9               lea eax, [ecx + edi*8]
// 00455540  8d4c2414             lea ecx, [esp + 0x14]
// 00455544  51                   push ecx
// 00455545  8d4804               lea ecx, [eax + 4]
// 00455548  8910                 mov dword ptr [eax], edx
// 0045554a  e811d5faff           call 0x402a60
// 0045554f  56                   push esi
// 00455550  8bcb                 mov ecx, ebx
// 00455552  e8d9c00e00           call 0x541630
// 00455557  8b742414             mov esi, dword ptr [esp + 0x14]
// 0045555b  85f6                 test esi, esi
// 0045555d  c7442420ffffffff     mov dword ptr [esp + 0x20], 0xffffffff
// 00455565  742a                 je 0x455591
// 00455567  8d5604               lea edx, [esi + 4]
// 0045556a  83c8ff               or eax, 0xffffffff
// 0045556d  f00fc102             lock xadd dword ptr [edx], eax
// 00455571  751e                 jne 0x455591
// 00455573  8b16                 mov edx, dword ptr [esi]
// 00455575  8b4204               mov eax, dword ptr [edx + 4]
// 00455578  8bce                 mov ecx, esi
// 0045557a  ffd0                 call eax
// 0045557c  8d4e08               lea ecx, [esi + 8]
// 0045557f  83caff               or edx, 0xffffffff
// 00455582  f00fc111             lock xadd dword ptr [ecx], edx
// 00455586  7509                 jne 0x455591
// 00455588  8b06                 mov eax, dword ptr [esi]
// 0045558a  8b5008               mov edx, dword ptr [eax + 8]
// 0045558d  8bce                 mov ecx, esi
// 0045558f  ffd2                 call edx
// 00455591  8bc3                 mov eax, ebx
// 00455593  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00455597  64890d00000000       mov dword ptr fs:[0], ecx
// 0045559e  59                   pop ecx
// 0045559f  5f                   pop edi
// 004555a0  5e                   pop esi
// 004555a1  5b                   pop ebx
// 004555a2  83c414               add esp, 0x14
// 004555a5  c3                   ret 

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
    char padding[0x134];
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
        if (index >= (unsigned)(first == 0 ? 0 : last - first))
            invalid_parameter_noinfo();
        Entry& entry = first[index];
        entry.value = p.value;
        entry.owner = p.owner;
        result->attach(this);
    }
    return result;
}
