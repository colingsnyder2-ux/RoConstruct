// from server: 100% by nuck16
// roc 2009-12 004f59c0  unit: RBX::GfxAttachement  size: 99 bytes
//
// 004f59c0  64a100000000         mov eax, dword ptr fs:[0]
// 004f59c6  6aff                 push -1
// 004f59c8  68ee569300           push 0x9356ee
// 004f59cd  50                   push eax
// 004f59ce  b801000000           mov eax, 1
// 004f59d3  64892500000000       mov dword ptr fs:[0], esp
// 004f59da  8405e8ddb700         test byte ptr [0xb7dde8], al
// 004f59e0  752e                 jne 0x4f5a10
// 004f59e2  0905e8ddb700         or dword ptr [0xb7dde8], eax
// 004f59e8  68d0d59d00           push 0x9dd5d0
// 004f59ed  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 004f59f5  e8e6c81300           call 0x6322e0
// 004f59fa  83c404               add esp, 4
// 004f59fd  a3e4ddb700           mov dword ptr [0xb7dde4], eax
// 004f5a02  8b0c24               mov ecx, dword ptr [esp]
// 004f5a05  64890d00000000       mov dword ptr fs:[0], ecx
// 004f5a0c  83c40c               add esp, 0xc
// 004f5a0f  c3                   ret 
// 004f5a10  8b0c24               mov ecx, dword ptr [esp]
// 004f5a13  a1e4ddb700           mov eax, dword ptr [0xb7dde4]
// 004f5a18  64890d00000000       mov dword ptr fs:[0], ecx
// 004f5a1f  83c40c               add esp, 0xc
// 004f5a22  c3                   ret 

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup("ShirtGraphic");
    return *name;
}
