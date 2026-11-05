// from server: 100% by nuck16
// roc 2009-12 00760030  unit: RBX::VBillboardGui::?$FactoryProduct  size: 99 bytes
//
// 00760030  64a100000000         mov eax, dword ptr fs:[0]
// 00760036  6aff                 push -1
// 00760038  688e1b9500           push 0x951b8e
// 0076003d  50                   push eax
// 0076003e  b801000000           mov eax, 1
// 00760043  64892500000000       mov dword ptr fs:[0], esp
// 0076004a  8405b87ab900         test byte ptr [0xb97ab8], al
// 00760050  752e                 jne 0x760080
// 00760052  0905b87ab900         or dword ptr [0xb97ab8], eax
// 00760058  6854e1b500           push 0xb5e154
// 0076005d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00760065  e87622edff           call 0x6322e0
// 0076006a  83c404               add esp, 4
// 0076006d  a3b47ab900           mov dword ptr [0xb97ab4], eax
// 00760072  8b0c24               mov ecx, dword ptr [esp]
// 00760075  64890d00000000       mov dword ptr fs:[0], ecx
// 0076007c  83c40c               add esp, 0xc
// 0076007f  c3                   ret 
// 00760080  8b0c24               mov ecx, dword ptr [esp]
// 00760083  a1b47ab900           mov eax, dword ptr [0xb97ab4]
// 00760088  64890d00000000       mov dword ptr fs:[0], ecx
// 0076008f  83c40c               add esp, 0xc
// 00760092  c3                   ret 

extern char string_00b5e154[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b5e154);
    return *name;
}
