// from server: 82% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 004daf50  unit: RBX::ViewNew::ViewRbxGfx  size: 232 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004daf50
//
// 004daf50  6aff                 push -1
// 004daf52  6808a17c00           push 0x7ca108
// 004daf57  64a100000000         mov eax, dword ptr fs:[0]
// 004daf5d  50                   push eax
// 004daf5e  64892500000000       mov dword ptr fs:[0], esp
// 004daf65  83ec08               sub esp, 8
// 004daf68  53                   push ebx
// 004daf69  55                   push ebp
// 004daf6a  56                   push esi
// 004daf6b  57                   push edi
// 004daf6c  683c279700           push 0x97273c
// 004daf71  6850974d00           push 0x4d9750
// 004daf76  e8b5c30700           call 0x557330
// 004daf7b  8b3524279700         mov esi, dword ptr [0x972724]
// 004daf81  8d5e10               lea ebx, [esi + 0x10]
// 004daf84  83c408               add esp, 8
// 004daf87  8bcb                 mov ecx, ebx
// 004daf89  895c2410             mov dword ptr [esp + 0x10], ebx
// 004daf8d  e8fe800800           call 0x563090
// 004daf92  c644241401           mov byte ptr [esp + 0x14], 1
// 004daf97  33ed                 xor ebp, ebp
// 004daf99  8bce                 mov ecx, esi
// 004daf9b  896c2420             mov dword ptr [esp + 0x20], ebp
// 004daf9f  e81cdeffff           call 0x4d8dc0
// 004dafa4  6a10                 push 0x10
// 004dafa6  6a50                 push 0x50
// 004dafa8  c7460c14000000       mov dword ptr [esi + 0xc], 0x14
// 004dafaf  896e04               mov dword ptr [esi + 4], ebp
// 004dafb2  e8c9d50200           call 0x508580
// 004dafb7  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 004dafba  03c9                 add ecx, ecx
// 004dafbc  03c9                 add ecx, ecx
// 004dafbe  51                   push ecx
// 004dafbf  55                   push ebp
// 004dafc0  50                   push eax
// 004dafc1  894608               mov dword ptr [esi + 8], eax
// 004dafc4  e867da0200           call 0x508a30
// 004dafc9  8b5634               mov edx, dword ptr [esi + 0x34]
// 004dafcc  8b4204               mov eax, dword ptr [edx + 4]
// 004dafcf  8d7e1c               lea edi, [esi + 0x1c]
// 004dafd2  83c414               add esp, 0x14
// 004dafd5  50                   push eax
// 004dafd6  8bcf                 mov ecx, edi
// 004dafd8  e803d4ffff           call 0x4d83e0
// 004dafdd  8b4718               mov eax, dword ptr [edi + 0x18]
// 004dafe0  894004               mov dword ptr [eax + 4], eax
// 004dafe3  8b4718               mov eax, dword ptr [edi + 0x18]
// 004dafe6  896f1c               mov dword ptr [edi + 0x1c], ebp
// 004dafe9  8900                 mov dword ptr [eax], eax
// 004dafeb  8b7f18               mov edi, dword ptr [edi + 0x18]
// 004dafee  897f08               mov dword ptr [edi + 8], edi
// 004daff1  8b4e54               mov ecx, dword ptr [esi + 0x54]
// 004daff4  8b5104               mov edx, dword ptr [ecx + 4]
// 004daff7  83c63c               add esi, 0x3c
// 004daffa  52                   push edx
// 004daffb  8bce                 mov ecx, esi
// 004daffd  e86ed4ffff           call 0x4d8470
// 004db002  8b4618               mov eax, dword ptr [esi + 0x18]
// 004db005  894004               mov dword ptr [eax + 4], eax
// 004db008  8b4618               mov eax, dword ptr [esi + 0x18]
// 004db00b  896e1c               mov dword ptr [esi + 0x1c], ebp
// 004db00e  8900                 mov dword ptr [eax], eax
// 004db010  8b7618               mov esi, dword ptr [esi + 0x18]
// 004db013  8bcb                 mov ecx, ebx
// 004db015  897608               mov dword ptr [esi + 8], esi
// 004db018  c7442420ffffffff     mov dword ptr [esp + 0x20], 0xffffffff
// 004db020  e8bb800800           call 0x5630e0
// 004db025  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004db029  5f                   pop edi
// 004db02a  5e                   pop esi
// 004db02b  5d                   pop ebp
// 004db02c  5b                   pop ebx
// 004db02d  64890d00000000       mov dword ptr fs:[0], ecx
// 004db034  83c414               add esp, 0x14
// 004db037  c3                   ret 

struct Mutex {
    unsigned char data[12];
    void lock();
    void unlock();
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
    unsigned int unknown;
    unsigned int count;
    void* buffer;
    unsigned int capacity;
    Mutex mutex;
    TreeA first;
    TreeB second;
    void reset();
};

struct Lock {
    Mutex* mutex;
    bool acquired;
    Lock(Mutex*);
    ~Lock();
};

inline Lock::Lock(Mutex* p) : mutex(p) {
    mutex->lock();
    acquired = true;
}

inline Lock::~Lock() {
    if (acquired)
        mutex->unlock();
}

extern State* instance;
extern unsigned int initialization;
extern void __cdecl initialize();
extern void __cdecl ensureInitialized(void (__cdecl*)(), unsigned int*);
extern void* __cdecl allocate(unsigned int, unsigned int);
extern void* __cdecl fill(void*, int, unsigned int);

void __cdecl clearState() {
    ensureInitialized(initialize, &initialization);
    State* s = instance;
    Lock lock(&s->mutex);

    s->reset();
    s->capacity = 20;
    s->count = 0;
    s->buffer = allocate(80, 16);
    fill(s->buffer, 0, s->capacity * 4);

    TreeA* a = &s->first;
    a->erase(a->head->parent);
    a->head->parent = a->head;
    a->size = 0;
    a->head->left = a->head;
    a->head->right = a->head;

    TreeB* b = &s->second;
    b->erase(b->head->parent);
    b->head->parent = b->head;
    b->size = 0;
    b->head->left = b->head;
    b->head->right = b->head;
}
