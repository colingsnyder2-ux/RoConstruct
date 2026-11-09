// from server: 100% by nuck16
// roc 2009-12 004039d0  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 99 bytes
//
// 004039d0  64a100000000         mov eax, dword ptr fs:[0]
// 004039d6  6aff                 push -1
// 004039d8  688e709200           push 0x92708e
// 004039dd  50                   push eax
// 004039de  b801000000           mov eax, 1
// 004039e3  64892500000000       mov dword ptr fs:[0], esp
// 004039ea  84058095b700         test byte ptr [0xb79580], al
// 004039f0  752e                 jne 0x403a20
// 004039f2  09058095b700         or dword ptr [0xb79580], eax
// 004039f8  68b428b100           push 0xb128b4
// 004039fd  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00403a05  e8d6e82200           call 0x6322e0
// 00403a0a  83c404               add esp, 4
// 00403a0d  a37c95b700           mov dword ptr [0xb7957c], eax
// 00403a12  8b0c24               mov ecx, dword ptr [esp]
// 00403a15  64890d00000000       mov dword ptr fs:[0], ecx
// 00403a1c  83c40c               add esp, 0xc
// 00403a1f  c3                   ret 
// 00403a20  8b0c24               mov ecx, dword ptr [esp]
// 00403a23  a17c95b700           mov eax, dword ptr [0xb7957c]
// 00403a28  64890d00000000       mov dword ptr fs:[0], ecx
// 00403a2f  83c40c               add esp, 0xc
// 00403a32  c3                   ret 

extern char string_00b128b4[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b128b4);
    return *name;
}
