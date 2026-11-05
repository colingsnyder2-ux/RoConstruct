// from server: 100% by Yeetserama
// roc 2007-08 00427c40  unit: MainLogManager  size: 361 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00427c40
//
// 00427c40  6aff                 push -1
// 00427c42  6878c97300           push 0x73c978
// 00427c47  64a100000000         mov eax, dword ptr fs:[0]
// 00427c4d  50                   push eax
// 00427c4e  83ec28               sub esp, 0x28
// 00427c51  a188518b00           mov eax, dword ptr [0x8b5188]
// 00427c56  33c4                 xor eax, esp
// 00427c58  50                   push eax
// 00427c59  8d44242c             lea eax, [esp + 0x2c]
// 00427c5d  64a300000000         mov dword ptr fs:[0], eax
// 00427c63  0fb744243c           movzx eax, word ptr [esp + 0x3c]
// 00427c68  83f810               cmp eax, 0x10
// 00427c6b  0f87fe000000         ja 0x427d6f
// 00427c71  0fb680987d4200       movzx eax, byte ptr [eax + 0x427d98]
// 00427c78  ff2485807d4200       jmp dword ptr [eax*4 + 0x427d80]
// 00427c7f  8d4c2404             lea ecx, [esp + 4]
// 00427c83  51                   push ecx
// 00427c84  e827471400           call 0x56c3b0
// 00427c89  8b542444             mov edx, dword ptr [esp + 0x44]
// 00427c8d  8b00                 mov eax, dword ptr [eax]
// 00427c8f  52                   push edx
// 00427c90  685ca07800           push 0x78a05c
// 00427c95  6a01                 push 1
// 00427c97  50                   push eax
// 00427c98  c744244800000000     mov dword ptr [esp + 0x48], 0
// 00427ca0  e8fb431400           call 0x56c0a0
// 00427ca5  8d4c2418             lea ecx, [esp + 0x18]
// 00427ca9  e9b1000000           jmp 0x427d5f
// 00427cae  8d44240c             lea eax, [esp + 0xc]
// 00427cb2  50                   push eax
// 00427cb3  e8f8461400           call 0x56c3b0
// 00427cb8  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 00427cbc  8b00                 mov eax, dword ptr [eax]
// 00427cbe  51                   push ecx
// 00427cbf  685ca07800           push 0x78a05c
// 00427cc4  6a03                 push 3
// 00427cc6  50                   push eax
// 00427cc7  c744244801000000     mov dword ptr [esp + 0x48], 1
// 00427ccf  e8cc431400           call 0x56c0a0
// 00427cd4  8d4c2420             lea ecx, [esp + 0x20]
// 00427cd8  e982000000           jmp 0x427d5f
// 00427cdd  8d542414             lea edx, [esp + 0x14]
// 00427ce1  52                   push edx
// 00427ce2  e8c9461400           call 0x56c3b0
// 00427ce7  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 00427ceb  8b00                 mov eax, dword ptr [eax]
// 00427ced  51                   push ecx
// 00427cee  685ca07800           push 0x78a05c
// 00427cf3  6a01                 push 1
// 00427cf5  50                   push eax
// 00427cf6  c744244802000000     mov dword ptr [esp + 0x48], 2
// 00427cfe  e89d431400           call 0x56c0a0
// 00427d03  8d4c2428             lea ecx, [esp + 0x28]
// 00427d07  eb56                 jmp 0x427d5f
// 00427d09  8d54241c             lea edx, [esp + 0x1c]
// 00427d0d  52                   push edx
// 00427d0e  e89d461400           call 0x56c3b0
// 00427d13  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 00427d17  8b00                 mov eax, dword ptr [eax]
// 00427d19  51                   push ecx
// 00427d1a  685ca07800           push 0x78a05c
// 00427d1f  6a01                 push 1
// 00427d21  50                   push eax
// 00427d22  c744244803000000     mov dword ptr [esp + 0x48], 3
// 00427d2a  e871431400           call 0x56c0a0
// 00427d2f  8d4c2430             lea ecx, [esp + 0x30]
// 00427d33  eb2a                 jmp 0x427d5f
// 00427d35  8d542424             lea edx, [esp + 0x24]
// 00427d39  52                   push edx
// 00427d3a  e871461400           call 0x56c3b0
// 00427d3f  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 00427d43  8b00                 mov eax, dword ptr [eax]
// 00427d45  51                   push ecx
// 00427d46  685ca07800           push 0x78a05c
// 00427d4b  6a03                 push 3
// 00427d4d  50                   push eax
// 00427d4e  c744244804000000     mov dword ptr [esp + 0x48], 4
// 00427d56  e845431400           call 0x56c0a0
// 00427d5b  8d4c2438             lea ecx, [esp + 0x38]
// 00427d5f  83c414               add esp, 0x14
// 00427d62  c7442434ffffffff     mov dword ptr [esp + 0x34], 0xffffffff
// 00427d6a  e8f1a50600           call 0x492360
// 00427d6f  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00427d73  64890d00000000       mov dword ptr fs:[0], ecx
// 00427d7a  59                   pop ecx
// 00427d7b  83c434               add esp, 0x34
// 00427d7e  c3                   ret 
// 00427d7f  90                   nop 
// 00427d80  7f7c                 jg 0x427dfe
// 00427d82  42                   inc edx
// 00427d83  00ae7c4200dd         add byte ptr [esi - 0x22ffbd84], ch
// 00427d89  7c42                 jl 0x427dcd
// 00427d8b  0009                 add byte ptr [ecx], cl
// 00427d8d  7d42                 jge 0x427dd1
// 00427d8f  00357d42006f         add byte ptr [0x6f00427d], dh
// 00427d95  7d42                 jge 0x427dd9
// 00427d97  0000                 add byte ptr [eax], al
// 00427d99  010505020505         add dword ptr [0x5050205], eax
// 00427d9f  0503050505           add eax, 0x5050503
// 00427da4  0505050504           add eax, 0x4050505
// copied from an identical function in another client (function ?reportStatus@ns_ROCX000019@@YAXGPBD@Z)

namespace ns_ROCX000019 {
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
