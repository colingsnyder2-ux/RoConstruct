// from server: 94% by EspClaude
// roc-cl: 50727
// from server: 100% by king_originala
// roc 2008-06 0041a530  unit: Marshaller  size: 160 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0041a530
//
// 0041a530  6aff                 push -1
// 0041a532  6830df7b00           push 0x7bdf30
// 0041a537  64a100000000         mov eax, dword ptr fs:[0]
// 0041a53d  50                   push eax
// 0041a53e  64892500000000       mov dword ptr fs:[0], esp
// 0041a545  83ec08               sub esp, 8
// 0041a548  56                   push esi
// 0041a549  57                   push edi
// 0041a54a  8bf1                 mov esi, ecx
// 0041a54c  8d7e4c               lea edi, [esi + 0x4c]
// 0041a54f  8bcf                 mov ecx, edi
// 0041a551  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0041a559  897c2408             mov dword ptr [esp + 8], edi
// 0041a55d  e87ea71700           call 0x594ce0
// 0041a562  c644240c01           mov byte ptr [esp + 0xc], 1
// 0041a567  8d442420             lea eax, [esp + 0x20]
// 0041a56b  50                   push eax
// 0041a56c  8d4e2c               lea ecx, [esi + 0x2c]
// 0041a56f  c644241c01           mov byte ptr [esp + 0x1c], 1
// 0041a574  e867f5ffff           call 0x419ae0
// 0041a579  8bcf                 mov ecx, edi
// 0041a57b  c644241800           mov byte ptr [esp + 0x18], 0
// 0041a580  e87ba71700           call 0x594d00
// 0041a585  8b4e04               mov ecx, dword ptr [esi + 4]
// 0041a588  6a00                 push 0
// 0041a58a  6a00                 push 0
// 0041a58c  6865040000           push 0x465
// 0041a591  51                   push ecx
// 0041a592  ff150c2e8000         call dword ptr [0x802e0c]
// 0041a598  8b442420             mov eax, dword ptr [esp + 0x20]
// 0041a59c  5f                   pop edi
// 0041a59d  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 0041a5a5  5e                   pop esi
// 0041a5a6  85c0                 test eax, eax
// 0041a5a8  7415                 je 0x41a5bf
// 0041a5aa  8b00                 mov eax, dword ptr [eax]
// 0041a5ac  85c0                 test eax, eax
// 0041a5ae  740f                 je 0x41a5bf
// 0041a5b0  8d542420             lea edx, [esp + 0x20]
// 0041a5b4  6a01                 push 1
// 0041a5b6  52                   push edx
// 0041a5b7  8bca                 mov ecx, edx
// 0041a5b9  51                   push ecx
// 0041a5ba  ffd0                 call eax
// 0041a5bc  83c40c               add esp, 0xc
// 0041a5bf  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0041a5c3  64890d00000000       mov dword ptr fs:[0], ecx
// 0041a5ca  83c414               add esp, 0x14
// 0041a5cd  c22000               ret 0x20

extern "C" int (__stdcall *PostMessageA)(void*, unsigned int, unsigned int, long);

struct FunctionTable {
    void (__cdecl *manager)(void*, void*, int);
};

struct Function {
    FunctionTable* table;
    unsigned int reserved;
    unsigned int storage[6];

    ~Function();
};

inline Function::~Function()
{
    if (table) {
        void (__cdecl *manager)(void*, void*, int) = table->manager;
        if (manager)
            manager(storage, storage, 1);
    }
}

struct Queue {
    unsigned int reserved[4];
    void** blocks;
    unsigned int capacity;
    unsigned int start;
    unsigned int count;

    void append(const void*);
};

struct Mutex {
    void* object;
    char kind;

    void lock();
    void unlock();
};

struct Lock {
    Mutex* mutex;
    bool locked;

    Lock(Mutex*);
    ~Lock();
};

inline Lock::Lock(Mutex* value) : mutex(value)
{
    mutex->lock();
    locked = true;
}

inline Lock::~Lock()
{
    if (locked)
        mutex->unlock();
}

struct Marshaller {
    unsigned int reserved;
    void* window;
    unsigned char padding[36];
    Queue queue;
    Mutex mutex;

    void submit(Function);
};

void Marshaller::submit(Function value)
{
    {
        Lock guard(&mutex);
        queue.append(&value);
    }
    PostMessageA(window, 0x465, 0, 0);
}
