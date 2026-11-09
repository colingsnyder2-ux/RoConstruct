// from server: 100% by colin
// from server: 75% by king_originala
// roc 2008-06 004ab960  unit: RBX::Network::Server::ClientProxy  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004ab960
//
// 004ab960  8b81702c0000         mov eax, dword ptr [ecx + 0x2c70]
// 004ab966  56                   push esi
// 004ab967  8b742408             mov esi, dword ptr [esp + 8]
// 004ab96b  8b8e04010000         mov ecx, dword ptr [esi + 0x104]
// 004ab971  3bc1                 cmp eax, ecx
// 004ab973  740e                 je 0x4ab983
// 004ab975  85c9                 test ecx, ecx
// 004ab977  7410                 je 0x4ab989
// 004ab979  50                   push eax
// 004ab97a  e86171f7ff           call 0x422ae0
// 004ab97f  84c0                 test al, al
// 004ab981  7406                 je 0x4ab989
// 004ab983  b001                 mov al, 1
// 004ab985  5e                   pop esi
// 004ab986  c20400               ret 4
// 004ab989  56                   push esi
// 004ab98a  e811f3feff           call 0x49aca0
// 004ab98f  83c404               add esp, 4
// 004ab992  3bf0                 cmp esi, eax
// 004ab994  0f94c0               sete al
// 004ab997  5e                   pop esi
// 004ab998  c20400               ret 4

struct Node {
    char padding[0x104];
    Node* parent;
    bool f(Node* node);
};

extern Node* __cdecl getCharacter(Node* node);

struct S {
    char padding[0x2c70];
    Node* root;
    bool f(Node* node);
};

inline bool isAncestor(Node* target, Node* parent)
{
    return target == parent || (parent && parent->f(target));
}
bool S::f(Node* node)
{
    Node* target = root;
    Node* parent = node->parent;
    if (isAncestor(target, parent))
        return true;
    if (node == getCharacter(node))
        return true;
    return false;
}
