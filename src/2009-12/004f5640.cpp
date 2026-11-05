// from server: 100% by nuck16
// roc 2009-12 004f5640  unit: RBX::GfxAttachement  size: 99 bytes
//
// 004f5640  64a100000000         mov eax, dword ptr fs:[0]
// 004f5646  6aff                 push -1
// 004f5648  68ee559300           push 0x9355ee
// 004f564d  50                   push eax
// 004f564e  b801000000           mov eax, 1
// 004f5653  64892500000000       mov dword ptr fs:[0], esp
// 004f565a  8405a8ddb700         test byte ptr [0xb7dda8], al
// 004f5660  752e                 jne 0x4f5690
// 004f5662  0905a8ddb700         or dword ptr [0xb7dda8], eax
// 004f5668  68aca0b100           push 0xb1a0ac
// 004f566d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 004f5675  e866cc1300           call 0x6322e0
// 004f567a  83c404               add esp, 4
// 004f567d  a3a4ddb700           mov dword ptr [0xb7dda4], eax
// 004f5682  8b0c24               mov ecx, dword ptr [esp]
// 004f5685  64890d00000000       mov dword ptr fs:[0], ecx
// 004f568c  83c40c               add esp, 0xc
// 004f568f  c3                   ret 
// 004f5690  8b0c24               mov ecx, dword ptr [esp]
// 004f5693  a1a4ddb700           mov eax, dword ptr [0xb7dda4]
// 004f5698  64890d00000000       mov dword ptr fs:[0], ecx
// 004f569f  83c40c               add esp, 0xc
// 004f56a2  c3                   ret 

extern char string_00b1a0ac[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b1a0ac);
    return *name;
}
