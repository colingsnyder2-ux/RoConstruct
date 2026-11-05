// from server: 100% by EspClaude
// roc 2009-06 00422de0  unit: LogManager  size: 349 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00422de0
//
// 00422de0  64a100000000         mov eax, dword ptr fs:[0]
// 00422de6  6aff                 push -1
// 00422de8  6818e98400           push 0x84e918
// 00422ded  50                   push eax
// 00422dee  0fb7442410           movzx eax, word ptr [esp + 0x10]
// 00422df3  64892500000000       mov dword ptr fs:[0], esp
// 00422dfa  83ec28               sub esp, 0x28
// 00422dfd  83f810               cmp eax, 0x10
// 00422e00  0f87fd000000         ja 0x422f03
// 00422e06  0fb6802c2f4200       movzx eax, byte ptr [eax + 0x422f2c]
// 00422e0d  ff2485142f4200       jmp dword ptr [eax*4 + 0x422f14]
// 00422e14  8d0c24               lea ecx, [esp]
// 00422e17  51                   push ecx
// 00422e18  e8a3ee1b00           call 0x5e1cc0
// 00422e1d  8b542440             mov edx, dword ptr [esp + 0x40]
// 00422e21  8b00                 mov eax, dword ptr [eax]
// 00422e23  52                   push edx
// 00422e24  68400b8b00           push 0x8b0b40
// 00422e29  6a01                 push 1
// 00422e2b  50                   push eax
// 00422e2c  c744244400000000     mov dword ptr [esp + 0x44], 0
// 00422e34  e827ec1b00           call 0x5e1a60
// 00422e39  8d4c2414             lea ecx, [esp + 0x14]
// 00422e3d  e9b1000000           jmp 0x422ef3
// 00422e42  8d442408             lea eax, [esp + 8]
// 00422e46  50                   push eax
// 00422e47  e874ee1b00           call 0x5e1cc0
// 00422e4c  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 00422e50  8b00                 mov eax, dword ptr [eax]
// 00422e52  51                   push ecx
// 00422e53  68400b8b00           push 0x8b0b40
// 00422e58  6a03                 push 3
// 00422e5a  50                   push eax
// 00422e5b  c744244401000000     mov dword ptr [esp + 0x44], 1
// 00422e63  e8f8eb1b00           call 0x5e1a60
// 00422e68  8d4c241c             lea ecx, [esp + 0x1c]
// 00422e6c  e982000000           jmp 0x422ef3
// 00422e71  8d542410             lea edx, [esp + 0x10]
// 00422e75  52                   push edx
// 00422e76  e845ee1b00           call 0x5e1cc0
// 00422e7b  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 00422e7f  8b00                 mov eax, dword ptr [eax]
// 00422e81  51                   push ecx
// 00422e82  68400b8b00           push 0x8b0b40
// 00422e87  6a01                 push 1
// 00422e89  50                   push eax
// 00422e8a  c744244402000000     mov dword ptr [esp + 0x44], 2
// 00422e92  e8c9eb1b00           call 0x5e1a60
// 00422e97  8d4c2424             lea ecx, [esp + 0x24]
// 00422e9b  eb56                 jmp 0x422ef3
// 00422e9d  8d542418             lea edx, [esp + 0x18]
// 00422ea1  52                   push edx
// 00422ea2  e819ee1b00           call 0x5e1cc0
// 00422ea7  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 00422eab  8b00                 mov eax, dword ptr [eax]
// 00422ead  51                   push ecx
// 00422eae  68400b8b00           push 0x8b0b40
// 00422eb3  6a01                 push 1
// 00422eb5  50                   push eax
// 00422eb6  c744244403000000     mov dword ptr [esp + 0x44], 3
// 00422ebe  e89deb1b00           call 0x5e1a60
// 00422ec3  8d4c242c             lea ecx, [esp + 0x2c]
// 00422ec7  eb2a                 jmp 0x422ef3
// 00422ec9  8d542420             lea edx, [esp + 0x20]
// 00422ecd  52                   push edx
// 00422ece  e8eded1b00           call 0x5e1cc0
// 00422ed3  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 00422ed7  8b00                 mov eax, dword ptr [eax]
// 00422ed9  51                   push ecx
// 00422eda  68400b8b00           push 0x8b0b40
// 00422edf  6a03                 push 3
// 00422ee1  50                   push eax
// 00422ee2  c744244404000000     mov dword ptr [esp + 0x44], 4
// 00422eea  e871eb1b00           call 0x5e1a60
// 00422eef  8d4c2434             lea ecx, [esp + 0x34]
// 00422ef3  83c414               add esp, 0x14
// 00422ef6  c7442430ffffffff     mov dword ptr [esp + 0x30], 0xffffffff
// 00422efe  e8ad182000           call 0x6247b0
// 00422f03  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00422f07  64890d00000000       mov dword ptr fs:[0], ecx
// 00422f0e  83c434               add esp, 0x34
// 00422f11  c3                   ret 
// 00422f12  8bff                 mov edi, edi
// 00422f14  142e                 adc al, 0x2e
// 00422f16  42                   inc edx
// 00422f17  00422e               add byte ptr [edx + 0x2e], al
// 00422f1a  42                   inc edx
// 00422f1b  00712e               add byte ptr [ecx + 0x2e], dh
// 00422f1e  42                   inc edx
// 00422f1f  009d2e4200c9         add byte ptr [ebp - 0x36ffbdd2], bl
// 00422f25  2e42                 inc edx
// 00422f27  0003                 add byte ptr [ebx], al
// 00422f29  2f                   das 
// 00422f2a  42                   inc edx
// 00422f2b  0000                 add byte ptr [eax], al
// 00422f2d  010505020505         add dword ptr [0x5050205], eax
// 00422f33  0503050505           add eax, 0x5050503
// 00422f38  0505050504           add eax, 0x4050505
// copied from an identical function in another client (function ?reportStatus@ns_ROCX0000a3@@YAXGPBD@Z)

namespace ns_ROCX0000a3 {
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
}
