// from server: 100% by Yeetserama
// roc 2011-06 00604f00  unit: RBX::ClearBackpack  size: 179 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00604f00
//
// 00604f00  6aff                 push -1
// 00604f02  68a37f9e00           push 0x9e7fa3
// 00604f07  64a100000000         mov eax, dword ptr fs:[0]
// 00604f0d  50                   push eax
// 00604f0e  64892500000000       mov dword ptr fs:[0], esp
// 00604f15  51                   push ecx
// 00604f16  56                   push esi
// 00604f17  57                   push edi
// 00604f18  8bf9                 mov edi, ecx
// 00604f1a  897c2408             mov dword ptr [esp + 8], edi
// 00604f1e  c7071c30a900         mov dword ptr [edi], 0xa9301c
// 00604f24  8b771c               mov esi, dword ptr [edi + 0x1c]
// 00604f27  c744241401000000     mov dword ptr [esp + 0x14], 1
// 00604f2f  85f6                 test esi, esi
// 00604f31  742a                 je 0x604f5d
// 00604f33  8d4604               lea eax, [esi + 4]
// 00604f36  83c9ff               or ecx, 0xffffffff
// 00604f39  f00fc108             lock xadd dword ptr [eax], ecx
// 00604f3d  751e                 jne 0x604f5d
// 00604f3f  8b16                 mov edx, dword ptr [esi]
// 00604f41  8b4204               mov eax, dword ptr [edx + 4]
// 00604f44  8bce                 mov ecx, esi
// 00604f46  ffd0                 call eax
// 00604f48  8d4e08               lea ecx, [esi + 8]
// 00604f4b  83caff               or edx, 0xffffffff
// 00604f4e  f00fc111             lock xadd dword ptr [ecx], edx
// 00604f52  7509                 jne 0x604f5d
// 00604f54  8b06                 mov eax, dword ptr [esi]
// 00604f56  8b5008               mov edx, dword ptr [eax + 8]
// 00604f59  8bce                 mov ecx, esi
// 00604f5b  ffd2                 call edx
// 00604f5d  8b7710               mov esi, dword ptr [edi + 0x10]
// 00604f60  c644241400           mov byte ptr [esp + 0x14], 0
// 00604f65  85f6                 test esi, esi
// 00604f67  742a                 je 0x604f93
// 00604f69  8d4604               lea eax, [esi + 4]
// 00604f6c  83c9ff               or ecx, 0xffffffff
// 00604f6f  f00fc108             lock xadd dword ptr [eax], ecx
// 00604f73  751e                 jne 0x604f93
// 00604f75  8b16                 mov edx, dword ptr [esi]
// 00604f77  8b4204               mov eax, dword ptr [edx + 4]
// 00604f7a  8bce                 mov ecx, esi
// 00604f7c  ffd0                 call eax
// 00604f7e  8d4e08               lea ecx, [esi + 8]
// 00604f81  83caff               or edx, 0xffffffff
// 00604f84  f00fc111             lock xadd dword ptr [ecx], edx
// 00604f88  7509                 jne 0x604f93
// 00604f8a  8b06                 mov eax, dword ptr [esi]
// 00604f8c  8b5008               mov edx, dword ptr [eax + 8]
// 00604f8f  8bce                 mov ecx, esi
// 00604f91  ffd2                 call edx
// 00604f93  8bcf                 mov ecx, edi
// 00604f95  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 00604f9d  e8be580000           call 0x60a860
// 00604fa2  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00604fa6  5f                   pop edi
// 00604fa7  5e                   pop esi
// 00604fa8  64890d00000000       mov dword ptr fs:[0], ecx
// 00604faf  83c410               add esp, 0x10
// 00604fb2  c3                   ret 
// copied from an identical function in another client (function ??1ClearBackpack@ns_ROCX00000c@@UAE@XZ)

namespace ns_ROCX00000c {
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
