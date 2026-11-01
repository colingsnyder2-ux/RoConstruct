// from server: 100% by auto
// roc 2009-12 00892e30  unit: CXTPMenuBarMDIMenuInfo  size: 74 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00892e30
//
// 00892e30  83ec0c               sub esp, 0xc
// 00892e33  56                   push esi
// 00892e34  8bf1                 mov esi, ecx
// 00892e36  8b462c               mov eax, dword ptr [esi + 0x2c]
// 00892e39  f7d8                 neg eax
// 00892e3b  1bc0                 sbb eax, eax
// 00892e3d  89442404             mov dword ptr [esp + 4], eax
// 00892e41  742b                 je 0x892e6e
// 00892e43  57                   push edi
// 00892e44  8d7e20               lea edi, [esi + 0x20]
// 00892e47  8d44240c             lea eax, [esp + 0xc]
// 00892e4b  50                   push eax
// 00892e4c  8d4c2414             lea ecx, [esp + 0x14]
// 00892e50  51                   push ecx
// 00892e51  8d542410             lea edx, [esp + 0x10]
// 00892e55  52                   push edx
// 00892e56  8bcf                 mov ecx, edi
// 00892e58  e8c369f7ff           call 0x809820
// 00892e5d  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00892e61  e8760ff6ff           call 0x7f3ddc
// 00892e66  837c240800           cmp dword ptr [esp + 8], 0
// 00892e6b  75da                 jne 0x892e47
// 00892e6d  5f                   pop edi
// 00892e6e  8d4e20               lea ecx, [esi + 0x20]
// 00892e71  5e                   pop esi
// 00892e72  83c40c               add esp, 0xc
// 00892e75  e9a636f6ff           jmp 0x7f6520
// library xtp-15.2.1/Source\CommandBars\XTPMenuBar.cpp (function ?RemoveAll@CXTPMenuBarMDIMenus@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPMenuBar.cpp
