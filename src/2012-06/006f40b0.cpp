// from server: 100% by Xemicl
// roc 2012-06 006f40b0  unit: RBX::ClearBackpack  size: 179 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006f40b0
//
// 006f40b0  6aff                 push -1
// 006f40b2  68a3cbab00           push 0xabcba3
// 006f40b7  64a100000000         mov eax, dword ptr fs:[0]
// 006f40bd  50                   push eax
// 006f40be  64892500000000       mov dword ptr fs:[0], esp
// 006f40c5  51                   push ecx
// 006f40c6  56                   push esi
// 006f40c7  57                   push edi
// 006f40c8  8bf9                 mov edi, ecx
// 006f40ca  897c2408             mov dword ptr [esp + 8], edi
// 006f40ce  c707a8c3b900         mov dword ptr [edi], 0xb9c3a8
// 006f40d4  8b771c               mov esi, dword ptr [edi + 0x1c]
// 006f40d7  c744241401000000     mov dword ptr [esp + 0x14], 1
// 006f40df  85f6                 test esi, esi
// 006f40e1  742a                 je 0x6f410d
// 006f40e3  8d4604               lea eax, [esi + 4]
// 006f40e6  83c9ff               or ecx, 0xffffffff
// 006f40e9  f00fc108             lock xadd dword ptr [eax], ecx
// 006f40ed  751e                 jne 0x6f410d
// 006f40ef  8b16                 mov edx, dword ptr [esi]
// 006f40f1  8b4204               mov eax, dword ptr [edx + 4]
// 006f40f4  8bce                 mov ecx, esi
// 006f40f6  ffd0                 call eax
// 006f40f8  8d4e08               lea ecx, [esi + 8]
// 006f40fb  83caff               or edx, 0xffffffff
// 006f40fe  f00fc111             lock xadd dword ptr [ecx], edx
// 006f4102  7509                 jne 0x6f410d
// 006f4104  8b06                 mov eax, dword ptr [esi]
// 006f4106  8b5008               mov edx, dword ptr [eax + 8]
// 006f4109  8bce                 mov ecx, esi
// 006f410b  ffd2                 call edx
// 006f410d  8b7710               mov esi, dword ptr [edi + 0x10]
// 006f4110  c644241400           mov byte ptr [esp + 0x14], 0
// 006f4115  85f6                 test esi, esi
// 006f4117  742a                 je 0x6f4143
// 006f4119  8d4604               lea eax, [esi + 4]
// 006f411c  83c9ff               or ecx, 0xffffffff
// 006f411f  f00fc108             lock xadd dword ptr [eax], ecx
// 006f4123  751e                 jne 0x6f4143
// 006f4125  8b16                 mov edx, dword ptr [esi]
// 006f4127  8b4204               mov eax, dword ptr [edx + 4]
// 006f412a  8bce                 mov ecx, esi
// 006f412c  ffd0                 call eax
// 006f412e  8d4e08               lea ecx, [esi + 8]
// 006f4131  83caff               or edx, 0xffffffff
// 006f4134  f00fc111             lock xadd dword ptr [ecx], edx
// 006f4138  7509                 jne 0x6f4143
// 006f413a  8b06                 mov eax, dword ptr [esi]
// 006f413c  8b5008               mov edx, dword ptr [eax + 8]
// 006f413f  8bce                 mov ecx, esi
// 006f4141  ffd2                 call edx
// 006f4143  8bcf                 mov ecx, edi
// 006f4145  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 006f414d  e85e760000           call 0x6fb7b0
// 006f4152  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 006f4156  5f                   pop edi
// 006f4157  5e                   pop esi
// 006f4158  64890d00000000       mov dword ptr fs:[0], ecx
// 006f415f  83c410               add esp, 0x10
// 006f4162  c3                   ret 
// copied from an identical function in another client (function ??1ClearBackpack@ns_ROCX00001c@@UAE@XZ)

namespace ns_ROCX00001c {
// from server: 82% by king_originala
// roc 2008-06 0057e050  unit: RBX::ClearBackpack  size: 179 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0057e050
//
// 0057e050  6aff                 push -1
// 0057e052  68c30f7d00           push 0x7d0fc3
// 0057e057  64a100000000         mov eax, dword ptr fs:[0]
// 0057e05d  50                   push eax
// 0057e05e  64892500000000       mov dword ptr fs:[0], esp
// 0057e065  51                   push ecx
// 0057e066  56                   push esi
// 0057e067  57                   push edi
// 0057e068  8bf9                 mov edi, ecx
// 0057e06a  897c2408             mov dword ptr [esp + 8], edi
// 0057e06e  c70764078300         mov dword ptr [edi], 0x830764
// 0057e074  8b771c               mov esi, dword ptr [edi + 0x1c]
// 0057e077  c744241401000000     mov dword ptr [esp + 0x14], 1
// 0057e07f  85f6                 test esi, esi
// 0057e081  742a                 je 0x57e0ad
// 0057e083  8d4604               lea eax, [esi + 4]
// 0057e086  83c9ff               or ecx, 0xffffffff
// 0057e089  f00fc108             lock xadd dword ptr [eax], ecx
// 0057e08d  751e                 jne 0x57e0ad
// 0057e08f  8b16                 mov edx, dword ptr [esi]
// 0057e091  8b4204               mov eax, dword ptr [edx + 4]
// 0057e094  8bce                 mov ecx, esi
// 0057e096  ffd0                 call eax
// 0057e098  8d4e08               lea ecx, [esi + 8]
// 0057e09b  83caff               or edx, 0xffffffff
// 0057e09e  f00fc111             lock xadd dword ptr [ecx], edx
// 0057e0a2  7509                 jne 0x57e0ad
// 0057e0a4  8b06                 mov eax, dword ptr [esi]
// 0057e0a6  8b5008               mov edx, dword ptr [eax + 8]
// 0057e0a9  8bce                 mov ecx, esi
// 0057e0ab  ffd2                 call edx
// 0057e0ad  8b7710               mov esi, dword ptr [edi + 0x10]
// 0057e0b0  c644241400           mov byte ptr [esp + 0x14], 0
// 0057e0b5  85f6                 test esi, esi
// 0057e0b7  742a                 je 0x57e0e3
// 0057e0b9  8d4604               lea eax, [esi + 4]
// 0057e0bc  83c9ff               or ecx, 0xffffffff
// 0057e0bf  f00fc108             lock xadd dword ptr [eax], ecx
// 0057e0c3  751e                 jne 0x57e0e3
// 0057e0c5  8b16                 mov edx, dword ptr [esi]
// 0057e0c7  8b4204               mov eax, dword ptr [edx + 4]
// 0057e0ca  8bce                 mov ecx, esi
// 0057e0cc  ffd0                 call eax
// 0057e0ce  8d4e08               lea ecx, [esi + 8]
// 0057e0d1  83caff               or edx, 0xffffffff
// 0057e0d4  f00fc111             lock xadd dword ptr [ecx], edx
// 0057e0d8  7509                 jne 0x57e0e3
// 0057e0da  8b06                 mov eax, dword ptr [esi]
// 0057e0dc  8b5008               mov edx, dword ptr [eax + 8]
// 0057e0df  8bce                 mov ecx, esi
// 0057e0e1  ffd2                 call edx
// 0057e0e3  8bcf                 mov ecx, edi
// 0057e0e5  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 0057e0ed  e8ce510000           call 0x5832c0
// 0057e0f2  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0057e0f6  5f                   pop edi
// 0057e0f7  5e                   pop esi
// 0057e0f8  64890d00000000       mov dword ptr fs:[0], ecx
// 0057e0ff  83c410               add esp, 0x10
// 0057e102  c3                   ret 

extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual ~Control();
    virtual void dispose();
    virtual void destroy();

    volatile long strong;
    volatile long weak;
};

struct Reference {
    void* object;
    Control* control;

    ~Reference()
    {
        Control* p = control;
        if (p && _InterlockedDecrement(&p->strong) == 0) {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
};

struct Base {
    virtual ~Base();
    unsigned char padding[8];
};

struct ClearBackpack : Base {
    Reference first;
    unsigned char padding[4];
    Reference second;

    virtual ~ClearBackpack();
};

ClearBackpack::~ClearBackpack()
{
}
}