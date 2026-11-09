// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005fe2f0  unit: RBX::VInstance::?$NonFactoryProduct  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005fe2f0
//
// 005fe2f0  6aff                 push -1
// 005fe2f2  68e87e7d00           push 0x7d7ee8
// 005fe2f7  64a100000000         mov eax, dword ptr fs:[0]
// 005fe2fd  50                   push eax
// 005fe2fe  64892500000000       mov dword ptr fs:[0], esp
// 005fe305  51                   push ecx
// 005fe306  56                   push esi
// 005fe307  57                   push edi
// 005fe308  8bf9                 mov edi, ecx
// 005fe30a  897c2408             mov dword ptr [esp + 8], edi
// 005fe30e  c7073c188400         mov dword ptr [edi], 0x84183c
// 005fe314  c7470424188400       mov dword ptr [edi + 4], 0x841824
// 005fe31b  8b7728               mov esi, dword ptr [edi + 0x28]
// 005fe31e  c744241400000000     mov dword ptr [esp + 0x14], 0
// 005fe326  85f6                 test esi, esi
// 005fe328  742a                 je 0x5fe354
// 005fe32a  8d4604               lea eax, [esi + 4]
// 005fe32d  83c9ff               or ecx, 0xffffffff
// 005fe330  f00fc108             lock xadd dword ptr [eax], ecx
// 005fe334  751e                 jne 0x5fe354
// 005fe336  8b16                 mov edx, dword ptr [esi]
// 005fe338  8b4204               mov eax, dword ptr [edx + 4]
// 005fe33b  8bce                 mov ecx, esi
// 005fe33d  ffd0                 call eax
// 005fe33f  8d4e08               lea ecx, [esi + 8]
// 005fe342  83caff               or edx, 0xffffffff
// 005fe345  f00fc111             lock xadd dword ptr [ecx], edx
// 005fe349  7509                 jne 0x5fe354
// 005fe34b  8b06                 mov eax, dword ptr [esi]
// 005fe34d  8b5008               mov edx, dword ptr [eax + 8]
// 005fe350  8bce                 mov ecx, esi
// 005fe352  ffd2                 call edx
// 005fe354  8bcf                 mov ecx, edi
// 005fe356  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 005fe35e  e85d4c0400           call 0x642fc0
// 005fe363  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005fe367  5f                   pop edi
// 005fe368  5e                   pop esi
// 005fe369  64890d00000000       mov dword ptr fs:[0], ecx
// 005fe370  83c410               add esp, 0x10
// 005fe373  c3                   ret 

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual ~Control();
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
};

struct Shared {
    void* object;
    Control* control;
    ~Shared();
};

struct First {
    virtual ~First();
};

struct Second {
    virtual ~Second();
};

struct Base : First, Second {
    char reserved[28];
    virtual ~Base();
};

struct Product : Base {
    Shared shared;
    virtual ~Product();
};

inline Shared::~Shared()
{
    Control* p = control;
    if (p && _InterlockedDecrement(&p->strong) == 0) {
        p->dispose();
        if (_InterlockedDecrement(&p->weak) == 0)
            p->destroy();
    }
}

Product::~Product()
{
}
