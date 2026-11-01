// from server: 82% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 004db310  unit: RBX::ViewNew::ViewRbxGfx  size: 232 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004db310
//
// 004db310  6aff                 push -1
// 004db312  6808a17c00           push 0x7ca108
// 004db317  64a100000000         mov eax, dword ptr fs:[0]
// 004db31d  50                   push eax
// 004db31e  64892500000000       mov dword ptr fs:[0], esp
// 004db325  83ec08               sub esp, 8
// 004db328  53                   push ebx
// 004db329  55                   push ebp
// 004db32a  56                   push esi
// 004db32b  57                   push edi
// 004db32c  684c279700           push 0x97274c
// 004db331  68d0984d00           push 0x4d98d0
// 004db336  e8f5bf0700           call 0x557330
// 004db33b  8b3534279700         mov esi, dword ptr [0x972734]
// 004db341  8d5e10               lea ebx, [esi + 0x10]
// 004db344  83c408               add esp, 8
// 004db347  8bcb                 mov ecx, ebx
// 004db349  895c2410             mov dword ptr [esp + 0x10], ebx
// 004db34d  e83e7d0800           call 0x563090
// 004db352  c644241401           mov byte ptr [esp + 0x14], 1
// 004db357  33ed                 xor ebp, ebp
// 004db359  8bce                 mov ecx, esi
// 004db35b  896c2420             mov dword ptr [esp + 0x20], ebp
// 004db35f  e81cdcffff           call 0x4d8f80
// 004db364  6a10                 push 0x10
// 004db366  6a50                 push 0x50
// 004db368  c7460c14000000       mov dword ptr [esi + 0xc], 0x14
// 004db36f  896e04               mov dword ptr [esi + 4], ebp
// 004db372  e809d20200           call 0x508580
// 004db377  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 004db37a  03c9                 add ecx, ecx
// 004db37c  03c9                 add ecx, ecx
// 004db37e  51                   push ecx
// 004db37f  55                   push ebp
// 004db380  50                   push eax
// 004db381  894608               mov dword ptr [esi + 8], eax
// 004db384  e8a7d60200           call 0x508a30
// 004db389  8b5634               mov edx, dword ptr [esi + 0x34]
// 004db38c  8b4204               mov eax, dword ptr [edx + 4]
// 004db38f  8d7e1c               lea edi, [esi + 0x1c]
// 004db392  83c414               add esp, 0x14
// 004db395  50                   push eax
// 004db396  8bcf                 mov ecx, edi
// 004db398  e843d0ffff           call 0x4d83e0
// 004db39d  8b4718               mov eax, dword ptr [edi + 0x18]
// 004db3a0  894004               mov dword ptr [eax + 4], eax
// 004db3a3  8b4718               mov eax, dword ptr [edi + 0x18]
// 004db3a6  896f1c               mov dword ptr [edi + 0x1c], ebp
// 004db3a9  8900                 mov dword ptr [eax], eax
// 004db3ab  8b7f18               mov edi, dword ptr [edi + 0x18]
// 004db3ae  897f08               mov dword ptr [edi + 8], edi
// 004db3b1  8b4e54               mov ecx, dword ptr [esi + 0x54]
// 004db3b4  8b5104               mov edx, dword ptr [ecx + 4]
// 004db3b7  83c63c               add esi, 0x3c
// 004db3ba  52                   push edx
// 004db3bb  8bce                 mov ecx, esi
// 004db3bd  e8aed0ffff           call 0x4d8470
// 004db3c2  8b4618               mov eax, dword ptr [esi + 0x18]
// 004db3c5  894004               mov dword ptr [eax + 4], eax
// 004db3c8  8b4618               mov eax, dword ptr [esi + 0x18]
// 004db3cb  896e1c               mov dword ptr [esi + 0x1c], ebp
// 004db3ce  8900                 mov dword ptr [eax], eax
// 004db3d0  8b7618               mov esi, dword ptr [esi + 0x18]
// 004db3d3  8bcb                 mov ecx, ebx
// 004db3d5  897608               mov dword ptr [esi + 8], esi
// 004db3d8  c7442420ffffffff     mov dword ptr [esp + 0x20], 0xffffffff
// 004db3e0  e8fb7c0800           call 0x5630e0
// 004db3e5  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004db3e9  5f                   pop edi
// 004db3ea  5e                   pop esi
// 004db3eb  5d                   pop ebp
// 004db3ec  5b                   pop ebx
// 004db3ed  64890d00000000       mov dword ptr fs:[0], ecx
// 004db3f4  83c414               add esp, 0x14
// 004db3f7  c3                   ret 

struct Mutex {
    unsigned char storage[12];
    void lock();
    void unlock();
};

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
    void release();
};

extern State* state;
extern int initialization;
extern void __cdecl initialize();
extern void __cdecl initializeOnce(void (__cdecl*)(), int*);
extern void* __cdecl allocateAligned(unsigned int, unsigned int);
extern void* __cdecl fillMemory(void*, int, unsigned int);

struct Guard {
    Mutex* mutex;
    bool locked;

    Guard(Mutex* p) : mutex(p) {
        mutex->lock();
        locked = true;
    }

    ~Guard() {
        if (locked)
            mutex->unlock();
    }
};

void reset()
{
    initializeOnce(initialize, &initialization);
    State* p = state;
    Guard guard(&p->mutex);

    p->release();
    p->capacity = 20;
    p->count = 0;
    p->data = allocateAligned(80, 16);
    fillMemory(p->data, 0, p->capacity * 4);

    TreeA* a = &p->first;
    a->erase(a->head->parent);
    a->head->parent = a->head;
    a->size = 0;
    a->head->left = a->head;
    a->head->right = a->head;

    TreeB* b = &p->second;
    b->erase(b->head->parent);
    b->head->parent = b->head;
    b->size = 0;
    b->head->left = b->head;
    b->head->right = b->head;
}
