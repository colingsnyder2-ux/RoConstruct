// from server: 82% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 004db040  unit: RBX::ViewNew::ViewRbxGfx  size: 232 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004db040
//
// 004db040  6aff                 push -1
// 004db042  6808a17c00           push 0x7ca108
// 004db047  64a100000000         mov eax, dword ptr fs:[0]
// 004db04d  50                   push eax
// 004db04e  64892500000000       mov dword ptr fs:[0], esp
// 004db055  83ec08               sub esp, 8
// 004db058  53                   push ebx
// 004db059  55                   push ebp
// 004db05a  56                   push esi
// 004db05b  57                   push edi
// 004db05c  6840279700           push 0x972740
// 004db061  68b0974d00           push 0x4d97b0
// 004db066  e8c5c20700           call 0x557330
// 004db06b  8b3528279700         mov esi, dword ptr [0x972728]
// 004db071  8d5e10               lea ebx, [esi + 0x10]
// 004db074  83c408               add esp, 8
// 004db077  8bcb                 mov ecx, ebx
// 004db079  895c2410             mov dword ptr [esp + 0x10], ebx
// 004db07d  e80e800800           call 0x563090
// 004db082  c644241401           mov byte ptr [esp + 0x14], 1
// 004db087  33ed                 xor ebp, ebp
// 004db089  8bce                 mov ecx, esi
// 004db08b  896c2420             mov dword ptr [esp + 0x20], ebp
// 004db08f  e89cddffff           call 0x4d8e30
// 004db094  6a10                 push 0x10
// 004db096  6a50                 push 0x50
// 004db098  c7460c14000000       mov dword ptr [esi + 0xc], 0x14
// 004db09f  896e04               mov dword ptr [esi + 4], ebp
// 004db0a2  e8d9d40200           call 0x508580
// 004db0a7  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 004db0aa  03c9                 add ecx, ecx
// 004db0ac  03c9                 add ecx, ecx
// 004db0ae  51                   push ecx
// 004db0af  55                   push ebp
// 004db0b0  50                   push eax
// 004db0b1  894608               mov dword ptr [esi + 8], eax
// 004db0b4  e877d90200           call 0x508a30
// 004db0b9  8b5634               mov edx, dword ptr [esi + 0x34]
// 004db0bc  8b4204               mov eax, dword ptr [edx + 4]
// 004db0bf  8d7e1c               lea edi, [esi + 0x1c]
// 004db0c2  83c414               add esp, 0x14
// 004db0c5  50                   push eax
// 004db0c6  8bcf                 mov ecx, edi
// 004db0c8  e813d3ffff           call 0x4d83e0
// 004db0cd  8b4718               mov eax, dword ptr [edi + 0x18]
// 004db0d0  894004               mov dword ptr [eax + 4], eax
// 004db0d3  8b4718               mov eax, dword ptr [edi + 0x18]
// 004db0d6  896f1c               mov dword ptr [edi + 0x1c], ebp
// 004db0d9  8900                 mov dword ptr [eax], eax
// 004db0db  8b7f18               mov edi, dword ptr [edi + 0x18]
// 004db0de  897f08               mov dword ptr [edi + 8], edi
// 004db0e1  8b4e54               mov ecx, dword ptr [esi + 0x54]
// 004db0e4  8b5104               mov edx, dword ptr [ecx + 4]
// 004db0e7  83c63c               add esi, 0x3c
// 004db0ea  52                   push edx
// 004db0eb  8bce                 mov ecx, esi
// 004db0ed  e87ed3ffff           call 0x4d8470
// 004db0f2  8b4618               mov eax, dword ptr [esi + 0x18]
// 004db0f5  894004               mov dword ptr [eax + 4], eax
// 004db0f8  8b4618               mov eax, dword ptr [esi + 0x18]
// 004db0fb  896e1c               mov dword ptr [esi + 0x1c], ebp
// 004db0fe  8900                 mov dword ptr [eax], eax
// 004db100  8b7618               mov esi, dword ptr [esi + 0x18]
// 004db103  8bcb                 mov ecx, ebx
// 004db105  897608               mov dword ptr [esi + 8], esi
// 004db108  c7442420ffffffff     mov dword ptr [esp + 0x20], 0xffffffff
// 004db110  e8cb7f0800           call 0x5630e0
// 004db115  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004db119  5f                   pop edi
// 004db11a  5e                   pop esi
// 004db11b  5d                   pop ebp
// 004db11c  5b                   pop ebx
// 004db11d  64890d00000000       mov dword ptr fs:[0], ecx
// 004db124  83c414               add esp, 0x14
// 004db127  c3                   ret 

struct Mutex {
    unsigned char storage[12];
    void lock();
    void unlock();
};

struct Lock {
    Mutex* mutex;
    bool held;
    Lock(Mutex*);
    ~Lock();
};

inline Lock::Lock(Mutex* p) : mutex(p) {
    mutex->lock();
    held = true;
}

inline Lock::~Lock() {
    if (held)
        mutex->unlock();
}

struct Node {
    Node* left;
    Node* parent;
    Node* right;
};

struct TreeA {
    unsigned char storage[24];
    Node* head;
    unsigned int size;
    void erase(Node*);
};

struct TreeB {
    unsigned char storage[24];
    Node* head;
    unsigned int size;
    void erase(Node*);
};

struct State {
    unsigned int field0;
    unsigned int count;
    void* data;
    unsigned int capacity;
    Mutex mutex;
    TreeA first;
    TreeB second;
    void clear();
};

extern State* state;
extern unsigned int initialization;
extern void __cdecl initializeState();
extern void __cdecl initialize(void (__cdecl*)(), unsigned int*);
extern void* __cdecl alignedAllocate(unsigned int, unsigned int);
extern void* __cdecl fill(void*, int, unsigned int);

void resetState() {
    initialize(initializeState, &initialization);
    State* p = state;
    Lock guard(&p->mutex);

    p->clear();
    p->capacity = 20;
    p->count = 0;
    p->data = alignedAllocate(80, 16);
    fill(p->data, 0, p->capacity * 4);

    TreeA* a = &p->first;
    a->erase(a->head->parent);
    a->head->parent = a->head;
    a->size = 0;
    a->head->left = a->head;
    Node* n = a->head;
    n->right = n;

    TreeB* b = &p->second;
    b->erase(b->head->parent);
    b->head->parent = b->head;
    b->size = 0;
    b->head->left = b->head;
    n = b->head;
    n->right = n;
}
