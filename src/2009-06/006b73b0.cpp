// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 006171e0  unit: RBX::BoxSelectCommand  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006171e0
//
// 006171e0  6aff                 push -1
// 006171e2  6883907d00           push 0x7d9083
// 006171e7  64a100000000         mov eax, dword ptr fs:[0]
// 006171ed  50                   push eax
// 006171ee  64892500000000       mov dword ptr fs:[0], esp
// 006171f5  51                   push ecx
// 006171f6  56                   push esi
// 006171f7  57                   push edi
// 006171f8  8bf9                 mov edi, ecx
// 006171fa  897c2408             mov dword ptr [esp + 8], edi
// 006171fe  8d4f34               lea ecx, [edi + 0x34]
// 00617201  c744241401000000     mov dword ptr [esp + 0x14], 1
// 00617209  e822400300           call 0x64b230
// 0061720e  8b7724               mov esi, dword ptr [edi + 0x24]
// 00617211  c644241400           mov byte ptr [esp + 0x14], 0
// 00617216  85f6                 test esi, esi
// 00617218  742a                 je 0x617244
// 0061721a  8d4604               lea eax, [esi + 4]
// 0061721d  83c9ff               or ecx, 0xffffffff
// 00617220  f00fc108             lock xadd dword ptr [eax], ecx
// 00617224  751e                 jne 0x617244
// 00617226  8b16                 mov edx, dword ptr [esi]
// 00617228  8b4204               mov eax, dword ptr [edx + 4]
// 0061722b  8bce                 mov ecx, esi
// 0061722d  ffd0                 call eax
// 0061722f  8d4e08               lea ecx, [esi + 8]
// 00617232  83caff               or edx, 0xffffffff
// 00617235  f00fc111             lock xadd dword ptr [ecx], edx
// 00617239  7509                 jne 0x617244
// 0061723b  8b06                 mov eax, dword ptr [esi]
// 0061723d  8b5008               mov edx, dword ptr [eax + 8]
// 00617240  8bce                 mov ecx, esi
// 00617242  ffd2                 call edx
// 00617244  8bcf                 mov ecx, edi
// 00617246  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 0061724e  e82de5ffff           call 0x615780
// 00617253  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00617257  5f                   pop edi
// 00617258  5e                   pop esi
// 00617259  64890d00000000       mov dword ptr fs:[0], ecx
// 00617260  83c410               add esp, 0x10
// 00617263  c3                   ret 

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct RefCount
{
    virtual void reserved();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Shared
{
    void* object;
    RefCount* control;
    ~Shared();
};

inline Shared::~Shared()
{
    RefCount* p = control;
    if (p && _InterlockedDecrement(&p->strong) == 0)
    {
        p->dispose();
        if (_InterlockedDecrement(&p->weak) == 0)
            p->destroy();
    }
}

struct Base
{
    unsigned char storage[32];
    ~Base();
};

struct Member
{
    ~Member();
};

struct S : Base
{
    Shared shared;
    unsigned char storage[12];
    Member member;
    ~S();
};

S::~S()
{
}
