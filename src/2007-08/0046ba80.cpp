// from server: 99% by EspClaude
// from server: 72% by EspClaude
// roc 2007-08 0046ba80  unit: RBX::LDraw2Lua::LDrawCommand  size: 261 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0046ba80
//
// 0046ba80  6aff                 push -1
// 0046ba82  68a93f7400           push 0x743fa9
// 0046ba87  64a100000000         mov eax, dword ptr fs:[0]
// 0046ba8d  50                   push eax
// 0046ba8e  51                   push ecx
// 0046ba8f  53                   push ebx
// 0046ba90  56                   push esi
// 0046ba91  57                   push edi
// 0046ba92  a188518b00           mov eax, dword ptr [0x8b5188]
// 0046ba97  33c4                 xor eax, esp
// 0046ba99  50                   push eax
// 0046ba9a  8d442414             lea eax, [esp + 0x14]
// 0046ba9e  64a300000000         mov dword ptr fs:[0], eax
// 0046baa4  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0046baa8  8bf1                 mov esi, ecx
// 0046baaa  837e0801             cmp dword ptr [esi + 8], 1
// 0046baae  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 0046bab6  0f85a0000000         jne 0x46bb5c
// 0046babc  8b4e04               mov ecx, dword ptr [esi + 4]
// 0046babf  8d4670               lea eax, [esi + 0x70]
// 0046bac2  50                   push eax
// 0046bac3  e8d8ddffff           call 0x4698a0
// 0046bac8  85c0                 test eax, eax
// 0046baca  0f848c000000         je 0x46bb5c
// 0046bad0  8bc8                 mov ecx, eax
// 0046bad2  e8f9eeffff           call 0x46a9d0
// 0046bad7  8bd8                 mov ebx, eax
// 0046bad9  85db                 test ebx, ebx
// 0046badb  747f                 je 0x46bb5c
// 0046badd  53                   push ebx
// 0046bade  57                   push edi
// 0046badf  8bce                 mov ecx, esi
// 0046bae1  e8aafaffff           call 0x46b590
// 0046bae6  57                   push edi
// 0046bae7  8bce                 mov ecx, esi
// 0046bae9  e872fcffff           call 0x46b760
// 0046baee  83ec1c               sub esp, 0x1c
// 0046baf1  83c324               add ebx, 0x24
// 0046baf4  8bcc                 mov ecx, esp
// 0046baf6  8964242c             mov dword ptr [esp + 0x2c], esp
// 0046bafa  53                   push ebx
// 0046bafb  ff159ce67700         call dword ptr [0x77e69c]
// 0046bb01  57                   push edi
// 0046bb02  8bce                 mov ecx, esi
// 0046bb04  e8a7fcffff           call 0x46b7b0
// 0046bb09  83ec1c               sub esp, 0x1c
// 0046bb0c  8d542444             lea edx, [esp + 0x44]
// 0046bb10  8bcc                 mov ecx, esp
// 0046bb12  8964242c             mov dword ptr [esp + 0x2c], esp
// 0046bb16  52                   push edx
// 0046bb17  ff159ce67700         call dword ptr [0x77e69c]
// 0046bb1d  57                   push edi
// 0046bb1e  8bce                 mov ecx, esi
// 0046bb20  e8bbfeffff           call 0x46b9e0
// 0046bb25  6868637900           push 0x796368
// 0046bb2a  57                   push edi
// 0046bb2b  e870f8ffff           call 0x46b3a0
// 0046bb30  83c408               add esp, 8
// 0046bb33  8d4c2428             lea ecx, [esp + 0x28]
// 0046bb37  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 0046bb3f  ff15ace67700         call dword ptr [0x77e6ac]
// 0046bb45  b001                 mov al, 1
// 0046bb47  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0046bb4b  64890d00000000       mov dword ptr fs:[0], ecx
// 0046bb52  59                   pop ecx
// 0046bb53  5f                   pop edi
// 0046bb54  5e                   pop esi
// 0046bb55  5b                   pop ebx
// 0046bb56  83c410               add esp, 0x10
// 0046bb59  c22000               ret 0x20
// 0046bb5c  8d4c2428             lea ecx, [esp + 0x28]
// 0046bb60  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 0046bb68  ff15ace67700         call dword ptr [0x77e6ac]
// 0046bb6e  32c0                 xor al, al
// 0046bb70  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0046bb74  64890d00000000       mov dword ptr fs:[0], ecx
// 0046bb7b  59                   pop ecx
// 0046bb7c  5f                   pop edi
// 0046bb7d  5e                   pop esi
// 0046bb7e  5b                   pop ebx
// 0046bb7f  83c410               add esp, 0x10
// 0046bb82  c22000               ret 0x20

// from server: 100% by colin
// roc 2008-06 0046f000  unit: RBX::LDraw2Lua::LDrawCommand  size: 251 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0046f000
//
// 0046f000  64a100000000         mov eax, dword ptr fs:[0]
// 0046f006  6aff                 push -1
// 0046f008  68793f7c00           push 0x7c3f79
// 0046f00d  50                   push eax
// 0046f00e  64892500000000       mov dword ptr fs:[0], esp
// 0046f015  53                   push ebx
// 0046f016  56                   push esi
// 0046f017  57                   push edi
// 0046f018  8bf1                 mov esi, ecx
// 0046f01a  837e0801             cmp dword ptr [esi + 8], 1
// 0046f01e  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0046f026  0f85a7000000         jne 0x46f0d3
// 0046f02c  8b4e04               mov ecx, dword ptr [esi + 4]
// 0046f02f  8d4670               lea eax, [esi + 0x70]
// 0046f032  50                   push eax
// 0046f033  e8d8e0ffff           call 0x46d110
// 0046f038  85c0                 test eax, eax
// 0046f03a  0f8493000000         je 0x46f0d3
// 0046f040  8bc8                 mov ecx, eax
// 0046f042  e829f3ffff           call 0x46e370
// 0046f047  8bd8                 mov ebx, eax
// 0046f049  85db                 test ebx, ebx
// 0046f04b  0f8482000000         je 0x46f0d3
// 0046f051  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0046f055  53                   push ebx
// 0046f056  57                   push edi
// 0046f057  8bce                 mov ecx, esi
// 0046f059  e8e2faffff           call 0x46eb40
// 0046f05e  57                   push edi
// 0046f05f  8bce                 mov ecx, esi
// 0046f061  e88afcffff           call 0x46ecf0
// 0046f066  83ec1c               sub esp, 0x1c
// 0046f069  83c324               add ebx, 0x24
// 0046f06c  8bcc                 mov ecx, esp
// 0046f06e  89642438             mov dword ptr [esp + 0x38], esp
// 0046f072  53                   push ebx
// 0046f073  ff155c248000         call dword ptr [0x80245c]
// 0046f079  57                   push edi
// 0046f07a  8bce                 mov ecx, esi
// 0046f07c  e8bffcffff           call 0x46ed40
// 0046f081  83ec1c               sub esp, 0x1c
// 0046f084  8d54243c             lea edx, [esp + 0x3c]
// 0046f088  8bcc                 mov ecx, esp
// 0046f08a  89642438             mov dword ptr [esp + 0x38], esp
// 0046f08e  52                   push edx
// 0046f08f  ff155c248000         call dword ptr [0x80245c]
// 0046f095  57                   push edi
// 0046f096  8bce                 mov ecx, esi
// 0046f098  e8d3feffff           call 0x46ef70
// 0046f09d  68cccb8100           push 0x81cbcc
// 0046f0a2  57                   push edi
// 0046f0a3  e8a8b3fdff           call 0x44a450
// 0046f0a8  83c408               add esp, 8
// 0046f0ab  8d4c2420             lea ecx, [esp + 0x20]
// 0046f0af  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 0046f0b7  ff1568248000         call dword ptr [0x802468]
// 0046f0bd  b001                 mov al, 1
// 0046f0bf  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0046f0c3  64890d00000000       mov dword ptr fs:[0], ecx
// 0046f0ca  5f                   pop edi
// 0046f0cb  5e                   pop esi
// 0046f0cc  5b                   pop ebx
// 0046f0cd  83c40c               add esp, 0xc
// 0046f0d0  c22000               ret 0x20
// 0046f0d3  8d4c2420             lea ecx, [esp + 0x20]
// 0046f0d7  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 0046f0df  ff1568248000         call dword ptr [0x802468]
// 0046f0e5  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0046f0e9  5f                   pop edi
// 0046f0ea  5e                   pop esi
// 0046f0eb  32c0                 xor al, al
// 0046f0ed  64890d00000000       mov dword ptr fs:[0], ecx
// 0046f0f4  5b                   pop ebx
// 0046f0f5  83c40c               add esp, 0xc
// 0046f0f8  c22000               ret 0x20

// from server: 97% by king_originala
// roc 2008-06 0046f000  unit: RBX::LDraw2Lua::LDrawCommand  size: 251 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0046f000
//
// 0046f000  64a100000000         mov eax, dword ptr fs:[0]
// 0046f006  6aff                 push -1
// 0046f008  68793f7c00           push 0x7c3f79
// 0046f00d  50                   push eax
// 0046f00e  64892500000000       mov dword ptr fs:[0], esp
// 0046f015  53                   push ebx
// 0046f016  56                   push esi
// 0046f017  57                   push edi
// 0046f018  8bf1                 mov esi, ecx
// 0046f01a  837e0801             cmp dword ptr [esi + 8], 1
// 0046f01e  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0046f026  0f85a7000000         jne 0x46f0d3
// 0046f02c  8b4e04               mov ecx, dword ptr [esi + 4]
// 0046f02f  8d4670               lea eax, [esi + 0x70]
// 0046f032  50                   push eax
// 0046f033  e8d8e0ffff           call 0x46d110
// 0046f038  85c0                 test eax, eax
// 0046f03a  0f8493000000         je 0x46f0d3
// 0046f040  8bc8                 mov ecx, eax
// 0046f042  e829f3ffff           call 0x46e370
// 0046f047  8bd8                 mov ebx, eax
// 0046f049  85db                 test ebx, ebx
// 0046f04b  0f8482000000         je 0x46f0d3
// 0046f051  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0046f055  53                   push ebx
// 0046f056  57                   push edi
// 0046f057  8bce                 mov ecx, esi
// 0046f059  e8e2faffff           call 0x46eb40
// 0046f05e  57                   push edi
// 0046f05f  8bce                 mov ecx, esi
// 0046f061  e88afcffff           call 0x46ecf0
// 0046f066  83ec1c               sub esp, 0x1c
// 0046f069  83c324               add ebx, 0x24
// 0046f06c  8bcc                 mov ecx, esp
// 0046f06e  89642438             mov dword ptr [esp + 0x38], esp
// 0046f072  53                   push ebx
// 0046f073  ff155c248000         call dword ptr [0x80245c]
// 0046f079  57                   push edi
// 0046f07a  8bce                 mov ecx, esi
// 0046f07c  e8bffcffff           call 0x46ed40
// 0046f081  83ec1c               sub esp, 0x1c
// 0046f084  8d54243c             lea edx, [esp + 0x3c]
// 0046f088  8bcc                 mov ecx, esp
// 0046f08a  89642438             mov dword ptr [esp + 0x38], esp
// 0046f08e  52                   push edx
// 0046f08f  ff155c248000         call dword ptr [0x80245c]
// 0046f095  57                   push edi
// 0046f096  8bce                 mov ecx, esi
// 0046f098  e8d3feffff           call 0x46ef70
// 0046f09d  68cccb8100           push 0x81cbcc
// 0046f0a2  57                   push edi
// 0046f0a3  e8a8b3fdff           call 0x44a450
// 0046f0a8  83c408               add esp, 8
// 0046f0ab  8d4c2420             lea ecx, [esp + 0x20]
// 0046f0af  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 0046f0b7  ff1568248000         call dword ptr [0x802468]
// 0046f0bd  b001                 mov al, 1
// 0046f0bf  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0046f0c3  64890d00000000       mov dword ptr fs:[0], ecx
// 0046f0ca  5f                   pop edi
// 0046f0cb  5e                   pop esi
// 0046f0cc  5b                   pop ebx
// 0046f0cd  83c40c               add esp, 0xc
// 0046f0d0  c22000               ret 0x20
// 0046f0d3  8d4c2420             lea ecx, [esp + 0x20]
// 0046f0d7  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 0046f0df  ff1568248000         call dword ptr [0x802468]
// 0046f0e5  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0046f0e9  5f                   pop edi
// 0046f0ea  5e                   pop esi
// 0046f0eb  32c0                 xor al, al
// 0046f0ed  64890d00000000       mov dword ptr fs:[0], ecx
// 0046f0f4  5b                   pop ebx
// 0046f0f5  83c40c               add esp, 0xc
// 0046f0f8  c22000               ret 0x20

extern void (__thiscall *string_copy)(void *, const void *);
extern void (__thiscall *string_destroy)(void *);

struct Text {
    char storage[28];

    __declspec(dllimport) Text(const Text& other);
    ~Text() { string_destroy(this); }
};

struct Text2 {
    char storage[28];
    __declspec(dllimport) Text2(const Text& other);
    __declspec(dllimport) Text2(const Text2& other);
    ~Text2() { string_destroy(this); }
};

struct Item {
    char reserved[36];
    Text text;
};

struct Entry {
    Item* getItem();
};

struct Lookup {
    Entry* find(const Text*);
};

extern "C" void __cdecl output(int, const char*);

struct S {
    void* table;
    Lookup* lookup;
    int mode;
    char reserved[100];
    Text key;

    void prepare(int, Item*);
    void begin(int);
    void writeItem(int, Text);
    void writeArgument(int, Text2);
    bool f(int, Text);
};

bool S::f(int context0, Text argument)
{
    int context = *(volatile int*)&context0;
    if (mode == 1) {
        Entry* entry = lookup->find(&key);
        if (entry) {
            Item* item = entry->getItem();
            if (item) {
                prepare(context, item);
                begin(context);
                writeItem(context, item->text);
                writeArgument(context, argument);
                output(context, "\n");
                return true;
            }
        }
    }
    return false;
}
