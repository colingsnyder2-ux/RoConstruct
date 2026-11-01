// from server: 100% by auto
// roc 2007-03 00718d60  unit: seg_00710000  size: 194 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00718d60
//
// 00718d60  83ec20               sub esp, 0x20
// 00718d63  53                   push ebx
// 00718d64  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 00718d68  56                   push esi
// 00718d69  6838010000           push 0x138
// 00718d6e  8d442434             lea eax, [esp + 0x34]
// 00718d72  50                   push eax
// 00718d73  53                   push ebx
// 00718d74  8bf1                 mov esi, ecx
// 00718d76  e8056c0000           call 0x71f980
// 00718d7b  8bce                 mov ecx, esi
// 00718d7d  e8421e0200           call 0x73abc4
// 00718d82  a900010000           test eax, 0x100
// 00718d87  0f858d000000         jne 0x718e1a
// 00718d8d  57                   push edi
// 00718d8e  8bce                 mov ecx, esi
// 00718d90  e8fbb1fdff           call 0x6f3f90
// 00718d95  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 00718d99  8b542438             mov edx, dword ptr [esp + 0x38]
// 00718d9d  894c240c             mov dword ptr [esp + 0xc], ecx
// 00718da1  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 00718da5  89542410             mov dword ptr [esp + 0x10], edx
// 00718da9  8bf8                 mov edi, eax
// 00718dab  8b44243c             mov eax, dword ptr [esp + 0x3c]
// 00718daf  8d54241c             lea edx, [esp + 0x1c]
// 00718db3  894c2418             mov dword ptr [esp + 0x18], ecx
// 00718db7  52                   push edx
// 00718db8  8bce                 mov ecx, esi
// 00718dba  89442418             mov dword ptr [esp + 0x18], eax
// 00718dbe  e8cdfeffff           call 0x718c90
// 00718dc3  8bce                 mov ecx, esi
// 00718dc5  e8fa1d0200           call 0x73abc4
// 00718dca  2582000000           and eax, 0x82
// 00718dcf  3d82000000           cmp eax, 0x82
// 00718dd4  750a                 jne 0x718de0
// 00718dd6  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00718dda  89442414             mov dword ptr [esp + 0x14], eax
// 00718dde  eb28                 jmp 0x718e08
// 00718de0  3d80000000           cmp eax, 0x80
// 00718de5  750a                 jne 0x718df1
// 00718de7  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00718deb  894c240c             mov dword ptr [esp + 0xc], ecx
// 00718def  eb17                 jmp 0x718e08
// 00718df1  83f802               cmp eax, 2
// 00718df4  750a                 jne 0x718e00
// 00718df6  8b542420             mov edx, dword ptr [esp + 0x20]
// 00718dfa  89542418             mov dword ptr [esp + 0x18], edx
// 00718dfe  eb08                 jmp 0x718e08
// 00718e00  8b442428             mov eax, dword ptr [esp + 0x28]
// 00718e04  89442410             mov dword ptr [esp + 0x10], eax
// 00718e08  8d4c240c             lea ecx, [esp + 0xc]
// 00718e0c  51                   push ecx
// 00718e0d  6a00                 push 0
// 00718e0f  6a09                 push 9
// 00718e11  53                   push ebx
// 00718e12  8bcf                 mov ecx, edi
// 00718e14  e85778f6ff           call 0x680670
// 00718e19  5f                   pop edi
// 00718e1a  5e                   pop esi
// 00718e1b  5b                   pop ebx
// 00718e1c  83c420               add esp, 0x20
// 00718e1f  c21400               ret 0x14
// library xtp-15.2.1/Source\SkinFramework\XTPSkinObjectTab.cpp (function ?FillClient@CXTPSkinObjectTab@@IAEXPAVCDC@@VCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SkinFramework/XTPSkinObjectTab.cpp
