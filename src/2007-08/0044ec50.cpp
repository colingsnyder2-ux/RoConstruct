// from server: 100% by Yeetserama
// roc 2007-08 0044ec50  unit: CRobloxDoc  size: 131 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0044ec50
//
// 0044ec50  6aff                 push -1
// 0044ec52  68580a7400           push 0x740a58
// 0044ec57  64a100000000         mov eax, dword ptr fs:[0]
// 0044ec5d  50                   push eax
// 0044ec5e  51                   push ecx
// 0044ec5f  56                   push esi
// 0044ec60  57                   push edi
// 0044ec61  a188518b00           mov eax, dword ptr [0x8b5188]
// 0044ec66  33c4                 xor eax, esp
// 0044ec68  50                   push eax
// 0044ec69  8d442410             lea eax, [esp + 0x10]
// 0044ec6d  64a300000000         mov dword ptr fs:[0], eax
// 0044ec73  8bf9                 mov edi, ecx
// 0044ec75  897c240c             mov dword ptr [esp + 0xc], edi
// 0044ec79  8b7718               mov esi, dword ptr [edi + 0x18]
// 0044ec7c  85f6                 test esi, esi
// 0044ec7e  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0044ec86  742a                 je 0x44ecb2
// 0044ec88  8d4604               lea eax, [esi + 4]
// 0044ec8b  83c9ff               or ecx, 0xffffffff
// 0044ec8e  f00fc108             lock xadd dword ptr [eax], ecx
// 0044ec92  751e                 jne 0x44ecb2
// 0044ec94  8b16                 mov edx, dword ptr [esi]
// 0044ec96  8b4204               mov eax, dword ptr [edx + 4]
// 0044ec99  8bce                 mov ecx, esi
// 0044ec9b  ffd0                 call eax
// 0044ec9d  8d4e08               lea ecx, [esi + 8]
// 0044eca0  83caff               or edx, 0xffffffff
// 0044eca3  f00fc111             lock xadd dword ptr [ecx], edx
// 0044eca7  7509                 jne 0x44ecb2
// 0044eca9  8b06                 mov eax, dword ptr [esi]
// 0044ecab  8b5008               mov edx, dword ptr [eax + 8]
// 0044ecae  8bce                 mov ecx, esi
// 0044ecb0  ffd2                 call edx
// 0044ecb2  8bcf                 mov ecx, edi
// 0044ecb4  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 0044ecbc  e8ef5e1100           call 0x564bb0
// 0044ecc1  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0044ecc5  64890d00000000       mov dword ptr fs:[0], ecx
// 0044eccc  59                   pop ecx
// 0044eccd  5f                   pop edi
// 0044ecce  5e                   pop esi
// 0044eccf  83c410               add esp, 0x10
// 0044ecd2  c3                   ret 
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
    char storage[0x14];
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