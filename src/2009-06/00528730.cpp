// from server: 80% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 004db400  unit: RBX::ViewNew::ViewRbxGfx  size: 232 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004db400
//
// 004db400  6aff                 push -1
// 004db402  6808a17c00           push 0x7ca108
// 004db407  64a100000000         mov eax, dword ptr fs:[0]
// 004db40d  50                   push eax
// 004db40e  64892500000000       mov dword ptr fs:[0], esp
// 004db415  83ec08               sub esp, 8
// 004db418  53                   push ebx
// 004db419  55                   push ebp
// 004db41a  56                   push esi
// 004db41b  57                   push edi
// 004db41c  6850279700           push 0x972750
// 004db421  6830994d00           push 0x4d9930
// 004db426  e805bf0700           call 0x557330
// 004db42b  8b3538279700         mov esi, dword ptr [0x972738]
// 004db431  8d5e10               lea ebx, [esi + 0x10]
// 004db434  83c408               add esp, 8
// 004db437  8bcb                 mov ecx, ebx
// 004db439  895c2410             mov dword ptr [esp + 0x10], ebx
// 004db43d  e84e7c0800           call 0x563090
// 004db442  c644241401           mov byte ptr [esp + 0x14], 1
// 004db447  33ed                 xor ebp, ebp
// 004db449  8bce                 mov ecx, esi
// 004db44b  896c2420             mov dword ptr [esp + 0x20], ebp
// 004db44f  e89cdbffff           call 0x4d8ff0
// 004db454  6a10                 push 0x10
// 004db456  6a50                 push 0x50
// 004db458  c7460c14000000       mov dword ptr [esi + 0xc], 0x14
// 004db45f  896e04               mov dword ptr [esi + 4], ebp
// 004db462  e819d10200           call 0x508580
// 004db467  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 004db46a  03c9                 add ecx, ecx
// 004db46c  03c9                 add ecx, ecx
// 004db46e  51                   push ecx
// 004db46f  55                   push ebp
// 004db470  50                   push eax
// 004db471  894608               mov dword ptr [esi + 8], eax
// 004db474  e8b7d50200           call 0x508a30
// 004db479  8b5634               mov edx, dword ptr [esi + 0x34]
// 004db47c  8b4204               mov eax, dword ptr [edx + 4]
// 004db47f  8d7e1c               lea edi, [esi + 0x1c]
// 004db482  83c414               add esp, 0x14
// 004db485  50                   push eax
// 004db486  8bcf                 mov ecx, edi
// 004db488  e853cfffff           call 0x4d83e0
// 004db48d  8b4718               mov eax, dword ptr [edi + 0x18]
// 004db490  894004               mov dword ptr [eax + 4], eax
// 004db493  8b4718               mov eax, dword ptr [edi + 0x18]
// 004db496  896f1c               mov dword ptr [edi + 0x1c], ebp
// 004db499  8900                 mov dword ptr [eax], eax
// 004db49b  8b7f18               mov edi, dword ptr [edi + 0x18]
// 004db49e  897f08               mov dword ptr [edi + 8], edi
// 004db4a1  8b4e54               mov ecx, dword ptr [esi + 0x54]
// 004db4a4  8b5104               mov edx, dword ptr [ecx + 4]
// 004db4a7  83c63c               add esi, 0x3c
// 004db4aa  52                   push edx
// 004db4ab  8bce                 mov ecx, esi
// 004db4ad  e8becfffff           call 0x4d8470
// 004db4b2  8b4618               mov eax, dword ptr [esi + 0x18]
// 004db4b5  894004               mov dword ptr [eax + 4], eax
// 004db4b8  8b4618               mov eax, dword ptr [esi + 0x18]
// 004db4bb  896e1c               mov dword ptr [esi + 0x1c], ebp
// 004db4be  8900                 mov dword ptr [eax], eax
// 004db4c0  8b7618               mov esi, dword ptr [esi + 0x18]
// 004db4c3  8bcb                 mov ecx, ebx
// 004db4c5  897608               mov dword ptr [esi + 8], esi
// 004db4c8  c7442420ffffffff     mov dword ptr [esp + 0x20], 0xffffffff
// 004db4d0  e80b7c0800           call 0x5630e0
// 004db4d5  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004db4d9  5f                   pop edi
// 004db4da  5e                   pop esi
// 004db4db  5d                   pop ebp
// 004db4dc  5b                   pop ebx
// 004db4dd  64890d00000000       mov dword ptr fs:[0], ecx
// 004db4e4  83c414               add esp, 0x14
// 004db4e7  c3                   ret 

extern void __cdecl initialize(void (__cdecl*)(), void*);
extern void __cdecl initializeCallback();
extern void* __cdecl allocate(unsigned int, unsigned int);
extern void* __cdecl fill(void*, int, unsigned int);

struct Mutex {
    unsigned char data[12];
    void acquire();
    void release();
};

struct Guard {
    Mutex* mutex;
    bool acquired;
    Guard(Mutex*);
    ~Guard();
};

inline Guard::Guard(Mutex* p) : mutex(p) {
    mutex->acquire();
    acquired = true;
}

inline Guard::~Guard() {
    mutex->release();
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
    unsigned int unknown;
    unsigned int count;
    void* storage;
    unsigned int capacity;
    Mutex mutex;
    TreeA first;
    TreeB second;
    void clearStorage();
};

void resetState() {
    initialize(initializeCallback, reinterpret_cast<void*>(0x972750));
    State* s = *reinterpret_cast<State**>(0x972738);
    Guard guard(&s->mutex);
    s->clearStorage();
    s->capacity = 20;
    s->count = 0;
    s->storage = allocate(80, 16);
    fill(s->storage, 0, s->capacity * 4);

    TreeA* first = &s->first;
    first->erase(first->head->parent);
    first->head->parent = first->head;
    first->count = 0;
    first->head->left = first->head;
    first->head->right = first->head;

    TreeB* second = &s->second;
    second->erase(second->head->parent);
    second->head->parent = second->head;
    second->count = 0;
    second->head->left = second->head;
    second->head->right = second->head;
}
