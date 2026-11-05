// from server: 100% by tester
// roc 2008-06 0042a330  unit: ThreadLogManager  size: 154 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0042a330
//
// 0042a330  64a100000000         mov eax, dword ptr fs:[0]
// 0042a336  6aff                 push -1
// 0042a338  6878f47b00           push 0x7bf478
// 0042a33d  50                   push eax
// 0042a33e  64892500000000       mov dword ptr fs:[0], esp
// 0042a345  56                   push esi
// 0042a346  57                   push edi
// 0042a347  8bf1                 mov esi, ecx
// 0042a349  8d442418             lea eax, [esp + 0x18]
// 0042a34d  50                   push eax
// 0042a34e  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0042a356  c70600000000         mov dword ptr [esi], 0
// 0042a35c  e88fff1d00           call 0x60a2f0
// 0042a361  83c404               add esp, 4
// 0042a364  84c0                 test al, al
// 0042a366  7522                 jne 0x42a38a
// 0042a368  6a20                 push 0x20
// 0042a36a  e8b1652700           call 0x6a0920
// 0042a36f  8d4c241c             lea ecx, [esp + 0x1c]
// 0042a373  8bf8                 mov edi, eax
// 0042a375  51                   push ecx
// 0042a376  57                   push edi
// 0042a377  e8c4ecffff           call 0x429040
// 0042a37c  83c40c               add esp, 0xc
// 0042a37f  897e08               mov dword ptr [esi + 8], edi
// 0042a382  c706f0048100         mov dword ptr [esi], 0x8104f0
// 0042a388  eb06                 jmp 0x42a390
// 0042a38a  c70600000000         mov dword ptr [esi], 0
// 0042a390  8b442418             mov eax, dword ptr [esp + 0x18]
// 0042a394  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 0042a39c  85c0                 test eax, eax
// 0042a39e  7415                 je 0x42a3b5
// 0042a3a0  8b00                 mov eax, dword ptr [eax]
// 0042a3a2  85c0                 test eax, eax
// 0042a3a4  740f                 je 0x42a3b5
// 0042a3a6  8d542420             lea edx, [esp + 0x20]
// 0042a3aa  6a01                 push 1
// 0042a3ac  52                   push edx
// 0042a3ad  8bca                 mov ecx, edx
// 0042a3af  51                   push ecx
// 0042a3b0  ffd0                 call eax
// 0042a3b2  83c40c               add esp, 0xc
// 0042a3b5  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0042a3b9  5f                   pop edi
// 0042a3ba  8bc6                 mov eax, esi
// 0042a3bc  64890d00000000       mov dword ptr fs:[0], ecx
// 0042a3c3  5e                   pop esi
// 0042a3c4  83c40c               add esp, 0xc
// 0042a3c7  c22400               ret 0x24

typedef void (__cdecl *Manager)(void *, void *, int);

struct ManagerTable {
    Manager destroy;
};

struct Argument {
    ManagerTable *table;
    unsigned int reserved;
    char storage[28];

    ~Argument();
};

inline Argument::~Argument()
{
    if (table) {
        Manager destroy = table->destroy;
        if (destroy)
            destroy(storage, storage, 1);
    }
}

extern bool __cdecl func_0060a2f0(const Argument *);
extern void *__cdecl operator new(unsigned int);
extern void __cdecl func_00429040(void *, const Argument *);
extern ManagerTable managerTable;

struct ThreadLogManager {
    ManagerTable *table;
    unsigned int reserved;
    void *storage;

    ThreadLogManager(Argument argument);
};

ThreadLogManager::ThreadLogManager(Argument argument)
{
    table = 0;
    if (!func_0060a2f0(&argument)) {
        void *allocated = operator new(32);
        func_00429040(allocated, &argument);
        storage = allocated;
        table = &managerTable;
    } else {
        table = 0;
    }
}
