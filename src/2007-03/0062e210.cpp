// from server: 100% by auto
// roc 2007-03 0062e210  unit: seg_00620000  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0062e210
//
// 0062e210  51                   push ecx
// 0062e211  8d442408             lea eax, [esp + 8]
// 0062e215  50                   push eax
// 0062e216  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0062e21a  8d542404             lea edx, [esp + 4]
// 0062e21e  52                   push edx
// 0062e21f  50                   push eax
// 0062e220  e80b8f0600           call 0x697130
// 0062e225  85c0                 test eax, eax
// 0062e227  7504                 jne 0x62e22d
// 0062e229  59                   pop ecx
// 0062e22a  c20800               ret 8
// 0062e22d  8b4804               mov ecx, dword ptr [eax + 4]
// 0062e230  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0062e234  890a                 mov dword ptr [edx], ecx
// 0062e236  b801000000           mov eax, 1
// 0062e23b  59                   pop ecx
// 0062e23c  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxcmdusagecount.cpp (function ?Lookup@?$CMap@IIII@@QBEHIAAI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcmdusagecount.cpp
