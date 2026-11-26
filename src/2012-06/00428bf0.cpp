// from server: 100% by Xemicl
// roc 2012-06 00428bf0  unit: rbx::signals::connection::islot  size: 125 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00428bf0
//
// 00428bf0  6aff                 push -1
// 00428bf2  68a83eaa00           push 0xaa3ea8
// 00428bf7  64a100000000         mov eax, dword ptr fs:[0]
// 00428bfd  50                   push eax
// 00428bfe  64892500000000       mov dword ptr fs:[0], esp
// 00428c05  51                   push ecx
// 00428c06  56                   push esi
// 00428c07  57                   push edi
// 00428c08  8bf9                 mov edi, ecx
// 00428c0a  897c2408             mov dword ptr [esp + 8], edi
// 00428c0e  c70714e6b400         mov dword ptr [edi], 0xb4e614
// 00428c14  8b7758               mov esi, dword ptr [edi + 0x58]
// 00428c17  c744241400000000     mov dword ptr [esp + 0x14], 0
// 00428c1f  85f6                 test esi, esi
// 00428c21  742a                 je 0x428c4d
// 00428c23  8d4604               lea eax, [esi + 4]
// 00428c26  83c9ff               or ecx, 0xffffffff
// 00428c29  f00fc108             lock xadd dword ptr [eax], ecx
// 00428c2d  751e                 jne 0x428c4d
// 00428c2f  8b16                 mov edx, dword ptr [esi]
// 00428c31  8b4204               mov eax, dword ptr [edx + 4]
// 00428c34  8bce                 mov ecx, esi
// 00428c36  ffd0                 call eax
// 00428c38  8d4e08               lea ecx, [esi + 8]
// 00428c3b  83caff               or edx, 0xffffffff
// 00428c3e  f00fc111             lock xadd dword ptr [ecx], edx
// 00428c42  7509                 jne 0x428c4d
// 00428c44  8b06                 mov eax, dword ptr [esi]
// 00428c46  8b5008               mov edx, dword ptr [eax + 8]
// 00428c49  8bce                 mov ecx, esi
// 00428c4b  ffd2                 call edx
// 00428c4d  8bcf                 mov ecx, edi
// 00428c4f  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 00428c57  e824035900           call 0x9b8f80
// 00428c5c  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00428c60  5f                   pop edi
// 00428c61  5e                   pop esi
// 00428c62  64890d00000000       mov dword ptr fs:[0], ecx
// 00428c69  83c410               add esp, 0x10
// 00428c6c  c3                   ret 
// copied from an identical function in another client (function ??1CInstanceExplorer@ns_ROCX00005e@@UAE@XZ)

namespace ns_ROCX00005e {
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