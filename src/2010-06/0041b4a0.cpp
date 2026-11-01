// from server: 100% by Yeetserama
// roc 2010-06 0041b4a0  unit: rbx::signals::connection::slot  size: 125 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0041b4a0
//
// 0041b4a0  6aff                 push -1
// 0041b4a2  6838ef9700           push 0x97ef38
// 0041b4a7  64a100000000         mov eax, dword ptr fs:[0]
// 0041b4ad  50                   push eax
// 0041b4ae  64892500000000       mov dword ptr fs:[0], esp
// 0041b4b5  51                   push ecx
// 0041b4b6  56                   push esi
// 0041b4b7  57                   push edi
// 0041b4b8  8bf9                 mov edi, ecx
// 0041b4ba  897c2408             mov dword ptr [esp + 8], edi
// 0041b4be  c707b439a000         mov dword ptr [edi], 0xa039b4
// 0041b4c4  8b7758               mov esi, dword ptr [edi + 0x58]
// 0041b4c7  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0041b4cf  85f6                 test esi, esi
// 0041b4d1  742a                 je 0x41b4fd
// 0041b4d3  8d4604               lea eax, [esi + 4]
// 0041b4d6  83c9ff               or ecx, 0xffffffff
// 0041b4d9  f00fc108             lock xadd dword ptr [eax], ecx
// 0041b4dd  751e                 jne 0x41b4fd
// 0041b4df  8b16                 mov edx, dword ptr [esi]
// 0041b4e1  8b4204               mov eax, dword ptr [edx + 4]
// 0041b4e4  8bce                 mov ecx, esi
// 0041b4e6  ffd0                 call eax
// 0041b4e8  8d4e08               lea ecx, [esi + 8]
// 0041b4eb  83caff               or edx, 0xffffffff
// 0041b4ee  f00fc111             lock xadd dword ptr [ecx], edx
// 0041b4f2  7509                 jne 0x41b4fd
// 0041b4f4  8b06                 mov eax, dword ptr [esi]
// 0041b4f6  8b5008               mov edx, dword ptr [eax + 8]
// 0041b4f9  8bce                 mov ecx, esi
// 0041b4fb  ffd2                 call edx
// 0041b4fd  8bcf                 mov ecx, edi
// 0041b4ff  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 0041b507  e8643a3c00           call 0x7def70
// 0041b50c  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0041b510  5f                   pop edi
// 0041b511  5e                   pop esi
// 0041b512  64890d00000000       mov dword ptr fs:[0], ecx
// 0041b519  83c410               add esp, 0x10
// 0041b51c  c3                   ret 
// copied from an identical function in another client (function ??1CInstanceExplorer@ns_ROCX00001e@@UAE@XZ)

namespace ns_ROCX00001e {
// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control
{
    virtual ~Control();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Base
{
    virtual ~Base();
    char padding[0x50];
};

struct CInstanceExplorer : Base
{
    void* object;
    Control* control;
    virtual ~CInstanceExplorer();
};

CInstanceExplorer::~CInstanceExplorer()
{
    Control* p = control;
    if (p && _InterlockedDecrement(&p->strong) == 0)
    {
        p->dispose();
        if (_InterlockedDecrement(&p->weak) == 0)
            p->destroy();
    }
}
}
