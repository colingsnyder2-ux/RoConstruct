// from server: 100% by EspClaude
// roc 2009-06 0060b7d0  unit: RBX::ClearBackpack  size: 179 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0060b7d0
//
// 0060b7d0  6aff                 push -1
// 0060b7d2  6843788600           push 0x867843
// 0060b7d7  64a100000000         mov eax, dword ptr fs:[0]
// 0060b7dd  50                   push eax
// 0060b7de  64892500000000       mov dword ptr fs:[0], esp
// 0060b7e5  51                   push ecx
// 0060b7e6  56                   push esi
// 0060b7e7  57                   push edi
// 0060b7e8  8bf9                 mov edi, ecx
// 0060b7ea  897c2408             mov dword ptr [esp + 8], edi
// 0060b7ee  c70728848d00         mov dword ptr [edi], 0x8d8428
// 0060b7f4  8b771c               mov esi, dword ptr [edi + 0x1c]
// 0060b7f7  c744241401000000     mov dword ptr [esp + 0x14], 1
// 0060b7ff  85f6                 test esi, esi
// 0060b801  742a                 je 0x60b82d
// 0060b803  8d4604               lea eax, [esi + 4]
// 0060b806  83c9ff               or ecx, 0xffffffff
// 0060b809  f00fc108             lock xadd dword ptr [eax], ecx
// 0060b80d  751e                 jne 0x60b82d
// 0060b80f  8b16                 mov edx, dword ptr [esi]
// 0060b811  8b4204               mov eax, dword ptr [edx + 4]
// 0060b814  8bce                 mov ecx, esi
// 0060b816  ffd0                 call eax
// 0060b818  8d4e08               lea ecx, [esi + 8]
// 0060b81b  83caff               or edx, 0xffffffff
// 0060b81e  f00fc111             lock xadd dword ptr [ecx], edx
// 0060b822  7509                 jne 0x60b82d
// 0060b824  8b06                 mov eax, dword ptr [esi]
// 0060b826  8b5008               mov edx, dword ptr [eax + 8]
// 0060b829  8bce                 mov ecx, esi
// 0060b82b  ffd2                 call edx
// 0060b82d  8b7710               mov esi, dword ptr [edi + 0x10]
// 0060b830  c644241400           mov byte ptr [esp + 0x14], 0
// 0060b835  85f6                 test esi, esi
// 0060b837  742a                 je 0x60b863
// 0060b839  8d4604               lea eax, [esi + 4]
// 0060b83c  83c9ff               or ecx, 0xffffffff
// 0060b83f  f00fc108             lock xadd dword ptr [eax], ecx
// 0060b843  751e                 jne 0x60b863
// 0060b845  8b16                 mov edx, dword ptr [esi]
// 0060b847  8b4204               mov eax, dword ptr [edx + 4]
// 0060b84a  8bce                 mov ecx, esi
// 0060b84c  ffd0                 call eax
// 0060b84e  8d4e08               lea ecx, [esi + 8]
// 0060b851  83caff               or edx, 0xffffffff
// 0060b854  f00fc111             lock xadd dword ptr [ecx], edx
// 0060b858  7509                 jne 0x60b863
// 0060b85a  8b06                 mov eax, dword ptr [esi]
// 0060b85c  8b5008               mov edx, dword ptr [eax + 8]
// 0060b85f  8bce                 mov ecx, esi
// 0060b861  ffd2                 call edx
// 0060b863  8bcf                 mov ecx, edi
// 0060b865  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 0060b86d  e82e500000           call 0x6108a0
// 0060b872  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0060b876  5f                   pop edi
// 0060b877  5e                   pop esi
// 0060b878  64890d00000000       mov dword ptr fs:[0], ecx
// 0060b87f  83c410               add esp, 0x10
// 0060b882  c3                   ret 
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
