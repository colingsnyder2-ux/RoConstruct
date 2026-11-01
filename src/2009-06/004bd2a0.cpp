// from server: 98% by EspClaude
// from server: 100% by colin
// roc 2008-06 00490c30  unit: RBX::VHumanoid::?$FactoryProduct::Creator  size: 320 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00490c30
//
// 00490c30  6aff                 push -1
// 00490c32  64a100000000         mov eax, dword ptr fs:[0]
// 00490c38  6868917d00           push 0x7d9168
// 00490c3d  50                   push eax
// 00490c3e  64892500000000       mov dword ptr fs:[0], esp
// 00490c45  83ec0c               sub esp, 0xc
// 00490c48  53                   push ebx
// 00490c49  55                   push ebp
// 00490c4a  56                   push esi
// 00490c4b  57                   push edi
// 00490c4c  68f4fb9600           push 0x96fbf4
// 00490c51  6870ad4800           push 0x48ad70
// 00490c56  8bd9                 mov ebx, ecx
// 00490c58  e8d3660c00           call 0x557330
// 00490c5d  83c408               add esp, 8
// 00490c60  e85b98ffff           call 0x48a4c0
// 00490c65  8b8ba0010000         mov ecx, dword ptr [ebx + 0x1a0]
// 00490c6b  2b8b9c010000         sub ecx, dword ptr [ebx + 0x19c]
// 00490c71  8b2d90288000         mov ebp, dword ptr [0x802890]
// 00490c77  8db390010000         lea esi, [ebx + 0x190]
// 00490c7d  8bf8                 mov edi, eax
// 00490c7f  8d4701               lea eax, [edi + 1]
// 00490c82  c1f903               sar ecx, 3
// 00490c85  3bc1                 cmp eax, ecx
// 00490c87  7620                 jbe 0x490ca9
// 00490c89  83ec08               sub esp, 8
// 00490c8c  8bcc                 mov ecx, esp
// 00490c8e  c70100000000         mov dword ptr [ecx], 0
// 00490c94  89642418             mov dword ptr [esp + 0x18], esp
// 00490c98  c7410400000000       mov dword ptr [ecx + 4], 0
// 00490c9f  50                   push eax
// 00490ca0  8bce                 mov ecx, esi
// 00490ca2  e81918f8ff           call 0x4124c0
// 00490ca7  eb1d                 jmp 0x490cc6
// 00490ca9  8b5610               mov edx, dword ptr [esi + 0x10]
// 00490cac  2b560c               sub edx, dword ptr [esi + 0xc]
// 00490caf  c1fa03               sar edx, 3
// 00490cb2  3bfa                 cmp edi, edx
// 00490cb4  7202                 jb 0x490cb8
// 00490cb6  ffd5                 call ebp
// 00490cb8  8b460c               mov eax, dword ptr [esi + 0xc]
// 00490cbb  8b04f8               mov eax, dword ptr [eax + edi*8]
// 00490cbe  85c0                 test eax, eax
// 00490cc0  0f8597000000         jne 0x490d5d
// 00490cc6  68c4fb9600           push 0x96fbc4
// 00490ccb  68d0aa4800           push 0x48aad0
// 00490cd0  e85b660c00           call 0x557330
// 00490cd5  83c408               add esp, 8
// 00490cd8  e8f391ffff           call 0x489ed0
// 00490cdd  50                   push eax
// 00490cde  8d4c2418             lea ecx, [esp + 0x18]
// 00490ce2  51                   push ecx
// 00490ce3  8bcb                 mov ecx, ebx
// 00490ce5  e8a61d0e00           call 0x572a90
// 00490cea  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00490cee  c744242400000000     mov dword ptr [esp + 0x24], 0
// 00490cf6  85c9                 test ecx, ecx
// 00490cf8  7526                 jne 0x490d20
// 00490cfa  8d4c2414             lea ecx, [esp + 0x14]
// 00490cfe  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 00490d06  e855f91600           call 0x600660
// 00490d0b  33c0                 xor eax, eax
// 00490d0d  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00490d11  64890d00000000       mov dword ptr fs:[0], ecx
// 00490d18  5f                   pop edi
// 00490d19  5e                   pop esi
// 00490d1a  5d                   pop ebp
// 00490d1b  5b                   pop ebx
// 00490d1c  83c418               add esp, 0x18
// 00490d1f  c3                   ret 
// 00490d20  8b5610               mov edx, dword ptr [esi + 0x10]
// 00490d23  2b560c               sub edx, dword ptr [esi + 0xc]
// 00490d26  8bd9                 mov ebx, ecx
// 00490d28  c1fa03               sar edx, 3
// 00490d2b  3bfa                 cmp edi, edx
// 00490d2d  7206                 jb 0x490d35
// 00490d2f  ffd5                 call ebp
// 00490d31  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00490d35  8b460c               mov eax, dword ptr [esi + 0xc]
// 00490d38  8d04f8               lea eax, [eax + edi*8]
// 00490d3b  8908                 mov dword ptr [eax], ecx
// 00490d3d  8d4c2418             lea ecx, [esp + 0x18]
// 00490d41  51                   push ecx
// 00490d42  8d4804               lea ecx, [eax + 4]
// 00490d45  e86618f7ff           call 0x4025b0
// 00490d4a  8d4c2414             lea ecx, [esp + 0x14]
// 00490d4e  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 00490d56  e805f91600           call 0x600660
// 00490d5b  8bc3                 mov eax, ebx
// 00490d5d  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00490d61  5f                   pop edi
// 00490d62  5e                   pop esi
// 00490d63  5d                   pop ebp
// 00490d64  64890d00000000       mov dword ptr fs:[0], ecx
// 00490d6b  5b                   pop ebx
// 00490d6c  83c418               add esp, 0x18
// 00490d6f  c3                   ret 

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
