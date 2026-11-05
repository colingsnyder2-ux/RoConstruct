// from server: 100% by Yeetserama
// roc 2010-06 00482e80  unit: RBX::LDraw2Lua::LDrawCommand  size: 251 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00482e80
//
// 00482e80  64a100000000         mov eax, dword ptr fs:[0]
// 00482e86  6aff                 push -1
// 00482e88  68a97e9900           push 0x997ea9
// 00482e8d  50                   push eax
// 00482e8e  64892500000000       mov dword ptr fs:[0], esp
// 00482e95  53                   push ebx
// 00482e96  56                   push esi
// 00482e97  57                   push edi
// 00482e98  8bf1                 mov esi, ecx
// 00482e9a  837e0801             cmp dword ptr [esi + 8], 1
// 00482e9e  c744241400000000     mov dword ptr [esp + 0x14], 0
// 00482ea6  0f85a7000000         jne 0x482f53
// 00482eac  8b4e04               mov ecx, dword ptr [esi + 4]
// 00482eaf  8d4670               lea eax, [esi + 0x70]
// 00482eb2  50                   push eax
// 00482eb3  e868e0ffff           call 0x480f20
// 00482eb8  85c0                 test eax, eax
// 00482eba  0f8493000000         je 0x482f53
// 00482ec0  8bc8                 mov ecx, eax
// 00482ec2  e8d9f2ffff           call 0x4821a0
// 00482ec7  8bd8                 mov ebx, eax
// 00482ec9  85db                 test ebx, ebx
// 00482ecb  0f8482000000         je 0x482f53
// 00482ed1  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 00482ed5  53                   push ebx
// 00482ed6  57                   push edi
// 00482ed7  8bce                 mov ecx, esi
// 00482ed9  e8e2faffff           call 0x4829c0
// 00482ede  57                   push edi
// 00482edf  8bce                 mov ecx, esi
// 00482ee1  e88afcffff           call 0x482b70
// 00482ee6  83ec1c               sub esp, 0x1c
// 00482ee9  83c324               add ebx, 0x24
// 00482eec  8bcc                 mov ecx, esp
// 00482eee  89642438             mov dword ptr [esp + 0x38], esp
// 00482ef2  53                   push ebx
// 00482ef3  ff150ca49e00         call dword ptr [0x9ea40c]
// 00482ef9  57                   push edi
// 00482efa  8bce                 mov ecx, esi
// 00482efc  e8bffcffff           call 0x482bc0
// 00482f01  83ec1c               sub esp, 0x1c
// 00482f04  8d54243c             lea edx, [esp + 0x3c]
// 00482f08  8bcc                 mov ecx, esp
// 00482f0a  89642438             mov dword ptr [esp + 0x38], esp
// 00482f0e  52                   push edx
// 00482f0f  ff150ca49e00         call dword ptr [0x9ea40c]
// 00482f15  57                   push edi
// 00482f16  8bce                 mov ecx, esi
// 00482f18  e8d3feffff           call 0x482df0
// 00482f1d  686431a100           push 0xa13164
// 00482f22  57                   push edi
// 00482f23  e8f8affcff           call 0x44df20
// 00482f28  83c408               add esp, 8
// 00482f2b  8d4c2420             lea ecx, [esp + 0x20]
// 00482f2f  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 00482f37  ff1500a49e00         call dword ptr [0x9ea400]
// 00482f3d  b001                 mov al, 1
// 00482f3f  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00482f43  64890d00000000       mov dword ptr fs:[0], ecx
// 00482f4a  5f                   pop edi
// 00482f4b  5e                   pop esi
// 00482f4c  5b                   pop ebx
// 00482f4d  83c40c               add esp, 0xc
// 00482f50  c22000               ret 0x20
// 00482f53  8d4c2420             lea ecx, [esp + 0x20]
// 00482f57  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 00482f5f  ff1500a49e00         call dword ptr [0x9ea400]
// 00482f65  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00482f69  5f                   pop edi
// 00482f6a  5e                   pop esi
// 00482f6b  32c0                 xor al, al
// 00482f6d  64890d00000000       mov dword ptr fs:[0], ecx
// 00482f74  5b                   pop ebx
// 00482f75  83c40c               add esp, 0xc
// 00482f78  c22000               ret 0x20
// copied from an identical function in another client (function ?f@S@ns_ROCX000000@@QAE_NHUText@2@@Z)

namespace ns_ROCX000000 {
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
