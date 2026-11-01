// from server: 100% by EspClaude
// from server: 98% by EspClaude
// roc 2009-06 00451230  unit: RBX::VVisit::?$FactoryProduct::Creator  size: 320 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00451230
//
// 00451230  6aff                 push -1
// 00451232  64a100000000         mov eax, dword ptr fs:[0]
// 00451238  68e8a68600           push 0x86a6e8
// 0045123d  50                   push eax
// 0045123e  64892500000000       mov dword ptr fs:[0], esp
// 00451245  83ec0c               sub esp, 0xc
// 00451248  53                   push ebx
// 00451249  55                   push ebp
// 0045124a  56                   push esi
// 0045124b  57                   push edi
// 0045124c  68a0ed4400           push 0x44eda0
// 00451251  68a0b3a300           push 0xa3b3a0
// 00451256  8bd9                 mov ebx, ecx
// 00451258  e8b304fbff           call 0x401710
// 0045125d  83c408               add esp, 8
// 00451260  e84bc3ffff           call 0x44d5b0
// 00451265  8b8b9c000000         mov ecx, dword ptr [ebx + 0x9c]
// 0045126b  2b8b98000000         sub ecx, dword ptr [ebx + 0x98]
// 00451271  8b2dace98900         mov ebp, dword ptr [0x89e9ac]
// 00451277  8db38c000000         lea esi, [ebx + 0x8c]
// 0045127d  8bf8                 mov edi, eax
// 0045127f  8d4701               lea eax, [edi + 1]
// 00451282  c1f903               sar ecx, 3
// 00451285  3bc1                 cmp eax, ecx
// 00451287  7620                 jbe 0x4512a9
// 00451289  83ec08               sub esp, 8
// 0045128c  8bcc                 mov ecx, esp
// 0045128e  c70100000000         mov dword ptr [ecx], 0
// 00451294  89642418             mov dword ptr [esp + 0x18], esp
// 00451298  c7410400000000       mov dword ptr [ecx + 4], 0
// 0045129f  50                   push eax
// 004512a0  8bce                 mov ecx, esi
// 004512a2  e839f4fbff           call 0x4106e0
// 004512a7  eb1d                 jmp 0x4512c6
// 004512a9  8b5610               mov edx, dword ptr [esi + 0x10]
// 004512ac  2b560c               sub edx, dword ptr [esi + 0xc]
// 004512af  c1fa03               sar edx, 3
// 004512b2  3bfa                 cmp edi, edx
// 004512b4  7202                 jb 0x4512b8
// 004512b6  ffd5                 call ebp
// 004512b8  8b460c               mov eax, dword ptr [esi + 0xc]
// 004512bb  8b04f8               mov eax, dword ptr [eax + edi*8]
// 004512be  85c0                 test eax, eax
// 004512c0  0f8597000000         jne 0x45135d
// 004512c6  6870254000           push 0x402570
// 004512cb  684097a300           push 0xa39740
// 004512d0  e83b04fbff           call 0x401710
// 004512d5  83c408               add esp, 8
// 004512d8  e8b311fbff           call 0x402490
// 004512dd  50                   push eax
// 004512de  8d4c2418             lea ecx, [esp + 0x18]
// 004512e2  51                   push ecx
// 004512e3  8bcb                 mov ecx, ebx
// 004512e5  e8768c1a00           call 0x5f9f60
// 004512ea  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004512ee  c744242400000000     mov dword ptr [esp + 0x24], 0
// 004512f6  85c9                 test ecx, ecx
// 004512f8  7526                 jne 0x451320
// 004512fa  8d4c2414             lea ecx, [esp + 0x14]
// 004512fe  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 00451306  e8a5341d00           call 0x6247b0
// 0045130b  33c0                 xor eax, eax
// 0045130d  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00451311  64890d00000000       mov dword ptr fs:[0], ecx
// 00451318  5f                   pop edi
// 00451319  5e                   pop esi
// 0045131a  5d                   pop ebp
// 0045131b  5b                   pop ebx
// 0045131c  83c418               add esp, 0x18
// 0045131f  c3                   ret 
// 00451320  8b5610               mov edx, dword ptr [esi + 0x10]
// 00451323  2b560c               sub edx, dword ptr [esi + 0xc]
// 00451326  8bd9                 mov ebx, ecx
// 00451328  c1fa03               sar edx, 3
// 0045132b  3bfa                 cmp edi, edx
// 0045132d  7206                 jb 0x451335
// 0045132f  ffd5                 call ebp
// 00451331  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00451335  8b460c               mov eax, dword ptr [esi + 0xc]
// 00451338  8d04f8               lea eax, [eax + edi*8]
// 0045133b  8908                 mov dword ptr [eax], ecx
// 0045133d  8d4c2418             lea ecx, [esp + 0x18]
// 00451341  51                   push ecx
// 00451342  8d4804               lea ecx, [eax + 4]
// 00451345  e8b611fbff           call 0x402500
// 0045134a  8d4c2414             lea ecx, [esp + 0x14]
// 0045134e  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 00451356  e855341d00           call 0x6247b0
// 0045135b  8bc3                 mov eax, ebx
// 0045135d  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00451361  5f                   pop edi
// 00451362  5e                   pop esi
// 00451363  5d                   pop ebp
// 00451364  64890d00000000       mov dword ptr fs:[0], ecx
// 0045136b  5b                   pop ebx
// 0045136c  83c418               add esp, 0x18
// 0045136f  c3                   ret 

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
