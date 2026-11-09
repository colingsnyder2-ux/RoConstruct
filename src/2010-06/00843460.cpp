// from server: 100% by auto
// roc 2010-06 00843460  unit: CXTPShortcutManager  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00843460
//
// 00843460  51                   push ecx
// 00843461  8d442408             lea eax, [esp + 8]
// 00843465  50                   push eax
// 00843466  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0084346a  8d542404             lea edx, [esp + 4]
// 0084346e  52                   push edx
// 0084346f  50                   push eax
// 00843470  e89b86f6ff           call 0x7abb10
// 00843475  85c0                 test eax, eax
// 00843477  7504                 jne 0x84347d
// 00843479  59                   pop ecx
// 0084347a  c20800               ret 8
// 0084347d  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00843481  83c004               add eax, 4
// 00843484  50                   push eax
// 00843485  ff1580c59e00         call dword ptr [0x9ec580]
// 0084348b  b801000000           mov eax, 1
// 00843490  59                   pop ecx
// 00843491  c20800               ret 8
// library xtp-13.2.1-shared-mfc/Source\CommandBars\XTPShortcutManager.cpp (function ?Lookup@?$CMap@GGV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V12@@@QBEHGAAV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/CommandBars/XTPShortcutManager.cpp
