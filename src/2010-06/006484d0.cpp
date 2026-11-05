// from server: 100% by Yeetserama
// roc 2010-06 006484d0  unit: RBX::RunStateVerb  size: 119 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006484d0
//
// 006484d0  6aff                 push -1
// 006484d2  68e8d39900           push 0x99d3e8
// 006484d7  64a100000000         mov eax, dword ptr fs:[0]
// 006484dd  50                   push eax
// 006484de  64892500000000       mov dword ptr fs:[0], esp
// 006484e5  51                   push ecx
// 006484e6  56                   push esi
// 006484e7  57                   push edi
// 006484e8  8bf9                 mov edi, ecx
// 006484ea  897c2408             mov dword ptr [esp + 8], edi
// 006484ee  8b7720               mov esi, dword ptr [edi + 0x20]
// 006484f1  c744241400000000     mov dword ptr [esp + 0x14], 0
// 006484f9  85f6                 test esi, esi
// 006484fb  742a                 je 0x648527
// 006484fd  8d4604               lea eax, [esi + 4]
// 00648500  83c9ff               or ecx, 0xffffffff
// 00648503  f00fc108             lock xadd dword ptr [eax], ecx
// 00648507  751e                 jne 0x648527
// 00648509  8b16                 mov edx, dword ptr [esi]
// 0064850b  8b4204               mov eax, dword ptr [edx + 4]
// 0064850e  8bce                 mov ecx, esi
// 00648510  ffd0                 call eax
// 00648512  8d4e08               lea ecx, [esi + 8]
// 00648515  83caff               or edx, 0xffffffff
// 00648518  f00fc111             lock xadd dword ptr [ecx], edx
// 0064851c  7509                 jne 0x648527
// 0064851e  8b06                 mov eax, dword ptr [esi]
// 00648520  8b5008               mov edx, dword ptr [eax + 8]
// 00648523  8bce                 mov ecx, esi
// 00648525  ffd2                 call edx
// 00648527  8bcf                 mov ecx, edi
// 00648529  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 00648531  e86a550d00           call 0x71daa0
// 00648536  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0064853a  5f                   pop edi
// 0064853b  5e                   pop esi
// 0064853c  64890d00000000       mov dword ptr fs:[0], ecx
// 00648543  83c410               add esp, 0x10
// 00648546  c3                   ret 
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
    char storage[0x1c];
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