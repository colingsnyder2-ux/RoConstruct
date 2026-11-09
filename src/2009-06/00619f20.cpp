// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00588f60  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00588f60
//
// 00588f60  56                   push esi
// 00588f61  57                   push edi
// 00588f62  8bf9                 mov edi, ecx
// 00588f64  8d4f10               lea ecx, [edi + 0x10]
// 00588f67  e814dfecff           call 0x456e80
// 00588f6c  8b4730               mov eax, dword ptr [edi + 0x30]
// 00588f6f  8b4804               mov ecx, dword ptr [eax + 4]
// 00588f72  8d7718               lea esi, [edi + 0x18]
// 00588f75  51                   push ecx
// 00588f76  8bce                 mov ecx, esi
// 00588f78  e8f3edffff           call 0x587d70
// 00588f7d  8b4618               mov eax, dword ptr [esi + 0x18]
// 00588f80  894004               mov dword ptr [eax + 4], eax
// 00588f83  8b4618               mov eax, dword ptr [esi + 0x18]
// 00588f86  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00588f8d  8900                 mov dword ptr [eax], eax
// 00588f8f  8b7618               mov esi, dword ptr [esi + 0x18]
// 00588f92  897608               mov dword ptr [esi + 8], esi
// 00588f95  8b570c               mov edx, dword ptr [edi + 0xc]
// 00588f98  4a                   dec edx
// 00588f99  f7da                 neg edx
// 00588f9b  1bd2                 sbb edx, edx
// 00588f9d  83e203               and edx, 3
// 00588fa0  89570c               mov dword ptr [edi + 0xc], edx
// 00588fa3  5f                   pop edi
// 00588fa4  5e                   pop esi
// 00588fa5  c3                   ret 

struct ResetValue {
    void reset();
    unsigned long words[2];
};

struct Node {
    Node* left;
    Node* parent;
    Node* right;
};

struct Tree {
    char padding[24];
    Node* head;
    unsigned long size;
    void erase(Node* node);
    void clear();
};

struct Service {
    char padding[12];
    unsigned long state;
    ResetValue value;
    Tree tree;
    void clear();
};

__forceinline void Tree::clear()
{
    erase(head->parent);
    head->parent = head;
    size = 0;
    head->left = head;
    head->right = head;
}

void Service::clear()
{
    value.reset();
    tree.clear();
    state = state == 1 ? 0 : 3;
}
