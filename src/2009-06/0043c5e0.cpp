// from server: 100% by EspClaude
// roc 2009-06 0043c5e0  unit: HVCXTPPropertyGridItemEnum::?$XItem  size: 61 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0043c5e0
//
// 0043c5e0  53                   push ebx
// 0043c5e1  56                   push esi
// 0043c5e2  57                   push edi
// 0043c5e3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0043c5e7  807f2900             cmp byte ptr [edi + 0x29], 0
// 0043c5eb  8bd9                 mov ebx, ecx
// 0043c5ed  8bf7                 mov esi, edi
// 0043c5ef  7526                 jne 0x43c617
// 0043c5f1  8b4608               mov eax, dword ptr [esi + 8]
// 0043c5f4  50                   push eax
// 0043c5f5  8bcb                 mov ecx, ebx
// 0043c5f7  e8e4ffffff           call 0x43c5e0
// 0043c5fc  8b36                 mov esi, dword ptr [esi]
// 0043c5fe  8d4f10               lea ecx, [edi + 0x10]
// 0043c601  e8baf32c00           call 0x70b9c0
// 0043c606  57                   push edi
// 0043c607  e826c42d00           call 0x718a32
// 0043c60c  83c404               add esp, 4
// 0043c60f  807e2900             cmp byte ptr [esi + 0x29], 0
// 0043c613  8bfe                 mov edi, esi
// 0043c615  74da                 je 0x43c5f1
// 0043c617  5f                   pop edi
// 0043c618  5e                   pop esi
// 0043c619  5b                   pop ebx
// 0043c61a  c20400               ret 4
// copied from an identical function in another client (function ?erase@Tree@@QAEXPAUNode@@@Z)

void __cdecl operator delete(void*);

struct Value {
    ~Value();
};

struct Node {
    Node* left;
    Node* parent;
    Node* right;
    char padding[4];
    Value value;
    char padding2[24];
    char isnil;
};

struct Tree {
    void erase(Node* root);
};

void Tree::erase(Node* root)
{
    for (Node* node = root; !node->isnil; root = node) {
        erase(node->right);
        node = node->left;
        root->value.~Value();
        operator delete(root);
    }
}