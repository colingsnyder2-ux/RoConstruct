// from server: 98% by EspClaude
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
    unsigned char padding[0x190];
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
