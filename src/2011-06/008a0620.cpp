// from server: 100% by auto
// roc 2011-06 008a0620  unit: CXTPShortcutManager  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008a0620
//
// 008a0620  51                   push ecx
// 008a0621  8d442408             lea eax, [esp + 8]
// 008a0625  50                   push eax
// 008a0626  8b44240c             mov eax, dword ptr [esp + 0xc]
// 008a062a  8d542404             lea edx, [esp + 4]
// 008a062e  52                   push edx
// 008a062f  50                   push eax
// 008a0630  e8dbe7fcff           call 0x86ee10
// 008a0635  85c0                 test eax, eax
// 008a0637  7504                 jne 0x8a063d
// 008a0639  59                   pop ecx
// 008a063a  c20800               ret 8
// 008a063d  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008a0641  83c004               add eax, 4
// 008a0644  50                   push eax
// 008a0645  ff156425a400         call dword ptr [0xa42564]
// 008a064b  b801000000           mov eax, 1
// 008a0650  59                   pop ecx
// 008a0651  c20800               ret 8
// library xtp-15.2.1-shared-mfc/Source\CommandBars\XTPShortcutManager.cpp (function ?Lookup@?$CMap@GGV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V12@@@QBEHGAAV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/CommandBars/XTPShortcutManager.cpp
