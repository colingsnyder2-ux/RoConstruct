// from server: 100% by EspClaude
// from server: 98% by EspClaude
// roc 2009-06 004ca060  unit: RBX::Network::VServer::?$FactoryProduct::Creator  size: 320 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004ca060
//
// 004ca060  6aff                 push -1
// 004ca062  64a100000000         mov eax, dword ptr fs:[0]
// 004ca068  68e8a68600           push 0x86a6e8
// 004ca06d  50                   push eax
// 004ca06e  64892500000000       mov dword ptr fs:[0], esp
// 004ca075  83ec0c               sub esp, 0xc
// 004ca078  53                   push ebx
// 004ca079  55                   push ebp
// 004ca07a  56                   push esi
// 004ca07b  57                   push edi
// 004ca07c  68804b4c00           push 0x4c4b80
// 004ca081  68a4dba300           push 0xa3dba4
// 004ca086  8bd9                 mov ebx, ecx
// 004ca088  e88376f3ff           call 0x401710
// 004ca08d  83c408               add esp, 8
// 004ca090  e8eba4ffff           call 0x4c4580
// 004ca095  8b8b9c000000         mov ecx, dword ptr [ebx + 0x9c]
// 004ca09b  2b8b98000000         sub ecx, dword ptr [ebx + 0x98]
// 004ca0a1  8b2dace98900         mov ebp, dword ptr [0x89e9ac]
// 004ca0a7  8db38c000000         lea esi, [ebx + 0x8c]
// 004ca0ad  8bf8                 mov edi, eax
// 004ca0af  8d4701               lea eax, [edi + 1]
// 004ca0b2  c1f903               sar ecx, 3
// 004ca0b5  3bc1                 cmp eax, ecx
// 004ca0b7  7620                 jbe 0x4ca0d9
// 004ca0b9  83ec08               sub esp, 8
// 004ca0bc  8bcc                 mov ecx, esp
// 004ca0be  c70100000000         mov dword ptr [ecx], 0
// 004ca0c4  89642418             mov dword ptr [esp + 0x18], esp
// 004ca0c8  c7410400000000       mov dword ptr [ecx + 4], 0
// 004ca0cf  50                   push eax
// 004ca0d0  8bce                 mov ecx, esi
// 004ca0d2  e80966f4ff           call 0x4106e0
// 004ca0d7  eb1d                 jmp 0x4ca0f6
// 004ca0d9  8b5610               mov edx, dword ptr [esi + 0x10]
// 004ca0dc  2b560c               sub edx, dword ptr [esi + 0xc]
// 004ca0df  c1fa03               sar edx, 3
// 004ca0e2  3bfa                 cmp edi, edx
// 004ca0e4  7202                 jb 0x4ca0e8
// 004ca0e6  ffd5                 call ebp
// 004ca0e8  8b460c               mov eax, dword ptr [esi + 0xc]
// 004ca0eb  8b04f8               mov eax, dword ptr [eax + edi*8]
// 004ca0ee  85c0                 test eax, eax
// 004ca0f0  0f8597000000         jne 0x4ca18d
// 004ca0f6  68d0484b00           push 0x4b48d0
// 004ca0fb  6808d5a300           push 0xa3d508
// 004ca100  e80b76f3ff           call 0x401710
// 004ca105  83c408               add esp, 8
// 004ca108  e8339dfeff           call 0x4b3e40
// 004ca10d  50                   push eax
// 004ca10e  8d4c2418             lea ecx, [esp + 0x18]
// 004ca112  51                   push ecx
// 004ca113  8bcb                 mov ecx, ebx
// 004ca115  e846fe1200           call 0x5f9f60
// 004ca11a  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004ca11e  c744242400000000     mov dword ptr [esp + 0x24], 0
// 004ca126  85c9                 test ecx, ecx
// 004ca128  7526                 jne 0x4ca150
// 004ca12a  8d4c2414             lea ecx, [esp + 0x14]
// 004ca12e  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 004ca136  e875a61500           call 0x6247b0
// 004ca13b  33c0                 xor eax, eax
// 004ca13d  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004ca141  64890d00000000       mov dword ptr fs:[0], ecx
// 004ca148  5f                   pop edi
// 004ca149  5e                   pop esi
// 004ca14a  5d                   pop ebp
// 004ca14b  5b                   pop ebx
// 004ca14c  83c418               add esp, 0x18
// 004ca14f  c3                   ret 
// 004ca150  8b5610               mov edx, dword ptr [esi + 0x10]
// 004ca153  2b560c               sub edx, dword ptr [esi + 0xc]
// 004ca156  8bd9                 mov ebx, ecx
// 004ca158  c1fa03               sar edx, 3
// 004ca15b  3bfa                 cmp edi, edx
// 004ca15d  7206                 jb 0x4ca165
// 004ca15f  ffd5                 call ebp
// 004ca161  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004ca165  8b460c               mov eax, dword ptr [esi + 0xc]
// 004ca168  8d04f8               lea eax, [eax + edi*8]
// 004ca16b  8908                 mov dword ptr [eax], ecx
// 004ca16d  8d4c2418             lea ecx, [esp + 0x18]
// 004ca171  51                   push ecx
// 004ca172  8d4804               lea ecx, [eax + 4]
// 004ca175  e88683f3ff           call 0x402500
// 004ca17a  8d4c2414             lea ecx, [esp + 0x14]
// 004ca17e  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 004ca186  e825a61500           call 0x6247b0
// 004ca18b  8bc3                 mov eax, ebx
// 004ca18d  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004ca191  5f                   pop edi
// 004ca192  5e                   pop esi
// 004ca193  5d                   pop ebp
// 004ca194  64890d00000000       mov dword ptr fs:[0], ecx
// 004ca19b  5b                   pop ebx
// 004ca19c  83c418               add esp, 0x18
// 004ca19f  c3                   ret 

// from server: 100% by colin
// roc 2008-06 0049a580  unit: RBX::Network::VServer::?$FactoryProduct::Creator  size: 320 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0049a580
//
// 0049a580  6aff                 push -1
// 0049a582  64a100000000         mov eax, dword ptr fs:[0]
// 0049a588  6868917d00           push 0x7d9168
// 0049a58d  50                   push eax
// 0049a58e  64892500000000       mov dword ptr fs:[0], esp
// 0049a595  83ec0c               sub esp, 0xc
// 0049a598  53                   push ebx
// 0049a599  55                   push ebp
// 0049a59a  56                   push esi
// 0049a59b  57                   push edi
// 0049a59c  6890029700           push 0x970290
// 0049a5a1  68f0694900           push 0x4969f0
// 0049a5a6  8bd9                 mov ebx, ecx
// 0049a5a8  e883cd0b00           call 0x557330
// 0049a5ad  83c408               add esp, 8
// 0049a5b0  e83bbdffff           call 0x4962f0
// 0049a5b5  8b8ba0010000         mov ecx, dword ptr [ebx + 0x1a0]
// 0049a5bb  2b8b9c010000         sub ecx, dword ptr [ebx + 0x19c]
// 0049a5c1  8b2d90288000         mov ebp, dword ptr [0x802890]
// 0049a5c7  8db390010000         lea esi, [ebx + 0x190]
// 0049a5cd  8bf8                 mov edi, eax
// 0049a5cf  8d4701               lea eax, [edi + 1]
// 0049a5d2  c1f903               sar ecx, 3
// 0049a5d5  3bc1                 cmp eax, ecx
// 0049a5d7  7620                 jbe 0x49a5f9
// 0049a5d9  83ec08               sub esp, 8
// 0049a5dc  8bcc                 mov ecx, esp
// 0049a5de  c70100000000         mov dword ptr [ecx], 0
// 0049a5e4  89642418             mov dword ptr [esp + 0x18], esp
// 0049a5e8  c7410400000000       mov dword ptr [ecx + 4], 0
// 0049a5ef  50                   push eax
// 0049a5f0  8bce                 mov ecx, esi
// 0049a5f2  e8c97ef7ff           call 0x4124c0
// 0049a5f7  eb1d                 jmp 0x49a616
// 0049a5f9  8b5610               mov edx, dword ptr [esi + 0x10]
// 0049a5fc  2b560c               sub edx, dword ptr [esi + 0xc]
// 0049a5ff  c1fa03               sar edx, 3
// 0049a602  3bfa                 cmp edi, edx
// 0049a604  7202                 jb 0x49a608
// 0049a606  ffd5                 call ebp
// 0049a608  8b460c               mov eax, dword ptr [esi + 0xc]
// 0049a60b  8b04f8               mov eax, dword ptr [eax + edi*8]
// 0049a60e  85c0                 test eax, eax
// 0049a610  0f8597000000         jne 0x49a6ad
// 0049a616  68e0fb9600           push 0x96fbe0
// 0049a61b  6840ab4800           push 0x48ab40
// 0049a620  e80bcd0b00           call 0x557330
// 0049a625  83c408               add esp, 8
// 0049a628  e8b3fbfeff           call 0x48a1e0
// 0049a62d  50                   push eax
// 0049a62e  8d4c2418             lea ecx, [esp + 0x18]
// 0049a632  51                   push ecx
// 0049a633  8bcb                 mov ecx, ebx
// 0049a635  e856840d00           call 0x572a90
// 0049a63a  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0049a63e  c744242400000000     mov dword ptr [esp + 0x24], 0
// 0049a646  85c9                 test ecx, ecx
// 0049a648  7526                 jne 0x49a670
// 0049a64a  8d4c2414             lea ecx, [esp + 0x14]
// 0049a64e  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 0049a656  e805601600           call 0x600660
// 0049a65b  33c0                 xor eax, eax
// 0049a65d  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0049a661  64890d00000000       mov dword ptr fs:[0], ecx
// 0049a668  5f                   pop edi
// 0049a669  5e                   pop esi
// 0049a66a  5d                   pop ebp
// 0049a66b  5b                   pop ebx
// 0049a66c  83c418               add esp, 0x18
// 0049a66f  c3                   ret 
// 0049a670  8b5610               mov edx, dword ptr [esi + 0x10]
// 0049a673  2b560c               sub edx, dword ptr [esi + 0xc]
// 0049a676  8bd9                 mov ebx, ecx
// 0049a678  c1fa03               sar edx, 3
// 0049a67b  3bfa                 cmp edi, edx
// 0049a67d  7206                 jb 0x49a685
// 0049a67f  ffd5                 call ebp
// 0049a681  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0049a685  8b460c               mov eax, dword ptr [esi + 0xc]
// 0049a688  8d04f8               lea eax, [eax + edi*8]
// 0049a68b  8908                 mov dword ptr [eax], ecx
// 0049a68d  8d4c2418             lea ecx, [esp + 0x18]
// 0049a691  51                   push ecx
// 0049a692  8d4804               lea ecx, [eax + 4]
// 0049a695  e8167ff6ff           call 0x4025b0
// 0049a69a  8d4c2414             lea ecx, [esp + 0x14]
// 0049a69e  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 0049a6a6  e8b55f1600           call 0x600660
// 0049a6ab  8bc3                 mov eax, ebx
// 0049a6ad  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0049a6b1  5f                   pop edi
// 0049a6b2  5e                   pop esi
// 0049a6b3  5d                   pop ebp
// 0049a6b4  64890d00000000       mov dword ptr fs:[0], ecx
// 0049a6bb  5b                   pop ebx
// 0049a6bc  83c418               add esp, 0x18
// 0049a6bf  c3                   ret 

extern void (__cdecl* invalid_parameter)();
extern void __cdecl initialize_index();
extern void __cdecl initialize_type();
extern unsigned long index_once;
extern unsigned long type_once;
extern void __cdecl call_once(void (__cdecl*)(), unsigned long*);
extern void* __cdecl func_0042d030();
extern void* __cdecl func_0042ced0();

struct Control {
    void* value;
    Control();
    Control& operator=(const Control&);
};

__forceinline Control::Control() : value(0)
{
}

struct Pair {
    void* object;
    Control control;
    ~Pair();
};

struct EmptyPair {
    void* object;
    Control control;
    EmptyPair();
    EmptyPair(const EmptyPair&);
    ~EmptyPair();
};

__forceinline EmptyPair::EmptyPair()
    : object(0), control()
{
}

struct Vector {
    unsigned char padding[12];
    Pair* first;
    Pair* last;
    Pair* limit;
    void resize(unsigned int, EmptyPair);
    unsigned int size() const;
    Pair& at(unsigned int, void (__cdecl*)());
};

__forceinline unsigned int Vector::size() const
{
    return (unsigned int)(last - first);
}

__forceinline Pair& Vector::at(unsigned int index, void (__cdecl* handler)())
{
    if (index >= (unsigned int)(last - first))
        handler();
    return first[index];
}

struct S {
    unsigned char padding[0x8c];
    Vector values;
    Pair create(void*);
    void* get();
};

void* S::get()
{
    call_once(initialize_index, &index_once);
    unsigned int index = (unsigned int)func_0042d030();
    void (__cdecl* handler)() = invalid_parameter;
    Vector& entries = values;

    if (index + 1 > values.size()) {
        entries.resize(index + 1, EmptyPair());
    } else {
        void* existing = entries.at(index, handler).object;
        if (existing)
            return existing;
    }

    call_once(initialize_type, &type_once);
    Pair result = create(func_0042ced0());

    if (!result.object)
        return 0;

    void* object = result.object;
    Pair& destination = entries.at(index, handler);
    destination.object = result.object;
    destination.control = result.control;
    return object;
}
