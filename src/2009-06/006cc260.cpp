// from server: 100% by EspClaude
// from server: 93% by EspClaude
// roc 2009-06 006cc260  unit: RBX::GrabTool  size: 238 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006cc260
//
// 006cc260  6aff                 push -1
// 006cc262  68980e8700           push 0x870e98
// 006cc267  64a100000000         mov eax, dword ptr fs:[0]
// 006cc26d  50                   push eax
// 006cc26e  64892500000000       mov dword ptr fs:[0], esp
// 006cc275  83ec24               sub esp, 0x24
// 006cc278  d9ee                 fldz 
// 006cc27a  53                   push ebx
// 006cc27b  8b5c2438             mov ebx, dword ptr [esp + 0x38]
// 006cc27f  d9542404             fst dword ptr [esp + 4]
// 006cc283  55                   push ebp
// 006cc284  d954240c             fst dword ptr [esp + 0xc]
// 006cc288  56                   push esi
// 006cc289  d95c2414             fstp dword ptr [esp + 0x14]
// 006cc28d  57                   push edi
// 006cc28e  8d442410             lea eax, [esp + 0x10]
// 006cc292  50                   push eax
// 006cc293  53                   push ebx
// 006cc294  8bf1                 mov esi, ecx
// 006cc296  e805a1feff           call 0x6b63a0
// 006cc29b  8bf8                 mov edi, eax
// 006cc29d  33ed                 xor ebp, ebp
// 006cc29f  3bfd                 cmp edi, ebp
// 006cc2a1  0f8490000000         je 0x6cc337
// 006cc2a7  8d4c241c             lea ecx, [esp + 0x1c]
// 006cc2ab  e860e3f8ff           call 0x65a610
// 006cc2b0  57                   push edi
// 006cc2b1  8bce                 mov ecx, esi
// 006cc2b3  896c2440             mov dword ptr [esp + 0x40], ebp
// 006cc2b7  e8e498feff           call 0x6b5ba0
// 006cc2bc  8d4c2444             lea ecx, [esp + 0x44]
// 006cc2c0  51                   push ecx
// 006cc2c1  8d4c2420             lea ecx, [esp + 0x20]
// 006cc2c5  89442448             mov dword ptr [esp + 0x48], eax
// 006cc2c9  e8a27ad6ff           call 0x433d70
// 006cc2ce  83ec08               sub esp, 8
// 006cc2d1  8bc4                 mov eax, esp
// 006cc2d3  8928                 mov dword ptr [eax], ebp
// 006cc2d5  8964244c             mov dword ptr [esp + 0x4c], esp
// 006cc2d9  896804               mov dword ptr [eax + 4], ebp
// 006cc2dc  8b5618               mov edx, dword ptr [esi + 0x18]
// 006cc2df  52                   push edx
// 006cc2e0  53                   push ebx
// 006cc2e1  8d44242c             lea eax, [esp + 0x2c]
// 006cc2e5  50                   push eax
// 006cc2e6  8d4c2424             lea ecx, [esp + 0x24]
// 006cc2ea  51                   push ecx
// 006cc2eb  57                   push edi
// 006cc2ec  e88fc20100           call 0x6e8580
// 006cc2f1  8bf0                 mov esi, eax
// 006cc2f3  8b442444             mov eax, dword ptr [esp + 0x44]
// 006cc2f7  83c41c               add esp, 0x1c
// 006cc2fa  3bc5                 cmp eax, ebp
// 006cc2fc  7409                 je 0x6cc307
// 006cc2fe  50                   push eax
// 006cc2ff  e82ec70400           call 0x718a32
// 006cc304  83c404               add esp, 4
// 006cc307  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 006cc30b  52                   push edx
// 006cc30c  896c242c             mov dword ptr [esp + 0x2c], ebp
// 006cc310  896c2430             mov dword ptr [esp + 0x30], ebp
// 006cc314  896c2434             mov dword ptr [esp + 0x34], ebp
// 006cc318  e815c70400           call 0x718a32
// 006cc31d  83c404               add esp, 4
// 006cc320  8bc6                 mov eax, esi
// 006cc322  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 006cc326  64890d00000000       mov dword ptr fs:[0], ecx
// 006cc32d  5f                   pop edi
// 006cc32e  5e                   pop esi
// 006cc32f  5d                   pop ebp
// 006cc330  5b                   pop ebx
// 006cc331  83c430               add esp, 0x30
// 006cc334  c20400               ret 4
// 006cc337  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 006cc33b  5f                   pop edi
// 006cc33c  5e                   pop esi
// 006cc33d  5d                   pop ebp
// 006cc33e  33c0                 xor eax, eax
// 006cc340  64890d00000000       mov dword ptr fs:[0], ecx
// 006cc347  5b                   pop ebx
// 006cc348  83c430               add esp, 0x30
// 006cc34b  c20400               ret 4

// from server: 100% by colin
// roc 2008-06 0063fca0  unit: RBX::GrabTool  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0063fca0
//
// 0063fca0  6aff                 push -1
// 0063fca2  6898a97d00           push 0x7da998
// 0063fca7  64a100000000         mov eax, dword ptr fs:[0]
// 0063fcad  50                   push eax
// 0063fcae  64892500000000       mov dword ptr fs:[0], esp
// 0063fcb5  83ec24               sub esp, 0x24
// 0063fcb8  d9ee                 fldz 
// 0063fcba  53                   push ebx
// 0063fcbb  8b5c2438             mov ebx, dword ptr [esp + 0x38]
// 0063fcbf  d9542404             fst dword ptr [esp + 4]
// 0063fcc3  55                   push ebp
// 0063fcc4  d954240c             fst dword ptr [esp + 0xc]
// 0063fcc8  56                   push esi
// 0063fcc9  d95c2414             fstp dword ptr [esp + 0x14]
// 0063fccd  57                   push edi
// 0063fcce  8d442410             lea eax, [esp + 0x10]
// 0063fcd2  50                   push eax
// 0063fcd3  53                   push ebx
// 0063fcd4  8bf9                 mov edi, ecx
// 0063fcd6  e82563fdff           call 0x616000
// 0063fcdb  8bf0                 mov esi, eax
// 0063fcdd  33ed                 xor ebp, ebp
// 0063fcdf  3bf5                 cmp esi, ebp
// 0063fce1  0f8491000000         je 0x63fd78
// 0063fce7  8d4c241c             lea ecx, [esp + 0x1c]
// 0063fceb  e8e096deff           call 0x4293d0
// 0063fcf0  56                   push esi
// 0063fcf1  896c2440             mov dword ptr [esp + 0x40], ebp
// 0063fcf5  e8a65afdff           call 0x6157a0
// 0063fcfa  83c404               add esp, 4
// 0063fcfd  8d4c2444             lea ecx, [esp + 0x44]
// 0063fd01  51                   push ecx
// 0063fd02  8d4c2420             lea ecx, [esp + 0x20]
// 0063fd06  89442448             mov dword ptr [esp + 0x48], eax
// 0063fd0a  e89116deff           call 0x4213a0
// 0063fd0f  83ec08               sub esp, 8
// 0063fd12  8bc4                 mov eax, esp
// 0063fd14  8928                 mov dword ptr [eax], ebp
// 0063fd16  8964244c             mov dword ptr [esp + 0x4c], esp
// 0063fd1a  896804               mov dword ptr [eax + 4], ebp
// 0063fd1d  8b5718               mov edx, dword ptr [edi + 0x18]
// 0063fd20  52                   push edx
// 0063fd21  53                   push ebx
// 0063fd22  8d44242c             lea eax, [esp + 0x2c]
// 0063fd26  50                   push eax
// 0063fd27  8d4c2424             lea ecx, [esp + 0x24]
// 0063fd2b  51                   push ecx
// 0063fd2c  56                   push esi
// 0063fd2d  e81e080200           call 0x660550
// 0063fd32  8bf0                 mov esi, eax
// 0063fd34  8b442444             mov eax, dword ptr [esp + 0x44]
// 0063fd38  83c41c               add esp, 0x1c
// 0063fd3b  3bc5                 cmp eax, ebp
// 0063fd3d  7409                 je 0x63fd48
// 0063fd3f  50                   push eax
// 0063fd40  e835090600           call 0x6a067a
// 0063fd45  83c404               add esp, 4
// 0063fd48  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0063fd4c  52                   push edx
// 0063fd4d  896c242c             mov dword ptr [esp + 0x2c], ebp
// 0063fd51  896c2430             mov dword ptr [esp + 0x30], ebp
// 0063fd55  896c2434             mov dword ptr [esp + 0x34], ebp
// 0063fd59  e81c090600           call 0x6a067a
// 0063fd5e  83c404               add esp, 4
// 0063fd61  8bc6                 mov eax, esi
// 0063fd63  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 0063fd67  64890d00000000       mov dword ptr fs:[0], ecx
// 0063fd6e  5f                   pop edi
// 0063fd6f  5e                   pop esi
// 0063fd70  5d                   pop ebp
// 0063fd71  5b                   pop ebx
// 0063fd72  83c430               add esp, 0x30
// 0063fd75  c20400               ret 4
// 0063fd78  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 0063fd7c  5f                   pop edi
// 0063fd7d  5e                   pop esi
// 0063fd7e  5d                   pop ebp
// 0063fd7f  33c0                 xor eax, eax
// 0063fd81  64890d00000000       mov dword ptr fs:[0], ecx
// 0063fd88  5b                   pop ebx
// 0063fd89  83c430               add esp, 0x30
// 0063fd8c  c20400               ret 4

// from server: 99% by king_originala
// roc 2008-06 0063fca0  unit: RBX::GrabTool  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0063fca0
//
// 0063fca0  6aff                 push -1
// 0063fca2  6898a97d00           push 0x7da998
// 0063fca7  64a100000000         mov eax, dword ptr fs:[0]
// 0063fcad  50                   push eax
// 0063fcae  64892500000000       mov dword ptr fs:[0], esp
// 0063fcb5  83ec24               sub esp, 0x24
// 0063fcb8  d9ee                 fldz 
// 0063fcba  53                   push ebx
// 0063fcbb  8b5c2438             mov ebx, dword ptr [esp + 0x38]
// 0063fcbf  d9542404             fst dword ptr [esp + 4]
// 0063fcc3  55                   push ebp
// 0063fcc4  d954240c             fst dword ptr [esp + 0xc]
// 0063fcc8  56                   push esi
// 0063fcc9  d95c2414             fstp dword ptr [esp + 0x14]
// 0063fccd  57                   push edi
// 0063fcce  8d442410             lea eax, [esp + 0x10]
// 0063fcd2  50                   push eax
// 0063fcd3  53                   push ebx
// 0063fcd4  8bf9                 mov edi, ecx
// 0063fcd6  e82563fdff           call 0x616000
// 0063fcdb  8bf0                 mov esi, eax
// 0063fcdd  33ed                 xor ebp, ebp
// 0063fcdf  3bf5                 cmp esi, ebp
// 0063fce1  0f8491000000         je 0x63fd78
// 0063fce7  8d4c241c             lea ecx, [esp + 0x1c]
// 0063fceb  e8e096deff           call 0x4293d0
// 0063fcf0  56                   push esi
// 0063fcf1  896c2440             mov dword ptr [esp + 0x40], ebp
// 0063fcf5  e8a65afdff           call 0x6157a0
// 0063fcfa  83c404               add esp, 4
// 0063fcfd  8d4c2444             lea ecx, [esp + 0x44]
// 0063fd01  51                   push ecx
// 0063fd02  8d4c2420             lea ecx, [esp + 0x20]
// 0063fd06  89442448             mov dword ptr [esp + 0x48], eax
// 0063fd0a  e89116deff           call 0x4213a0
// 0063fd0f  83ec08               sub esp, 8
// 0063fd12  8bc4                 mov eax, esp
// 0063fd14  8928                 mov dword ptr [eax], ebp
// 0063fd16  8964244c             mov dword ptr [esp + 0x4c], esp
// 0063fd1a  896804               mov dword ptr [eax + 4], ebp
// 0063fd1d  8b5718               mov edx, dword ptr [edi + 0x18]
// 0063fd20  52                   push edx
// 0063fd21  53                   push ebx
// 0063fd22  8d44242c             lea eax, [esp + 0x2c]
// 0063fd26  50                   push eax
// 0063fd27  8d4c2424             lea ecx, [esp + 0x24]
// 0063fd2b  51                   push ecx
// 0063fd2c  56                   push esi
// 0063fd2d  e81e080200           call 0x660550
// 0063fd32  8bf0                 mov esi, eax
// 0063fd34  8b442444             mov eax, dword ptr [esp + 0x44]
// 0063fd38  83c41c               add esp, 0x1c
// 0063fd3b  3bc5                 cmp eax, ebp
// 0063fd3d  7409                 je 0x63fd48
// 0063fd3f  50                   push eax
// 0063fd40  e835090600           call 0x6a067a
// 0063fd45  83c404               add esp, 4
// 0063fd48  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0063fd4c  52                   push edx
// 0063fd4d  896c242c             mov dword ptr [esp + 0x2c], ebp
// 0063fd51  896c2430             mov dword ptr [esp + 0x30], ebp
// 0063fd55  896c2434             mov dword ptr [esp + 0x34], ebp
// 0063fd59  e81c090600           call 0x6a067a
// 0063fd5e  83c404               add esp, 4
// 0063fd61  8bc6                 mov eax, esi
// 0063fd63  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 0063fd67  64890d00000000       mov dword ptr fs:[0], ecx
// 0063fd6e  5f                   pop edi
// 0063fd6f  5e                   pop esi
// 0063fd70  5d                   pop ebp
// 0063fd71  5b                   pop ebx
// 0063fd72  83c430               add esp, 0x30
// 0063fd75  c20400               ret 4
// 0063fd78  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 0063fd7c  5f                   pop edi
// 0063fd7d  5e                   pop esi
// 0063fd7e  5d                   pop ebp
// 0063fd7f  33c0                 xor eax, eax
// 0063fd81  64890d00000000       mov dword ptr fs:[0], ecx
// 0063fd88  5b                   pop ebx
// 0063fd89  83c430               add esp, 0x30
// 0063fd8c  c20400               ret 4

struct Vec3 {
    float x, y, z;
};

void __cdecl operator delete(void *) throw();

struct Buffer {
    void *head;
    unsigned int reserved[2];
    void *first;
    void *last;
    void *limit;

    Buffer();
    void assign(void *const &value);
    ~Buffer();
};

__forceinline Buffer::~Buffer()
{
    if (first)
        operator delete(first);
    first = 0;
    last = 0;
    limit = 0;
    operator delete(head);
}

struct Count {
    void *pi;
    Count() : pi(0) {}
};

struct EmptyReference {
    void *object;
    Count control;

    EmptyReference();
    EmptyReference(const EmptyReference &);
    ~EmptyReference();
};

__forceinline EmptyReference::EmptyReference() : object(0)
{
}

__forceinline EmptyReference::~EmptyReference()
{
}

extern int __cdecl perform(void *, Vec3 *, Buffer *, int, void *,
                           EmptyReference);

struct S {
    unsigned char reserved[24];
    void *context;

    void *find(int, Vec3 *);
    void *getValue(void *);
    int f(int);
};

int S::f(int argument)
{
    Vec3 position = { 0.0f, 0.0f, 0.0f };
    void *object = find(argument, &position);
    if (object) {
        Buffer values;
        {
            void *value = getValue(object);
            values.assign(value);
        }
        return perform(object, &position, &values, argument, context,
                       EmptyReference());
    }
    return 0;
}
