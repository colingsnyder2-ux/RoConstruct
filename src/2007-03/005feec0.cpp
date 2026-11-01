// from server: 100% by auto
// roc 2007-03 005feec0  unit: seg_005f0000  size: 301 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005feec0
//
// 005feec0  83ec38               sub esp, 0x38
// 005feec3  53                   push ebx
// 005feec4  8b5c2444             mov ebx, dword ptr [esp + 0x44]
// 005feec8  8b4308               mov eax, dword ptr [ebx + 8]
// 005feecb  83f806               cmp eax, 6
// 005feece  55                   push ebp
// 005feecf  8d6b08               lea ebp, [ebx + 8]
// 005feed2  56                   push esi
// 005feed3  8b742448             mov esi, dword ptr [esp + 0x48]
// 005feed7  57                   push edi
// 005feed8  7c05                 jl 0x5feedf
// 005feeda  83f809               cmp eax, 9
// 005feedd  7e0e                 jle 0x5feeed
// 005feedf  68f0057c00           push 0x7c05f0
// 005feee4  56                   push esi
// 005feee5  e886200000           call 0x600f70
// 005feeea  83c408               add esp, 8
// 005feeed  8b4610               mov eax, dword ptr [esi + 0x10]
// 005feef0  83f82c               cmp eax, 0x2c
// 005feef3  753e                 jne 0x5fef33
// 005feef5  56                   push esi
// 005feef6  e8a5340000           call 0x6023a0
// 005feefb  83c404               add esp, 4
// 005feefe  8d7c2430             lea edi, [esp + 0x30]
// 005fef02  895c2428             mov dword ptr [esp + 0x28], ebx
// 005fef06  e845f7ffff           call 0x5fe650
// 005fef0b  837c243006           cmp dword ptr [esp + 0x30], 6
// 005fef10  7509                 jne 0x5fef1b
// 005fef12  8bc3                 mov eax, ebx
// 005fef14  8bce                 mov ecx, esi
// 005fef16  e845ffffff           call 0x5fee60
// 005fef1b  8b442454             mov eax, dword ptr [esp + 0x54]
// 005fef1f  83c001               add eax, 1
// 005fef22  50                   push eax
// 005fef23  8d4c242c             lea ecx, [esp + 0x2c]
// 005fef27  51                   push ecx
// 005fef28  56                   push esi
// 005fef29  e892ffffff           call 0x5feec0
// 005fef2e  83c40c               add esp, 0xc
// 005fef31  eb5f                 jmp 0x5fef92
// 005fef33  83f83d               cmp eax, 0x3d
// 005fef36  7421                 je 0x5fef59
// 005fef38  6a3d                 push 0x3d
// 005fef3a  56                   push esi
// 005fef3b  e8301f0000           call 0x600e70
// 005fef40  8b5634               mov edx, dword ptr [esi + 0x34]
// 005fef43  50                   push eax
// 005fef44  6828047c00           push 0x7c0428
// 005fef49  52                   push edx
// 005fef4a  e8f198ffff           call 0x5f8840
// 005fef4f  50                   push eax
// 005fef50  56                   push esi
// 005fef51  e81a200000           call 0x600f70
// 005fef56  83c41c               add esp, 0x1c
// 005fef59  56                   push esi
// 005fef5a  e841340000           call 0x6023a0
// 005fef5f  83c404               add esp, 4
// 005fef62  8d7c2410             lea edi, [esp + 0x10]
// 005fef66  e8f5f4ffff           call 0x5fe460
// 005fef6b  8b7c2454             mov edi, dword ptr [esp + 0x54]
// 005fef6f  8bd8                 mov ebx, eax
// 005fef71  3bdf                 cmp ebx, edi
// 005fef73  8d4c2410             lea ecx, [esp + 0x10]
// 005fef77  7450                 je 0x5fefc9
// 005fef79  53                   push ebx
// 005fef7a  8bd7                 mov edx, edi
// 005fef7c  8bc6                 mov eax, esi
// 005fef7e  e8fde9ffff           call 0x5fd980
// 005fef83  83c404               add esp, 4
// 005fef86  3bdf                 cmp ebx, edi
// 005fef88  7e08                 jle 0x5fef92
// 005fef8a  8b4630               mov eax, dword ptr [esi + 0x30]
// 005fef8d  2bfb                 sub edi, ebx
// 005fef8f  017824               add dword ptr [eax + 0x24], edi
// 005fef92  8b7630               mov esi, dword ptr [esi + 0x30]
// 005fef95  8b4624               mov eax, dword ptr [esi + 0x24]
// 005fef98  83e801               sub eax, 1
// 005fef9b  89442418             mov dword ptr [esp + 0x18], eax
// 005fef9f  8d442410             lea eax, [esp + 0x10]
// 005fefa3  50                   push eax
// 005fefa4  83c9ff               or ecx, 0xffffffff
// 005fefa7  55                   push ebp
// 005fefa8  56                   push esi
// 005fefa9  894c242c             mov dword ptr [esp + 0x2c], ecx
// 005fefad  894c2430             mov dword ptr [esp + 0x30], ecx
// 005fefb1  c744241c0c000000     mov dword ptr [esp + 0x1c], 0xc
// 005fefb9  e8f2630100           call 0x6153b0
// 005fefbe  83c40c               add esp, 0xc
// 005fefc1  5f                   pop edi
// 005fefc2  5e                   pop esi
// 005fefc3  5d                   pop ebp
// 005fefc4  5b                   pop ebx
// 005fefc5  83c438               add esp, 0x38
// 005fefc8  c3                   ret 
// 005fefc9  8b5630               mov edx, dword ptr [esi + 0x30]
// 005fefcc  51                   push ecx
// 005fefcd  52                   push edx
// 005fefce  e87d590100           call 0x614950
// 005fefd3  8b4e30               mov ecx, dword ptr [esi + 0x30]
// 005fefd6  8d442418             lea eax, [esp + 0x18]
// 005fefda  50                   push eax
// 005fefdb  55                   push ebp
// 005fefdc  51                   push ecx
// 005fefdd  e8ce630100           call 0x6153b0
// 005fefe2  83c414               add esp, 0x14
// 005fefe5  5f                   pop edi
// 005fefe6  5e                   pop esi
// 005fefe7  5d                   pop ebp
// 005fefe8  5b                   pop ebx
// 005fefe9  83c438               add esp, 0x38
// 005fefec  c3                   ret 
// library lua-5.1.1/lparser.c (function _assignment)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lparser.c
