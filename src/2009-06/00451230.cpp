// from server: 98% by EspClaude
// from server: 100% by colin
// roc 2008-06 00452c80  unit: RBX::VVisit::?$FactoryProduct::Creator  size: 320 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00452c80
//
// 00452c80  6aff                 push -1
// 00452c82  64a100000000         mov eax, dword ptr fs:[0]
// 00452c88  6868917d00           push 0x7d9168
// 00452c8d  50                   push eax
// 00452c8e  64892500000000       mov dword ptr fs:[0], esp
// 00452c95  83ec0c               sub esp, 0xc
// 00452c98  53                   push ebx
// 00452c99  55                   push ebp
// 00452c9a  56                   push esi
// 00452c9b  57                   push edi
// 00452c9c  6870dd9600           push 0x96dd70
// 00452ca1  6860084500           push 0x450860
// 00452ca6  8bd9                 mov ebx, ecx
// 00452ca8  e883461000           call 0x557330
// 00452cad  83c408               add esp, 8
// 00452cb0  e80bc7ffff           call 0x44f3c0
// 00452cb5  8b8ba0010000         mov ecx, dword ptr [ebx + 0x1a0]
// 00452cbb  2b8b9c010000         sub ecx, dword ptr [ebx + 0x19c]
// 00452cc1  8b2d90288000         mov ebp, dword ptr [0x802890]
// 00452cc7  8db390010000         lea esi, [ebx + 0x190]
// 00452ccd  8bf8                 mov edi, eax
// 00452ccf  8d4701               lea eax, [edi + 1]
// 00452cd2  c1f903               sar ecx, 3
// 00452cd5  3bc1                 cmp eax, ecx
// 00452cd7  7620                 jbe 0x452cf9
// 00452cd9  83ec08               sub esp, 8
// 00452cdc  8bcc                 mov ecx, esp
// 00452cde  c70100000000         mov dword ptr [ecx], 0
// 00452ce4  89642418             mov dword ptr [esp + 0x18], esp
// 00452ce8  c7410400000000       mov dword ptr [ecx + 4], 0
// 00452cef  50                   push eax
// 00452cf0  8bce                 mov ecx, esi
// 00452cf2  e8c9f7fbff           call 0x4124c0
// 00452cf7  eb1d                 jmp 0x452d16
// 00452cf9  8b5610               mov edx, dword ptr [esi + 0x10]
// 00452cfc  2b560c               sub edx, dword ptr [esi + 0xc]
// 00452cff  c1fa03               sar edx, 3
// 00452d02  3bfa                 cmp edi, edx
// 00452d04  7202                 jb 0x452d08
// 00452d06  ffd5                 call ebp
// 00452d08  8b460c               mov eax, dword ptr [esi + 0xc]
// 00452d0b  8b04f8               mov eax, dword ptr [eax + edi*8]
// 00452d0e  85c0                 test eax, eax
// 00452d10  0f8597000000         jne 0x452dad
// 00452d16  68b0c29600           push 0x96c2b0
// 00452d1b  68f0294000           push 0x4029f0
// 00452d20  e80b461000           call 0x557330
// 00452d25  83c408               add esp, 8
// 00452d28  e8d3ecfaff           call 0x401a00
// 00452d2d  50                   push eax
// 00452d2e  8d4c2418             lea ecx, [esp + 0x18]
// 00452d32  51                   push ecx
// 00452d33  8bcb                 mov ecx, ebx
// 00452d35  e856fd1100           call 0x572a90
// 00452d3a  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00452d3e  c744242400000000     mov dword ptr [esp + 0x24], 0
// 00452d46  85c9                 test ecx, ecx
// 00452d48  7526                 jne 0x452d70
// 00452d4a  8d4c2414             lea ecx, [esp + 0x14]
// 00452d4e  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 00452d56  e805d91a00           call 0x600660
// 00452d5b  33c0                 xor eax, eax
// 00452d5d  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00452d61  64890d00000000       mov dword ptr fs:[0], ecx
// 00452d68  5f                   pop edi
// 00452d69  5e                   pop esi
// 00452d6a  5d                   pop ebp
// 00452d6b  5b                   pop ebx
// 00452d6c  83c418               add esp, 0x18
// 00452d6f  c3                   ret 
// 00452d70  8b5610               mov edx, dword ptr [esi + 0x10]
// 00452d73  2b560c               sub edx, dword ptr [esi + 0xc]
// 00452d76  8bd9                 mov ebx, ecx
// 00452d78  c1fa03               sar edx, 3
// 00452d7b  3bfa                 cmp edi, edx
// 00452d7d  7206                 jb 0x452d85
// 00452d7f  ffd5                 call ebp
// 00452d81  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00452d85  8b460c               mov eax, dword ptr [esi + 0xc]
// 00452d88  8d04f8               lea eax, [eax + edi*8]
// 00452d8b  8908                 mov dword ptr [eax], ecx
// 00452d8d  8d4c2418             lea ecx, [esp + 0x18]
// 00452d91  51                   push ecx
// 00452d92  8d4804               lea ecx, [eax + 4]
// 00452d95  e816f8faff           call 0x4025b0
// 00452d9a  8d4c2414             lea ecx, [esp + 0x14]
// 00452d9e  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 00452da6  e8b5d81a00           call 0x600660
// 00452dab  8bc3                 mov eax, ebx
// 00452dad  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00452db1  5f                   pop edi
// 00452db2  5e                   pop esi
// 00452db3  5d                   pop ebp
// 00452db4  64890d00000000       mov dword ptr fs:[0], ecx
// 00452dbb  5b                   pop ebx
// 00452dbc  83c418               add esp, 0x18
// 00452dbf  c3                   ret 

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
