// from server: 100% by auto
// roc 2007-03 00698010  unit: seg_00690000  size: 74 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00698010
//
// 00698010  83ec0c               sub esp, 0xc
// 00698013  56                   push esi
// 00698014  8bf1                 mov esi, ecx
// 00698016  8b462c               mov eax, dword ptr [esi + 0x2c]
// 00698019  f7d8                 neg eax
// 0069801b  1bc0                 sbb eax, eax
// 0069801d  89442404             mov dword ptr [esp + 4], eax
// 00698021  742b                 je 0x69804e
// 00698023  57                   push edi
// 00698024  8d7e20               lea edi, [esi + 0x20]
// 00698027  8d44240c             lea eax, [esp + 0xc]
// 0069802b  50                   push eax
// 0069802c  8d4c2414             lea ecx, [esp + 0x14]
// 00698030  51                   push ecx
// 00698031  8d542410             lea edx, [esp + 0x10]
// 00698035  52                   push edx
// 00698036  8bcf                 mov ecx, edi
// 00698038  e8c3d4f8ff           call 0x625500
// 0069803d  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00698041  e82c66f8ff           call 0x61e672
// 00698046  837c240800           cmp dword ptr [esp + 8], 0
// 0069804b  75da                 jne 0x698027
// 0069804d  5f                   pop edi
// 0069804e  8d4e20               lea ecx, [esi + 0x20]
// 00698051  5e                   pop esi
// 00698052  83c40c               add esp, 0xc
// 00698055  e96639f9ff           jmp 0x62b9c0
// library xtp-15.2.1/Source\CommandBars\XTPMenuBar.cpp (function ?RemoveAll@CXTPMenuBarMDIMenus@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPMenuBar.cpp
