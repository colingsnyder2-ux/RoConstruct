// from server: 100% by colin
// from server: 92% by colin
// roc 2008-06 005ac450  unit: RBX::VScriptContext::?$FactoryProduct  size: 158 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005ac450
//
// 005ac450  83ec10               sub esp, 0x10
// 005ac453  8b442424             mov eax, dword ptr [esp + 0x24]
// 005ac457  53                   push ebx
// 005ac458  8b1d90288000         mov ebx, dword ptr [0x802890]
// 005ac45e  55                   push ebp
// 005ac45f  8b6c2428             mov ebp, dword ptr [esp + 0x28]
// 005ac463  56                   push esi
// 005ac464  8b742424             mov esi, dword ptr [esp + 0x24]
// 005ac468  57                   push edi
// 005ac469  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 005ac46d  89742410             mov dword ptr [esp + 0x10], esi
// 005ac471  897c2414             mov dword ptr [esp + 0x14], edi
// 005ac475  8944241c             mov dword ptr [esp + 0x1c], eax
// 005ac479  8da42400000000       lea esp, [esp]
// 005ac480  85f6                 test esi, esi
// 005ac482  7404                 je 0x5ac488
// 005ac484  3bf5                 cmp esi, ebp
// 005ac486  7402                 je 0x5ac48a
// 005ac488  ffd3                 call ebx
// 005ac48a  3b7c241c             cmp edi, dword ptr [esp + 0x1c]
// 005ac48e  7437                 je 0x5ac4c7
// 005ac490  85f6                 test esi, esi
// 005ac492  752f                 jne 0x5ac4c3
// 005ac494  ffd3                 call ebx
// 005ac496  3b7e18               cmp edi, dword ptr [esi + 0x18]
// 005ac499  7502                 jne 0x5ac49d
// 005ac49b  ffd3                 call ebx
// 005ac49d  8b4f0c               mov ecx, dword ptr [edi + 0xc]
// 005ac4a0  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 005ac4a4  8b442440             mov eax, dword ptr [esp + 0x40]
// 005ac4a8  51                   push ecx
// 005ac4a9  8d0c10               lea ecx, [eax + edx]
// 005ac4ac  ff54243c             call dword ptr [esp + 0x3c]
// 005ac4b0  8d4c2410             lea ecx, [esp + 0x10]
// 005ac4b4  e887ce0300           call 0x5e9340
// 005ac4b9  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 005ac4bd  8b742410             mov esi, dword ptr [esp + 0x10]
// 005ac4c1  ebbd                 jmp 0x5ac480
// 005ac4c3  8b36                 mov esi, dword ptr [esi]
// 005ac4c5  ebcf                 jmp 0x5ac496
// 005ac4c7  8b442424             mov eax, dword ptr [esp + 0x24]
// 005ac4cb  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 005ac4cf  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 005ac4d3  5f                   pop edi
// 005ac4d4  8908                 mov dword ptr [eax], ecx
// 005ac4d6  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 005ac4da  895004               mov dword ptr [eax + 4], edx
// 005ac4dd  8b542440             mov edx, dword ptr [esp + 0x40]
// 005ac4e1  5e                   pop esi
// 005ac4e2  5d                   pop ebp
// 005ac4e3  894808               mov dword ptr [eax + 8], ecx
// 005ac4e6  89500c               mov dword ptr [eax + 0xc], edx
// 005ac4e9  5b                   pop ebx
// 005ac4ea  83c410               add esp, 0x10
// 005ac4ed  c3                   ret 

extern "C" void (__cdecl *invalid_parameter_noinfo)();

struct Node {
    Node* left;
    Node* parent;
    Node* right;
    void* value;
};

struct Container {
    unsigned char padding[24];
    Node* sentinel;
};

struct Owner {
    Container* container;
};

struct Iterator {
    Owner* owner;
    Node* node;
    void increment();
};

typedef void (__thiscall *Callback)(void*, void*);

struct Function {
    Callback callback;
    int adjustment;
    char* object;
    unsigned int extra;
};

Function __cdecl for_each(Iterator begin, Iterator end, Function function)
{
    void (__cdecl *invalid)() = invalid_parameter_noinfo;
    Iterator current = begin;
    Iterator finish = end;
    Owner* owner = current.owner;
    Node* node = current.node;

    for (;;) {
        if (!owner || owner != finish.owner)
            invalid();

        if (node == finish.node)
            break;

        if (!(owner != 0))
            invalid();
        Container* container = owner ? owner->container : 0;
        if (node == container->sentinel)
            invalid();

        function.callback(reinterpret_cast<char*>(function.adjustment + reinterpret_cast<int>(function.object)), node->value);
        current.increment();
        node = current.node;
        owner = current.owner;
    }

    return function;
}
