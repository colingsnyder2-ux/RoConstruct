// from server: 82% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 004db130  unit: RBX::ViewNew::ViewRbxGfx  size: 232 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004db130
//
// 004db130  6aff                 push -1
// 004db132  6808a17c00           push 0x7ca108
// 004db137  64a100000000         mov eax, dword ptr fs:[0]
// 004db13d  50                   push eax
// 004db13e  64892500000000       mov dword ptr fs:[0], esp
// 004db145  83ec08               sub esp, 8
// 004db148  53                   push ebx
// 004db149  55                   push ebp
// 004db14a  56                   push esi
// 004db14b  57                   push edi
// 004db14c  6844279700           push 0x972744
// 004db151  6810984d00           push 0x4d9810
// 004db156  e8d5c10700           call 0x557330
// 004db15b  8b352c279700         mov esi, dword ptr [0x97272c]
// 004db161  8d5e10               lea ebx, [esi + 0x10]
// 004db164  83c408               add esp, 8
// 004db167  8bcb                 mov ecx, ebx
// 004db169  895c2410             mov dword ptr [esp + 0x10], ebx
// 004db16d  e81e7f0800           call 0x563090
// 004db172  c644241401           mov byte ptr [esp + 0x14], 1
// 004db177  33ed                 xor ebp, ebp
// 004db179  8bce                 mov ecx, esi
// 004db17b  896c2420             mov dword ptr [esp + 0x20], ebp
// 004db17f  e81cddffff           call 0x4d8ea0
// 004db184  6a10                 push 0x10
// 004db186  6a50                 push 0x50
// 004db188  c7460c14000000       mov dword ptr [esi + 0xc], 0x14
// 004db18f  896e04               mov dword ptr [esi + 4], ebp
// 004db192  e8e9d30200           call 0x508580
// 004db197  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 004db19a  03c9                 add ecx, ecx
// 004db19c  03c9                 add ecx, ecx
// 004db19e  51                   push ecx
// 004db19f  55                   push ebp
// 004db1a0  50                   push eax
// 004db1a1  894608               mov dword ptr [esi + 8], eax
// 004db1a4  e887d80200           call 0x508a30
// 004db1a9  8b5634               mov edx, dword ptr [esi + 0x34]
// 004db1ac  8b4204               mov eax, dword ptr [edx + 4]
// 004db1af  8d7e1c               lea edi, [esi + 0x1c]
// 004db1b2  83c414               add esp, 0x14
// 004db1b5  50                   push eax
// 004db1b6  8bcf                 mov ecx, edi
// 004db1b8  e823d2ffff           call 0x4d83e0
// 004db1bd  8b4718               mov eax, dword ptr [edi + 0x18]
// 004db1c0  894004               mov dword ptr [eax + 4], eax
// 004db1c3  8b4718               mov eax, dword ptr [edi + 0x18]
// 004db1c6  896f1c               mov dword ptr [edi + 0x1c], ebp
// 004db1c9  8900                 mov dword ptr [eax], eax
// 004db1cb  8b7f18               mov edi, dword ptr [edi + 0x18]
// 004db1ce  897f08               mov dword ptr [edi + 8], edi
// 004db1d1  8b4e54               mov ecx, dword ptr [esi + 0x54]
// 004db1d4  8b5104               mov edx, dword ptr [ecx + 4]
// 004db1d7  83c63c               add esi, 0x3c
// 004db1da  52                   push edx
// 004db1db  8bce                 mov ecx, esi
// 004db1dd  e88ed2ffff           call 0x4d8470
// 004db1e2  8b4618               mov eax, dword ptr [esi + 0x18]
// 004db1e5  894004               mov dword ptr [eax + 4], eax
// 004db1e8  8b4618               mov eax, dword ptr [esi + 0x18]
// 004db1eb  896e1c               mov dword ptr [esi + 0x1c], ebp
// 004db1ee  8900                 mov dword ptr [eax], eax
// 004db1f0  8b7618               mov esi, dword ptr [esi + 0x18]
// 004db1f3  8bcb                 mov ecx, ebx
// 004db1f5  897608               mov dword ptr [esi + 8], esi
// 004db1f8  c7442420ffffffff     mov dword ptr [esp + 0x20], 0xffffffff
// 004db200  e8db7e0800           call 0x5630e0
// 004db205  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004db209  5f                   pop edi
// 004db20a  5e                   pop esi
// 004db20b  5d                   pop ebp
// 004db20c  5b                   pop ebx
// 004db20d  64890d00000000       mov dword ptr fs:[0], ecx
// 004db214  83c414               add esp, 0x14
// 004db217  c3                   ret 

struct Mutex {
    unsigned char data[12];
    void lock();
    void unlock();
};

struct Lock {
    Mutex* mutex;
    bool active;
    Lock(Mutex*);
    ~Lock();
};

Lock::Lock(Mutex* p) : mutex(p) {
    mutex->lock();
    active = true;
}

Lock::~Lock() {
    if (active)
        mutex->unlock();
}

struct Node {
    Node* left;
    Node* parent;
    Node* right;
};

struct TreeA {
    unsigned char data[24];
    Node* head;
    unsigned int count;
    void erase(Node*);
};

struct TreeB {
    unsigned char data[24];
    Node* head;
    unsigned int count;
    void erase(Node*);
};

struct State {
    unsigned int unused;
    unsigned int count;
    void* storage;
    unsigned int capacity;
    Mutex mutex;
    TreeA first;
    TreeB second;
    void release();
};

extern State* state;
extern int initializationFlag;

void __cdecl initialize();
void __cdecl ensureInitialized(void (__cdecl*)(), int*);
void* __cdecl allocate(unsigned int, unsigned int);
void* __cdecl fill(void*, int, unsigned int);

void __cdecl reset()
{
    ensureInitialized(initialize, &initializationFlag);
    State* p = state;
    Lock lock(&p->mutex);

    p->release();
    p->capacity = 20;
    p->count = 0;
    p->storage = allocate(80, 16);
    fill(p->storage, 0, p->capacity * 4);

    TreeA* a = &p->first;
    a->erase(a->head->parent);
    a->head->parent = a->head;
    a->count = 0;
    a->head->left = a->head;
    Node* n = a->head;
    n->right = n;

    TreeB* b = &p->second;
    b->erase(b->head->parent);
    b->head->parent = b->head;
    b->count = 0;
    b->head->left = b->head;
    n = b->head;
    n->right = n;
}
