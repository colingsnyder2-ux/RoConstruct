// from server: 100% by coldek
// from server: 100% by king_originala
// roc 2008-06 004cc960  unit: RBX::VInstance::?$NonFactoryProduct  size: 148 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004cc960
//
// 004cc960  55                   push ebp
// 004cc961  8bec                 mov ebp, esp
// 004cc963  6aff                 push -1
// 004cc965  6810997c00           push 0x7c9910
// 004cc96a  64a100000000         mov eax, dword ptr fs:[0]
// 004cc970  50                   push eax
// 004cc971  64892500000000       mov dword ptr fs:[0], esp
// 004cc978  83ec08               sub esp, 8
// 004cc97b  53                   push ebx
// 004cc97c  56                   push esi
// 004cc97d  57                   push edi
// 004cc97e  8965f0               mov dword ptr [ebp - 0x10], esp
// 004cc981  6a78                 push 0x78
// 004cc983  8bf9                 mov edi, ecx
// 004cc985  e8963f1d00           call 0x6a0920
// 004cc98a  8bd8                 mov ebx, eax
// 004cc98c  8b450c               mov eax, dword ptr [ebp + 0xc]
// 004cc98f  83c404               add esp, 4
// 004cc992  53                   push ebx
// 004cc993  50                   push eax
// 004cc994  8d4f0c               lea ecx, [edi + 0xc]
// 004cc997  895dec               mov dword ptr [ebp - 0x14], ebx
// 004cc99a  c745fc00000000       mov dword ptr [ebp - 4], 0
// 004cc9a1  e83afbffff           call 0x4cc4e0
// 004cc9a6  8bf0                 mov esi, eax
// 004cc9a8  3bf3                 cmp esi, ebx
// 004cc9aa  7523                 jne 0x4cc9cf
// 004cc9ac  8b4508               mov eax, dword ptr [ebp + 8]
// 004cc9af  b901000000           mov ecx, 1
// 004cc9b4  014f30               add dword ptr [edi + 0x30], ecx
// 004cc9b7  8930                 mov dword ptr [eax], esi
// 004cc9b9  884804               mov byte ptr [eax + 4], cl
// 004cc9bc  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004cc9bf  64890d00000000       mov dword ptr fs:[0], ecx
// 004cc9c6  5f                   pop edi
// 004cc9c7  5e                   pop esi
// 004cc9c8  5b                   pop ebx
// 004cc9c9  8be5                 mov esp, ebp
// 004cc9cb  5d                   pop ebp
// 004cc9cc  c20800               ret 8
// 004cc9cf  53                   push ebx
// 004cc9d0  e8a53c1d00           call 0x6a067a
// 004cc9d5  8b4508               mov eax, dword ptr [ebp + 8]
// 004cc9d8  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004cc9db  83c404               add esp, 4
// 004cc9de  5f                   pop edi
// 004cc9df  8930                 mov dword ptr [eax], esi
// 004cc9e1  5e                   pop esi
// 004cc9e2  c6400400             mov byte ptr [eax + 4], 0
// 004cc9e6  64890d00000000       mov dword ptr fs:[0], ecx
// 004cc9ed  5b                   pop ebx
// 004cc9ee  8be5                 mov esp, ebp
// 004cc9f0  5d                   pop ebp
// 004cc9f1  c20800               ret 8

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
    Node* allocated = static_cast<Node*>(operator new(120));
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
