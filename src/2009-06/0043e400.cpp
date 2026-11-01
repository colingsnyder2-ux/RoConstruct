// from server: 100% by EspClaude
// from server: 100% by colin
// roc 2008-06 00443b00  unit: RBX::Reflection::H::?$TypedPropertyDescriptor  size: 73 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00443b00
//
// 00443b00  8b8930010000         mov ecx, dword ptr [ecx + 0x8c]
// 00443b06  56                   push esi
// 00443b07  8b742408             mov esi, dword ptr [esp + 8]
// 00443b0b  85c9                 test ecx, ecx
// 00443b0d  7411                 je 0x443b20
// 00443b0f  8b460c               mov eax, dword ptr [esi + 0xc]
// 00443b12  8b4004               mov eax, dword ptr [eax + 4]
// 00443b15  83c004               add eax, 4
// 00443b18  50                   push eax
// 00443b19  e8323e1100           call 0x557950
// 00443b1e  eb02                 jmp 0x443b22
// 00443b20  33c0                 xor eax, eax
// 00443b22  85c0                 test eax, eax
// 00443b24  741d                 je 0x443b43
// 00443b26  8bc8                 mov ecx, eax
// 00443b28  e8f3fcffff           call 0x443820
// 00443b2d  85c0                 test eax, eax
// 00443b2f  7412                 je 0x443b43
// 00443b31  8b5604               mov edx, dword ptr [esi + 4]
// 00443b34  83c204               add edx, 4
// 00443b37  5e                   pop esi
// 00443b38  89542404             mov dword ptr [esp + 4], edx
// 00443b3c  8bc8                 mov ecx, eax
// 00443b3e  e90d3e1100           jmp 0x557950
// 00443b43  33c0                 xor eax, eax
// 00443b45  5e                   pop esi
// 00443b46  c20400               ret 4

struct Storage;

struct Node {
    Storage* convert();
};

struct Storage {
    Node* find(const char* key);
    Node* lookup(const char* key);
};

struct Link {
    void* reserved;
    const char* key;
};

struct Argument {
    void* reserved0;
    const char* key;
    void* reserved8;
    Link* parent;
};

struct Descriptor {
    char reserved[0x8c];
    Storage* storage;
    Node* find(Argument* argument);
};

Node* Storage::lookup(const char* key)
{
    if (this)
        return find(key);
    return 0;
}

Node* Descriptor::find(Argument* argument)
{
    Storage* s = storage;
    Node* node = s ? s->lookup(argument->parent->key) : 0;
    if (node) {
        Storage* next = node->convert();
        if (next) {
            const char* key = argument->key;
            return next->find(key);
        }
    }
    return 0;
}
