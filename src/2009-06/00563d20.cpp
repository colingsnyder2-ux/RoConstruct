// from server: 78% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 004e5670  unit: RBX::ViewNew::BrickMesh  size: 147 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004e5670
//
// 004e5670  6aff                 push -1
// 004e5672  6808a17c00           push 0x7ca108
// 004e5677  64a100000000         mov eax, dword ptr fs:[0]
// 004e567d  50                   push eax
// 004e567e  64892500000000       mov dword ptr fs:[0], esp
// 004e5685  83ec08               sub esp, 8
// 004e5688  56                   push esi
// 004e5689  57                   push edi
// 004e568a  6870289700           push 0x972870
// 004e568f  6860534e00           push 0x4e5360
// 004e5694  e8971c0700           call 0x557330
// 004e5699  8b3554279700         mov esi, dword ptr [0x972754]
// 004e569f  8d7e20               lea edi, [esi + 0x20]
// 004e56a2  83c408               add esp, 8
// 004e56a5  8bcf                 mov ecx, edi
// 004e56a7  897c2408             mov dword ptr [esp + 8], edi
// 004e56ab  e8e0d90700           call 0x563090
// 004e56b0  c644240c01           mov byte ptr [esp + 0xc], 1
// 004e56b5  8b4618               mov eax, dword ptr [esi + 0x18]
// 004e56b8  8b4804               mov ecx, dword ptr [eax + 4]
// 004e56bb  51                   push ecx
// 004e56bc  8bce                 mov ecx, esi
// 004e56be  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 004e56c6  e8657dffff           call 0x4dd430
// 004e56cb  8b4618               mov eax, dword ptr [esi + 0x18]
// 004e56ce  894004               mov dword ptr [eax + 4], eax
// 004e56d1  8b4618               mov eax, dword ptr [esi + 0x18]
// 004e56d4  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 004e56db  8900                 mov dword ptr [eax], eax
// 004e56dd  8b7618               mov esi, dword ptr [esi + 0x18]
// 004e56e0  8bcf                 mov ecx, edi
// 004e56e2  897608               mov dword ptr [esi + 8], esi
// 004e56e5  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 004e56ed  e8eed90700           call 0x5630e0
// 004e56f2  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004e56f6  5f                   pop edi
// 004e56f7  5e                   pop esi
// 004e56f8  64890d00000000       mov dword ptr fs:[0], ecx
// 004e56ff  83c414               add esp, 0x14
// 004e5702  c3                   ret 

struct Lock {
    int value;
    unsigned char flag;
    int count;
    void acquire();
    void release();
};

struct Node {
    Node *left;
    Node *parent;
    Node *right;
};

struct Container {
    unsigned char padding[24];
    Node *head;
    unsigned int size;
    Lock lock;
    void erase(Node *);
};

struct Guard {
    Lock *lock;
    bool held;
    Guard(Lock *);
    ~Guard();
};

inline Guard::Guard(Lock *p) : lock(p)
{
    lock->acquire();
    held = true;
}

inline Guard::~Guard()
{
    if (held)
        lock->release();
}

extern Container *container;
extern int initialization;
extern void __cdecl initialize();
extern void __cdecl ensureInitialized(void (__cdecl *)(), void *);

void __cdecl func_004e5670()
{
    ensureInitialized(initialize, &initialization);
    Container *p = container;
    Guard guard(&p->lock);
    p->erase(p->head->parent);
    p->head->parent = p->head;
    p->size = 0;
    p->head->left = p->head;
    p->head->right = p->head;
}
