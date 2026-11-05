// from server: 100% by nuck16
// roc 2009-12 0076dc50  unit: RBX::VFrame::?$FactoryProduct  size: 99 bytes
//
// 0076dc50  64a100000000         mov eax, dword ptr fs:[0]
// 0076dc56  6aff                 push -1
// 0076dc58  687e2b9500           push 0x952b7e
// 0076dc5d  50                   push eax
// 0076dc5e  b801000000           mov eax, 1
// 0076dc63  64892500000000       mov dword ptr fs:[0], esp
// 0076dc6a  84053c82b900         test byte ptr [0xb9823c], al
// 0076dc70  752e                 jne 0x76dca0
// 0076dc72  09053c82b900         or dword ptr [0xb9823c], eax
// 0076dc78  68b0fdb500           push 0xb5fdb0
// 0076dc7d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 0076dc85  e85646ecff           call 0x6322e0
// 0076dc8a  83c404               add esp, 4
// 0076dc8d  a33882b900           mov dword ptr [0xb98238], eax
// 0076dc92  8b0c24               mov ecx, dword ptr [esp]
// 0076dc95  64890d00000000       mov dword ptr fs:[0], ecx
// 0076dc9c  83c40c               add esp, 0xc
// 0076dc9f  c3                   ret 
// 0076dca0  8b0c24               mov ecx, dword ptr [esp]
// 0076dca3  a13882b900           mov eax, dword ptr [0xb98238]
// 0076dca8  64890d00000000       mov dword ptr fs:[0], ecx
// 0076dcaf  83c40c               add esp, 0xc
// 0076dcb2  c3                   ret 

extern char string_00b5fdb0[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b5fdb0);
    return *name;
}
