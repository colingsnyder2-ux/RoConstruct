// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0056e430  unit: G3D::VVector2int16::?$TypedPropertyDescriptor  size: 224 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0056e430
//
// 0056e430  83ec08               sub esp, 8
// 0056e433  53                   push ebx
// 0056e434  55                   push ebp
// 0056e435  56                   push esi
// 0056e436  8b3534539700         mov esi, dword ptr [0x975334]
// 0056e43c  57                   push edi
// 0056e43d  6a28                 push 0x28
// 0056e43f  894c2418             mov dword ptr [esp + 0x18], ecx
// 0056e443  e8d8241300           call 0x6a0920
// 0056e448  33db                 xor ebx, ebx
// 0056e44a  83c404               add esp, 4
// 0056e44d  3bc3                 cmp eax, ebx
// 0056e44f  7418                 je 0x56e469
// 0056e451  8918                 mov dword ptr [eax], ebx
// 0056e453  895804               mov dword ptr [eax + 4], ebx
// 0056e456  895808               mov dword ptr [eax + 8], ebx
// 0056e459  897010               mov dword ptr [eax + 0x10], esi
// 0056e45c  895814               mov dword ptr [eax + 0x14], ebx
// 0056e45f  895820               mov dword ptr [eax + 0x20], ebx
// 0056e462  895824               mov dword ptr [eax + 0x24], ebx
// 0056e465  8be8                 mov ebp, eax
// 0056e467  eb02                 jmp 0x56e46b
// 0056e469  33ed                 xor ebp, ebp
// 0056e46b  8b742420             mov esi, dword ptr [esp + 0x20]
// 0056e46f  8b4608               mov eax, dword ptr [esi + 8]
// 0056e472  3bc3                 cmp eax, ebx
// 0056e474  7505                 jne 0x56e47b
// 0056e476  896e04               mov dword ptr [esi + 4], ebp
// 0056e479  eb02                 jmp 0x56e47d
// 0056e47b  8928                 mov dword ptr [eax], ebp
// 0056e47d  896e08               mov dword ptr [esi + 8], ebp
// 0056e480  8b3d80539700         mov edi, dword ptr [0x975380]
// 0056e486  6a28                 push 0x28
// 0056e488  e893241300           call 0x6a0920
// 0056e48d  83c404               add esp, 4
// 0056e490  3bc3                 cmp eax, ebx
// 0056e492  7418                 je 0x56e4ac
// 0056e494  8918                 mov dword ptr [eax], ebx
// 0056e496  895804               mov dword ptr [eax + 4], ebx
// 0056e499  895808               mov dword ptr [eax + 8], ebx
// 0056e49c  897810               mov dword ptr [eax + 0x10], edi
// 0056e49f  895814               mov dword ptr [eax + 0x14], ebx
// 0056e4a2  895820               mov dword ptr [eax + 0x20], ebx
// 0056e4a5  895824               mov dword ptr [eax + 0x24], ebx
// 0056e4a8  8bf8                 mov edi, eax
// 0056e4aa  eb02                 jmp 0x56e4ae
// 0056e4ac  33ff                 xor edi, edi
// 0056e4ae  8b4608               mov eax, dword ptr [esi + 8]
// 0056e4b1  3bc3                 cmp eax, ebx
// 0056e4b3  7505                 jne 0x56e4ba
// 0056e4b5  897e04               mov dword ptr [esi + 4], edi
// 0056e4b8  eb02                 jmp 0x56e4bc
// 0056e4ba  8938                 mov dword ptr [eax], edi
// 0056e4bc  8b442414             mov eax, dword ptr [esp + 0x14]
// 0056e4c0  897e08               mov dword ptr [esi + 8], edi
// 0056e4c3  8b4818               mov ecx, dword ptr [eax + 0x18]
// 0056e4c6  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0056e4ca  8b11                 mov edx, dword ptr [ecx]
// 0056e4cc  8b5208               mov edx, dword ptr [edx + 8]
// 0056e4cf  50                   push eax
// 0056e4d0  8d442414             lea eax, [esp + 0x14]
// 0056e4d4  50                   push eax
// 0056e4d5  ffd2                 call edx
// 0056e4d7  0fbf5c2410           movsx ebx, word ptr [esp + 0x10]
// 0056e4dc  8d7510               lea esi, [ebp + 0x10]
// 0056e4df  8bce                 mov ecx, esi
// 0056e4e1  e8eadd0000           call 0x57c2d0
// 0056e4e6  895e08               mov dword ptr [esi + 8], ebx
// 0056e4e9  bd05000000           mov ebp, 5
// 0056e4ee  896e04               mov dword ptr [esi + 4], ebp
// 0056e4f1  0fbf5c2412           movsx ebx, word ptr [esp + 0x12]
// 0056e4f6  8d7710               lea esi, [edi + 0x10]
// 0056e4f9  8bce                 mov ecx, esi
// 0056e4fb  e8d0dd0000           call 0x57c2d0
// 0056e500  5f                   pop edi
// 0056e501  895e08               mov dword ptr [esi + 8], ebx
// 0056e504  896e04               mov dword ptr [esi + 4], ebp
// 0056e507  5e                   pop esi
// 0056e508  5d                   pop ebp
// 0056e509  5b                   pop ebx
// 0056e50a  83c408               add esp, 8
// 0056e50d  c20800               ret 8

void* __cdecl operator new(unsigned int);

extern unsigned int firstType;
extern unsigned int secondType;

struct Value {
    volatile unsigned int type;
    int tag;
    int number;
    unsigned int reserved;
    unsigned int extra1;
    unsigned int extra2;

    void clear();
};

struct Node {
    Node* volatile next;
    volatile unsigned int field4;
    volatile unsigned int field8;
    unsigned int field12;
    Value value;

    Node(unsigned int type);
};

inline Node::Node(unsigned int type)
{
    next = 0;
    field4 = 0;
    field8 = 0;
    value.type = type;
    value.tag = 0;
    value.extra1 = 0;
    value.extra2 = 0;
}

struct List {
    unsigned int field0;
    Node* first;
    Node* last;
};

struct Pair {
    short x;
    short y;
};

struct Accessor;

struct AccessorTable {
    void* unused[2];
    Pair* (__thiscall *get)(Accessor*, Pair*, void*);
};

struct Accessor {
    AccessorTable* table;
};

struct S {
    unsigned char padding[24];
    Accessor* accessor;

    void f(void* object, List* list);
};

void S::f(void* object, List* list)
{
    unsigned int type1 = firstType;
    Node* a = new Node(type1);

    if (!list->last)
        list->first = a;
    else
        list->last->next = a;
    list->last = a;

    unsigned int type2 = secondType;
    Node* b = new Node(type2);

    if (!list->last)
        list->first = b;
    else
        list->last->next = b;
    list->last = b;

    Pair result;
    accessor->table->get(accessor, &result, object);

    int x = result.x;
    Value* value = &a->value;
    value->clear();
    value->number = x;
    value->tag = 5;

    int y = result.y;
    value = &b->value;
    value->clear();
    value->number = y;
    value->tag = 5;
}
