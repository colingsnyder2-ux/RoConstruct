// from server: 100% by colin
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

extern void *__cdecl getValue(void *);
extern int __cdecl perform(void *, Vec3 *, Buffer *, int, void *,
                           EmptyReference);

struct S {
    unsigned char reserved[24];
    void *context;

    void *find(int, Vec3 *);
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
