// from server: 100% by nuck16
// roc 2009-12 004f56b0  unit: RBX::GfxAttachement  size: 99 bytes
//
// 004f56b0  64a100000000         mov eax, dword ptr fs:[0]
// 004f56b6  6aff                 push -1
// 004f56b8  680e569300           push 0x93560e
// 004f56bd  50                   push eax
// 004f56be  b801000000           mov eax, 1
// 004f56c3  64892500000000       mov dword ptr fs:[0], esp
// 004f56ca  8405b0ddb700         test byte ptr [0xb7ddb0], al
// 004f56d0  752e                 jne 0x4f5700
// 004f56d2  0905b0ddb700         or dword ptr [0xb7ddb0], eax
// 004f56d8  684887b300           push 0xb38748
// 004f56dd  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 004f56e5  e8f6cb1300           call 0x6322e0
// 004f56ea  83c404               add esp, 4
// 004f56ed  a3acddb700           mov dword ptr [0xb7ddac], eax
// 004f56f2  8b0c24               mov ecx, dword ptr [esp]
// 004f56f5  64890d00000000       mov dword ptr fs:[0], ecx
// 004f56fc  83c40c               add esp, 0xc
// 004f56ff  c3                   ret 
// 004f5700  8b0c24               mov ecx, dword ptr [esp]
// 004f5703  a1acddb700           mov eax, dword ptr [0xb7ddac]
// 004f5708  64890d00000000       mov dword ptr fs:[0], ecx
// 004f570f  83c40c               add esp, 0xc
// 004f5712  c3                   ret 

extern char string_00b38748[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b38748);
    return *name;
}
