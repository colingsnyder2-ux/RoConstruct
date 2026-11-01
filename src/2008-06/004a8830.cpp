// from server: 100% by colin
// from server: 100% by king_originala
// roc 2008-06 004a8830  unit: RBX::VHint::?$FactoryProduct::Creator  size: 161 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004a8830
//
// 004a8830  55                   push ebp
// 004a8831  8bec                 mov ebp, esp
// 004a8833  6aff                 push -1
// 004a8835  68e17f7c00           push 0x7c7fe1
// 004a883a  64a100000000         mov eax, dword ptr fs:[0]
// 004a8840  50                   push eax
// 004a8841  64892500000000       mov dword ptr fs:[0], esp
// 004a8848  83ec0c               sub esp, 0xc
// 004a884b  53                   push ebx
// 004a884c  56                   push esi
// 004a884d  57                   push edi
// 004a884e  8965f0               mov dword ptr [ebp - 0x10], esp
// 004a8851  6a30                 push 0x30
// 004a8853  e8c8801f00           call 0x6a0920
// 004a8858  8bf0                 mov esi, eax
// 004a885a  83c404               add esp, 4
// 004a885d  8975ec               mov dword ptr [ebp - 0x14], esi
// 004a8860  c745fc00000000       mov dword ptr [ebp - 4], 0
// 004a8867  8975e8               mov dword ptr [ebp - 0x18], esi
// 004a886a  c645fc01             mov byte ptr [ebp - 4], 1
// 004a886e  85f6                 test esi, esi
// 004a8870  7435                 je 0x4a88a7
// 004a8872  8b4508               mov eax, dword ptr [ebp + 8]
// 004a8875  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 004a8878  8b5510               mov edx, dword ptr [ebp + 0x10]
// 004a887b  8906                 mov dword ptr [esi], eax
// 004a887d  8b4514               mov eax, dword ptr [ebp + 0x14]
// 004a8880  894e04               mov dword ptr [esi + 4], ecx
// 004a8883  895608               mov dword ptr [esi + 8], edx
// 004a8886  8b08                 mov ecx, dword ptr [eax]
// 004a8888  894e0c               mov dword ptr [esi + 0xc], ecx
// 004a888b  8b5004               mov edx, dword ptr [eax + 4]
// 004a888e  83c008               add eax, 8
// 004a8891  50                   push eax
// 004a8892  8d4e14               lea ecx, [esi + 0x14]
// 004a8895  895610               mov dword ptr [esi + 0x10], edx
// 004a8898  e873f7ffff           call 0x4a8010
// 004a889d  8a4518               mov al, byte ptr [ebp + 0x18]
// 004a88a0  88462c               mov byte ptr [esi + 0x2c], al
// 004a88a3  c6462d00             mov byte ptr [esi + 0x2d], 0
// 004a88a7  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004a88aa  5f                   pop edi
// 004a88ab  8bc6                 mov eax, esi
// 004a88ad  5e                   pop esi
// 004a88ae  64890d00000000       mov dword ptr fs:[0], ecx
// 004a88b5  5b                   pop ebx
// 004a88b6  8be5                 mov esp, ebp
// 004a88b8  5d                   pop ebp
// 004a88b9  c21400               ret 0x14
// 004a88bc  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 004a88bf  51                   push ecx
// 004a88c0  e8b57d1f00           call 0x6a067a
// 004a88c5  83c404               add esp, 4
// 004a88c8  6a00                 push 0
// 004a88ca  6a00                 push 0
// 004a88cc  e8bb8c1f00           call 0x6a158c

typedef unsigned int size_t;

void* __cdecl operator new(size_t);
void __cdecl operator delete(void*);

__forceinline void* __cdecl operator new(size_t, void* p)
{
    return p;
}

__forceinline void __cdecl operator delete(void*, void*)
{
}

struct Payload {
    char storage[24];
    Payload(const Payload&);
};

struct Value {
    unsigned int first;
    unsigned int second;
    Payload payload;
};

struct Node {
    Node* left;
    Node* parent;
    Node* right;
    Value value;
    unsigned char color;
    unsigned char nil;

    Node(Node*, Node*, Node*, const Value&, unsigned char);
};

__forceinline Node::Node(Node* l, Node* p, Node* r,
                         const Value& v, unsigned char c)
    : left(l), parent(p), right(r), value(v), color(c), nil(0)
{
}

Node* __stdcall create(Node* left, Node* parent, Node* right,
                       const Value& value, unsigned char color)
{
    Node* p = static_cast<Node*>(operator new(sizeof(Node)));
    try {
        new(p) Node(left, parent, right, value, color);
    }
    catch (...) {
        operator delete(p);
        throw;
    }
    return p;
}
