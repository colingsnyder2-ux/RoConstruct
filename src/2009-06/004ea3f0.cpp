// from server: 98% by EspClaude
// from server: 100% by colin
// roc 2008-06 004b3380  unit: RBX::VMotor::?$FactoryProduct::Creator  size: 320 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004b3380
//
// 004b3380  6aff                 push -1
// 004b3382  64a100000000         mov eax, dword ptr fs:[0]
// 004b3388  6868917d00           push 0x7d9168
// 004b338d  50                   push eax
// 004b338e  64892500000000       mov dword ptr fs:[0], esp
// 004b3395  83ec0c               sub esp, 0xc
// 004b3398  53                   push ebx
// 004b3399  55                   push ebp
// 004b339a  56                   push esi
// 004b339b  57                   push edi
// 004b339c  6890149700           push 0x971490
// 004b33a1  6800c64a00           push 0x4ac600
// 004b33a6  8bd9                 mov ebx, ecx
// 004b33a8  e8833f0a00           call 0x557330
// 004b33ad  83c408               add esp, 8
// 004b33b0  e8bb80ffff           call 0x4ab470
// 004b33b5  8b8ba0010000         mov ecx, dword ptr [ebx + 0x1a0]
// 004b33bb  2b8b9c010000         sub ecx, dword ptr [ebx + 0x19c]
// 004b33c1  8b2d90288000         mov ebp, dword ptr [0x802890]
// 004b33c7  8db390010000         lea esi, [ebx + 0x190]
// 004b33cd  8bf8                 mov edi, eax
// 004b33cf  8d4701               lea eax, [edi + 1]
// 004b33d2  c1f903               sar ecx, 3
// 004b33d5  3bc1                 cmp eax, ecx
// 004b33d7  7620                 jbe 0x4b33f9
// 004b33d9  83ec08               sub esp, 8
// 004b33dc  8bcc                 mov ecx, esp
// 004b33de  c70100000000         mov dword ptr [ecx], 0
// 004b33e4  89642418             mov dword ptr [esp + 0x18], esp
// 004b33e8  c7410400000000       mov dword ptr [ecx + 4], 0
// 004b33ef  50                   push eax
// 004b33f0  8bce                 mov ecx, esi
// 004b33f2  e8c9f0f5ff           call 0x4124c0
// 004b33f7  eb1d                 jmp 0x4b3416
// 004b33f9  8b5610               mov edx, dword ptr [esi + 0x10]
// 004b33fc  2b560c               sub edx, dword ptr [esi + 0xc]
// 004b33ff  c1fa03               sar edx, 3
// 004b3402  3bfa                 cmp edi, edx
// 004b3404  7202                 jb 0x4b3408
// 004b3406  ffd5                 call ebp
// 004b3408  8b460c               mov eax, dword ptr [esi + 0xc]
// 004b340b  8b04f8               mov eax, dword ptr [eax + edi*8]
// 004b340e  85c0                 test eax, eax
// 004b3410  0f8597000000         jne 0x4b34ad
// 004b3416  6870149700           push 0x971470
// 004b341b  6810c34a00           push 0x4ac310
// 004b3420  e80b3f0a00           call 0x557330
// 004b3425  83c408               add esp, 8
// 004b3428  e8c37cffff           call 0x4ab0f0
// 004b342d  50                   push eax
// 004b342e  8d4c2418             lea ecx, [esp + 0x18]
// 004b3432  51                   push ecx
// 004b3433  8bcb                 mov ecx, ebx
// 004b3435  e856f60b00           call 0x572a90
// 004b343a  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004b343e  c744242400000000     mov dword ptr [esp + 0x24], 0
// 004b3446  85c9                 test ecx, ecx
// 004b3448  7526                 jne 0x4b3470
// 004b344a  8d4c2414             lea ecx, [esp + 0x14]
// 004b344e  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 004b3456  e805d21400           call 0x600660
// 004b345b  33c0                 xor eax, eax
// 004b345d  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004b3461  64890d00000000       mov dword ptr fs:[0], ecx
// 004b3468  5f                   pop edi
// 004b3469  5e                   pop esi
// 004b346a  5d                   pop ebp
// 004b346b  5b                   pop ebx
// 004b346c  83c418               add esp, 0x18
// 004b346f  c3                   ret 
// 004b3470  8b5610               mov edx, dword ptr [esi + 0x10]
// 004b3473  2b560c               sub edx, dword ptr [esi + 0xc]
// 004b3476  8bd9                 mov ebx, ecx
// 004b3478  c1fa03               sar edx, 3
// 004b347b  3bfa                 cmp edi, edx
// 004b347d  7206                 jb 0x4b3485
// 004b347f  ffd5                 call ebp
// 004b3481  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004b3485  8b460c               mov eax, dword ptr [esi + 0xc]
// 004b3488  8d04f8               lea eax, [eax + edi*8]
// 004b348b  8908                 mov dword ptr [eax], ecx
// 004b348d  8d4c2418             lea ecx, [esp + 0x18]
// 004b3491  51                   push ecx
// 004b3492  8d4804               lea ecx, [eax + 4]
// 004b3495  e816f1f4ff           call 0x4025b0
// 004b349a  8d4c2414             lea ecx, [esp + 0x14]
// 004b349e  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 004b34a6  e8b5d11400           call 0x600660
// 004b34ab  8bc3                 mov eax, ebx
// 004b34ad  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004b34b1  5f                   pop edi
// 004b34b2  5e                   pop esi
// 004b34b3  5d                   pop ebp
// 004b34b4  64890d00000000       mov dword ptr fs:[0], ecx
// 004b34bb  5b                   pop ebx
// 004b34bc  83c418               add esp, 0x18
// 004b34bf  c3                   ret 

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
