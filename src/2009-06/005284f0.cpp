// from server: 80% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 004db220  unit: RBX::ViewNew::ViewRbxGfx  size: 232 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004db220
//
// 004db220  6aff                 push -1
// 004db222  6808a17c00           push 0x7ca108
// 004db227  64a100000000         mov eax, dword ptr fs:[0]
// 004db22d  50                   push eax
// 004db22e  64892500000000       mov dword ptr fs:[0], esp
// 004db235  83ec08               sub esp, 8
// 004db238  53                   push ebx
// 004db239  55                   push ebp
// 004db23a  56                   push esi
// 004db23b  57                   push edi
// 004db23c  6848279700           push 0x972748
// 004db241  6870984d00           push 0x4d9870
// 004db246  e8e5c00700           call 0x557330
// 004db24b  8b3530279700         mov esi, dword ptr [0x972730]
// 004db251  8d5e10               lea ebx, [esi + 0x10]
// 004db254  83c408               add esp, 8
// 004db257  8bcb                 mov ecx, ebx
// 004db259  895c2410             mov dword ptr [esp + 0x10], ebx
// 004db25d  e82e7e0800           call 0x563090
// 004db262  c644241401           mov byte ptr [esp + 0x14], 1
// 004db267  33ed                 xor ebp, ebp
// 004db269  8bce                 mov ecx, esi
// 004db26b  896c2420             mov dword ptr [esp + 0x20], ebp
// 004db26f  e89cdcffff           call 0x4d8f10
// 004db274  6a10                 push 0x10
// 004db276  6a50                 push 0x50
// 004db278  c7460c14000000       mov dword ptr [esi + 0xc], 0x14
// 004db27f  896e04               mov dword ptr [esi + 4], ebp
// 004db282  e8f9d20200           call 0x508580
// 004db287  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 004db28a  03c9                 add ecx, ecx
// 004db28c  03c9                 add ecx, ecx
// 004db28e  51                   push ecx
// 004db28f  55                   push ebp
// 004db290  50                   push eax
// 004db291  894608               mov dword ptr [esi + 8], eax
// 004db294  e897d70200           call 0x508a30
// 004db299  8b5634               mov edx, dword ptr [esi + 0x34]
// 004db29c  8b4204               mov eax, dword ptr [edx + 4]
// 004db29f  8d7e1c               lea edi, [esi + 0x1c]
// 004db2a2  83c414               add esp, 0x14
// 004db2a5  50                   push eax
// 004db2a6  8bcf                 mov ecx, edi
// 004db2a8  e833d1ffff           call 0x4d83e0
// 004db2ad  8b4718               mov eax, dword ptr [edi + 0x18]
// 004db2b0  894004               mov dword ptr [eax + 4], eax
// 004db2b3  8b4718               mov eax, dword ptr [edi + 0x18]
// 004db2b6  896f1c               mov dword ptr [edi + 0x1c], ebp
// 004db2b9  8900                 mov dword ptr [eax], eax
// 004db2bb  8b7f18               mov edi, dword ptr [edi + 0x18]
// 004db2be  897f08               mov dword ptr [edi + 8], edi
// 004db2c1  8b4e54               mov ecx, dword ptr [esi + 0x54]
// 004db2c4  8b5104               mov edx, dword ptr [ecx + 4]
// 004db2c7  83c63c               add esi, 0x3c
// 004db2ca  52                   push edx
// 004db2cb  8bce                 mov ecx, esi
// 004db2cd  e89ed1ffff           call 0x4d8470
// 004db2d2  8b4618               mov eax, dword ptr [esi + 0x18]
// 004db2d5  894004               mov dword ptr [eax + 4], eax
// 004db2d8  8b4618               mov eax, dword ptr [esi + 0x18]
// 004db2db  896e1c               mov dword ptr [esi + 0x1c], ebp
// 004db2de  8900                 mov dword ptr [eax], eax
// 004db2e0  8b7618               mov esi, dword ptr [esi + 0x18]
// 004db2e3  8bcb                 mov ecx, ebx
// 004db2e5  897608               mov dword ptr [esi + 8], esi
// 004db2e8  c7442420ffffffff     mov dword ptr [esp + 0x20], 0xffffffff
// 004db2f0  e8eb7d0800           call 0x5630e0
// 004db2f5  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004db2f9  5f                   pop edi
// 004db2fa  5e                   pop esi
// 004db2fb  5d                   pop ebp
// 004db2fc  5b                   pop ebx
// 004db2fd  64890d00000000       mov dword ptr fs:[0], ecx
// 004db304  83c414               add esp, 0x14
// 004db307  c3                   ret 

struct Mutex {
    void lock();
    void unlock();
};

struct Lock {
    Mutex* mutex;
    bool held;

    Lock(Mutex& m) : mutex(&m) {
        mutex->lock();
        held = true;
    }

    ~Lock() {
        if (held)
            mutex->unlock();
    }
};

struct Node {
    Node* left;
    Node* parent;
    Node* right;
};

struct TreeA {
    unsigned char data[24];
    Node* head;
    unsigned int size;
    void erase(Node*);
};

struct TreeB {
    unsigned char data[24];
    Node* head;
    unsigned int size;
    void erase(Node*);
};

struct State {
    unsigned int field0;
    unsigned int size;
    void* buffer;
    unsigned int capacity;
    Mutex mutex;
    unsigned char padding[11];
    TreeA first;
    TreeB second;

    void clear();
};

extern void __cdecl initialize(void (__cdecl*)(), void*);
extern void __cdecl callback();
extern void* __cdecl allocate(unsigned int, unsigned int);
extern void* __cdecl fill(void*, int, unsigned int);

void reset()
{
    initialize(callback, reinterpret_cast<void*>(0x972748));

    State* state = *reinterpret_cast<State**>(0x972730);
    Lock lock(state->mutex);

    state->clear();
    state->capacity = 20;
    state->size = 0;
    state->buffer = allocate(80, 16);
    fill(state->buffer, 0, state->capacity * 4);

    TreeA* first = &state->first;
    first->erase(first->head->parent);
    first->head->parent = first->head;
    first->size = 0;
    first->head->left = first->head;
    first->head->right = first->head;

    TreeB* second = &state->second;
    second->erase(second->head->parent);
    second->head->parent = second->head;
    second->size = 0;
    second->head->left = second->head;
    second->head->right = second->head;
}
