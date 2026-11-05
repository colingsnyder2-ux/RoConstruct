// from server: 100% by EspClaude
// roc 2009-06 00655320  unit: RBX::HammerTool  size: 119 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00655320
//
// 00655320  6aff                 push -1
// 00655322  6868068700           push 0x870668
// 00655327  64a100000000         mov eax, dword ptr fs:[0]
// 0065532d  50                   push eax
// 0065532e  64892500000000       mov dword ptr fs:[0], esp
// 00655335  51                   push ecx
// 00655336  56                   push esi
// 00655337  57                   push edi
// 00655338  8bf9                 mov edi, ecx
// 0065533a  897c2408             mov dword ptr [esp + 8], edi
// 0065533e  8b7720               mov esi, dword ptr [edi + 0x20]
// 00655341  c744241400000000     mov dword ptr [esp + 0x14], 0
// 00655349  85f6                 test esi, esi
// 0065534b  742a                 je 0x655377
// 0065534d  8d4604               lea eax, [esi + 4]
// 00655350  83c9ff               or ecx, 0xffffffff
// 00655353  f00fc108             lock xadd dword ptr [eax], ecx
// 00655357  751e                 jne 0x655377
// 00655359  8b16                 mov edx, dword ptr [esi]
// 0065535b  8b4204               mov eax, dword ptr [edx + 4]
// 0065535e  8bce                 mov ecx, esi
// 00655360  ffd0                 call eax
// 00655362  8d4e08               lea ecx, [esi + 8]
// 00655365  83caff               or edx, 0xffffffff
// 00655368  f00fc111             lock xadd dword ptr [ecx], edx
// 0065536c  7509                 jne 0x655377
// 0065536e  8b06                 mov eax, dword ptr [esi]
// 00655370  8b5008               mov edx, dword ptr [eax + 8]
// 00655373  8bce                 mov ecx, esi
// 00655375  ffd2                 call edx
// 00655377  8bcf                 mov ecx, edi
// 00655379  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 00655381  e8fa070600           call 0x6b5b80
// 00655386  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0065538a  5f                   pop edi
// 0065538b  5e                   pop esi
// 0065538c  64890d00000000       mov dword ptr fs:[0], ecx
// 00655393  83c410               add esp, 0x10
// 00655396  c3                   ret 
// copied from an identical function in another client (function ??1Derived@@QAE@XZ)

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