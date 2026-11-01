// from server: 83% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0064d300  unit: RBX::SimJobStage  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0064d300
//
// 0064d300  6aff                 push -1
// 0064d302  68b3b17d00           push 0x7db1b3
// 0064d307  64a100000000         mov eax, dword ptr fs:[0]
// 0064d30d  50                   push eax
// 0064d30e  64892500000000       mov dword ptr fs:[0], esp
// 0064d315  83ec08               sub esp, 8
// 0064d318  56                   push esi
// 0064d319  8bf1                 mov esi, ecx
// 0064d31b  6a24                 push 0x24
// 0064d31d  89742408             mov dword ptr [esp + 8], esi
// 0064d321  e8fa350500           call 0x6a0920
// 0064d326  83c404               add esp, 4
// 0064d329  89442408             mov dword ptr [esp + 8], eax
// 0064d32d  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0064d335  85c0                 test eax, eax
// 0064d337  740a                 je 0x64d343
// 0064d339  56                   push esi
// 0064d33a  8bc8                 mov ecx, eax
// 0064d33c  e80fe3faff           call 0x5fb650
// 0064d341  eb02                 jmp 0x64d345
// 0064d343  33c0                 xor eax, eax
// 0064d345  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0064d349  8b542420             mov edx, dword ptr [esp + 0x20]
// 0064d34d  894e04               mov dword ptr [esi + 4], ecx
// 0064d350  894608               mov dword ptr [esi + 8], eax
// 0064d353  89560c               mov dword ptr [esi + 0xc], edx
// 0064d356  8d4e10               lea ecx, [esi + 0x10]
// 0064d359  c744241401000000     mov dword ptr [esp + 0x14], 1
// 0064d361  c70674b18400         mov dword ptr [esi], 0x84b174
// 0064d367  e894cefcff           call 0x61a200
// 0064d36c  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0064d370  8bc6                 mov eax, esi
// 0064d372  5e                   pop esi
// 0064d373  64890d00000000       mov dword ptr fs:[0], ecx
// 0064d37a  83c414               add esp, 0x14
// 0064d37d  c20800               ret 8

typedef unsigned int size_t;
void* __cdecl operator new(size_t);
void __cdecl operator delete(void*);

struct Node {
    char storage[36];
    Node(void*);
};

struct Member {
    void* storage;
    Member();
    ~Member();
};

struct Parent {
    void* first;
    Node* node;
    void* second;
    Parent(void*, Node*, void*);
    virtual ~Parent();
};

inline Parent::Parent(void* a, Node* n, void* b)
    : first(a), node(n), second(b)
{
}

struct S : Parent {
    Member member;
    S(void*, void*);
    virtual ~S();
};

S::S(void* a, void* b)
    : Parent(a, new Node(this), b), member()
{
}
