// from server: 100% by EspClaude
// roc 2009-06 004efa00  unit: RBX::Network::Replicator::ChangePropertyItem  size: 61 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004efa00
//
// 004efa00  53                   push ebx
// 004efa01  56                   push esi
// 004efa02  57                   push edi
// 004efa03  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004efa07  807f2d00             cmp byte ptr [edi + 0x2d], 0
// 004efa0b  8bd9                 mov ebx, ecx
// 004efa0d  8bf7                 mov esi, edi
// 004efa0f  7526                 jne 0x4efa37
// 004efa11  8b4608               mov eax, dword ptr [esi + 8]
// 004efa14  50                   push eax
// 004efa15  8bcb                 mov ecx, ebx
// 004efa17  e8e4ffffff           call 0x4efa00
// 004efa1c  8b36                 mov esi, dword ptr [esi]
// 004efa1e  8d4f14               lea ecx, [edi + 0x14]
// 004efa21  e89af5feff           call 0x4defc0
// 004efa26  57                   push edi
// 004efa27  e806902200           call 0x718a32
// 004efa2c  83c404               add esp, 4
// 004efa2f  807e2d00             cmp byte ptr [esi + 0x2d], 0
// 004efa33  8bfe                 mov edi, esi
// 004efa35  74da                 je 0x4efa11
// 004efa37  5f                   pop edi
// 004efa38  5e                   pop esi
// 004efa39  5b                   pop ebx
// 004efa3a  c20400               ret 4
// copied from an identical function in another client (function ?erase@S@ns_ROCX0000ca@@QAEXPAUNode@2@@Z)

namespace ns_ROCX0000ca {
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
