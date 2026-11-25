// from server: 100% by Xemicl
// from server: 100% by EspClaude
// roc 2009-06 0043e450  unit: RBX::Reflection::H::?$TypedPropertyDescriptor  size: 67 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0043e450
//
// 0043e450  8b898c000000         mov ecx, dword ptr [ecx + 0x8c]
// 0043e456  56                   push esi
// 0043e457  8b742408             mov esi, dword ptr [esp + 8]
// 0043e45b  85c9                 test ecx, ecx
// 0043e45d  740e                 je 0x43e46d
// 0043e45f  8b460c               mov eax, dword ptr [esi + 0xc]
// 0043e462  8b4004               mov eax, dword ptr [eax + 4]
// 0043e465  50                   push eax
// 0043e466  e805fb1800           call 0x5cdf70
// 0043e46b  eb02                 jmp 0x43e46f
// 0043e46d  33c0                 xor eax, eax
// 0043e46f  85c0                 test eax, eax
// 0043e471  741a                 je 0x43e48d
// 0043e473  8bc8                 mov ecx, eax
// 0043e475  e826fdffff           call 0x43e1a0
// 0043e47a  85c0                 test eax, eax
// 0043e47c  740f                 je 0x43e48d
// 0043e47e  8b4e04               mov ecx, dword ptr [esi + 4]
// 0043e481  5e                   pop esi
// 0043e482  894c2404             mov dword ptr [esp + 4], ecx
// 0043e486  8bc8                 mov ecx, eax
// 0043e488  e9e3fa1800           jmp 0x5cdf70
// 0043e48d  33c0                 xor eax, eax
// 0043e48f  5e                   pop esi
// 0043e490  c20400               ret 4

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
