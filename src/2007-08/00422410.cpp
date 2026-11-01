// from server: 100% by Yeetserama
// roc 2007-08 00422410  unit: CRobloxTreeCtrlNode  size: 169 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00422410
//
// 00422410  6aff                 push -1
// 00422412  6858be7300           push 0x73be58
// 00422417  64a100000000         mov eax, dword ptr fs:[0]
// 0042241d  50                   push eax
// 0042241e  83ec08               sub esp, 8
// 00422421  56                   push esi
// 00422422  57                   push edi
// 00422423  a188518b00           mov eax, dword ptr [0x8b5188]
// 00422428  33c4                 xor eax, esp
// 0042242a  50                   push eax
// 0042242b  8d442414             lea eax, [esp + 0x14]
// 0042242f  64a300000000         mov dword ptr fs:[0], eax
// 00422435  8d44240c             lea eax, [esp + 0xc]
// 00422439  50                   push eax
// 0042243a  e831270200           call 0x444b70
// 0042243f  83c404               add esp, 4
// 00422442  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00422446  6a01                 push 1
// 00422448  51                   push ecx
// 00422449  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0042244d  c744242400000000     mov dword ptr [esp + 0x24], 0
// 00422455  e806080200           call 0x442c60
// 0042245a  85c0                 test eax, eax
// 0042245c  740b                 je 0x422469
// 0042245e  8bc8                 mov ecx, eax
// 00422460  e82bffffff           call 0x422390
// 00422465  8bf8                 mov edi, eax
// 00422467  eb02                 jmp 0x42246b
// 00422469  33ff                 xor edi, edi
// 0042246b  8b742410             mov esi, dword ptr [esp + 0x10]
// 0042246f  85f6                 test esi, esi
// 00422471  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 00422479  742a                 je 0x4224a5
// 0042247b  8d5604               lea edx, [esi + 4]
// 0042247e  83c8ff               or eax, 0xffffffff
// 00422481  f00fc102             lock xadd dword ptr [edx], eax
// 00422485  751e                 jne 0x4224a5
// 00422487  8b16                 mov edx, dword ptr [esi]
// 00422489  8b4204               mov eax, dword ptr [edx + 4]
// 0042248c  8bce                 mov ecx, esi
// 0042248e  ffd0                 call eax
// 00422490  8d4e08               lea ecx, [esi + 8]
// 00422493  83caff               or edx, 0xffffffff
// 00422496  f00fc111             lock xadd dword ptr [ecx], edx
// 0042249a  7509                 jne 0x4224a5
// 0042249c  8b06                 mov eax, dword ptr [esi]
// 0042249e  8b5008               mov edx, dword ptr [eax + 8]
// 004224a1  8bce                 mov ecx, esi
// 004224a3  ffd2                 call edx
// 004224a5  8bc7                 mov eax, edi
// 004224a7  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004224ab  64890d00000000       mov dword ptr fs:[0], ecx
// 004224b2  59                   pop ecx
// 004224b3  5f                   pop edi
// 004224b4  5e                   pop esi
// 004224b5  83c414               add esp, 0x14
// 004224b8  c3                   ret 
// copied from an identical function in another client (function ?lookup@ns_ROCX000005@@YAHH@Z)

namespace ns_ROCX000005 {
// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Target {
    int invoke(int a, int b);
};

struct S {
    char padding[0x130];
    Target* target;
    int invoke(int a, int b);
};

struct Node {
    int get();
};

struct RefCount {
    virtual void reserved();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Handle {
    S* pointer;
    RefCount* count;
    ~Handle();
};

Handle __cdecl acquire();

__forceinline Handle::~Handle()
{
    RefCount* p = count;
    if (p) {
        if (_InterlockedDecrement(&p->strong) == 0) {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

int __cdecl lookup(int value)
{
    Handle handle = acquire();
    int node = handle.pointer->invoke(value, 1);
    return node ? ((Node*)node)->get() : 0;
}
}
