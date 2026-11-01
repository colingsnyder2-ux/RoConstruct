// from server: 100% by EspClaude
// from server: 98% by EspClaude
// roc 2009-06 004c9c70  unit: RBX::Network::VServer::?$FactoryProduct::Creator  size: 320 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004c9c70
//
// 004c9c70  6aff                 push -1
// 004c9c72  64a100000000         mov eax, dword ptr fs:[0]
// 004c9c78  68e8a68600           push 0x86a6e8
// 004c9c7d  50                   push eax
// 004c9c7e  64892500000000       mov dword ptr fs:[0], esp
// 004c9c85  83ec0c               sub esp, 0xc
// 004c9c88  53                   push ebx
// 004c9c89  55                   push ebp
// 004c9c8a  56                   push esi
// 004c9c8b  57                   push edi
// 004c9c8c  68504b4c00           push 0x4c4b50
// 004c9c91  6898dba300           push 0xa3db98
// 004c9c96  8bd9                 mov ebx, ecx
// 004c9c98  e8737af3ff           call 0x401710
// 004c9c9d  83c408               add esp, 8
// 004c9ca0  e8bba7ffff           call 0x4c4460
// 004c9ca5  8b8b9c000000         mov ecx, dword ptr [ebx + 0x9c]
// 004c9cab  2b8b98000000         sub ecx, dword ptr [ebx + 0x98]
// 004c9cb1  8b2dace98900         mov ebp, dword ptr [0x89e9ac]
// 004c9cb7  8db38c000000         lea esi, [ebx + 0x8c]
// 004c9cbd  8bf8                 mov edi, eax
// 004c9cbf  8d4701               lea eax, [edi + 1]
// 004c9cc2  c1f903               sar ecx, 3
// 004c9cc5  3bc1                 cmp eax, ecx
// 004c9cc7  7620                 jbe 0x4c9ce9
// 004c9cc9  83ec08               sub esp, 8
// 004c9ccc  8bcc                 mov ecx, esp
// 004c9cce  c70100000000         mov dword ptr [ecx], 0
// 004c9cd4  89642418             mov dword ptr [esp + 0x18], esp
// 004c9cd8  c7410400000000       mov dword ptr [ecx + 4], 0
// 004c9cdf  50                   push eax
// 004c9ce0  8bce                 mov ecx, esi
// 004c9ce2  e8f969f4ff           call 0x4106e0
// 004c9ce7  eb1d                 jmp 0x4c9d06
// 004c9ce9  8b5610               mov edx, dword ptr [esi + 0x10]
// 004c9cec  2b560c               sub edx, dword ptr [esi + 0xc]
// 004c9cef  c1fa03               sar edx, 3
// 004c9cf2  3bfa                 cmp edi, edx
// 004c9cf4  7202                 jb 0x4c9cf8
// 004c9cf6  ffd5                 call ebp
// 004c9cf8  8b460c               mov eax, dword ptr [esi + 0xc]
// 004c9cfb  8b04f8               mov eax, dword ptr [eax + edi*8]
// 004c9cfe  85c0                 test eax, eax
// 004c9d00  0f8597000000         jne 0x4c9d9d
// 004c9d06  68904a4c00           push 0x4c4a90
// 004c9d0b  687cdba300           push 0xa3db7c
// 004c9d10  e8fb79f3ff           call 0x401710
// 004c9d15  83c408               add esp, 8
// 004c9d18  e843a6ffff           call 0x4c4360
// 004c9d1d  50                   push eax
// 004c9d1e  8d4c2418             lea ecx, [esp + 0x18]
// 004c9d22  51                   push ecx
// 004c9d23  8bcb                 mov ecx, ebx
// 004c9d25  e836021300           call 0x5f9f60
// 004c9d2a  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004c9d2e  c744242400000000     mov dword ptr [esp + 0x24], 0
// 004c9d36  85c9                 test ecx, ecx
// 004c9d38  7526                 jne 0x4c9d60
// 004c9d3a  8d4c2414             lea ecx, [esp + 0x14]
// 004c9d3e  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 004c9d46  e865aa1500           call 0x6247b0
// 004c9d4b  33c0                 xor eax, eax
// 004c9d4d  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004c9d51  64890d00000000       mov dword ptr fs:[0], ecx
// 004c9d58  5f                   pop edi
// 004c9d59  5e                   pop esi
// 004c9d5a  5d                   pop ebp
// 004c9d5b  5b                   pop ebx
// 004c9d5c  83c418               add esp, 0x18
// 004c9d5f  c3                   ret 
// 004c9d60  8b5610               mov edx, dword ptr [esi + 0x10]
// 004c9d63  2b560c               sub edx, dword ptr [esi + 0xc]
// 004c9d66  8bd9                 mov ebx, ecx
// 004c9d68  c1fa03               sar edx, 3
// 004c9d6b  3bfa                 cmp edi, edx
// 004c9d6d  7206                 jb 0x4c9d75
// 004c9d6f  ffd5                 call ebp
// 004c9d71  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004c9d75  8b460c               mov eax, dword ptr [esi + 0xc]
// 004c9d78  8d04f8               lea eax, [eax + edi*8]
// 004c9d7b  8908                 mov dword ptr [eax], ecx
// 004c9d7d  8d4c2418             lea ecx, [esp + 0x18]
// 004c9d81  51                   push ecx
// 004c9d82  8d4804               lea ecx, [eax + 4]
// 004c9d85  e87687f3ff           call 0x402500
// 004c9d8a  8d4c2414             lea ecx, [esp + 0x14]
// 004c9d8e  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 004c9d96  e815aa1500           call 0x6247b0
// 004c9d9b  8bc3                 mov eax, ebx
// 004c9d9d  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004c9da1  5f                   pop edi
// 004c9da2  5e                   pop esi
// 004c9da3  5d                   pop ebp
// 004c9da4  64890d00000000       mov dword ptr fs:[0], ecx
// 004c9dab  5b                   pop ebx
// 004c9dac  83c418               add esp, 0x18
// 004c9daf  c3                   ret 

// from server: 100% by colin
// roc 2008-06 004a3e40  unit: RBX::VHint::?$FactoryProduct  size: 320 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004a3e40
//
// 004a3e40  6aff                 push -1
// 004a3e42  64a100000000         mov eax, dword ptr fs:[0]
// 004a3e48  6868917d00           push 0x7d9168
// 004a3e4d  50                   push eax
// 004a3e4e  64892500000000       mov dword ptr fs:[0], esp
// 004a3e55  83ec0c               sub esp, 0xc
// 004a3e58  53                   push ebx
// 004a3e59  55                   push ebp
// 004a3e5a  56                   push esi
// 004a3e5b  57                   push edi
// 004a3e5c  68180d9700           push 0x970d18
// 004a3e61  68001d4a00           push 0x4a1d00
// 004a3e66  8bd9                 mov ebx, ecx
// 004a3e68  e8c3340b00           call 0x557330
// 004a3e6d  83c408               add esp, 8
// 004a3e70  e8ebd8ffff           call 0x4a1760
// 004a3e75  8b8ba0010000         mov ecx, dword ptr [ebx + 0x1a0]
// 004a3e7b  2b8b9c010000         sub ecx, dword ptr [ebx + 0x19c]
// 004a3e81  8b2d90288000         mov ebp, dword ptr [0x802890]
// 004a3e87  8db390010000         lea esi, [ebx + 0x190]
// 004a3e8d  8bf8                 mov edi, eax
// 004a3e8f  8d4701               lea eax, [edi + 1]
// 004a3e92  c1f903               sar ecx, 3
// 004a3e95  3bc1                 cmp eax, ecx
// 004a3e97  7620                 jbe 0x4a3eb9
// 004a3e99  83ec08               sub esp, 8
// 004a3e9c  8bcc                 mov ecx, esp
// 004a3e9e  c70100000000         mov dword ptr [ecx], 0
// 004a3ea4  89642418             mov dword ptr [esp + 0x18], esp
// 004a3ea8  c7410400000000       mov dword ptr [ecx + 4], 0
// 004a3eaf  50                   push eax
// 004a3eb0  8bce                 mov ecx, esi
// 004a3eb2  e809e6f6ff           call 0x4124c0
// 004a3eb7  eb1d                 jmp 0x4a3ed6
// 004a3eb9  8b5610               mov edx, dword ptr [esi + 0x10]
// 004a3ebc  2b560c               sub edx, dword ptr [esi + 0xc]
// 004a3ebf  c1fa03               sar edx, 3
// 004a3ec2  3bfa                 cmp edi, edx
// 004a3ec4  7202                 jb 0x4a3ec8
// 004a3ec6  ffd5                 call ebp
// 004a3ec8  8b460c               mov eax, dword ptr [esi + 0xc]
// 004a3ecb  8b04f8               mov eax, dword ptr [eax + edi*8]
// 004a3ece  85c0                 test eax, eax
// 004a3ed0  0f8597000000         jne 0x4a3f6d
// 004a3ed6  688c029700           push 0x97028c
// 004a3edb  6800694900           push 0x496900
// 004a3ee0  e84b340b00           call 0x557330
// 004a3ee5  83c408               add esp, 8
// 004a3ee8  e85323ffff           call 0x496240
// 004a3eed  50                   push eax
// 004a3eee  8d4c2418             lea ecx, [esp + 0x18]
// 004a3ef2  51                   push ecx
// 004a3ef3  8bcb                 mov ecx, ebx
// 004a3ef5  e896eb0c00           call 0x572a90
// 004a3efa  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004a3efe  c744242400000000     mov dword ptr [esp + 0x24], 0
// 004a3f06  85c9                 test ecx, ecx
// 004a3f08  7526                 jne 0x4a3f30
// 004a3f0a  8d4c2414             lea ecx, [esp + 0x14]
// 004a3f0e  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 004a3f16  e845c71500           call 0x600660
// 004a3f1b  33c0                 xor eax, eax
// 004a3f1d  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004a3f21  64890d00000000       mov dword ptr fs:[0], ecx
// 004a3f28  5f                   pop edi
// 004a3f29  5e                   pop esi
// 004a3f2a  5d                   pop ebp
// 004a3f2b  5b                   pop ebx
// 004a3f2c  83c418               add esp, 0x18
// 004a3f2f  c3                   ret 
// 004a3f30  8b5610               mov edx, dword ptr [esi + 0x10]
// 004a3f33  2b560c               sub edx, dword ptr [esi + 0xc]
// 004a3f36  8bd9                 mov ebx, ecx
// 004a3f38  c1fa03               sar edx, 3
// 004a3f3b  3bfa                 cmp edi, edx
// 004a3f3d  7206                 jb 0x4a3f45
// 004a3f3f  ffd5                 call ebp
// 004a3f41  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004a3f45  8b460c               mov eax, dword ptr [esi + 0xc]
// 004a3f48  8d04f8               lea eax, [eax + edi*8]
// 004a3f4b  8908                 mov dword ptr [eax], ecx
// 004a3f4d  8d4c2418             lea ecx, [esp + 0x18]
// 004a3f51  51                   push ecx
// 004a3f52  8d4804               lea ecx, [eax + 4]
// 004a3f55  e856e6f5ff           call 0x4025b0
// 004a3f5a  8d4c2414             lea ecx, [esp + 0x14]
// 004a3f5e  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 004a3f66  e8f5c61500           call 0x600660
// 004a3f6b  8bc3                 mov eax, ebx
// 004a3f6d  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004a3f71  5f                   pop edi
// 004a3f72  5e                   pop esi
// 004a3f73  5d                   pop ebp
// 004a3f74  64890d00000000       mov dword ptr fs:[0], ecx
// 004a3f7b  5b                   pop ebx
// 004a3f7c  83c418               add esp, 0x18
// 004a3f7f  c3                   ret 

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
