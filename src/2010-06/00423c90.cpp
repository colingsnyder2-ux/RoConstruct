// from server: 100% by Yeetserama
// roc 2010-06 00423c90  unit: LogManager  size: 349 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00423c90
//
// 00423c90  64a100000000         mov eax, dword ptr fs:[0]
// 00423c96  6aff                 push -1
// 00423c98  68f8f89700           push 0x97f8f8
// 00423c9d  50                   push eax
// 00423c9e  0fb7442410           movzx eax, word ptr [esp + 0x10]
// 00423ca3  64892500000000       mov dword ptr fs:[0], esp
// 00423caa  83ec28               sub esp, 0x28
// 00423cad  83f810               cmp eax, 0x10
// 00423cb0  0f87fd000000         ja 0x423db3
// 00423cb6  0fb680dc3d4200       movzx eax, byte ptr [eax + 0x423ddc]
// 00423cbd  ff2485c43d4200       jmp dword ptr [eax*4 + 0x423dc4]
// 00423cc4  8d0c24               lea ecx, [esp]
// 00423cc7  51                   push ecx
// 00423cc8  e893cb1700           call 0x5a0860
// 00423ccd  8b542440             mov edx, dword ptr [esp + 0x40]
// 00423cd1  8b00                 mov eax, dword ptr [eax]
// 00423cd3  52                   push edx
// 00423cd4  68e444a000           push 0xa044e4
// 00423cd9  6a01                 push 1
// 00423cdb  50                   push eax
// 00423cdc  c744244400000000     mov dword ptr [esp + 0x44], 0
// 00423ce4  e817c91700           call 0x5a0600
// 00423ce9  8d4c2414             lea ecx, [esp + 0x14]
// 00423ced  e9b1000000           jmp 0x423da3
// 00423cf2  8d442408             lea eax, [esp + 8]
// 00423cf6  50                   push eax
// 00423cf7  e864cb1700           call 0x5a0860
// 00423cfc  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 00423d00  8b00                 mov eax, dword ptr [eax]
// 00423d02  51                   push ecx
// 00423d03  68e444a000           push 0xa044e4
// 00423d08  6a03                 push 3
// 00423d0a  50                   push eax
// 00423d0b  c744244401000000     mov dword ptr [esp + 0x44], 1
// 00423d13  e8e8c81700           call 0x5a0600
// 00423d18  8d4c241c             lea ecx, [esp + 0x1c]
// 00423d1c  e982000000           jmp 0x423da3
// 00423d21  8d542410             lea edx, [esp + 0x10]
// 00423d25  52                   push edx
// 00423d26  e835cb1700           call 0x5a0860
// 00423d2b  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 00423d2f  8b00                 mov eax, dword ptr [eax]
// 00423d31  51                   push ecx
// 00423d32  68e444a000           push 0xa044e4
// 00423d37  6a01                 push 1
// 00423d39  50                   push eax
// 00423d3a  c744244402000000     mov dword ptr [esp + 0x44], 2
// 00423d42  e8b9c81700           call 0x5a0600
// 00423d47  8d4c2424             lea ecx, [esp + 0x24]
// 00423d4b  eb56                 jmp 0x423da3
// 00423d4d  8d542418             lea edx, [esp + 0x18]
// 00423d51  52                   push edx
// 00423d52  e809cb1700           call 0x5a0860
// 00423d57  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 00423d5b  8b00                 mov eax, dword ptr [eax]
// 00423d5d  51                   push ecx
// 00423d5e  68e444a000           push 0xa044e4
// 00423d63  6a01                 push 1
// 00423d65  50                   push eax
// 00423d66  c744244403000000     mov dword ptr [esp + 0x44], 3
// 00423d6e  e88dc81700           call 0x5a0600
// 00423d73  8d4c242c             lea ecx, [esp + 0x2c]
// 00423d77  eb2a                 jmp 0x423da3
// 00423d79  8d542420             lea edx, [esp + 0x20]
// 00423d7d  52                   push edx
// 00423d7e  e8ddca1700           call 0x5a0860
// 00423d83  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 00423d87  8b00                 mov eax, dword ptr [eax]
// 00423d89  51                   push ecx
// 00423d8a  68e444a000           push 0xa044e4
// 00423d8f  6a03                 push 3
// 00423d91  50                   push eax
// 00423d92  c744244404000000     mov dword ptr [esp + 0x44], 4
// 00423d9a  e861c81700           call 0x5a0600
// 00423d9f  8d4c2434             lea ecx, [esp + 0x34]
// 00423da3  83c414               add esp, 0x14
// 00423da6  c7442430ffffffff     mov dword ptr [esp + 0x30], 0xffffffff
// 00423dae  e80dd31700           call 0x5a10c0
// 00423db3  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00423db7  64890d00000000       mov dword ptr fs:[0], ecx
// 00423dbe  83c434               add esp, 0x34
// 00423dc1  c3                   ret 
// 00423dc2  8bff                 mov edi, edi
// 00423dc4  c43c42               les edi, ptr [edx + eax*2]
// 00423dc7  00f2                 add dl, dh
// 00423dc9  3c42                 cmp al, 0x42
// 00423dcb  0021                 add byte ptr [ecx], ah
// 00423dcd  3d42004d3d           cmp eax, 0x3d4d0042
// 00423dd2  42                   inc edx
// 00423dd3  00793d               add byte ptr [ecx + 0x3d], bh
// 00423dd6  42                   inc edx
// 00423dd7  00b33d420000         add byte ptr [ebx + 0x423d], dh
// 00423ddd  010505020505         add dword ptr [0x5050205], eax
// 00423de3  0503050505           add eax, 0x5050503
// 00423de8  0505050504           add eax, 0x4050505
// copied from an identical function in another client (function ?reportStatus@ns_ROCX000003@@YAXGPBD@Z)

namespace ns_ROCX000003 {
struct SharedHandle
{
    void* pointer;
    void* get() const { return pointer; }
    void* control;
    ~SharedHandle();
};

SharedHandle __cdecl getHandle();
void __cdecl report(void*, int, const char*, ...);
extern const char reportFormat[];

void __cdecl reportStatus(unsigned short status, const char* message)
{
    switch (status)
    {
    case 0:
        report(getHandle().get(), 1, reportFormat, message);
        break;
    case 1:
        report(getHandle().get(), 3, reportFormat, message);
        break;
    case 4:
        report(getHandle().get(), 1, reportFormat, message);
        break;
    case 8:
        report(getHandle().get(), 1, reportFormat, message);
        break;
    case 16:
        report(getHandle().get(), 3, reportFormat, message);
        break;
    }
}
}
