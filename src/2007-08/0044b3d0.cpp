// from server: 100% by Yeetserama
// roc 2007-08 0044b3d0  unit: CRobloxApp  size: 139 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0044b3d0
//
// 0044b3d0  6aff                 push -1
// 0044b3d2  6848017400           push 0x740148
// 0044b3d7  64a100000000         mov eax, dword ptr fs:[0]
// 0044b3dd  50                   push eax
// 0044b3de  51                   push ecx
// 0044b3df  53                   push ebx
// 0044b3e0  56                   push esi
// 0044b3e1  57                   push edi
// 0044b3e2  a188518b00           mov eax, dword ptr [0x8b5188]
// 0044b3e7  33c4                 xor eax, esp
// 0044b3e9  50                   push eax
// 0044b3ea  8d442414             lea eax, [esp + 0x14]
// 0044b3ee  64a300000000         mov dword ptr fs:[0], eax
// 0044b3f4  8bf1                 mov esi, ecx
// 0044b3f6  6a01                 push 1
// 0044b3f8  8d4c2414             lea ecx, [esp + 0x14]
// 0044b3fc  e8fffdffff           call 0x44b200
// 0044b401  8bce                 mov ecx, esi
// 0044b403  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 0044b40b  e876541e00           call 0x630886
// 0044b410  8bd8                 mov ebx, eax
// 0044b412  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 0044b41a  e871fdffff           call 0x44b190
// 0044b41f  8bf0                 mov esi, eax
// 0044b421  8bce                 mov ecx, esi
// 0044b423  e848ab2d00           call 0x725f70
// 0044b428  8bf8                 mov edi, eax
// 0044b42a  8b442410             mov eax, dword ptr [esp + 0x10]
// 0044b42e  3bf8                 cmp edi, eax
// 0044b430  7414                 je 0x44b446
// 0044b432  50                   push eax
// 0044b433  8bce                 mov ecx, esi
// 0044b435  e8d6ad2d00           call 0x726210
// 0044b43a  85ff                 test edi, edi
// 0044b43c  7408                 je 0x44b446
// 0044b43e  57                   push edi
// 0044b43f  8bce                 mov ecx, esi
// 0044b441  e8daa52d00           call 0x725a20
// 0044b446  8bc3                 mov eax, ebx
// 0044b448  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0044b44c  64890d00000000       mov dword ptr fs:[0], ecx
// 0044b453  59                   pop ecx
// 0044b454  5f                   pop edi
// 0044b455  5e                   pop esi
// 0044b456  5b                   pop ebx
// 0044b457  83c410               add esp, 0x10
// 0044b45a  c3                   ret 
// copied from an identical function in another client (function ?f@CRobloxApp@ns_ROCX000006@@QAEHXZ)

namespace ns_ROCX000006 {
// from server: 100% by king_originala
struct ThreadState {
    void* get();
    void set(void*);
    void cleanup(void*);
};

ThreadState* threadState();

struct Guard {
    void* previous;
    Guard(int);
    ~Guard();
};

inline Guard::~Guard()
{
    ThreadState* state = threadState();
    void* current = state->get();
    if (current != previous) {
        state->set(previous);
        if (current)
            state->cleanup(current);
    }
}

struct CRobloxApp {
    int operation();
    int f();
};

int CRobloxApp::f()
{
    Guard guard(1);
    return operation();
}
}
