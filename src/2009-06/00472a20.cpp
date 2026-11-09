// from server: 100% by EspClaude
// roc 2009-06 00472a20  unit: RBX::LDraw2Lua::LDrawCommand  size: 251 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00472a20
//
// 00472a20  64a100000000         mov eax, dword ptr fs:[0]
// 00472a26  6aff                 push -1
// 00472a28  68f9788600           push 0x8678f9
// 00472a2d  50                   push eax
// 00472a2e  64892500000000       mov dword ptr fs:[0], esp
// 00472a35  53                   push ebx
// 00472a36  56                   push esi
// 00472a37  57                   push edi
// 00472a38  8bf1                 mov esi, ecx
// 00472a3a  837e0801             cmp dword ptr [esi + 8], 1
// 00472a3e  c744241400000000     mov dword ptr [esp + 0x14], 0
// 00472a46  0f85a7000000         jne 0x472af3
// 00472a4c  8b4e04               mov ecx, dword ptr [esi + 4]
// 00472a4f  8d4670               lea eax, [esi + 0x70]
// 00472a52  50                   push eax
// 00472a53  e808deffff           call 0x470860
// 00472a58  85c0                 test eax, eax
// 00472a5a  0f8493000000         je 0x472af3
// 00472a60  8bc8                 mov ecx, eax
// 00472a62  e8d9f2ffff           call 0x471d40
// 00472a67  8bd8                 mov ebx, eax
// 00472a69  85db                 test ebx, ebx
// 00472a6b  0f8482000000         je 0x472af3
// 00472a71  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 00472a75  53                   push ebx
// 00472a76  57                   push edi
// 00472a77  8bce                 mov ecx, esi
// 00472a79  e8e2faffff           call 0x472560
// 00472a7e  57                   push edi
// 00472a7f  8bce                 mov ecx, esi
// 00472a81  e88afcffff           call 0x472710
// 00472a86  83ec1c               sub esp, 0x1c
// 00472a89  83c324               add ebx, 0x24
// 00472a8c  8bcc                 mov ecx, esp
// 00472a8e  89642438             mov dword ptr [esp + 0x38], esp
// 00472a92  53                   push ebx
// 00472a93  ff15b8e48900         call dword ptr [0x89e4b8]
// 00472a99  57                   push edi
// 00472a9a  8bce                 mov ecx, esi
// 00472a9c  e8bffcffff           call 0x472760
// 00472aa1  83ec1c               sub esp, 0x1c
// 00472aa4  8d54243c             lea edx, [esp + 0x3c]
// 00472aa8  8bcc                 mov ecx, esp
// 00472aaa  89642438             mov dword ptr [esp + 0x38], esp
// 00472aae  52                   push edx
// 00472aaf  ff15b8e48900         call dword ptr [0x89e4b8]
// 00472ab5  57                   push edi
// 00472ab6  8bce                 mov ecx, esi
// 00472ab8  e8d3feffff           call 0x472990
// 00472abd  682cdb8b00           push 0x8bdb2c
// 00472ac2  57                   push edi
// 00472ac3  e8483cfdff           call 0x446710
// 00472ac8  83c408               add esp, 8
// 00472acb  8d4c2420             lea ecx, [esp + 0x20]
// 00472acf  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 00472ad7  ff15c4e48900         call dword ptr [0x89e4c4]
// 00472add  b001                 mov al, 1
// 00472adf  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00472ae3  64890d00000000       mov dword ptr fs:[0], ecx
// 00472aea  5f                   pop edi
// 00472aeb  5e                   pop esi
// 00472aec  5b                   pop ebx
// 00472aed  83c40c               add esp, 0xc
// 00472af0  c22000               ret 0x20
// 00472af3  8d4c2420             lea ecx, [esp + 0x20]
// 00472af7  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 00472aff  ff15c4e48900         call dword ptr [0x89e4c4]
// 00472b05  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00472b09  5f                   pop edi
// 00472b0a  5e                   pop esi
// 00472b0b  32c0                 xor al, al
// 00472b0d  64890d00000000       mov dword ptr fs:[0], ecx
// 00472b14  5b                   pop ebx
// 00472b15  83c40c               add esp, 0xc
// 00472b18  c22000               ret 0x20
// copied from an identical function in another client (function ?f@S@ns_ROCX00000b@@QAE_NHUText@2@@Z)

namespace ns_ROCX00000b {
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

bool S::f(int context, Text argument)
{
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
}
