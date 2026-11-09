// from server: 100% by colin
// from server: 95% by king_originala
// roc 2008-06 00427c20  unit: RobloxCrashReporter  size: 349 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00427c20
//
// 00427c20  64a100000000         mov eax, dword ptr fs:[0]
// 00427c26  6aff                 push -1
// 00427c28  6888f07b00           push 0x7bf088
// 00427c2d  50                   push eax
// 00427c2e  0fb7442410           movzx eax, word ptr [esp + 0x10]
// 00427c33  64892500000000       mov dword ptr fs:[0], esp
// 00427c3a  83ec28               sub esp, 0x28
// 00427c3d  83f810               cmp eax, 0x10
// 00427c40  0f87fd000000         ja 0x427d43
// 00427c46  0fb6806c7d4200       movzx eax, byte ptr [eax + 0x427d6c]
// 00427c4d  ff2485547d4200       jmp dword ptr [eax*4 + 0x427d54]
// 00427c54  8d0c24               lea ecx, [esp]
// 00427c57  51                   push ecx
// 00427c58  e8c3191400           call 0x569620
// 00427c5d  8b542440             mov edx, dword ptr [esp + 0x40]
// 00427c61  8b00                 mov eax, dword ptr [eax]
// 00427c63  52                   push edx
// 00427c64  68ac038100           push 0x8103ac
// 00427c69  6a01                 push 1
// 00427c6b  50                   push eax
// 00427c6c  c744244400000000     mov dword ptr [esp + 0x44], 0
// 00427c74  e827171400           call 0x5693a0
// 00427c79  8d4c2414             lea ecx, [esp + 0x14]
// 00427c7d  e9b1000000           jmp 0x427d33
// 00427c82  8d442408             lea eax, [esp + 8]
// 00427c86  50                   push eax
// 00427c87  e894191400           call 0x569620
// 00427c8c  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 00427c90  8b00                 mov eax, dword ptr [eax]
// 00427c92  51                   push ecx
// 00427c93  68ac038100           push 0x8103ac
// 00427c98  6a03                 push 3
// 00427c9a  50                   push eax
// 00427c9b  c744244401000000     mov dword ptr [esp + 0x44], 1
// 00427ca3  e8f8161400           call 0x5693a0
// 00427ca8  8d4c241c             lea ecx, [esp + 0x1c]
// 00427cac  e982000000           jmp 0x427d33
// 00427cb1  8d542410             lea edx, [esp + 0x10]
// 00427cb5  52                   push edx
// 00427cb6  e865191400           call 0x569620
// 00427cbb  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 00427cbf  8b00                 mov eax, dword ptr [eax]
// 00427cc1  51                   push ecx
// 00427cc2  68ac038100           push 0x8103ac
// 00427cc7  6a01                 push 1
// 00427cc9  50                   push eax
// 00427cca  c744244402000000     mov dword ptr [esp + 0x44], 2
// 00427cd2  e8c9161400           call 0x5693a0
// 00427cd7  8d4c2424             lea ecx, [esp + 0x24]
// 00427cdb  eb56                 jmp 0x427d33
// 00427cdd  8d542418             lea edx, [esp + 0x18]
// 00427ce1  52                   push edx
// 00427ce2  e839191400           call 0x569620
// 00427ce7  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 00427ceb  8b00                 mov eax, dword ptr [eax]
// 00427ced  51                   push ecx
// 00427cee  68ac038100           push 0x8103ac
// 00427cf3  6a01                 push 1
// 00427cf5  50                   push eax
// 00427cf6  c744244403000000     mov dword ptr [esp + 0x44], 3
// 00427cfe  e89d161400           call 0x5693a0
// 00427d03  8d4c242c             lea ecx, [esp + 0x2c]
// 00427d07  eb2a                 jmp 0x427d33
// 00427d09  8d542420             lea edx, [esp + 0x20]
// 00427d0d  52                   push edx
// 00427d0e  e80d191400           call 0x569620
// 00427d13  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 00427d17  8b00                 mov eax, dword ptr [eax]
// 00427d19  51                   push ecx
// 00427d1a  68ac038100           push 0x8103ac
// 00427d1f  6a03                 push 3
// 00427d21  50                   push eax
// 00427d22  c744244404000000     mov dword ptr [esp + 0x44], 4
// 00427d2a  e871161400           call 0x5693a0
// 00427d2f  8d4c2434             lea ecx, [esp + 0x34]
// 00427d33  83c414               add esp, 0x14
// 00427d36  c7442430ffffffff     mov dword ptr [esp + 0x30], 0xffffffff
// 00427d3e  e81d891d00           call 0x600660
// 00427d43  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00427d47  64890d00000000       mov dword ptr fs:[0], ecx
// 00427d4e  83c434               add esp, 0x34
// 00427d51  c3                   ret 
// 00427d52  8bff                 mov edi, edi
// 00427d54  54                   push esp
// 00427d55  7c42                 jl 0x427d99
// 00427d57  00827c4200b1         add byte ptr [edx - 0x4effbd84], al
// 00427d5d  7c42                 jl 0x427da1
// 00427d5f  00dd                 add ch, bl
// 00427d61  7c42                 jl 0x427da5
// 00427d63  0009                 add byte ptr [ecx], cl
// 00427d65  7d42                 jge 0x427da9
// 00427d67  00437d               add byte ptr [ebx + 0x7d], al
// 00427d6a  42                   inc edx
// 00427d6b  0000                 add byte ptr [eax], al
// 00427d6d  010505020505         add dword ptr [0x5050205], eax
// 00427d73  0503050505           add eax, 0x5050503
// 00427d78  0505050504           add eax, 0x4050505

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
