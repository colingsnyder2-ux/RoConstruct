// from server: 100% by auto
// roc 2007-03 0071c200  unit: seg_00710000  size: 88 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0071c200
//
// 0071c200  83ec2c               sub esp, 0x2c
// 0071c203  56                   push esi
// 0071c204  57                   push edi
// 0071c205  8b7c2438             mov edi, dword ptr [esp + 0x38]
// 0071c209  8b4758               mov eax, dword ptr [edi + 0x58]
// 0071c20c  8bf1                 mov esi, ecx
// 0071c20e  50                   push eax
// 0071c20f  8d4c240c             lea ecx, [esp + 0xc]
// 0071c213  51                   push ecx
// 0071c214  8bce                 mov ecx, esi
// 0071c216  e8d5feffff           call 0x71c0f0
// 0071c21b  8b4758               mov eax, dword ptr [edi + 0x58]
// 0071c21e  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 0071c221  8d542418             lea edx, [esp + 0x18]
// 0071c225  52                   push edx
// 0071c226  50                   push eax
// 0071c227  51                   push ecx
// 0071c228  c74424241c000000     mov dword ptr [esp + 0x24], 0x1c
// 0071c230  c744242807000000     mov dword ptr [esp + 0x28], 7
// 0071c238  ff1578ee7700         call dword ptr [0x77ee78]
// 0071c23e  8d542418             lea edx, [esp + 0x18]
// 0071c242  52                   push edx
// 0071c243  57                   push edi
// 0071c244  8d442410             lea eax, [esp + 0x10]
// 0071c248  50                   push eax
// 0071c249  8bce                 mov ecx, esi
// 0071c24b  e890fbffff           call 0x71bde0
// 0071c250  5f                   pop edi
// 0071c251  5e                   pop esi
// 0071c252  83c42c               add esp, 0x2c
// 0071c255  c20400               ret 4
// library xtp-15.2.1/Source\SkinFramework\XTPSkinObjectScrollBar.cpp (function ?SetupScrollInfo@CXTPSkinObjectFrame@@IAEXPAUXTP_SKINSCROLLBARPOSINFO@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SkinFramework/XTPSkinObjectScrollBar.cpp
