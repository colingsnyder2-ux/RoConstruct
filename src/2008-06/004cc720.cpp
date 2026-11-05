// from server: 100% by colin
// from server: 94% by colin
// roc 2008-06 004cc720  unit: RBX::VInstance::?$NonFactoryProduct  size: 192 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004cc720
//
// 004cc720  83ec18               sub esp, 0x18
// 004cc723  8b442428             mov eax, dword ptr [esp + 0x28]
// 004cc727  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 004cc72b  55                   push ebp
// 004cc72c  8b2d90288000         mov ebp, dword ptr [0x802890]
// 004cc732  56                   push esi
// 004cc733  8b742428             mov esi, dword ptr [esp + 0x28]
// 004cc737  57                   push edi
// 004cc738  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 004cc73c  89742414             mov dword ptr [esp + 0x14], esi
// 004cc740  897c2418             mov dword ptr [esp + 0x18], edi
// 004cc744  8944241c             mov dword ptr [esp + 0x1c], eax
// 004cc748  894c2420             mov dword ptr [esp + 0x20], ecx
// 004cc74c  8d642400             lea esp, [esp]
// 004cc750  85f6                 test esi, esi
// 004cc752  7406                 je 0x4cc75a
// 004cc754  3b74241c             cmp esi, dword ptr [esp + 0x1c]
// 004cc758  7402                 je 0x4cc75c
// 004cc75a  ffd5                 call ebp
// 004cc75c  3b7c2420             cmp edi, dword ptr [esp + 0x20]
// 004cc760  744a                 je 0x4cc7ac
// 004cc762  85f6                 test esi, esi
// 004cc764  7542                 jne 0x4cc7a8
// 004cc766  ffd5                 call ebp
// 004cc768  3b7e18               cmp edi, dword ptr [esi + 0x18]
// 004cc76b  7502                 jne 0x4cc76f
// 004cc76d  ffd5                 call ebp
// 004cc76f  6a00                 push 0
// 004cc771  8d542410             lea edx, [esp + 0x10]
// 004cc775  52                   push edx
// 004cc776  8d442444             lea eax, [esp + 0x44]
// 004cc77a  c644241800           mov byte ptr [esp + 0x18], 0
// 004cc77f  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004cc783  50                   push eax
// 004cc784  51                   push ecx
// 004cc785  83c70c               add edi, 0xc
// 004cc788  8d4c2454             lea ecx, [esp + 0x54]
// 004cc78c  897c241c             mov dword ptr [esp + 0x1c], edi
// 004cc790  e8cbf3ffff           call 0x4cbb60
// 004cc795  8d4c2414             lea ecx, [esp + 0x14]
// 004cc799  e8a2cb1100           call 0x5e9340
// 004cc79e  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 004cc7a2  8b742414             mov esi, dword ptr [esp + 0x14]
// 004cc7a6  eba8                 jmp 0x4cc750
// 004cc7a8  8b36                 mov esi, dword ptr [esi]
// 004cc7aa  ebbc                 jmp 0x4cc768
// 004cc7ac  8b442428             mov eax, dword ptr [esp + 0x28]
// 004cc7b0  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 004cc7b4  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 004cc7b8  8910                 mov dword ptr [eax], edx
// 004cc7ba  8b542444             mov edx, dword ptr [esp + 0x44]
// 004cc7be  894804               mov dword ptr [eax + 4], ecx
// 004cc7c1  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 004cc7c5  895008               mov dword ptr [eax + 8], edx
// 004cc7c8  8b54244c             mov edx, dword ptr [esp + 0x4c]
// 004cc7cc  89480c               mov dword ptr [eax + 0xc], ecx
// 004cc7cf  8b4c2450             mov ecx, dword ptr [esp + 0x50]
// 004cc7d3  5f                   pop edi
// 004cc7d4  5e                   pop esi
// 004cc7d5  895010               mov dword ptr [eax + 0x10], edx
// 004cc7d8  894814               mov dword ptr [eax + 0x14], ecx
// 004cc7db  5d                   pop ebp
// 004cc7dc  83c418               add esp, 0x18
// 004cc7df  c3                   ret 

extern "C" void (__cdecl *invalid_parameter_noinfo)();

struct Node {
    Node* next;
    unsigned char padding[20];
    Node* sentinel;
};

struct Position {
    Node* owner;
    Node* node;
};

struct Iterator {
    Node* owner;
    Node* node;
    Node* endOwner;
    Node* endNode;

    void advance();
};

struct Tag {
    unsigned char value;
};

struct Action {
    unsigned int state[4];

    void apply(Tag, void*, void**, int);
};

struct Functor {
    unsigned int bound[2];
    Action action;
};

Functor __cdecl run(Position first, Position last, Functor functor)
{
    void (__cdecl * const invalid)() = invalid_parameter_noinfo;
    void* value;
    Tag tag;
    Iterator current;
    current.owner = first.owner;
    current.node = first.node;
    current.endOwner = last.owner;
    current.endNode = last.node;

    Node* owner = current.owner;
    Node* node = current.node;

    for (;;) {
        if (!owner || owner != current.endOwner)
            invalid();

        if (node == current.endNode)
            break;

        if (!owner)
            invalid();
        Node* container = owner ? owner->next : 0;
        if (node == container->sentinel)
            invalid();

        tag.value = 0;
        value = reinterpret_cast<unsigned char*>(node) + 12;
        functor.action.apply(tag, &functor, &value, 0);
        current.advance();
        node = current.node;
        owner = current.owner;
    }

    return functor;
}
