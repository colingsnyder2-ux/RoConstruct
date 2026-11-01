// from server: 98% by EspClaude
// from server: 100% by colin
// roc 2008-06 00490d70  unit: RBX::VHumanoid::?$FactoryProduct::Creator  size: 320 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00490d70
//
// 00490d70  6aff                 push -1
// 00490d72  64a100000000         mov eax, dword ptr fs:[0]
// 00490d78  6868917d00           push 0x7d9168
// 00490d7d  50                   push eax
// 00490d7e  64892500000000       mov dword ptr fs:[0], esp
// 00490d85  83ec0c               sub esp, 0xc
// 00490d88  53                   push ebx
// 00490d89  55                   push ebp
// 00490d8a  56                   push esi
// 00490d8b  57                   push edi
// 00490d8c  68f8fb9600           push 0x96fbf8
// 00490d91  6880ad4800           push 0x48ad80
// 00490d96  8bd9                 mov ebx, ecx
// 00490d98  e893650c00           call 0x557330
// 00490d9d  83c408               add esp, 8
// 00490da0  e87b97ffff           call 0x48a520
// 00490da5  8b8ba0010000         mov ecx, dword ptr [ebx + 0x1a0]
// 00490dab  2b8b9c010000         sub ecx, dword ptr [ebx + 0x19c]
// 00490db1  8b2d90288000         mov ebp, dword ptr [0x802890]
// 00490db7  8db390010000         lea esi, [ebx + 0x190]
// 00490dbd  8bf8                 mov edi, eax
// 00490dbf  8d4701               lea eax, [edi + 1]
// 00490dc2  c1f903               sar ecx, 3
// 00490dc5  3bc1                 cmp eax, ecx
// 00490dc7  7620                 jbe 0x490de9
// 00490dc9  83ec08               sub esp, 8
// 00490dcc  8bcc                 mov ecx, esp
// 00490dce  c70100000000         mov dword ptr [ecx], 0
// 00490dd4  89642418             mov dword ptr [esp + 0x18], esp
// 00490dd8  c7410400000000       mov dword ptr [ecx + 4], 0
// 00490ddf  50                   push eax
// 00490de0  8bce                 mov ecx, esi
// 00490de2  e8d916f8ff           call 0x4124c0
// 00490de7  eb1d                 jmp 0x490e06
// 00490de9  8b5610               mov edx, dword ptr [esi + 0x10]
// 00490dec  2b560c               sub edx, dword ptr [esi + 0xc]
// 00490def  c1fa03               sar edx, 3
// 00490df2  3bfa                 cmp edi, edx
// 00490df4  7202                 jb 0x490df8
// 00490df6  ffd5                 call ebp
// 00490df8  8b460c               mov eax, dword ptr [esi + 0xc]
// 00490dfb  8b04f8               mov eax, dword ptr [eax + edi*8]
// 00490dfe  85c0                 test eax, eax
// 00490e00  0f8597000000         jne 0x490e9d
// 00490e06  68b4fb9600           push 0x96fbb4
// 00490e0b  6890aa4800           push 0x48aa90
// 00490e10  e81b650c00           call 0x557330
// 00490e15  83c408               add esp, 8
// 00490e18  e8f38effff           call 0x489d10
// 00490e1d  50                   push eax
// 00490e1e  8d4c2418             lea ecx, [esp + 0x18]
// 00490e22  51                   push ecx
// 00490e23  8bcb                 mov ecx, ebx
// 00490e25  e8661c0e00           call 0x572a90
// 00490e2a  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00490e2e  c744242400000000     mov dword ptr [esp + 0x24], 0
// 00490e36  85c9                 test ecx, ecx
// 00490e38  7526                 jne 0x490e60
// 00490e3a  8d4c2414             lea ecx, [esp + 0x14]
// 00490e3e  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 00490e46  e815f81600           call 0x600660
// 00490e4b  33c0                 xor eax, eax
// 00490e4d  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00490e51  64890d00000000       mov dword ptr fs:[0], ecx
// 00490e58  5f                   pop edi
// 00490e59  5e                   pop esi
// 00490e5a  5d                   pop ebp
// 00490e5b  5b                   pop ebx
// 00490e5c  83c418               add esp, 0x18
// 00490e5f  c3                   ret 
// 00490e60  8b5610               mov edx, dword ptr [esi + 0x10]
// 00490e63  2b560c               sub edx, dword ptr [esi + 0xc]
// 00490e66  8bd9                 mov ebx, ecx
// 00490e68  c1fa03               sar edx, 3
// 00490e6b  3bfa                 cmp edi, edx
// 00490e6d  7206                 jb 0x490e75
// 00490e6f  ffd5                 call ebp
// 00490e71  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00490e75  8b460c               mov eax, dword ptr [esi + 0xc]
// 00490e78  8d04f8               lea eax, [eax + edi*8]
// 00490e7b  8908                 mov dword ptr [eax], ecx
// 00490e7d  8d4c2418             lea ecx, [esp + 0x18]
// 00490e81  51                   push ecx
// 00490e82  8d4804               lea ecx, [eax + 4]
// 00490e85  e82617f7ff           call 0x4025b0
// 00490e8a  8d4c2414             lea ecx, [esp + 0x14]
// 00490e8e  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 00490e96  e8c5f71600           call 0x600660
// 00490e9b  8bc3                 mov eax, ebx
// 00490e9d  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00490ea1  5f                   pop edi
// 00490ea2  5e                   pop esi
// 00490ea3  5d                   pop ebp
// 00490ea4  64890d00000000       mov dword ptr fs:[0], ecx
// 00490eab  5b                   pop ebx
// 00490eac  83c418               add esp, 0x18
// 00490eaf  c3                   ret 

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
