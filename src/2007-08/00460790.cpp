// from server: 100% by Yeetserama
// roc 2007-08 00460790  unit: CScriptEditor  size: 131 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00460790
//
// 00460790  6aff                 push -1
// 00460792  6898277400           push 0x742798
// 00460797  64a100000000         mov eax, dword ptr fs:[0]
// 0046079d  50                   push eax
// 0046079e  51                   push ecx
// 0046079f  56                   push esi
// 004607a0  57                   push edi
// 004607a1  a188518b00           mov eax, dword ptr [0x8b5188]
// 004607a6  33c4                 xor eax, esp
// 004607a8  50                   push eax
// 004607a9  8d442410             lea eax, [esp + 0x10]
// 004607ad  64a300000000         mov dword ptr fs:[0], eax
// 004607b3  8bf9                 mov edi, ecx
// 004607b5  897c240c             mov dword ptr [esp + 0xc], edi
// 004607b9  8b7758               mov esi, dword ptr [edi + 0x58]
// 004607bc  85f6                 test esi, esi
// 004607be  c744241800000000     mov dword ptr [esp + 0x18], 0
// 004607c6  742a                 je 0x4607f2
// 004607c8  8d4604               lea eax, [esi + 4]
// 004607cb  83c9ff               or ecx, 0xffffffff
// 004607ce  f00fc108             lock xadd dword ptr [eax], ecx
// 004607d2  751e                 jne 0x4607f2
// 004607d4  8b16                 mov edx, dword ptr [esi]
// 004607d6  8b4204               mov eax, dword ptr [edx + 4]
// 004607d9  8bce                 mov ecx, esi
// 004607db  ffd0                 call eax
// 004607dd  8d4e08               lea ecx, [esi + 8]
// 004607e0  83caff               or edx, 0xffffffff
// 004607e3  f00fc111             lock xadd dword ptr [ecx], edx
// 004607e7  7509                 jne 0x4607f2
// 004607e9  8b06                 mov eax, dword ptr [esi]
// 004607eb  8b5008               mov edx, dword ptr [eax + 8]
// 004607ee  8bce                 mov ecx, esi
// 004607f0  ffd2                 call edx
// 004607f2  8bcf                 mov ecx, edi
// 004607f4  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 004607fc  e8f7f71c00           call 0x62fff8
// 00460801  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00460805  64890d00000000       mov dword ptr fs:[0], ecx
// 0046080c  59                   pop ecx
// 0046080d  5f                   pop edi
// 0046080e  5e                   pop esi
// 0046080f  83c410               add esp, 0x10
// 00460812  c3                   ret 
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
    char storage[0x54];
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