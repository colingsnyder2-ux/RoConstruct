// from server: 98% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0042de90  unit: RBX::VScriptContext::?$FactoryProduct::Creator  size: 320 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0042de90
//
// 0042de90  6aff                 push -1
// 0042de92  64a100000000         mov eax, dword ptr fs:[0]
// 0042de98  6868917d00           push 0x7d9168
// 0042de9d  50                   push eax
// 0042de9e  64892500000000       mov dword ptr fs:[0], esp
// 0042dea5  83ec0c               sub esp, 0xc
// 0042dea8  53                   push ebx
// 0042dea9  55                   push ebp
// 0042deaa  56                   push esi
// 0042deab  57                   push edi
// 0042deac  6830d19600           push 0x96d130
// 0042deb1  6880d14200           push 0x42d180
// 0042deb6  8bd9                 mov ebx, ecx
// 0042deb8  e873941200           call 0x557330
// 0042debd  83c408               add esp, 8
// 0042dec0  e86bf1ffff           call 0x42d030
// 0042dec5  8b8ba0010000         mov ecx, dword ptr [ebx + 0x1a0]
// 0042decb  2b8b9c010000         sub ecx, dword ptr [ebx + 0x19c]
// 0042ded1  8b2d90288000         mov ebp, dword ptr [0x802890]
// 0042ded7  8db390010000         lea esi, [ebx + 0x190]
// 0042dedd  8bf8                 mov edi, eax
// 0042dedf  8d4701               lea eax, [edi + 1]
// 0042dee2  c1f903               sar ecx, 3
// 0042dee5  3bc1                 cmp eax, ecx
// 0042dee7  7620                 jbe 0x42df09
// 0042dee9  83ec08               sub esp, 8
// 0042deec  8bcc                 mov ecx, esp
// 0042deee  c70100000000         mov dword ptr [ecx], 0
// 0042def4  89642418             mov dword ptr [esp + 0x18], esp
// 0042def8  c7410400000000       mov dword ptr [ecx + 4], 0
// 0042deff  50                   push eax
// 0042df00  8bce                 mov ecx, esi
// 0042df02  e8b945feff           call 0x4124c0
// 0042df07  eb1d                 jmp 0x42df26
// 0042df09  8b5610               mov edx, dword ptr [esi + 0x10]
// 0042df0c  2b560c               sub edx, dword ptr [esi + 0xc]
// 0042df0f  c1fa03               sar edx, 3
// 0042df12  3bfa                 cmp edi, edx
// 0042df14  7202                 jb 0x42df18
// 0042df16  ffd5                 call ebp
// 0042df18  8b460c               mov eax, dword ptr [esi + 0xc]
// 0042df1b  8b04f8               mov eax, dword ptr [eax + edi*8]
// 0042df1e  85c0                 test eax, eax
// 0042df20  0f8597000000         jne 0x42dfbd
// 0042df26  682cd19600           push 0x96d12c
// 0042df2b  6890d04200           push 0x42d090
// 0042df30  e8fb931200           call 0x557330
// 0042df35  83c408               add esp, 8
// 0042df38  e893efffff           call 0x42ced0
// 0042df3d  50                   push eax
// 0042df3e  8d4c2418             lea ecx, [esp + 0x18]
// 0042df42  51                   push ecx
// 0042df43  8bcb                 mov ecx, ebx
// 0042df45  e8464b1400           call 0x572a90
// 0042df4a  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0042df4e  c744242400000000     mov dword ptr [esp + 0x24], 0
// 0042df56  85c9                 test ecx, ecx
// 0042df58  7526                 jne 0x42df80
// 0042df5a  8d4c2414             lea ecx, [esp + 0x14]
// 0042df5e  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 0042df66  e8f5261d00           call 0x600660
// 0042df6b  33c0                 xor eax, eax
// 0042df6d  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0042df71  64890d00000000       mov dword ptr fs:[0], ecx
// 0042df78  5f                   pop edi
// 0042df79  5e                   pop esi
// 0042df7a  5d                   pop ebp
// 0042df7b  5b                   pop ebx
// 0042df7c  83c418               add esp, 0x18
// 0042df7f  c3                   ret 
// 0042df80  8b5610               mov edx, dword ptr [esi + 0x10]
// 0042df83  2b560c               sub edx, dword ptr [esi + 0xc]
// 0042df86  8bd9                 mov ebx, ecx
// 0042df88  c1fa03               sar edx, 3
// 0042df8b  3bfa                 cmp edi, edx
// 0042df8d  7206                 jb 0x42df95
// 0042df8f  ffd5                 call ebp
// 0042df91  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0042df95  8b460c               mov eax, dword ptr [esi + 0xc]
// 0042df98  8d04f8               lea eax, [eax + edi*8]
// 0042df9b  8908                 mov dword ptr [eax], ecx
// 0042df9d  8d4c2418             lea ecx, [esp + 0x18]
// 0042dfa1  51                   push ecx
// 0042dfa2  8d4804               lea ecx, [eax + 4]
// 0042dfa5  e80646fdff           call 0x4025b0
// 0042dfaa  8d4c2414             lea ecx, [esp + 0x14]
// 0042dfae  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 0042dfb6  e8a5261d00           call 0x600660
// 0042dfbb  8bc3                 mov eax, ebx
// 0042dfbd  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0042dfc1  5f                   pop edi
// 0042dfc2  5e                   pop esi
// 0042dfc3  5d                   pop ebp
// 0042dfc4  64890d00000000       mov dword ptr fs:[0], ecx
// 0042dfcb  5b                   pop ebx
// 0042dfcc  83c418               add esp, 0x18
// 0042dfcf  c3                   ret 

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
