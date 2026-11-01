// from server: 100% by auto
// roc 2009-06 007b5c50  unit: CXTPMenuBarMDIMenuInfo  size: 74 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007b5c50
//
// 007b5c50  83ec0c               sub esp, 0xc
// 007b5c53  56                   push esi
// 007b5c54  8bf1                 mov esi, ecx
// 007b5c56  8b462c               mov eax, dword ptr [esi + 0x2c]
// 007b5c59  f7d8                 neg eax
// 007b5c5b  1bc0                 sbb eax, eax
// 007b5c5d  89442404             mov dword ptr [esp + 4], eax
// 007b5c61  742b                 je 0x7b5c8e
// 007b5c63  57                   push edi
// 007b5c64  8d7e20               lea edi, [esi + 0x20]
// 007b5c67  8d44240c             lea eax, [esp + 0xc]
// 007b5c6b  50                   push eax
// 007b5c6c  8d4c2414             lea ecx, [esp + 0x14]
// 007b5c70  51                   push ecx
// 007b5c71  8d542410             lea edx, [esp + 0x10]
// 007b5c75  52                   push edx
// 007b5c76  8bcf                 mov ecx, edi
// 007b5c78  e8f3d3fdff           call 0x793070
// 007b5c7d  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 007b5c81  e82233f6ff           call 0x718fa8
// 007b5c86  837c240800           cmp dword ptr [esp + 8], 0
// 007b5c8b  75da                 jne 0x7b5c67
// 007b5c8d  5f                   pop edi
// 007b5c8e  8d4e20               lea ecx, [esi + 0x20]
// 007b5c91  5e                   pop esi
// 007b5c92  83c40c               add esp, 0xc
// 007b5c95  e9e6c9f7ff           jmp 0x732680
// library xtp-15.2.1/Source\CommandBars\XTPMenuBar.cpp (function ?RemoveAll@CXTPMenuBarMDIMenus@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPMenuBar.cpp
