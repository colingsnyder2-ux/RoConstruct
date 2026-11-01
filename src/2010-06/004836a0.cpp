// from server: 100% by Yeetserama
// roc 2010-06 004836a0  unit: RBX::LDraw2Lua::LDrawParser  size: 217 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004836a0
//
// 004836a0  6aff                 push -1
// 004836a2  68e75a9800           push 0x985ae7
// 004836a7  64a100000000         mov eax, dword ptr fs:[0]
// 004836ad  50                   push eax
// 004836ae  64892500000000       mov dword ptr fs:[0], esp
// 004836b5  83ec0c               sub esp, 0xc
// 004836b8  53                   push ebx
// 004836b9  55                   push ebp
// 004836ba  56                   push esi
// 004836bb  57                   push edi
// 004836bc  894c2410             mov dword ptr [esp + 0x10], ecx
// 004836c0  c7016c31a100         mov dword ptr [ecx], 0xa1316c
// 004836c6  8b7930               mov edi, dword ptr [ecx + 0x30]
// 004836c9  2b792c               sub edi, dword ptr [ecx + 0x2c]
// 004836cc  8d7120               lea esi, [ecx + 0x20]
// 004836cf  c1ff02               sar edi, 2
// 004836d2  33db                 xor ebx, ebx
// 004836d4  c744242401000000     mov dword ptr [esp + 0x24], 1
// 004836dc  85ff                 test edi, edi
// 004836de  761b                 jbe 0x4836fb
// 004836e0  53                   push ebx
// 004836e1  8bce                 mov ecx, esi
// 004836e3  e838fdffff           call 0x483420
// 004836e8  8b08                 mov ecx, dword ptr [eax]
// 004836ea  85c9                 test ecx, ecx
// 004836ec  7408                 je 0x4836f6
// 004836ee  8b01                 mov eax, dword ptr [ecx]
// 004836f0  8b10                 mov edx, dword ptr [eax]
// 004836f2  6a01                 push 1
// 004836f4  ffd2                 call edx
// 004836f6  43                   inc ebx
// 004836f7  3bdf                 cmp ebx, edi
// 004836f9  72e5                 jb 0x4836e0
// 004836fb  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 004836fe  395e0c               cmp dword ptr [esi + 0xc], ebx
// 00483701  7606                 jbe 0x483709
// 00483703  ff150ca99e00         call dword ptr [0x9ea90c]
// 00483709  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 0048370c  8b2e                 mov ebp, dword ptr [esi]
// 0048370e  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 00483711  7606                 jbe 0x483719
// 00483713  ff150ca99e00         call dword ptr [0x9ea90c]
// 00483719  8b06                 mov eax, dword ptr [esi]
// 0048371b  53                   push ebx
// 0048371c  55                   push ebp
// 0048371d  57                   push edi
// 0048371e  50                   push eax
// 0048371f  8d442424             lea eax, [esp + 0x24]
// 00483723  50                   push eax
// 00483724  8bce                 mov ecx, esi
// 00483726  e8c51f0a00           call 0x5256f0
// 0048372b  8b460c               mov eax, dword ptr [esi + 0xc]
// 0048372e  33ff                 xor edi, edi
// 00483730  3bc7                 cmp eax, edi
// 00483732  7409                 je 0x48373d
// 00483734  50                   push eax
// 00483735  e860423200           call 0x7a799a
// 0048373a  83c404               add esp, 4
// 0048373d  897e0c               mov dword ptr [esi + 0xc], edi
// 00483740  897e10               mov dword ptr [esi + 0x10], edi
// 00483743  897e14               mov dword ptr [esi + 0x14], edi
// 00483746  8b36                 mov esi, dword ptr [esi]
// 00483748  56                   push esi
// 00483749  e84c423200           call 0x7a799a
// 0048374e  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00483752  83c404               add esp, 4
// 00483755  83c104               add ecx, 4
// 00483758  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 00483760  ff1500a49e00         call dword ptr [0x9ea400]
// 00483766  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0048376a  5f                   pop edi
// 0048376b  5e                   pop esi
// 0048376c  5d                   pop ebp
// 0048376d  5b                   pop ebx
// 0048376e  64890d00000000       mov dword ptr fs:[0], ecx
// 00483775  83c418               add esp, 0x18
// 00483778  c3                   ret 
// copied from an identical function in another client (function ??1S@@UAE@XZ)

// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
#include <vector>

struct Object {
    virtual ~Object();
};

struct Objects : std::vector<Object*> {
    Object*& at(unsigned int);
    iterator erase(iterator, iterator);
};

struct S {
    std::string name;
    Objects objects;

    virtual ~S();
};

S::~S()
{
    unsigned int count = objects.size();
    for (unsigned int i = 0; i < count; ++i) {
        Object *p = objects.at(i);
        if (p)
            delete p;
    }
    objects.erase(objects.begin(), objects.end());
}