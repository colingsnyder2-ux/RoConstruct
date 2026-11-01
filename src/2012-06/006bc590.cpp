// from server: 100% by Yeetserama
// roc 2012-06 006bc590  unit: RBX::VStandardOut::?$sp_counted_impl_p  size: 119 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006bc590
//
// 006bc590  6aff                 push -1
// 006bc592  68d895ab00           push 0xab95d8
// 006bc597  64a100000000         mov eax, dword ptr fs:[0]
// 006bc59d  50                   push eax
// 006bc59e  64892500000000       mov dword ptr fs:[0], esp
// 006bc5a5  51                   push ecx
// 006bc5a6  56                   push esi
// 006bc5a7  57                   push edi
// 006bc5a8  8bf9                 mov edi, ecx
// 006bc5aa  897c2408             mov dword ptr [esp + 8], edi
// 006bc5ae  8b774c               mov esi, dword ptr [edi + 0x4c]
// 006bc5b1  c744241400000000     mov dword ptr [esp + 0x14], 0
// 006bc5b9  85f6                 test esi, esi
// 006bc5bb  742a                 je 0x6bc5e7
// 006bc5bd  8d4604               lea eax, [esi + 4]
// 006bc5c0  83c9ff               or ecx, 0xffffffff
// 006bc5c3  f00fc108             lock xadd dword ptr [eax], ecx
// 006bc5c7  751e                 jne 0x6bc5e7
// 006bc5c9  8b16                 mov edx, dword ptr [esi]
// 006bc5cb  8b4204               mov eax, dword ptr [edx + 4]
// 006bc5ce  8bce                 mov ecx, esi
// 006bc5d0  ffd0                 call eax
// 006bc5d2  8d4e08               lea ecx, [esi + 8]
// 006bc5d5  83caff               or edx, 0xffffffff
// 006bc5d8  f00fc111             lock xadd dword ptr [ecx], edx
// 006bc5dc  7509                 jne 0x6bc5e7
// 006bc5de  8b06                 mov eax, dword ptr [esi]
// 006bc5e0  8b5008               mov edx, dword ptr [eax + 8]
// 006bc5e3  8bce                 mov ecx, esi
// 006bc5e5  ffd2                 call edx
// 006bc5e7  8bcf                 mov ecx, edi
// 006bc5e9  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 006bc5f1  e85af1d4ff           call 0x40b750
// 006bc5f6  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 006bc5fa  5f                   pop edi
// 006bc5fb  5e                   pop esi
// 006bc5fc  64890d00000000       mov dword ptr fs:[0], ecx
// 006bc603  83c410               add esp, 0x10
// 006bc606  c3                   ret 
// copied from an identical function in another client (function ??1Derived@@QAE@XZ)

// from server: 100% by tester
#include <intrin.h>

struct Counted {
    virtual ~Counted();
    virtual void dispose();
    virtual void destroy();
    long use;
    long weak;
    void release()
    {
        if (_InterlockedDecrement(&use) == 0) {
            dispose();
            if (_InterlockedDecrement(&weak) == 0)
                destroy();
        }
    }
};

struct Base {
    char storage[0x48];
    ~Base();
};

struct Derived : Base {
    void* px;
    Counted* pn;
    ~Derived();
};

Derived::~Derived()
{
    if (pn)
        pn->release();
}