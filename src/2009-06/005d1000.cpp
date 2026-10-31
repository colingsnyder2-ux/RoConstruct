// from server: 86% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00558c50  unit: RBX::VInstance::?$NonFactoryProduct  size: 314 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00558c50
//
// 00558c50  6aff                 push -1
// 00558c52  64a100000000         mov eax, dword ptr fs:[0]
// 00558c58  682bf57b00           push 0x7bf52b
// 00558c5d  50                   push eax
// 00558c5e  64892500000000       mov dword ptr fs:[0], esp
// 00558c65  83ec08               sub esp, 8
// 00558c68  53                   push ebx
// 00558c69  55                   push ebp
// 00558c6a  56                   push esi
// 00558c6b  57                   push edi
// 00558c6c  8bf9                 mov edi, ecx
// 00558c6e  33db                 xor ebx, ebx
// 00558c70  389f2c010000         cmp byte ptr [edi + 0x12c], bl
// 00558c76  0f84b2000000         je 0x558d2e
// 00558c7c  e8efb5ffff           call 0x554270
// 00558c81  8d6f10               lea ebp, [edi + 0x10]
// 00558c84  8bf0                 mov esi, eax
// 00558c86  8b4500               mov eax, dword ptr [ebp]
// 00558c89  8b5004               mov edx, dword ptr [eax + 4]
// 00558c8c  8bcd                 mov ecx, ebp
// 00558c8e  ffd2                 call edx
// 00558c90  3bc6                 cmp eax, esi
// 00558c92  0f8496000000         je 0x558d2e
// 00558c98  6a28                 push 0x28
// 00558c9a  e8817c1400           call 0x6a0920
// 00558c9f  83c404               add esp, 4
// 00558ca2  3bc3                 cmp eax, ebx
// 00558ca4  741e                 je 0x558cc4
// 00558ca6  8b0d5c539700         mov ecx, dword ptr [0x97535c]
// 00558cac  8918                 mov dword ptr [eax], ebx
// 00558cae  895804               mov dword ptr [eax + 4], ebx
// 00558cb1  895808               mov dword ptr [eax + 8], ebx
// 00558cb4  894810               mov dword ptr [eax + 0x10], ecx
// 00558cb7  895814               mov dword ptr [eax + 0x14], ebx
// 00558cba  895820               mov dword ptr [eax + 0x20], ebx
// 00558cbd  895824               mov dword ptr [eax + 0x24], ebx
// 00558cc0  8bf0                 mov esi, eax
// 00558cc2  eb02                 jmp 0x558cc6
// 00558cc4  33f6                 xor esi, esi
// 00558cc6  8b4500               mov eax, dword ptr [ebp]
// 00558cc9  8b5004               mov edx, dword ptr [eax + 4]
// 00558ccc  8bcd                 mov ecx, ebp
// 00558cce  ffd2                 call edx
// 00558cd0  50                   push eax
// 00558cd1  a178539700           mov eax, dword ptr [0x975378]
// 00558cd6  50                   push eax
// 00558cd7  8bce                 mov ecx, esi
// 00558cd9  e852f1ffff           call 0x557e30
// 00558cde  83ec08               sub esp, 8
// 00558ce1  8bcc                 mov ecx, esp
// 00558ce3  89642418             mov dword ptr [esp + 0x18], esp
// 00558ce7  57                   push edi
// 00558ce8  e813c10300           call 0x594e00
// 00558ced  8b0d10539700         mov ecx, dword ptr [0x975310]
// 00558cf3  51                   push ecx
// 00558cf4  8bce                 mov ecx, esi
// 00558cf6  e835fbffff           call 0x558830
// 00558cfb  8b150c539700         mov edx, dword ptr [0x97530c]
// 00558d01  52                   push edx
// 00558d02  8bce                 mov ecx, esi
// 00558d04  e8b7def3ff           call 0x496bc0
// 00558d09  50                   push eax
// 00558d0a  8bcf                 mov ecx, edi
// 00558d0c  e86ffeffff           call 0x558b80
// 00558d11  56                   push esi
// 00558d12  8bcf                 mov ecx, edi
// 00558d14  e8f7f3ffff           call 0x558110
// 00558d19  8bc6                 mov eax, esi
// 00558d1b  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00558d1f  64890d00000000       mov dword ptr fs:[0], ecx
// 00558d26  5f                   pop edi
// 00558d27  5e                   pop esi
// 00558d28  5d                   pop ebp
// 00558d29  5b                   pop ebx
// 00558d2a  83c414               add esp, 0x14
// 00558d2d  c3                   ret 
// 00558d2e  6a28                 push 0x28
// 00558d30  e8eb7b1400           call 0x6a0920
// 00558d35  8bf0                 mov esi, eax
// 00558d37  83c404               add esp, 4
// 00558d3a  89742410             mov dword ptr [esp + 0x10], esi
// 00558d3e  895c2420             mov dword ptr [esp + 0x20], ebx
// 00558d42  3bf3                 cmp esi, ebx
// 00558d44  742f                 je 0x558d75
// 00558d46  83ec08               sub esp, 8
// 00558d49  8bcc                 mov ecx, esp
// 00558d4b  8964241c             mov dword ptr [esp + 0x1c], esp
// 00558d4f  57                   push edi
// 00558d50  e8abc00300           call 0x594e00
// 00558d55  a158539700           mov eax, dword ptr [0x975358]
// 00558d5a  50                   push eax
// 00558d5b  8bce                 mov ecx, esi
// 00558d5d  e8aee7ebff           call 0x417510
// 00558d62  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00558d66  64890d00000000       mov dword ptr fs:[0], ecx
// 00558d6d  5f                   pop edi
// 00558d6e  5e                   pop esi
// 00558d6f  5d                   pop ebp
// 00558d70  5b                   pop ebx
// 00558d71  83c414               add esp, 0x14
// 00558d74  c3                   ret 
// 00558d75  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00558d79  5f                   pop edi
// 00558d7a  5e                   pop esi
// 00558d7b  5d                   pop ebp
// 00558d7c  33c0                 xor eax, eax
// 00558d7e  64890d00000000       mov dword ptr fs:[0], ecx
// 00558d85  5b                   pop ebx
// 00558d86  83c414               add esp, 0x14
// 00558d89  c3                   ret 

void * __cdecl operator new(unsigned int);
void __cdecl operator delete(void *) throw();

extern void *defaultValue;
extern void *scopeKey;
extern void *parentKey;
extern void *lookupKey;
extern void *constructorKey;

void * __cdecl localScope();

struct S;

struct Ref {
    void *object;
    void *control;

    Ref(S *);
    Ref(const Ref &);
    ~Ref();
};

struct Interface {
    virtual void unused();
    virtual void *scope();
};

struct Node {
    unsigned int a;
    unsigned int b;
    unsigned int c;
    unsigned int reserved0;
    void *value;
    unsigned int d;
    unsigned int reserved1;
    unsigned int reserved2;
    unsigned int e;
    unsigned int f;

    Node();
    Node(void *, Ref);
    void setScope(void *, void *);
    void setParent(void *, Ref);
    void *find(void *);
};

__forceinline Node::Node()
{
    void *initialValue = defaultValue;
    a = 0;
    b = 0;
    c = 0;
    value = initialValue;
    d = 0;
    e = 0;
    f = 0;
}

struct S {
    char prefix[16];
    Interface interfacePart;
    char padding[280];
    bool enabled;

    Node *create();
    void update(void *);
    void attach(Node *);
};

Node *S::create()
{
    if (enabled) {
        void *scope = localScope();
        if (interfacePart.scope() != scope) {
            Node *p = new Node;
            p->setScope(scopeKey, interfacePart.scope());
            p->setParent(parentKey, Ref(this));
            update(p->find(lookupKey));
            attach(p);
            return p;
        }
    }

    return new Node(constructorKey, Ref(this));
}
