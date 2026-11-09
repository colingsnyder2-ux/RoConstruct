// from server: 100% by EspClaude
// roc 2009-06 004e6cf0  unit: RBX::Network::DirectPhysicsReceiver  size: 102 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004e6cf0
//
// 004e6cf0  83ec0c               sub esp, 0xc
// 004e6cf3  53                   push ebx
// 004e6cf4  56                   push esi
// 004e6cf5  57                   push edi
// 004e6cf6  8bf9                 mov edi, ecx
// 004e6cf8  8d442420             lea eax, [esp + 0x20]
// 004e6cfc  50                   push eax
// 004e6cfd  8d4c2414             lea ecx, [esp + 0x14]
// 004e6d01  51                   push ecx
// 004e6d02  8bcf                 mov ecx, edi
// 004e6d04  e8777c1000           call 0x5ee980
// 004e6d09  8b1dace98900         mov ebx, dword ptr [0x89e9ac]
// 004e6d0f  8bf0                 mov esi, eax
// 004e6d11  8b06                 mov eax, dword ptr [esi]
// 004e6d13  85c0                 test eax, eax
// 004e6d15  7508                 jne 0x4e6d1f
// 004e6d17  ffd3                 call ebx
// 004e6d19  8b06                 mov eax, dword ptr [esi]
// 004e6d1b  85c0                 test eax, eax
// 004e6d1d  7404                 je 0x4e6d23
// 004e6d1f  8b00                 mov eax, dword ptr [eax]
// 004e6d21  eb02                 jmp 0x4e6d25
// 004e6d23  33c0                 xor eax, eax
// 004e6d25  8b5604               mov edx, dword ptr [esi + 4]
// 004e6d28  3b5018               cmp edx, dword ptr [eax + 0x18]
// 004e6d2b  7502                 jne 0x4e6d2f
// 004e6d2d  ffd3                 call ebx
// 004e6d2f  8b4604               mov eax, dword ptr [esi + 4]
// 004e6d32  8b4810               mov ecx, dword ptr [eax + 0x10]
// 004e6d35  8b5720               mov edx, dword ptr [edi + 0x20]
// 004e6d38  6a01                 push 1
// 004e6d3a  52                   push edx
// 004e6d3b  8d442414             lea eax, [esp + 0x14]
// 004e6d3f  894c2414             mov dword ptr [esp + 0x14], ecx
// 004e6d43  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 004e6d47  50                   push eax
// 004e6d48  e8f32effff           call 0x4d9c40
// 004e6d4d  5f                   pop edi
// 004e6d4e  5e                   pop esi
// 004e6d4f  5b                   pop ebx
// 004e6d50  83c40c               add esp, 0xc
// 004e6d53  c20800               ret 8
// copied from an identical function in another client (function ?f@S@ns_ROCX0000b1@@QAEXPAUWriter@2@H@Z)

namespace ns_ROCX0000b1 {
// from server: 94% by king_originala
struct Node {
    char padding[16];
    int value;
};

struct Container {
    char padding[24];
    Node* end;
};

struct Iterator {
    Container** owner;
    Node* node;
};

extern "C" {
    extern __declspec(dllimport) void __cdecl invalid_parameter_noinfo();
}

struct Writer {
    void write(const int* value, int count, int flag);
};

struct S {
    char padding[32];
    int count;

    Iterator* lookup(Iterator* result, const int* key);
    void f(Writer* writer, int key);
};

void S::f(Writer* writer, int key)
{
    Iterator temporary;
    Iterator* position = lookup(&temporary, &key);
    void (__cdecl *report)() = invalid_parameter_noinfo;

    if (!position->owner)
        report();

    Container* container = position->owner ? *position->owner : 0;

    if (position->node == container->end)
        report();

    int value = position->node->value;
    writer->write(&value, count, 1);
}
}
