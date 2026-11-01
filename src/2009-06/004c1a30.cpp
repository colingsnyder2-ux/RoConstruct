// from server: 81% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00493bf0  unit: RBX::VShirt::?$FactoryProduct  size: 424 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00493bf0
//
// 00493bf0  6aff                 push -1
// 00493bf2  68d9667c00           push 0x7c66d9
// 00493bf7  64a100000000         mov eax, dword ptr fs:[0]
// 00493bfd  50                   push eax
// 00493bfe  64892500000000       mov dword ptr fs:[0], esp
// 00493c05  83ec20               sub esp, 0x20
// 00493c08  53                   push ebx
// 00493c09  56                   push esi
// 00493c0a  8bf1                 mov esi, ecx
// 00493c0c  8d842490000000       lea eax, [esp + 0x90]
// 00493c13  50                   push eax
// 00493c14  8d4c2444             lea ecx, [esp + 0x44]
// 00493c18  c744243401000000     mov dword ptr [esp + 0x34], 1
// 00493c20  e89b9effff           call 0x48dac0
// 00493c25  84c0                 test al, al
// 00493c27  0f8506010000         jne 0x493d33
// 00493c2d  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 00493c30  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 00493c33  2bcb                 sub ecx, ebx
// 00493c35  b893244992           mov eax, 0x92492493
// 00493c3a  f7e9                 imul ecx
// 00493c3c  03d1                 add edx, ecx
// 00493c3e  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 00493c42  55                   push ebp
// 00493c43  c1fa04               sar edx, 4
// 00493c46  57                   push edi
// 00493c47  8bfa                 mov edi, edx
// 00493c49  2bcb                 sub ecx, ebx
// 00493c4b  c1ef1f               shr edi, 0x1f
// 00493c4e  03fa                 add edi, edx
// 00493c50  b893244992           mov eax, 0x92492493
// 00493c55  f7e9                 imul ecx
// 00493c57  03d1                 add edx, ecx
// 00493c59  c1fa04               sar edx, 4
// 00493c5c  8bea                 mov ebp, edx
// 00493c5e  8d8c2498000000       lea ecx, [esp + 0x98]
// 00493c65  51                   push ecx
// 00493c66  c1ed1f               shr ebp, 0x1f
// 00493c69  8d4c244c             lea ecx, [esp + 0x4c]
// 00493c6d  03ea                 add ebp, edx
// 00493c6f  e84c9effff           call 0x48dac0
// 00493c74  84c0                 test al, al
// 00493c76  756c                 jne 0x493ce4
// 00493c78  eb06                 jmp 0x493c80
// 00493c7a  8d9b00000000         lea ebx, [ebx]
// 00493c80  8b4610               mov eax, dword ptr [esi + 0x10]
// 00493c83  89442410             mov dword ptr [esp + 0x10], eax
// 00493c87  39460c               cmp dword ptr [esi + 0xc], eax
// 00493c8a  7606                 jbe 0x493c92
// 00493c8c  ff1590288000         call dword ptr [0x802890]
// 00493c92  8b1e                 mov ebx, dword ptr [esi]
// 00493c94  8d542414             lea edx, [esp + 0x14]
// 00493c98  52                   push edx
// 00493c99  8d4c244c             lea ecx, [esp + 0x4c]
// 00493c9d  e8ced5ffff           call 0x491270
// 00493ca2  50                   push eax
// 00493ca3  8b442414             mov eax, dword ptr [esp + 0x14]
// 00493ca7  6a01                 push 1
// 00493ca9  50                   push eax
// 00493caa  53                   push ebx
// 00493cab  8bce                 mov ecx, esi
// 00493cad  c644244802           mov byte ptr [esp + 0x48], 2
// 00493cb2  e8c957f9ff           call 0x429480
// 00493cb7  8d4c2414             lea ecx, [esp + 0x14]
// 00493cbb  c644243801           mov byte ptr [esp + 0x38], 1
// 00493cc0  ff1568248000         call dword ptr [0x802468]
// 00493cc6  8d4c2448             lea ecx, [esp + 0x48]
// 00493cca  e82184ffff           call 0x48c0f0
// 00493ccf  8d8c2498000000       lea ecx, [esp + 0x98]
// 00493cd6  51                   push ecx
// 00493cd7  8d4c244c             lea ecx, [esp + 0x4c]
// 00493cdb  e8e09dffff           call 0x48dac0
// 00493ce0  84c0                 test al, al
// 00493ce2  749c                 je 0x493c80
// 00493ce4  8b460c               mov eax, dword ptr [esi + 0xc]
// 00493ce7  8d1cfd00000000       lea ebx, [edi*8]
// 00493cee  2bdf                 sub ebx, edi
// 00493cf0  8d3ced00000000       lea edi, [ebp*8]
// 00493cf7  2bfd                 sub edi, ebp
// 00493cf9  03db                 add ebx, ebx
// 00493cfb  03db                 add ebx, ebx
// 00493cfd  03ff                 add edi, edi
// 00493cff  8d1403               lea edx, [ebx + eax]
// 00493d02  03ff                 add edi, edi
// 00493d04  52                   push edx
// 00493d05  03c7                 add eax, edi
// 00493d07  50                   push eax
// 00493d08  8bce                 mov ecx, esi
// 00493d0a  e87168ffff           call 0x48a580
// 00493d0f  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 00493d12  8b560c               mov edx, dword ptr [esi + 0xc]
// 00493d15  51                   push ecx
// 00493d16  03d3                 add edx, ebx
// 00493d18  52                   push edx
// 00493d19  8bce                 mov ecx, esi
// 00493d1b  e86068ffff           call 0x48a580
// 00493d20  8b4610               mov eax, dword ptr [esi + 0x10]
// 00493d23  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00493d26  03cf                 add ecx, edi
// 00493d28  50                   push eax
// 00493d29  51                   push ecx
// 00493d2a  8bce                 mov ecx, esi
// 00493d2c  e84f68ffff           call 0x48a580
// 00493d31  5f                   pop edi
// 00493d32  5d                   pop ebp
// 00493d33  8b442440             mov eax, dword ptr [esp + 0x40]
// 00493d37  33db                 xor ebx, ebx
// 00493d39  885c2430             mov byte ptr [esp + 0x30], bl
// 00493d3d  3bc3                 cmp eax, ebx
// 00493d3f  7419                 je 0x493d5a
// 00493d41  8b00                 mov eax, dword ptr [eax]
// 00493d43  3bc3                 cmp eax, ebx
// 00493d45  740f                 je 0x493d56
// 00493d47  8d542448             lea edx, [esp + 0x48]
// 00493d4b  6a01                 push 1
// 00493d4d  52                   push edx
// 00493d4e  8bca                 mov ecx, edx
// 00493d50  51                   push ecx
// 00493d51  ffd0                 call eax
// 00493d53  83c40c               add esp, 0xc
// 00493d56  895c2440             mov dword ptr [esp + 0x40], ebx
// 00493d5a  8b842490000000       mov eax, dword ptr [esp + 0x90]
// 00493d61  c7442430ffffffff     mov dword ptr [esp + 0x30], 0xffffffff
// 00493d69  3bc3                 cmp eax, ebx
// 00493d6b  7418                 je 0x493d85
// 00493d6d  8b00                 mov eax, dword ptr [eax]
// 00493d6f  3bc3                 cmp eax, ebx
// 00493d71  7412                 je 0x493d85
// 00493d73  8d942498000000       lea edx, [esp + 0x98]
// 00493d7a  6a01                 push 1
// 00493d7c  52                   push edx
// 00493d7d  8bca                 mov ecx, edx
// 00493d7f  51                   push ecx
// 00493d80  ffd0                 call eax
// 00493d82  83c40c               add esp, 0xc
// 00493d85  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00493d89  5e                   pop esi
// 00493d8a  5b                   pop ebx
// 00493d8b  64890d00000000       mov dword ptr fs:[0], ecx
// 00493d92  83c42c               add esp, 0x2c
// 00493d95  c2ac00               ret 0xac

extern "C" void (__cdecl *_invalid_parameter_noinfo)();

struct String;
extern void (__thiscall *destroyString)(String*);

struct String
{
    unsigned char data[28];
    ~String();
};

inline String::~String()
{
    destroyString(this);
}

struct Iterator
{
    typedef void (__cdecl *Cleanup)(void*, void*, int);

    Cleanup* manager;
    unsigned int reserved;
    unsigned char storage[72];

    bool equal(const Iterator& other) const;
    String dereference();
    void increment();
    ~Iterator();
};

inline Iterator::~Iterator()
{
    if (manager)
    {
        Cleanup cleanup = *manager;
        if (cleanup)
            cleanup(storage, storage, 1);
        manager = 0;
    }
}

struct Position
{
    void* owner;
    String* pointer;
};

struct S
{
    void* owner;
    unsigned int reserved[2];
    String* begin;
    String* end;

    void insert(void* owner, String* position, unsigned int count,
                const String& value);
    void reverse(String* first, String* last);
    void func_00493bf0(Position position, Iterator first, Iterator last,
                       unsigned int unused);
};

void S::func_00493bf0(Position position, Iterator first, Iterator last,
                     unsigned int unused)
{
    if (!first.equal(last))
    {
        int oldSize = end - begin;
        int offset = position.pointer - begin;

        while (!first.equal(last))
        {
            String* insertionPoint = end;
            if (begin > insertionPoint)
                _invalid_parameter_noinfo();

            void* insertionOwner = owner;
            insert(insertionOwner, insertionPoint, 1, first.dereference());
            first.increment();
        }

        reverse(begin + offset, begin + oldSize);
        reverse(begin + oldSize, end);
        reverse(begin + offset, end);
    }
}
