// from server: 100% by EspClaude
// from server: 98% by EspClaude
// roc 2009-06 00450310  unit: RBX::VVisit::?$FactoryProduct::Creator  size: 320 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00450310
//
// 00450310  6aff                 push -1
// 00450312  64a100000000         mov eax, dword ptr fs:[0]
// 00450318  68e8a68600           push 0x86a6e8
// 0045031d  50                   push eax
// 0045031e  64892500000000       mov dword ptr fs:[0], esp
// 00450325  83ec0c               sub esp, 0xc
// 00450328  53                   push ebx
// 00450329  55                   push ebp
// 0045032a  56                   push esi
// 0045032b  57                   push edi
// 0045032c  68c0ed4400           push 0x44edc0
// 00450331  68a8b3a300           push 0xa3b3a8
// 00450336  8bd9                 mov ebx, ecx
// 00450338  e8d313fbff           call 0x401710
// 0045033d  83c408               add esp, 8
// 00450340  e82bd3ffff           call 0x44d670
// 00450345  8b8b9c000000         mov ecx, dword ptr [ebx + 0x9c]
// 0045034b  2b8b98000000         sub ecx, dword ptr [ebx + 0x98]
// 00450351  8b2dace98900         mov ebp, dword ptr [0x89e9ac]
// 00450357  8db38c000000         lea esi, [ebx + 0x8c]
// 0045035d  8bf8                 mov edi, eax
// 0045035f  8d4701               lea eax, [edi + 1]
// 00450362  c1f903               sar ecx, 3
// 00450365  3bc1                 cmp eax, ecx
// 00450367  7620                 jbe 0x450389
// 00450369  83ec08               sub esp, 8
// 0045036c  8bcc                 mov ecx, esp
// 0045036e  c70100000000         mov dword ptr [ecx], 0
// 00450374  89642418             mov dword ptr [esp + 0x18], esp
// 00450378  c7410400000000       mov dword ptr [ecx + 4], 0
// 0045037f  50                   push eax
// 00450380  8bce                 mov ecx, esi
// 00450382  e85903fcff           call 0x4106e0
// 00450387  eb1d                 jmp 0x4503a6
// 00450389  8b5610               mov edx, dword ptr [esi + 0x10]
// 0045038c  2b560c               sub edx, dword ptr [esi + 0xc]
// 0045038f  c1fa03               sar edx, 3
// 00450392  3bfa                 cmp edi, edx
// 00450394  7202                 jb 0x450398
// 00450396  ffd5                 call ebp
// 00450398  8b460c               mov eax, dword ptr [esi + 0xc]
// 0045039b  8b04f8               mov eax, dword ptr [eax + edi*8]
// 0045039e  85c0                 test eax, eax
// 004503a0  0f8597000000         jne 0x45043d
// 004503a6  6880ed4400           push 0x44ed80
// 004503ab  6898b3a300           push 0xa3b398
// 004503b0  e85b13fbff           call 0x401710
// 004503b5  83c408               add esp, 8
// 004503b8  e813d1ffff           call 0x44d4d0
// 004503bd  50                   push eax
// 004503be  8d4c2418             lea ecx, [esp + 0x18]
// 004503c2  51                   push ecx
// 004503c3  8bcb                 mov ecx, ebx
// 004503c5  e8969b1a00           call 0x5f9f60
// 004503ca  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004503ce  c744242400000000     mov dword ptr [esp + 0x24], 0
// 004503d6  85c9                 test ecx, ecx
// 004503d8  7526                 jne 0x450400
// 004503da  8d4c2414             lea ecx, [esp + 0x14]
// 004503de  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 004503e6  e8c5431d00           call 0x6247b0
// 004503eb  33c0                 xor eax, eax
// 004503ed  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004503f1  64890d00000000       mov dword ptr fs:[0], ecx
// 004503f8  5f                   pop edi
// 004503f9  5e                   pop esi
// 004503fa  5d                   pop ebp
// 004503fb  5b                   pop ebx
// 004503fc  83c418               add esp, 0x18
// 004503ff  c3                   ret 
// 00450400  8b5610               mov edx, dword ptr [esi + 0x10]
// 00450403  2b560c               sub edx, dword ptr [esi + 0xc]
// 00450406  8bd9                 mov ebx, ecx
// 00450408  c1fa03               sar edx, 3
// 0045040b  3bfa                 cmp edi, edx
// 0045040d  7206                 jb 0x450415
// 0045040f  ffd5                 call ebp
// 00450411  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00450415  8b460c               mov eax, dword ptr [esi + 0xc]
// 00450418  8d04f8               lea eax, [eax + edi*8]
// 0045041b  8908                 mov dword ptr [eax], ecx
// 0045041d  8d4c2418             lea ecx, [esp + 0x18]
// 00450421  51                   push ecx
// 00450422  8d4804               lea ecx, [eax + 4]
// 00450425  e8d620fbff           call 0x402500
// 0045042a  8d4c2414             lea ecx, [esp + 0x14]
// 0045042e  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 00450436  e875431d00           call 0x6247b0
// 0045043b  8bc3                 mov eax, ebx
// 0045043d  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00450441  5f                   pop edi
// 00450442  5e                   pop esi
// 00450443  5d                   pop ebp
// 00450444  64890d00000000       mov dword ptr fs:[0], ecx
// 0045044b  5b                   pop ebx
// 0045044c  83c418               add esp, 0x18
// 0045044f  c3                   ret 

// from server: 100% by colin
// roc 2008-06 00452b40  unit: RBX::VVisit::?$FactoryProduct::Creator  size: 320 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00452b40
//
// 00452b40  6aff                 push -1
// 00452b42  64a100000000         mov eax, dword ptr fs:[0]
// 00452b48  6868917d00           push 0x7d9168
// 00452b4d  50                   push eax
// 00452b4e  64892500000000       mov dword ptr fs:[0], esp
// 00452b55  83ec0c               sub esp, 0xc
// 00452b58  53                   push ebx
// 00452b59  55                   push ebp
// 00452b5a  56                   push esi
// 00452b5b  57                   push edi
// 00452b5c  6878dd9600           push 0x96dd78
// 00452b61  6880084500           push 0x450880
// 00452b66  8bd9                 mov ebx, ecx
// 00452b68  e8c3471000           call 0x557330
// 00452b6d  83c408               add esp, 8
// 00452b70  e82bc9ffff           call 0x44f4a0
// 00452b75  8b8ba0010000         mov ecx, dword ptr [ebx + 0x1a0]
// 00452b7b  2b8b9c010000         sub ecx, dword ptr [ebx + 0x19c]
// 00452b81  8b2d90288000         mov ebp, dword ptr [0x802890]
// 00452b87  8db390010000         lea esi, [ebx + 0x190]
// 00452b8d  8bf8                 mov edi, eax
// 00452b8f  8d4701               lea eax, [edi + 1]
// 00452b92  c1f903               sar ecx, 3
// 00452b95  3bc1                 cmp eax, ecx
// 00452b97  7620                 jbe 0x452bb9
// 00452b99  83ec08               sub esp, 8
// 00452b9c  8bcc                 mov ecx, esp
// 00452b9e  c70100000000         mov dword ptr [ecx], 0
// 00452ba4  89642418             mov dword ptr [esp + 0x18], esp
// 00452ba8  c7410400000000       mov dword ptr [ecx + 4], 0
// 00452baf  50                   push eax
// 00452bb0  8bce                 mov ecx, esi
// 00452bb2  e809f9fbff           call 0x4124c0
// 00452bb7  eb1d                 jmp 0x452bd6
// 00452bb9  8b5610               mov edx, dword ptr [esi + 0x10]
// 00452bbc  2b560c               sub edx, dword ptr [esi + 0xc]
// 00452bbf  c1fa03               sar edx, 3
// 00452bc2  3bfa                 cmp edi, edx
// 00452bc4  7202                 jb 0x452bc8
// 00452bc6  ffd5                 call ebp
// 00452bc8  8b460c               mov eax, dword ptr [esi + 0xc]
// 00452bcb  8b04f8               mov eax, dword ptr [eax + edi*8]
// 00452bce  85c0                 test eax, eax
// 00452bd0  0f8597000000         jne 0x452c6d
// 00452bd6  6868dd9600           push 0x96dd68
// 00452bdb  6840084500           push 0x450840
// 00452be0  e84b471000           call 0x557330
// 00452be5  83c408               add esp, 8
// 00452be8  e803c7ffff           call 0x44f2f0
// 00452bed  50                   push eax
// 00452bee  8d4c2418             lea ecx, [esp + 0x18]
// 00452bf2  51                   push ecx
// 00452bf3  8bcb                 mov ecx, ebx
// 00452bf5  e896fe1100           call 0x572a90
// 00452bfa  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00452bfe  c744242400000000     mov dword ptr [esp + 0x24], 0
// 00452c06  85c9                 test ecx, ecx
// 00452c08  7526                 jne 0x452c30
// 00452c0a  8d4c2414             lea ecx, [esp + 0x14]
// 00452c0e  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 00452c16  e845da1a00           call 0x600660
// 00452c1b  33c0                 xor eax, eax
// 00452c1d  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00452c21  64890d00000000       mov dword ptr fs:[0], ecx
// 00452c28  5f                   pop edi
// 00452c29  5e                   pop esi
// 00452c2a  5d                   pop ebp
// 00452c2b  5b                   pop ebx
// 00452c2c  83c418               add esp, 0x18
// 00452c2f  c3                   ret 
// 00452c30  8b5610               mov edx, dword ptr [esi + 0x10]
// 00452c33  2b560c               sub edx, dword ptr [esi + 0xc]
// 00452c36  8bd9                 mov ebx, ecx
// 00452c38  c1fa03               sar edx, 3
// 00452c3b  3bfa                 cmp edi, edx
// 00452c3d  7206                 jb 0x452c45
// 00452c3f  ffd5                 call ebp
// 00452c41  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00452c45  8b460c               mov eax, dword ptr [esi + 0xc]
// 00452c48  8d04f8               lea eax, [eax + edi*8]
// 00452c4b  8908                 mov dword ptr [eax], ecx
// 00452c4d  8d4c2418             lea ecx, [esp + 0x18]
// 00452c51  51                   push ecx
// 00452c52  8d4804               lea ecx, [eax + 4]
// 00452c55  e856f9faff           call 0x4025b0
// 00452c5a  8d4c2414             lea ecx, [esp + 0x14]
// 00452c5e  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 00452c66  e8f5d91a00           call 0x600660
// 00452c6b  8bc3                 mov eax, ebx
// 00452c6d  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00452c71  5f                   pop edi
// 00452c72  5e                   pop esi
// 00452c73  5d                   pop ebp
// 00452c74  64890d00000000       mov dword ptr fs:[0], ecx
// 00452c7b  5b                   pop ebx
// 00452c7c  83c418               add esp, 0x18
// 00452c7f  c3                   ret 

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
