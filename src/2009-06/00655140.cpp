// from server: 100% by EspClaude
// from server: 100% by tester
// roc 2008-06 0063fe00  unit: RBX::CloneTool  size: 119 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0063fe00
//
// 0063fe00  6aff                 push -1
// 0063fe02  68f8a97d00           push 0x7da9f8
// 0063fe07  64a100000000         mov eax, dword ptr fs:[0]
// 0063fe0d  50                   push eax
// 0063fe0e  64892500000000       mov dword ptr fs:[0], esp
// 0063fe15  51                   push ecx
// 0063fe16  56                   push esi
// 0063fe17  57                   push edi
// 0063fe18  8bf9                 mov edi, ecx
// 0063fe1a  897c2408             mov dword ptr [esp + 8], edi
// 0063fe1e  8b7720               mov esi, dword ptr [edi + 0x20]
// 0063fe21  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0063fe29  85f6                 test esi, esi
// 0063fe2b  742a                 je 0x63fe57
// 0063fe2d  8d4604               lea eax, [esi + 4]
// 0063fe30  83c9ff               or ecx, 0xffffffff
// 0063fe33  f00fc108             lock xadd dword ptr [eax], ecx
// 0063fe37  751e                 jne 0x63fe57
// 0063fe39  8b16                 mov edx, dword ptr [esi]
// 0063fe3b  8b4204               mov eax, dword ptr [edx + 4]
// 0063fe3e  8bce                 mov ecx, esi
// 0063fe40  ffd0                 call eax
// 0063fe42  8d4e08               lea ecx, [esi + 8]
// 0063fe45  83caff               or edx, 0xffffffff
// 0063fe48  f00fc111             lock xadd dword ptr [ecx], edx
// 0063fe4c  7509                 jne 0x63fe57
// 0063fe4e  8b06                 mov eax, dword ptr [esi]
// 0063fe50  8b5008               mov edx, dword ptr [eax + 8]
// 0063fe53  8bce                 mov ecx, esi
// 0063fe55  ffd2                 call edx
// 0063fe57  8bcf                 mov ecx, edi
// 0063fe59  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 0063fe61  e81a59fdff           call 0x615780
// 0063fe66  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0063fe6a  5f                   pop edi
// 0063fe6b  5e                   pop esi
// 0063fe6c  64890d00000000       mov dword ptr fs:[0], ecx
// 0063fe73  83c410               add esp, 0x10
// 0063fe76  c3                   ret 

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
