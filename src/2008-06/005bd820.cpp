// from server: 100% by colin
// from server: 92% by colin
// roc 2008-06 005bd820  unit: RBX::VNetworkSettings::?$BoundPropGetSet  size: 98 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005bd820
//
// 005bd820  83ec08               sub esp, 8
// 005bd823  53                   push ebx
// 005bd824  55                   push ebp
// 005bd825  56                   push esi
// 005bd826  57                   push edi
// 005bd827  8db13c010000         lea esi, [ecx + 0x13c]
// 005bd82d  8d44241c             lea eax, [esp + 0x1c]
// 005bd831  50                   push eax
// 005bd832  8d4c2414             lea ecx, [esp + 0x14]
// 005bd836  51                   push ecx
// 005bd837  8bce                 mov ecx, esi
// 005bd839  e862c1ffff           call 0x5b99a0
// 005bd83e  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 005bd842  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 005bd845  8b36                 mov esi, dword ptr [esi]
// 005bd847  8b2d90288000         mov ebp, dword ptr [0x802890]
// 005bd84d  85ff                 test edi, edi
// 005bd84f  7404                 je 0x5bd855
// 005bd851  3bfe                 cmp edi, esi
// 005bd853  7402                 je 0x5bd857
// 005bd855  ffd5                 call ebp
// 005bd857  8b742414             mov esi, dword ptr [esp + 0x14]
// 005bd85b  3bf3                 cmp esi, ebx
// 005bd85d  7415                 je 0x5bd874
// 005bd85f  85ff                 test edi, edi
// 005bd861  751b                 jne 0x5bd87e
// 005bd863  ffd5                 call ebp
// 005bd865  3b7718               cmp esi, dword ptr [edi + 0x18]
// 005bd868  7502                 jne 0x5bd86c
// 005bd86a  ffd5                 call ebp
// 005bd86c  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 005bd86f  e87cfcffff           call 0x5bd4f0
// 005bd874  5f                   pop edi
// 005bd875  5e                   pop esi
// 005bd876  5d                   pop ebp
// 005bd877  5b                   pop ebx
// 005bd878  83c408               add esp, 8
// 005bd87b  c20400               ret 4
// 005bd87e  8b3f                 mov edi, dword ptr [edi]
// 005bd880  ebe3                 jmp 0x5bd865

extern "C" void (__cdecl* _invalid_parameter_noinfo)();

struct Value {
    void invoke();
};

struct Node {
    Node* left;
    Node* parent;
    Node* right;
    int key;
    Value* value;
    int reserved;
    unsigned char color;
    unsigned char nil;
};

struct Tree;

struct Iterator {
    Tree** owner;
    Node* node;
};

struct Tree {
    Tree** owner;
    char reserved[20];
    Node* head;

    Iterator end(const int& key);
};

struct S {
    char reserved[316];
    Tree tree;

    void f(int key);
};

void S::f(int key)
{
    Tree& t = tree;
    Iterator it = t.end(key);
    Tree** owner = reinterpret_cast<Tree** volatile&>(it.owner);
    Node* head = t.head;
    Tree** expected = reinterpret_cast<Tree** volatile&>(t.owner);
    void (__cdecl* invalid)() = _invalid_parameter_noinfo;

    if (!owner || owner != expected)
        invalid();

    Node* node = reinterpret_cast<Node* volatile&>(it.node);
    if (node != head) {
        if (!(owner != 0))
            invalid();
        Tree* container = owner ? *owner : 0;
        if (node == container->head)
            invalid();

        node->value->invoke();
    }
}
