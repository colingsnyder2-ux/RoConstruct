// from server: 85% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0058c0f0  unit: RBX::VChangeHistoryService::?$BoundFuncDesc  size: 199 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0058c0f0
//
// 0058c0f0  83ec08               sub esp, 8
// 0058c0f3  57                   push edi
// 0058c0f4  8bf9                 mov edi, ecx
// 0058c0f6  80bf6501000000       cmp byte ptr [edi + 0x165], 0
// 0058c0fd  0f84af000000         je 0x58c1b2
// 0058c103  8b8754010000         mov eax, dword ptr [edi + 0x154]
// 0058c109  8b8f38010000         mov ecx, dword ptr [edi + 0x138]
// 0058c10f  53                   push ebx
// 0058c110  8b9f4c010000         mov ebx, dword ptr [edi + 0x14c]
// 0058c116  55                   push ebp
// 0058c117  8b2d90288000         mov ebp, dword ptr [0x802890]
// 0058c11d  56                   push esi
// 0058c11e  8db738010000         lea esi, [edi + 0x138]
// 0058c124  85c0                 test eax, eax
// 0058c126  7404                 je 0x58c12c
// 0058c128  3bc1                 cmp eax, ecx
// 0058c12a  7402                 je 0x58c12e
// 0058c12c  ffd5                 call ebp
// 0058c12e  399f58010000         cmp dword ptr [edi + 0x158], ebx
// 0058c134  745d                 je 0x58c193
// 0058c136  8b4614               mov eax, dword ptr [esi + 0x14]
// 0058c139  8b0e                 mov ecx, dword ptr [esi]
// 0058c13b  50                   push eax
// 0058c13c  8b8758010000         mov eax, dword ptr [edi + 0x158]
// 0058c142  51                   push ecx
// 0058c143  8b8f54010000         mov ecx, dword ptr [edi + 0x154]
// 0058c149  50                   push eax
// 0058c14a  51                   push ecx
// 0058c14b  8d542420             lea edx, [esp + 0x20]
// 0058c14f  52                   push edx
// 0058c150  8bce                 mov ecx, esi
// 0058c152  e819c8ffff           call 0x588970
// 0058c157  8b4614               mov eax, dword ptr [esi + 0x14]
// 0058c15a  8b0e                 mov ecx, dword ptr [esi]
// 0058c15c  898f54010000         mov dword ptr [edi + 0x154], ecx
// 0058c162  898758010000         mov dword ptr [edi + 0x158], eax
// 0058c168  8b5e14               mov ebx, dword ptr [esi + 0x14]
// 0058c16b  8b36                 mov esi, dword ptr [esi]
// 0058c16d  85f6                 test esi, esi
// 0058c16f  7502                 jne 0x58c173
// 0058c171  ffd5                 call ebp
// 0058c173  8b5b04               mov ebx, dword ptr [ebx + 4]
// 0058c176  85f6                 test esi, esi
// 0058c178  7404                 je 0x58c17e
// 0058c17a  8b06                 mov eax, dword ptr [esi]
// 0058c17c  eb02                 jmp 0x58c180
// 0058c17e  33c0                 xor eax, eax
// 0058c180  3b5814               cmp ebx, dword ptr [eax + 0x14]
// 0058c183  7502                 jne 0x58c187
// 0058c185  ffd5                 call ebp
// 0058c187  89b75c010000         mov dword ptr [edi + 0x15c], esi
// 0058c18d  899f60010000         mov dword ptr [edi + 0x160], ebx
// 0058c193  be0a000000           mov esi, 0xa
// 0058c198  39b750010000         cmp dword ptr [edi + 0x150], esi
// 0058c19e  760f                 jbe 0x58c1af
// 0058c1a0  8bcf                 mov ecx, edi
// 0058c1a2  e8d9fdffff           call 0x58bf80
// 0058c1a7  39b750010000         cmp dword ptr [edi + 0x150], esi
// 0058c1ad  77f1                 ja 0x58c1a0
// 0058c1af  5e                   pop esi
// 0058c1b0  5d                   pop ebp
// 0058c1b1  5b                   pop ebx
// 0058c1b2  5f                   pop edi
// 0058c1b3  83c408               add esp, 8
// 0058c1b6  c3                   ret 

struct List;

struct Proxy {
    List* list;
};

struct Node {
    Node* next;
    Node* previous;
};

struct Iterator {
    Proxy* owner;
    Node* node;
};

struct List {
    Proxy* volatile proxy;
    unsigned char padding[16];
    Node* head;
    unsigned int size;

    Iterator erase(Iterator first, Iterator last);
};

extern "C" {
    extern void (__cdecl* invalid_parameter_noinfo)();
}

struct S {
    unsigned char padding[0x138];
    List history;
    Iterator current;
    Iterator previous;
    unsigned char reserved;
    bool enabled;

    void trim();
    void update();
};

void S::update()
{
    if (enabled) {
        Proxy* owner = current.owner;
        Proxy* expected = history.proxy;
        Node* end = history.head;
        void (__cdecl* invalid)() = invalid_parameter_noinfo;
        List* list = &history;

        if (!owner || owner != expected)
            invalid();

        if (current.node != end) {
            Iterator last;
            last.node = list->head;
            last.owner = list->proxy;
            list->erase(current, last);

            Iterator position;
            position.node = *reinterpret_cast<Node* volatile*>(&list->head);
            position.owner = list->proxy;
            current = position;

            Node* node = list->head;
            Proxy* proxy = list->proxy;

            if (!proxy)
                invalid();

            node = node->previous;

            List* container = proxy ? proxy->list : 0;
            if (node == container->head)
                invalid();

            Iterator before;
            before.owner = proxy;
            before.node = node;
            previous = before;
        }

        while (history.size > 10)
            trim();
    }
}
