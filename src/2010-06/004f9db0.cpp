// from server: 100% by Yeetserama
// roc 2010-06 004f9db0  unit: RBX::Network::Replicator::EventInvocationItem  size: 61 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004f9db0
//
// 004f9db0  53                   push ebx
// 004f9db1  56                   push esi
// 004f9db2  57                   push edi
// 004f9db3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004f9db7  807f2d00             cmp byte ptr [edi + 0x2d], 0
// 004f9dbb  8bd9                 mov ebx, ecx
// 004f9dbd  8bf7                 mov esi, edi
// 004f9dbf  7526                 jne 0x4f9de7
// 004f9dc1  8b4608               mov eax, dword ptr [esi + 8]
// 004f9dc4  50                   push eax
// 004f9dc5  8bcb                 mov ecx, ebx
// 004f9dc7  e8e4ffffff           call 0x4f9db0
// 004f9dcc  8b36                 mov esi, dword ptr [esi]
// 004f9dce  8d4f14               lea ecx, [edi + 0x14]
// 004f9dd1  e84a9dfeff           call 0x4e3b20
// 004f9dd6  57                   push edi
// 004f9dd7  e8bedb2a00           call 0x7a799a
// 004f9ddc  83c404               add esp, 4
// 004f9ddf  807e2d00             cmp byte ptr [esi + 0x2d], 0
// 004f9de3  8bfe                 mov edi, esi
// 004f9de5  74da                 je 0x4f9dc1
// 004f9de7  5f                   pop edi
// 004f9de8  5e                   pop esi
// 004f9de9  5b                   pop ebx
// 004f9dea  c20400               ret 4
// copied from an identical function in another client (function ?erase@S@ns_ROCX000002@@QAEXPAUNode@2@@Z)

namespace ns_ROCX000002 {
// from server: 100% by king_originala
struct Value {
    char data[24];
    ~Value();
};

struct Node {
    Node* left;
    Node* parent;
    Node* right;
    char padding[8];
    Value value;
    unsigned char color;
    unsigned char nil;
};

extern "C" void __cdecl release(void*);

struct S {
    void erase(Node* node);
};

void S::erase(Node* node)
{
    for (Node* next = node; !next->nil; node = next) {
        erase(next->right);
        next = next->left;
        node->value.~Value();
        release(node);
    }
}
}
