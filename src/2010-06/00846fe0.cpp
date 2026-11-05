// from server: 100% by auto
// roc 2010-06 00846fe0  unit: CXTPMenuBarMDIMenuInfo  size: 74 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00846fe0
//
// 00846fe0  83ec0c               sub esp, 0xc
// 00846fe3  56                   push esi
// 00846fe4  8bf1                 mov esi, ecx
// 00846fe6  8b462c               mov eax, dword ptr [esi + 0x2c]
// 00846fe9  f7d8                 neg eax
// 00846feb  1bc0                 sbb eax, eax
// 00846fed  89442404             mov dword ptr [esp + 4], eax
// 00846ff1  742b                 je 0x84701e
// 00846ff3  57                   push edi
// 00846ff4  8d7e20               lea edi, [esi + 0x20]
// 00846ff7  8d44240c             lea eax, [esp + 0xc]
// 00846ffb  50                   push eax
// 00846ffc  8d4c2414             lea ecx, [esp + 0x14]
// 00847000  51                   push ecx
// 00847001  8d542410             lea edx, [esp + 0x10]
// 00847005  52                   push edx
// 00847006  8bcf                 mov ecx, edi
// 00847008  e883920200           call 0x870290
// 0084700d  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00847011  e8060ff6ff           call 0x7a7f1c
// 00847016  837c240800           cmp dword ptr [esp + 8], 0
// 0084701b  75da                 jne 0x846ff7
// 0084701d  5f                   pop edi
// 0084701e  8d4e20               lea ecx, [esi + 0x20]
// 00847021  5e                   pop esi
// 00847022  83c40c               add esp, 0xc
// 00847025  e99669f7ff           jmp 0x7bd9c0
// library xtp-13.2.1/Source\CommandBars\XTPMenuBar.cpp (function ?RemoveAll@CXTPMenuBarMDIMenus@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPMenuBar.cpp
