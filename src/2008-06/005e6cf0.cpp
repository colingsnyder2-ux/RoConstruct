// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_clumppipelinedcleanup892f336e907113db.cpp

// Candidate translation unit (score above; library headers required).
#include "G3D/Array.h"
#include "util/ComputeProp.h"
#include <stddef.h>
#include <vector>
// from server: 82% by king_originala
// roc 2008-06 005e6cf0  unit: RBX::Clump  size: 233 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005e6cf0
//
// 005e6cf0  6aff                 push -1
// 005e6cf2  684e687d00           push 0x7d684e
// 005e6cf7  64a100000000         mov eax, dword ptr fs:[0]
// 005e6cfd  50                   push eax
// 005e6cfe  64892500000000       mov dword ptr fs:[0], esp
// 005e6d05  83ec08               sub esp, 8
// 005e6d08  53                   push ebx
// 005e6d09  55                   push ebp
// 005e6d0a  33ed                 xor ebp, ebp
// 005e6d0c  56                   push esi
// 005e6d0d  8bf1                 mov esi, ecx
// 005e6d0f  896e04               mov dword ptr [esi + 4], ebp
// 005e6d12  c706acf78300         mov dword ptr [esi], 0x83f7ac
// 005e6d18  57                   push edi
// 005e6d19  89742414             mov dword ptr [esp + 0x14], esi
// 005e6d1d  896e0c               mov dword ptr [esi + 0xc], ebp
// 005e6d20  896e10               mov dword ptr [esi + 0x10], ebp
// 005e6d23  896e08               mov dword ptr [esi + 8], ebp
// 005e6d26  8b442428             mov eax, dword ptr [esp + 0x28]
// 005e6d2a  b301                 mov bl, 1
// 005e6d2c  6a04                 push 4
// 005e6d2e  896c2424             mov dword ptr [esp + 0x24], ebp
// 005e6d32  885e14               mov byte ptr [esi + 0x14], bl
// 005e6d35  896e18               mov dword ptr [esi + 0x18], ebp
// 005e6d38  89461c               mov dword ptr [esi + 0x1c], eax
// 005e6d3b  896e20               mov dword ptr [esi + 0x20], ebp
// 005e6d3e  8d7e28               lea edi, [esi + 0x28]
// 005e6d41  e8da9b0b00           call 0x6a0920
// 005e6d46  83c404               add esp, 4
// 005e6d49  3bc5                 cmp eax, ebp
// 005e6d4b  7404                 je 0x5e6d51
// 005e6d4d  8938                 mov dword ptr [eax], edi
// 005e6d4f  eb02                 jmp 0x5e6d53
// 005e6d51  33c0                 xor eax, eax
// 005e6d53  8907                 mov dword ptr [edi], eax
// 005e6d55  896f0c               mov dword ptr [edi + 0xc], ebp
// 005e6d58  896f10               mov dword ptr [edi + 0x10], ebp
// 005e6d5b  896f14               mov dword ptr [edi + 0x14], ebp
// 005e6d5e  896e40               mov dword ptr [esi + 0x40], ebp
// 005e6d61  83c8ff               or eax, 0xffffffff
// 005e6d64  894644               mov dword ptr [esi + 0x44], eax
// 005e6d67  894648               mov dword ptr [esi + 0x48], eax
// 005e6d6a  885e54               mov byte ptr [esi + 0x54], bl
// 005e6d6d  897658               mov dword ptr [esi + 0x58], esi
// 005e6d70  b820645e00           mov eax, 0x5e6420
// 005e6d75  894660               mov dword ptr [esi + 0x60], eax
// 005e6d78  33c9                 xor ecx, ecx
// 005e6d7a  894e64               mov dword ptr [esi + 0x64], ecx
// 005e6d7d  b820615e00           mov eax, 0x5e6120
// 005e6d82  894e74               mov dword ptr [esi + 0x74], ecx
// 005e6d85  885e69               mov byte ptr [esi + 0x69], bl
// 005e6d88  89766c               mov dword ptr [esi + 0x6c], esi
// 005e6d8b  894670               mov dword ptr [esi + 0x70], eax
// 005e6d8e  8b7e1c               mov edi, dword ptr [esi + 0x1c]
// 005e6d91  56                   push esi
// 005e6d92  8bcf                 mov ecx, edi
// 005e6d94  c644242402           mov byte ptr [esp + 0x24], 2
// 005e6d99  897624               mov dword ptr [esi + 0x24], esi
// 005e6d9c  e8af070000           call 0x5e7550
// 005e6da1  8b8fa0000000         mov ecx, dword ptr [edi + 0xa0]
// 005e6da7  55                   push ebp
// 005e6da8  e803db0200           call 0x6148b0
// 005e6dad  885e14               mov byte ptr [esi + 0x14], bl
// 005e6db0  885e54               mov byte ptr [esi + 0x54], bl
// 005e6db3  885e69               mov byte ptr [esi + 0x69], bl
// 005e6db6  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 005e6db9  3bcd                 cmp ecx, ebp
// 005e6dbb  7405                 je 0x5e6dc2
// 005e6dbd  e8def4ffff           call 0x5e62a0
// 005e6dc2  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 005e6dc6  5f                   pop edi
// 005e6dc7  8bc6                 mov eax, esi
// 005e6dc9  5e                   pop esi
// 005e6dca  5d                   pop ebp
// 005e6dcb  5b                   pop ebx
// 005e6dcc  64890d00000000       mov dword ptr fs:[0], ecx
// 005e6dd3  83c414               add esp, 0x14
// 005e6dd6  c20400               ret 4

void* __cdecl operator new(unsigned int);

struct __multiple_inheritance Clump;

struct Action {
    void reset(int);
};

struct Ball {
    char pad[0x5c];
    int field_5c;
    char pad60[0x40];
    Action* action;
    void setField(int);
};

struct Pending {
    void refresh();
};

typedef std::vector<void*> Links;

struct __declspec(novtable) Base {
    int references;
    Base() { references = 0; }
    virtual ~Base() {}
};

struct EmptyBase {
};

struct Triplet {
    int allocation;
    int first;
    int last;
    Triplet() : first(0), last(0) { allocation = 0; }
};

struct Zero {
    int value;
    Zero() : value(0) {}
};

#pragma pack(push,4)
struct BindingA {
    Clump* owner;
    int unused;
    void (Clump::*function)();

    BindingA(Clump* p, void (Clump::*f)()) : owner(p) {
        function = f;
    }

};

struct BindingB {
    Clump* owner;
    void (Clump::*function)();

    BindingB(Clump* p, void (Clump::*f)()) : owner(p) {
        function = f;
    }
};

#pragma pack(pop)
struct Clump : Base, EmptyBase {
    G3D::Array<void*> fields;
    bool dirty;
    char pad15[3];
    int field18;
    Ball* ball;
    Pending* pending;
    Clump* self;
    Links links;
    Zero field40;
    int field44;
    int field48;
    char pad4c[4];
    RBX::ComputeProp<float,Clump> maxRadius;
    RBX::ComputeProp<bool,Clump> canSleep;

    Clump(Ball*);
    virtual ~Clump();
    float callbackA()const;
    bool callbackB()const;
};

Clump::Clump(Ball* p)
    : dirty(true), field18(0), ball(p), pending(0),
      field44(-1), field48(-1),
      maxRadius(this, &Clump::callbackA),
      canSleep(this, &Clump::callbackB)
{
    Ball* b = ball;
    self = this;
    b->setField(reinterpret_cast<int>(this));
    b->action->reset(0);
    dirty = true;
    maxRadius.setDirty();
    canSleep.setDirty();
    if (pending)
        pending->refresh();
}


typedef char checkRadius[(offsetof(Clump,maxRadius)==0x50)?1:-1];
typedef char checkSleep[(offsetof(Clump,canSleep)==0x68)?1:-1];
