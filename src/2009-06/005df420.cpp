// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00561850  unit: RBX::VContentProvider::?$DescribedNonCreatable  size: 129 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00561850
//
// 00561850  6aff                 push -1
// 00561852  68a8057d00           push 0x7d05a8
// 00561857  64a100000000         mov eax, dword ptr fs:[0]
// 0056185d  50                   push eax
// 0056185e  64892500000000       mov dword ptr fs:[0], esp
// 00561865  51                   push ecx
// 00561866  56                   push esi
// 00561867  57                   push edi
// 00561868  8bf9                 mov edi, ecx
// 0056186a  8b4714               mov eax, dword ptr [edi + 0x14]
// 0056186d  8b30                 mov esi, dword ptr [eax]
// 0056186f  8900                 mov dword ptr [eax], eax
// 00561871  8b4714               mov eax, dword ptr [edi + 0x14]
// 00561874  894004               mov dword ptr [eax + 4], eax
// 00561877  c7471800000000       mov dword ptr [edi + 0x18], 0
// 0056187e  3b7714               cmp esi, dword ptr [edi + 0x14]
// 00561881  743d                 je 0x5618c0
// 00561883  53                   push ebx
// 00561884  55                   push ebp
// 00561885  8b1e                 mov ebx, dword ptr [esi]
// 00561887  8d6e08               lea ebp, [esi + 8]
// 0056188a  896c2410             mov dword ptr [esp + 0x10], ebp
// 0056188e  8d4d20               lea ecx, [ebp + 0x20]
// 00561891  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 00561899  e8c2f2ffff           call 0x560b60
// 0056189e  8bcd                 mov ecx, ebp
// 005618a0  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 005618a8  ff1568248000         call dword ptr [0x802468]
// 005618ae  56                   push esi
// 005618af  e8c6ed1300           call 0x6a067a
// 005618b4  83c404               add esp, 4
// 005618b7  8bf3                 mov esi, ebx
// 005618b9  3b5f14               cmp ebx, dword ptr [edi + 0x14]
// 005618bc  75c7                 jne 0x561885
// 005618be  5d                   pop ebp
// 005618bf  5b                   pop ebx
// 005618c0  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005618c4  5f                   pop edi
// 005618c5  5e                   pop esi
// 005618c6  64890d00000000       mov dword ptr fs:[0], ecx
// 005618cd  83c410               add esp, 0x10
// 005618d0  c3                   ret 

struct String;
extern void (__thiscall *stringDestroy)(String *);
extern void __cdecl operator delete(void *);

struct String {
    char storage[32];
    ~String();
};

__forceinline String::~String() {
    stringDestroy(this);
}

struct Tail {
    ~Tail();
};

struct Value {
    String text;
    Tail tail;
    ~Value();
};

__forceinline Value::~Value() {
}

struct Node {
    Node *next;
    Node *previous;
    Value value;
};

struct S {
    char reserved[20];
    Node *head;
    unsigned int count;

    void clear();
};

void S::clear() {
    Node *current = head->next;
    head->next = head;
    head->previous = head;
    count = 0;

    while (current != head) {
        Node *next = current->next;
        current->value.~Value();
        operator delete(current);
        current = next;
    }
}
