// from server: 100% by Yeetserama
// roc 2010-06 00442070  unit: HVCXTPPropertyGridItemEnum::?$XItem  size: 61 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00442070
//
// 00442070  53                   push ebx
// 00442071  56                   push esi
// 00442072  57                   push edi
// 00442073  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00442077  807f2900             cmp byte ptr [edi + 0x29], 0
// 0044207b  8bd9                 mov ebx, ecx
// 0044207d  8bf7                 mov esi, edi
// 0044207f  7526                 jne 0x4420a7
// 00442081  8b4608               mov eax, dword ptr [esi + 8]
// 00442084  50                   push eax
// 00442085  8bcb                 mov ecx, ebx
// 00442087  e8e4ffffff           call 0x442070
// 0044208c  8b36                 mov esi, dword ptr [esi]
// 0044208e  8d4f10               lea ecx, [edi + 0x10]
// 00442091  e83aa33500           call 0x79c3d0
// 00442096  57                   push edi
// 00442097  e8fe583600           call 0x7a799a
// 0044209c  83c404               add esp, 4
// 0044209f  807e2900             cmp byte ptr [esi + 0x29], 0
// 004420a3  8bfe                 mov edi, esi
// 004420a5  74da                 je 0x442081
// 004420a7  5f                   pop edi
// 004420a8  5e                   pop esi
// 004420a9  5b                   pop ebx
// 004420aa  c20400               ret 4
// copied from an identical function in another client (function ?erase@Tree@@QAEXPAUNode@@@Z)

// from server: 100% by tester
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