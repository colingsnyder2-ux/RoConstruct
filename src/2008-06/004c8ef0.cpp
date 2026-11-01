// from server: 100% by coldek
// from server: 100% by colin
// roc 2008-06 004c8ef0  unit: RBX::Network::DirectPhysicsReceiver  size: 151 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004c8ef0
//
// 004c8ef0  55                   push ebp
// 004c8ef1  8bec                 mov ebp, esp
// 004c8ef3  6aff                 push -1
// 004c8ef5  68e0967c00           push 0x7c96e0
// 004c8efa  64a100000000         mov eax, dword ptr fs:[0]
// 004c8f00  50                   push eax
// 004c8f01  64892500000000       mov dword ptr fs:[0], esp
// 004c8f08  83ec08               sub esp, 8
// 004c8f0b  53                   push ebx
// 004c8f0c  56                   push esi
// 004c8f0d  57                   push edi
// 004c8f0e  8965f0               mov dword ptr [ebp - 0x10], esp
// 004c8f11  6898020000           push 0x298
// 004c8f16  8bf9                 mov edi, ecx
// 004c8f18  e8037a1d00           call 0x6a0920
// 004c8f1d  8bd8                 mov ebx, eax
// 004c8f1f  8b450c               mov eax, dword ptr [ebp + 0xc]
// 004c8f22  83c404               add esp, 4
// 004c8f25  53                   push ebx
// 004c8f26  50                   push eax
// 004c8f27  8d4f0c               lea ecx, [edi + 0xc]
// 004c8f2a  895dec               mov dword ptr [ebp - 0x14], ebx
// 004c8f2d  c745fc00000000       mov dword ptr [ebp - 4], 0
// 004c8f34  e807ffffff           call 0x4c8e40
// 004c8f39  8bf0                 mov esi, eax
// 004c8f3b  3bf3                 cmp esi, ebx
// 004c8f3d  7523                 jne 0x4c8f62
// 004c8f3f  8b4508               mov eax, dword ptr [ebp + 8]
// 004c8f42  b901000000           mov ecx, 1
// 004c8f47  014f30               add dword ptr [edi + 0x30], ecx
// 004c8f4a  8930                 mov dword ptr [eax], esi
// 004c8f4c  884804               mov byte ptr [eax + 4], cl
// 004c8f4f  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004c8f52  64890d00000000       mov dword ptr fs:[0], ecx
// 004c8f59  5f                   pop edi
// 004c8f5a  5e                   pop esi
// 004c8f5b  5b                   pop ebx
// 004c8f5c  8be5                 mov esp, ebp
// 004c8f5e  5d                   pop ebp
// 004c8f5f  c20800               ret 8
// 004c8f62  53                   push ebx
// 004c8f63  e812771d00           call 0x6a067a
// 004c8f68  8b4508               mov eax, dword ptr [ebp + 8]
// 004c8f6b  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004c8f6e  83c404               add esp, 4
// 004c8f71  5f                   pop edi
// 004c8f72  8930                 mov dword ptr [eax], esi
// 004c8f74  5e                   pop esi
// 004c8f75  c6400400             mov byte ptr [eax + 4], 0
// 004c8f79  64890d00000000       mov dword ptr fs:[0], ecx
// 004c8f80  5b                   pop ebx
// 004c8f81  8be5                 mov esp, ebp
// 004c8f83  5d                   pop ebp
// 004c8f84  c20800               ret 8

// from server: 100% by king_originala
typedef unsigned int UInt;

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*) throw();

struct Link {
    Link* next;
};

struct Payload {
    UInt key;
    char padding[108];
};

struct Node : Payload, Link {
};

struct Result {
    Node* node;
    bool inserted;

    Result(Node* p, bool b);
};

struct Table {
    char padding[36];
    Node* reserve(const Payload& value, Node* node);
};

struct S {
    char padding[12];
    Table table;
    UInt count;

    Result insert(const Payload& value);
};

inline Result::Result(Node* p, bool b)
    : node(p), inserted(b) {
}

Result S::insert(const Payload& value) {
    Node* allocated = static_cast<Node*>(operator new(0x298));
    try {
        Node* result = table.reserve(value, allocated);
        if (result == allocated) {
            ++count;
            return Result(result, true);
        }
        operator delete(allocated);
        return Result(result, false);
    } catch (...) {
        operator delete(allocated);
        throw;
    }
}
