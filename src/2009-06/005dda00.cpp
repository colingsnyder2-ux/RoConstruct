// from server: 100% by EspClaude
// from server: 100% by Espeon
// roc 2008-06 00560720  unit: RBX::VContentProvider::?$DescribedNonCreatable  size: 250 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00560720
//
// 00560720  6aff                 push -1
// 00560722  64a100000000         mov eax, dword ptr fs:[0]
// 00560728  6830ed7c00           push 0x7ced30
// 0056072d  50                   push eax
// 0056072e  8b442410             mov eax, dword ptr [esp + 0x10]
// 00560732  64892500000000       mov dword ptr fs:[0], esp
// 00560739  83ec48               sub esp, 0x48
// 0056073c  53                   push ebx
// 0056073d  55                   push ebp
// 0056073e  56                   push esi
// 0056073f  57                   push edi
// 00560740  50                   push eax
// 00560741  8bf1                 mov esi, ecx
// 00560743  e848c3ffff           call 0x55ca90
// 00560748  33db                 xor ebx, ebx
// 0056074a  8be8                 mov ebp, eax
// 0056074c  3bf3                 cmp esi, ebx
// 0056074e  7506                 jne 0x560756
// 00560750  ff1590288000         call dword ptr [0x802890]
// 00560756  8b3e                 mov edi, dword ptr [esi]
// 00560758  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0056075b  894c2414             mov dword ptr [esp + 0x14], ecx
// 0056075f  3bfb                 cmp edi, ebx
// 00560761  7404                 je 0x560767
// 00560763  3bff                 cmp edi, edi
// 00560765  7406                 je 0x56076d
// 00560767  ff1590288000         call dword ptr [0x802890]
// 0056076d  3b6c2414             cmp ebp, dword ptr [esp + 0x14]
// 00560771  7416                 je 0x560789
// 00560773  8b442468             mov eax, dword ptr [esp + 0x68]
// 00560777  8d550c               lea edx, [ebp + 0xc]
// 0056077a  52                   push edx
// 0056077b  50                   push eax
// 0056077c  ff155c238000         call dword ptr [0x80235c]
// 00560782  83c408               add esp, 8
// 00560785  84c0                 test al, al
// 00560787  745e                 je 0x5607e7
// 00560789  895c2418             mov dword ptr [esp + 0x18], ebx
// 0056078d  895c241c             mov dword ptr [esp + 0x1c], ebx
// 00560791  895c2420             mov dword ptr [esp + 0x20], ebx
// 00560795  895c2424             mov dword ptr [esp + 0x24], ebx
// 00560799  8b542468             mov edx, dword ptr [esp + 0x68]
// 0056079d  8d4c2418             lea ecx, [esp + 0x18]
// 005607a1  51                   push ecx
// 005607a2  52                   push edx
// 005607a3  8d4c2430             lea ecx, [esp + 0x30]
// 005607a7  895c2468             mov dword ptr [esp + 0x68], ebx
// 005607ab  e860caffff           call 0x55d210
// 005607b0  50                   push eax
// 005607b1  55                   push ebp
// 005607b2  57                   push edi
// 005607b3  8d44241c             lea eax, [esp + 0x1c]
// 005607b7  50                   push eax
// 005607b8  8bce                 mov ecx, esi
// 005607ba  c644247001           mov byte ptr [esp + 0x70], 1
// 005607bf  e8fcf7ffff           call 0x55ffc0
// 005607c4  8b38                 mov edi, dword ptr [eax]
// 005607c6  8b6804               mov ebp, dword ptr [eax + 4]
// 005607c9  8d4c2428             lea ecx, [esp + 0x28]
// 005607cd  885c2460             mov byte ptr [esp + 0x60], bl
// 005607d1  e87ac9ffff           call 0x55d150
// 005607d6  8d4c2418             lea ecx, [esp + 0x18]
// 005607da  c7442460ffffffff     mov dword ptr [esp + 0x60], 0xffffffff
// 005607e2  e87924ecff           call 0x422c60
// 005607e7  3bfb                 cmp edi, ebx
// 005607e9  752b                 jne 0x560816
// 005607eb  ff1590288000         call dword ptr [0x802890]
// 005607f1  33ff                 xor edi, edi
// 005607f3  3b6f18               cmp ebp, dword ptr [edi + 0x18]
// 005607f6  7506                 jne 0x5607fe
// 005607f8  ff1590288000         call dword ptr [0x802890]
// 005607fe  8b4c2458             mov ecx, dword ptr [esp + 0x58]
// 00560802  5f                   pop edi
// 00560803  5e                   pop esi
// 00560804  8d452c               lea eax, [ebp + 0x2c]
// 00560807  5d                   pop ebp
// 00560808  5b                   pop ebx
// 00560809  64890d00000000       mov dword ptr fs:[0], ecx
// 00560810  83c454               add esp, 0x54
// 00560813  c20400               ret 4
// 00560816  8b3f                 mov edi, dword ptr [edi]
// 00560818  ebd9                 jmp 0x5607f3

// from server: 91% by king_originala
struct String
{
    char storage[32];
};

struct Value
{
    unsigned int data[4];
    ~Value();
};

struct Pair
{
    String key;
    Value value;
    Pair(const String &, const Value &);
    ~Pair();
};

struct Node
{
    char links[12];
    String key;
    Value value;
};

struct S;

struct Proxy
{
    S *container;
};

extern __declspec(dllimport) void __cdecl _invalid_parameter_noinfo();
extern bool (__cdecl *string_less)(const String &, const String &);

struct Iterator
{
    Proxy *owner;
    Node *node;

    bool operator==(const Iterator &) const;
    void unpack(Proxy *&, Node *&) const;
};

inline bool Iterator::operator==(const Iterator &other) const
{
    if (!owner || owner != other.owner)
        _invalid_parameter_noinfo();
    return node == other.node;
}

inline void Iterator::unpack(Proxy *&outOwner, Node *&outNode) const
{
    outOwner = owner;
    outNode = node;
}

struct S
{
    Proxy *proxy;
    char padding[20];
    Node *head;

    Node *lower_bound(const String &);
    Iterator insert(Iterator, const Pair &);
    Value &lookup(const String &);
};

Value &S::lookup(const String &key)
{
    Node *node = lower_bound(key);

    if (!this)
        _invalid_parameter_noinfo();

    Proxy *owner = proxy;
    Iterator position = { owner, node };
    Iterator end = { proxy, head };

    if (position == end || string_less(key, node->key))
    {
        Value empty = { 0, 0, 0, 0 };
        insert(position, Pair(key, empty)).unpack(owner, node);
    }

    if (!owner)
        _invalid_parameter_noinfo();
    S *container = owner ? owner->container : 0;

    if (node == container->head)
        _invalid_parameter_noinfo();

    return node->value;
}
