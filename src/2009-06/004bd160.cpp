// from server: 98% by EspClaude
// from server: 100% by colin
// roc 2008-06 00490af0  unit: RBX::VHumanoid::?$FactoryProduct::Creator  size: 320 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00490af0
//
// 00490af0  6aff                 push -1
// 00490af2  64a100000000         mov eax, dword ptr fs:[0]
// 00490af8  6868917d00           push 0x7d9168
// 00490afd  50                   push eax
// 00490afe  64892500000000       mov dword ptr fs:[0], esp
// 00490b05  83ec0c               sub esp, 0xc
// 00490b08  53                   push ebx
// 00490b09  55                   push ebp
// 00490b0a  56                   push esi
// 00490b0b  57                   push edi
// 00490b0c  68f0fb9600           push 0x96fbf0
// 00490b11  6860ad4800           push 0x48ad60
// 00490b16  8bd9                 mov ebx, ecx
// 00490b18  e813680c00           call 0x557330
// 00490b1d  83c408               add esp, 8
// 00490b20  e83b99ffff           call 0x48a460
// 00490b25  8b8ba0010000         mov ecx, dword ptr [ebx + 0x1a0]
// 00490b2b  2b8b9c010000         sub ecx, dword ptr [ebx + 0x19c]
// 00490b31  8b2d90288000         mov ebp, dword ptr [0x802890]
// 00490b37  8db390010000         lea esi, [ebx + 0x190]
// 00490b3d  8bf8                 mov edi, eax
// 00490b3f  8d4701               lea eax, [edi + 1]
// 00490b42  c1f903               sar ecx, 3
// 00490b45  3bc1                 cmp eax, ecx
// 00490b47  7620                 jbe 0x490b69
// 00490b49  83ec08               sub esp, 8
// 00490b4c  8bcc                 mov ecx, esp
// 00490b4e  c70100000000         mov dword ptr [ecx], 0
// 00490b54  89642418             mov dword ptr [esp + 0x18], esp
// 00490b58  c7410400000000       mov dword ptr [ecx + 4], 0
// 00490b5f  50                   push eax
// 00490b60  8bce                 mov ecx, esi
// 00490b62  e85919f8ff           call 0x4124c0
// 00490b67  eb1d                 jmp 0x490b86
// 00490b69  8b5610               mov edx, dword ptr [esi + 0x10]
// 00490b6c  2b560c               sub edx, dword ptr [esi + 0xc]
// 00490b6f  c1fa03               sar edx, 3
// 00490b72  3bfa                 cmp edi, edx
// 00490b74  7202                 jb 0x490b78
// 00490b76  ffd5                 call ebp
// 00490b78  8b460c               mov eax, dword ptr [esi + 0xc]
// 00490b7b  8b04f8               mov eax, dword ptr [eax + edi*8]
// 00490b7e  85c0                 test eax, eax
// 00490b80  0f8597000000         jne 0x490c1d
// 00490b86  68acfb9600           push 0x96fbac
// 00490b8b  6870aa4800           push 0x48aa70
// 00490b90  e89b670c00           call 0x557330
// 00490b95  83c408               add esp, 8
// 00490b98  e89390ffff           call 0x489c30
// 00490b9d  50                   push eax
// 00490b9e  8d4c2418             lea ecx, [esp + 0x18]
// 00490ba2  51                   push ecx
// 00490ba3  8bcb                 mov ecx, ebx
// 00490ba5  e8e61e0e00           call 0x572a90
// 00490baa  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00490bae  c744242400000000     mov dword ptr [esp + 0x24], 0
// 00490bb6  85c9                 test ecx, ecx
// 00490bb8  7526                 jne 0x490be0
// 00490bba  8d4c2414             lea ecx, [esp + 0x14]
// 00490bbe  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 00490bc6  e895fa1600           call 0x600660
// 00490bcb  33c0                 xor eax, eax
// 00490bcd  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00490bd1  64890d00000000       mov dword ptr fs:[0], ecx
// 00490bd8  5f                   pop edi
// 00490bd9  5e                   pop esi
// 00490bda  5d                   pop ebp
// 00490bdb  5b                   pop ebx
// 00490bdc  83c418               add esp, 0x18
// 00490bdf  c3                   ret 
// 00490be0  8b5610               mov edx, dword ptr [esi + 0x10]
// 00490be3  2b560c               sub edx, dword ptr [esi + 0xc]
// 00490be6  8bd9                 mov ebx, ecx
// 00490be8  c1fa03               sar edx, 3
// 00490beb  3bfa                 cmp edi, edx
// 00490bed  7206                 jb 0x490bf5
// 00490bef  ffd5                 call ebp
// 00490bf1  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00490bf5  8b460c               mov eax, dword ptr [esi + 0xc]
// 00490bf8  8d04f8               lea eax, [eax + edi*8]
// 00490bfb  8908                 mov dword ptr [eax], ecx
// 00490bfd  8d4c2418             lea ecx, [esp + 0x18]
// 00490c01  51                   push ecx
// 00490c02  8d4804               lea ecx, [eax + 4]
// 00490c05  e8a619f7ff           call 0x4025b0
// 00490c0a  8d4c2414             lea ecx, [esp + 0x14]
// 00490c0e  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 00490c16  e845fa1600           call 0x600660
// 00490c1b  8bc3                 mov eax, ebx
// 00490c1d  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00490c21  5f                   pop edi
// 00490c22  5e                   pop esi
// 00490c23  5d                   pop ebp
// 00490c24  64890d00000000       mov dword ptr fs:[0], ecx
// 00490c2b  5b                   pop ebx
// 00490c2c  83c418               add esp, 0x18
// 00490c2f  c3                   ret 

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
