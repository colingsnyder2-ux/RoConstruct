// from server: 100% by coldek
// from server: 100% by king_originala
// roc 2008-06 0055e010  unit: RBX::VInstance::?$NonFactoryProduct  size: 126 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0055e010
//
// 0055e010  55                   push ebp
// 0055e011  8bec                 mov ebp, esp
// 0055e013  6aff                 push -1
// 0055e015  6821e97c00           push 0x7ce921
// 0055e01a  64a100000000         mov eax, dword ptr fs:[0]
// 0055e020  50                   push eax
// 0055e021  64892500000000       mov dword ptr fs:[0], esp
// 0055e028  83ec0c               sub esp, 0xc
// 0055e02b  53                   push ebx
// 0055e02c  56                   push esi
// 0055e02d  57                   push edi
// 0055e02e  8965f0               mov dword ptr [ebp - 0x10], esp
// 0055e031  6a40                 push 0x40
// 0055e033  e8e8281400           call 0x6a0920
// 0055e038  8bf0                 mov esi, eax
// 0055e03a  83c404               add esp, 4
// 0055e03d  8975ec               mov dword ptr [ebp - 0x14], esi
// 0055e040  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0055e047  8975e8               mov dword ptr [ebp - 0x18], esi
// 0055e04a  c645fc01             mov byte ptr [ebp - 4], 1
// 0055e04e  85f6                 test esi, esi
// 0055e050  7427                 je 0x55e079
// 0055e052  8b4508               mov eax, dword ptr [ebp + 8]
// 0055e055  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 0055e058  8b5510               mov edx, dword ptr [ebp + 0x10]
// 0055e05b  8906                 mov dword ptr [esi], eax
// 0055e05d  8b4514               mov eax, dword ptr [ebp + 0x14]
// 0055e060  894e04               mov dword ptr [esi + 4], ecx
// 0055e063  50                   push eax
// 0055e064  8d4e0c               lea ecx, [esi + 0xc]
// 0055e067  895608               mov dword ptr [esi + 8], edx
// 0055e06a  e891f3ffff           call 0x55d400
// 0055e06f  8a4d18               mov cl, byte ptr [ebp + 0x18]
// 0055e072  884e3c               mov byte ptr [esi + 0x3c], cl
// 0055e075  c6463d00             mov byte ptr [esi + 0x3d], 0
// 0055e079  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0055e07c  5f                   pop edi
// 0055e07d  8bc6                 mov eax, esi
// 0055e07f  5e                   pop esi
// 0055e080  64890d00000000       mov dword ptr fs:[0], ecx
// 0055e087  5b                   pop ebx
// 0055e088  8be5                 mov esp, ebp
// 0055e08a  5d                   pop ebp
// 0055e08b  c21400               ret 0x14

typedef unsigned int size_t;

void* __cdecl operator new(size_t);
void __cdecl operator delete(void*);

inline void* __cdecl operator new(size_t, void* p) { return p; }
inline void __cdecl operator delete(void*, void*) {}

struct Value {
    unsigned char storage[48];
    Value(const Value&);
};

struct Node {
    int first;
    int second;
    int third;
    Value value;
    unsigned char flag;
    unsigned char cleared;

    Node(int, int, int, const Value&, unsigned char);
};

inline Node::Node(int a, int b, int c, const Value& v, unsigned char f)
    : first(a), second(b), third(c), value(v), flag(f), cleared(0)
{
}

Node* __stdcall createNode(int a, int b, int c,
                          const Value& v, unsigned char flag)
{
    Node* p = static_cast<Node*>(operator new(sizeof(Node)));
    try {
        new (p) Node(a, b, c, v, flag);
    }
    catch (...) {
        operator delete(p);
        throw;
    }
    return p;
}
