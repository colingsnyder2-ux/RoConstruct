// from server: 99% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00577590  unit: RBX::DataModel  size: 151 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00577590
//
// 00577590  6aff                 push -1
// 00577592  6878f47b00           push 0x7bf478
// 00577597  64a100000000         mov eax, dword ptr fs:[0]
// 0057759d  50                   push eax
// 0057759e  64892500000000       mov dword ptr fs:[0], esp
// 005775a5  51                   push ecx
// 005775a6  56                   push esi
// 005775a7  8bf1                 mov esi, ecx
// 005775a9  83ec20               sub esp, 0x20
// 005775ac  8bc4                 mov eax, esp
// 005775ae  c70000000000         mov dword ptr [eax], 0
// 005775b4  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 005775b8  c744243000000000     mov dword ptr [esp + 0x30], 0
// 005775c0  89642424             mov dword ptr [esp + 0x24], esp
// 005775c4  85c9                 test ecx, ecx
// 005775c6  7418                 je 0x5775e0
// 005775c8  8908                 mov dword ptr [eax], ecx
// 005775ca  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 005775ce  8b11                 mov edx, dword ptr [ecx]
// 005775d0  83c008               add eax, 8
// 005775d3  6a00                 push 0
// 005775d5  50                   push eax
// 005775d6  8d442448             lea eax, [esp + 0x48]
// 005775da  50                   push eax
// 005775db  ffd2                 call edx
// 005775dd  83c40c               add esp, 0xc
// 005775e0  8bce                 mov ecx, esi
// 005775e2  e849fcffff           call 0x577230
// 005775e7  8b442438             mov eax, dword ptr [esp + 0x38]
// 005775eb  894620               mov dword ptr [esi + 0x20], eax
// 005775ee  8b442418             mov eax, dword ptr [esp + 0x18]
// 005775f2  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 005775fa  85c0                 test eax, eax
// 005775fc  7415                 je 0x577613
// 005775fe  8b00                 mov eax, dword ptr [eax]
// 00577600  85c0                 test eax, eax
// 00577602  740f                 je 0x577613
// 00577604  8d4c2420             lea ecx, [esp + 0x20]
// 00577608  6a01                 push 1
// 0057760a  51                   push ecx
// 0057760b  8bd1                 mov edx, ecx
// 0057760d  52                   push edx
// 0057760e  ffd0                 call eax
// 00577610  83c40c               add esp, 0xc
// 00577613  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00577617  8bc6                 mov eax, esi
// 00577619  64890d00000000       mov dword ptr fs:[0], ecx
// 00577620  5e                   pop esi
// 00577621  83c410               add esp, 0x10
// 00577624  c22400               ret 0x24

struct Manager {
    void (__cdecl *manage)(const void *, void *, int);
};

struct Function {
    Manager *manager;
    unsigned int padding;
    char storage[24];

    Function(const Function &other)
        : manager(0)
    {
        if (other.manager) {
            manager = other.manager;
            other.manager->manage(other.storage, storage, 0);
        }
    }

    ~Function()
    {
        if (manager) {
            void (__cdecl *callback)(const void *, void *, int) = manager->manage;
            if (callback)
                callback(storage, storage, 1);
        }
    }
};

struct S {
    char padding[32];
    int value;

    void set(Function function);
    S &f(Function function, int newValue);
};

S &S::f(Function function, int newValue)
{
    set(function);
    value = newValue;
    return *this;
}
